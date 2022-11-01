--  procedures & functions in file  -- script1.file
-- 1p}} get info about ATM by mach_id 
-- 2.1p}} get info about bank account by acc_id
-- 2.2p}} get info about office by acc_id 
-- 2.3p}} get info about client by acc_id
-- 3p}} get balance & dgt_code by acc_id
-- 4.1f}} get acc_type by acc_id
-- 4.2f}} get balance  by acc_id
-- 4.3f}} get atm_fee  by acc_id
-- 5.1p}} take money out of bank account
-- 5.2p}} put money on bank account
-- 6.1p}} make transaction
-- 6.2p}} make withdraw

-- 1p}} get info about ATM by mach_id 
drop procedure if exists get_ATM_info;
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

-- 2.1p}} get info about bank account 
drop procedure if exists get_acc_info;
delimiter //
create procedure get_acc_info(IN acc_id INT) 
begin 
	select acc_num, date_open, balance, is_blocked, tps.name, tps.descript
    from Accounts as accs
    inner join Account_types as tps
    on tps.account_type = accs.account_type
    where acc_id = accs.account_id;
end //
delimiter ;

-- 2.2p}} get info about office by acc_id 
drop procedure if exists get_acc_off_info;
delimiter //
create procedure get_acc_off_info(IN acc_id INT) 
begin 
	select office_city, office_street,
           office_building
    from Accounts as accs
	inner join Offices as offs
    on offs.office_id = accs.office_id
    where acc_id = accs.account_id;
end //
delimiter ;

-- 2.3p}} get info about client by acc_id
drop procedure if exists get_acc_client_info;
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

-- 3p}} get balance & dgt_code by acc_id
drop procedure if exists get_acc_balance_info;
delimiter //
create procedure get_acc_balance_info(IN acc_id INT) 
begin 
	select balance, digital_code
    from Accounts as accs
    where acc_id = accs.account_id;
end //
delimiter ;

-- 4.1f}} get account_type by acc_id
drop function if exists get_acc_tp;
DELIMITER //
create function get_acc_tp(acc_id INT)
returns int deterministic
begin
	declare acc_type int;
	select account_type into acc_type
	from Accounts
	where account_id = acc_id;
    return acc_type;
end //
DELIMITER ;

-- 4.2f}} get balance by acc_id
drop function if exists get_acc_blnc;
delimiter //
create function get_acc_blnc(acc_id int)
returns double deterministic
begin 
	declare blnc double;
	select balance into blnc
    from Accounts as accs
    where acc_id = accs.account_id;
    return blnc;
end //
delimiter ;

-- 4.3f}} get atm_fee by acc_id
drop function if exists get_atm_fee;
delimiter //
create function get_atm_fee(acc_id INT)
returns double deterministic
begin 
	declare fee double;
	select atm_fee into fee
    from Accounts as accs
    where accs.account_id = acc_id;
    return fee;
end //
delimiter ;

-- check for
-- enougth funds on account being charged after t_sum is suplmented with atm_fee coefficient
-- MAYBE if trans_lim is not excedeeing (we need functions to count how many operations were made by this acc for last month)

-- 5.1p}} take money out of bank account
drop procedure if exists withdrawal;
delimiter //
create procedure withdrawal
(in acc_from INT, IN t_sum INT,
 out is_successful tinyint) 
begin 

declare not_enougth_funds
condition for sqlstate '45000';  

declare sum double;
declare blnc double;
declare atm_fee double;

set blnc = get_acc_balance(acc_from);
set atm_fee = t_sum*get_atm_fee(acc_from);
set sum = t_sum + atm_fee;

if (blnc < sum)
	then
		set is_successful = false;
		signal not_enougth_funds SET MESSAGE_TEXT = 'Not enougth funds';
else
	 set is_successful = true;
	 update Accounts as accs
	 set balance = balance-sum
	 where accs.account_id = acc_from;
end if;
end //
delimiter ;


-- should check for currency of acc_to !!

-- 5.2p}} put money on bank account
drop procedure if exists deposit;
delimiter //
create procedure deposit
(in acc_to INT, IN t_sum INT,
 out is_successful tinyint) 
begin 
	 set is_successful = true;
	 update Accounts as accs
	 set balance = balance+t_sum
	 where accs.account_id = acc_from;
end //
delimiter ;

-- 3}} make transaction
-- making ATMtransaction we need:
-- 	if acc_from balance >= sum
-- 	if acc_from currency == acc_to currency
--  \withdraw/ acc_from currency == atm currency
-- take current_date and use it for current row

-- should make dangling transaction? (коли не вдалось провести транзакцію, чи повинен я в деяких випадках просто відкладати її??)
-- need to check if one branched if works fine

-- 6.1p}} make transaction
drop procedure if exists transact;
delimiter //
create procedure transact(
IN mach_id INT, IN acc_from INT,
IN acc_to INT, IN t_sum INT) 
begin 

declare is_successful tinyint;

call withdrawal(acc_from, t_sum, is_successful);

if is_successful
	then
		call deposit(acc_to, t_sum, is_susccessful);
end if;

insert into Transactions
VALUES ( null , mach_id , acc_from, null , t_sum , curdate(), is_successful , null);
end //
delimiter ;

-- should check for currencies of atm itself 

-- 6.2p}} make withdraw
drop procedure if exists withdraw;
delimiter //
create procedure withdraw(
IN mach_id INT,
IN acc_from INT,
IN t_sum INT) 
begin 

declare is_successful tinyint;

call withdrawal(acc_from, t_sum, is_successful);

insert into Transactions
VALUES ( null , mach_id , acc_from, null , t_sum , curdate(), is_successful , null);

end //
delimiter ;




















