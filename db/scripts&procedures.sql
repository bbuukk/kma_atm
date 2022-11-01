--  		planned procedures
-- 1}} show info about current ATM being used
-- 2}} show info about current user's bank account
-- 3}} make transaction
-- 4}} add account
-- 5}} get balance of current account
-- 6}} show account's history of transactions
-- 7}} 

DROP PROCEDURE IF EXISTS get_ATM_info;
-- 1}} show info about current ATM being used // CHECK
delimiter //
create procedure get_ATM_info(IN m_id INT) 
begin 
	select concat(atm_building,' ',atm_street) as ATMAdress,
		  concat(office_city,', ', office_building,' ',
           office_street) as BranchOfficeAdress, 
           bank_name as Bankname
	from AutoTellerMachine as atm
    inner join Offices as offs
    on offs.office_id=atm.office_id
    inner join Banks as banks
    on offs.bank_id = banks.bank_id
    where machine_id = m_id;
end //
delimiter ;

DROP PROCEDURE IF EXISTS get_acc_gen_info;
-- 2.1}} get general info about bank account //CHECK
delimiter //
create procedure get_acc_gen_info(IN acc_id INT) 
begin 
	select account_number, date_open, balance, iban
    from Accounts as accs
    where acc_id = accs.account_id;
end //
delimiter;

-- 2.01}} get info about checking account //CHECK
delimiter //
create procedure get_chk_acc_info(IN acc_id INT) 
begin 
	select account_number, date_open, balance, iban , overdraft_limit
    from Accounts as accs
    where acc_id = accs.account_id;
end //
delimiter ;

-- 2.02}} get info about savings account //CHECK
delimiter //
create procedure get_sv_acc_info(IN acc_id INT) 
begin 
	select account_number, date_open, balance, iban, intrest, trans_limit
    from Accounts as accs
    inner join Account_types as acc_tps
    on acc_tps.account_type = accs.account_type
    where acc_id = accs.account_id;
end //
delimiter ;

-- 2.03}} get info about loc account //CHECK
delimiter //
create procedure get_loc_acc_info(IN acc_id INT) 
begin 
	select account_number, date_open, balance, iban , credit_sum_taken, loc_limit
    from Accounts as accs
    where acc_id = accs.account_id;
end //
delimiter ;

DELIMITER //
CREATE procedure get_acc_t(in acc_id INT, out acc_type tinyint)
BEGIN
 select account_type into acc_type
		 from Accounts
         where account_id = acc_id;
END 
//
DELIMITER ;

DROP PROCEDURE IF EXISTS get_account_info;
-- 2.2}} show info about current user's bank account including unique characteristics for every type of accounts //CHECK
delimiter //
create procedure get_account_info(IN acc_id INT) 
begin 

declare acc_type tinyint;
call get_acc_t(acc_id, acc_type);
    
case  
when (acc_type = 1 OR acc_type = 2)
then call get_chk_acc_info(acc_id); 

when acc_type = 3 
then call get_sv_acc_info(acc_id); 

when acc_type = 4
then call get_loc_acc_info(acc_id); 

else call get_acc_gen_info(acc_id); 

end case;
end //
delimiter ;


-- 2.1}} show acc info(balance) //check
delimiter //
create procedure get_acc_balance(in acc_id int, out blnc double)
begin 
	select balance into blnc
    from Accounts as accs
    where acc_id = accs.account_id;
end //
delimiter ;

-- 2.1}} show acc info(balance&digital_code) //check
-- procedure
-- delimiter //
-- create procedure get_acc_balance_info(IN acc_id INT) 
-- begin 
-- 	select balance, digital_code
--     from Accounts as accs
--     where acc_id = accs.account_id;
-- end //
-- delimiter ;

-- 2.2}} show acc info(bank&office) //check
delimiter //
create procedure get_acc_office_info(IN acc_id INT) 
begin 
	select account_id, bank_name,
		   office_city, office_street,
           office_building
    from Accounts as accs
	inner join Offices as offs
    on offs.office_id = accs.office_id
    inner join Banks as bnks
    on offs.bank_id = bnks.bank_id 
    where acc_id = accs.account_id;
