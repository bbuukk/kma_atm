		-- account relating scripts
        
				-- procedures
--
-- • get_transaction    	  	  -- get transaction number with account number of payer and account number of payee 					
-- • withdrawal    	  			  -- (private) take money out of bank account 					  
-- • deposit 					  -- (private) put money on bank account 						 
-- • transact           		  -- make transaction 											  
-- • withdraw   	  			  -- make withdraw												  
-- • get_all_acc_trans 	     	  -- get transactions of account for the whole time				  
-- • get_acc_trans_curr_month 	  -- get transactions of account for the current month			  
-- • get_acc_trans_by_month    	  -- get transactions of account for input month in this year	  
-- • get_acc_trans_by_date    	  -- get transactions of account for exact date                   
--
				-- functions
-- • get_acc_blnc   	  -- returns balance of acc 	
-- • is_acc_blocked 	  -- returns is_blocked of acc 

drop procedure if exists get_transaction;
delimiter //
create procedure get_transaction
(in trans_num nvarchar(30)) 
begin 
	select t.num,
		   a1.num as acc_from,
           a2.num as acc_to,
           t.sum, t.date,
           t.successful,
           atms.num as atm_num,
           t.descript
    from Transactions as t
    inner join Accounts as a1
    on t.acc_from = a1.id
    left join Accounts as a2
    on t.acc_to = a2.id
    left join ATMs as atms
    on t.atm_id = atms.id
    where t.num = trans_num;
    
end //
delimiter ;

-- ------------------------------------------------------------

-- call insert_transaction("01234", 1,null,30, true,"for laziness");
-- select * from Transactions;

drop procedure if exists insert_transaction;
delimiter //
create procedure insert_transaction(
in atm_num nvarchar(10),
in f_id int unsigned,
in t_id int unsigned,
in sum int unsigned,
in is_successful tinyint,
in descript tinytext)
begin
	declare trans_num nvarchar(10);
    declare atm_id int unsigned;
     
	select cast(t.num as unsigned)
	into trans_num
	from Transactions as t
	order by t.id desc limit 1;
	set trans_num = trans_num + 1;
     
	set atm_id = atm_id(atm_num);

	insert into Transactions
	VALUES ( null, cast(trans_num as char(10)) , atm_id , f_id , t_id , sum, now(), is_successful , descript );
end //
delimiter ;	

drop function if exists deposit;
delimiter //
create function deposit(
t_id int unsigned, sum int unsigned)
returns tinyint deterministic
begin     
	 declare is_successful tinyint;
     set is_successful = true;
	 update Accounts as a
	 set a.balance = a.balance+sum
	 where a.id = t_id;
     return is_successful;
end //
delimiter ;	

drop function if exists withdrawal;
delimiter //
create function withdrawal(
f_id int unsigned, sum int unsigned)
returns tinyint deterministic
begin     
	 declare is_successful tinyint;

	declare not_enougth_funds
	condition for sqlstate '45000';  

	if (balance(f_id) < sum)
		then
			set is_successful = false;
			signal not_enougth_funds SET MESSAGE_TEXT = 'Not enougth funds';
	else
		 set is_successful = true;
		 update Accounts as a
		 set a.balance = a.balance-sum
		 where a.id = f_id;
	end if;
    return is_successful;
end //
delimiter ;	

drop function if exists balance;
delimiter //
create function balance(id int unsigned)
returns double deterministic
begin 
	declare blnc double;
	select a.balance into blnc
    from Accounts as a
    where a.id = id;
    return blnc;
end //
delimiter ;

drop function if exists atm_fee;
delimiter //
create function atm_fee(id int unsigned)
returns double deterministic
begin 
	declare fee double;
	select a.atm_fee into fee
    from Accounts as a
    where a.id = id;
    return fee;
end //
delimiter ;	

drop procedure if exists acc_trans;
delimiter //
create procedure acc_trans
(in acc_id int unsigned) 
begin 
	select t.num, t.acc_from,
		   t.acc_to, t.sum, t.date,
           t.is_successful, t.descript
    from Transactions as t
    where t.acc_from = acc_id OR t.acc_to = acc_id;
end //
delimiter ;

	