end //
delimiter ;

-- 2.3}} show acc info(client) //check
delimiter //
create procedure get_acc_client_info(IN acc_id INT) 
begin 
	select account_id, first_name,
		   last_name, mobile_phone
    from Accounts as accs
	inner join Clients as clnts
    on clnts.client_id = accs.client_id
    where acc_id = accs.account_id;
end //
delimiter ;

-- 2.4}} show acc info(acc_type) //check
delimiter //
create procedure get_acc_acc_type_info(IN acc_id INT) 
begin 
	select account_id, account_name,
		   atm_fee, description
    from Accounts as accs
	inner join Account_types as acc_tps
    on acc_tps.account_type = accs.account_type
    where acc_id = accs.account_id;
end //
delimiter ;

delimiter //
create procedure count_oper_sum(in acc_id INT, out sum double)
begin 
	select balance * get_atm_fee(acc_id) into sum
    from Accounts as accs
    where acc_id = accs.account_id;
end //
delimiter ;

delimiter //
create procedure get_atm_fee(in acc_id INT , out fee double)
begin 
	select atm_fee into fee
    from Accounts as accs
    inner join Account_types as acc_tps
    on acc_tps.account_type = acc_id
    where accs.account_id = acc_id;
end //
delimiter ;

-- should check for currencies of atm itself //check
-- 3.2}} make withdraw
delimiter //
create procedure withdraw(
IN mach_id INT,
IN acc_from INT,
IN t_sum INT) 
begin 

declare not_enougth_funds
condition for sqlstate '45000'; 

declare sum double;
declare blnc double;
declare atm_fee double;
declare fee double;
declare is_success tinyint;

call get_acc_balance(acc_from, blnc);
call get_atm_fee(acc_from, atm_fee);
set fee = t_sum*atm_fee;
set sum = t_sum + fee;

if (blnc < sum)
	then
		set is_success = false;
		signal not_enougth_funds SET MESSAGE_TEXT = 'Not enougth funds';
else
	 update Accounts as accs
	 set balance = balance-sum
	 where accs.account_id = acc_from;
     set is_success = true;
end if;

insert into Transactions
VALUES ( null , mach_id , acc_from, null , t_sum , curdate(), is_success , null);
select t_sum, is_success;
end //
delimiter ;


-- check for
-- enougth funds on account being charged after t_sum is suplmented with atm_fee coefficient
-- if trans_lim is not excedeeing (we need functions to count how many operations were made by this acc for last month)
-- if acc_type is 1,2 or 3
-- 3.2}} make withdraw
delimiter //
create procedure charge
(acc_from INT, IN t_sum INT) 
begin 



declare not_enougth_funds
condition for sqlstate '45000'; 

declare sum double;
declare blnc double;
declare atm_fee double;
declare fee double;
declare is_success tinyint;

call get_acc_balance(acc_from, blnc);
call get_atm_fee(acc_from, atm_fee);
set fee = t_sum*atm_fee;
set sum = t_sum + fee;

if ()

if (blnc < sum)
	then
		set is_success = false;
		signal not_enougth_funds SET MESSAGE_TEXT = 'Not enougth funds';
else
	 update Accounts as accs
	 set balance = balance-sum
	 where accs.account_id = acc_from;
     set is_success = true;
end if;

insert into Transactions
VALUES ( null , mach_id , acc_from, null , t_sum , curdate(), is_success , null);
select t_sum, is_success;
end //
delimiter ;


-- 3}} make transaction
-- making ATMtransaction we need:
-- 	if acc_from balance >= sum
-- 	if acc_from currency == acc_to currency
--  \withdraw/ acc_from currency == atm currency
-- take current_date and use it for current row

-- 3.1}} make transaction
delimiter //
create procedure transact(
IN mach_id INT, IN acc_from INT,
IN acc_to INT, IN t_sum INT) 
begin 

	update Accounts
	set balance = balance-t_sum
	where acocutn = acc_from;

    update Accounts
	set balance = balance+t_sum
	where account_id = acc_to;
end //
delimiter ;




















