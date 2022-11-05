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
--

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

-- should check for currency of acc_to !!
drop procedure if exists deposit;
delimiter //
create procedure deposit
(in acc_to nvarchar(30),
 IN t_sum INT,
 out is_successful tinyint) 
begin 
	 set is_successful = true;
	 update Accounts as a
	 set balance = balance+t_sum
	 where a.num = acc_to;
end //
delimiter ;

-- !!make transaction
-- making ATMtransaction we need:
-- 	if acc_from balance >= sum
-- 	if acc_from currency == acc_to currency
--  \withdraw/ acc_from currency == atm currency
-- take current_date and use it for current row

-- should make dangling transaction? (коли не вдалось провести транзакцію, чи повинен я в деяких випадках просто відкладати її??)
-- need to check if one branched if works fine


drop procedure if exists transact;
delimiter //
create procedure transact(
in atm_num nvarchar(10),
in acc_from nvarchar(30),
in acc_to nvarchar(30),
in sum int unsigned,
in descript tinytext) 
begin 

declare is_successful tinyint;

call withdrawal(acc_from, t_sum, is_successful);

if is_successful
	then
		call deposit(acc_to, t_sum, is_susccessful);
end if;

insert into Transactions
VALUES ( null, cast(trans_num as char(10)) , atm_num , acc_from , acc_to , 76543, now(), is_successful , descript );
select is_successful;
end //
delimiter ;

-- should check for currencies of atm itself 
drop procedure if exists withdraw;
delimiter //
create procedure withdraw(
in atm_num nvarchar(10),
in acc_from nvarchar(30),
in sum int unsigned,
in descript tinytext) 
begin 

declare is_successful tinyint;
declare trans_num int unsigned;

call withdrawal(acc_from, sum, is_successful);

select cast(t.num as unsigned)
into trans_num
from Transactions as t
order by t.id desc limit 1;
set trans_num = trans_num + 1;

insert into Transactions
VALUES ( null, cast(trans_num as char(10)) , atm_num , acc_from , null , 76543, now(), is_successful , descript );
select is_successful;
end //
delimiter ;

-- check for
-- enougth funds on account being charged after t_sum is suplmented with atm_fee coefficient
-- MAYBE if trans_lim is not excedeeing (we need functions to count how many operations were made by this acc for last month)

drop procedure if exists withdrawal;
delimiter //
create procedure withdrawal
(in acc_from nvarchar(30),
 IN t_sum INT,
 out is_successful tinyint) 
begin 

declare not_enougth_funds
condition for sqlstate '45000';  

declare sum double;
declare blnc double;
declare atm_fee double;

set blnc = get_acc_balance(acc_from);
set atm_fee = t_sum*get_acc_atm_fee(acc_from);
set sum = t_sum + atm_fee;

if (blnc < sum)
	then
		set is_successful = false;
		signal not_enougth_funds SET MESSAGE_TEXT = 'Not enougth funds';
else
	 set is_successful = true;
	 update Accounts as a
	 set balance = balance-sum
	 where a.num = acc_from;
end if;
end //
delimiter ;

drop function if exists get_acc_blnc;
delimiter //
create function get_acc_blnc(acc_num nvarchar(30))
returns double deterministic
begin 
	declare blnc double;
	select balance into blnc
    from Accounts as a
    where a.num = acc_num;
    return blnc;
end //
delimiter ;

drop function if exists get_acc_atm_fee;
delimiter //
create function get_acc_atm_fee(acc_num nvarchar(30))
returns double deterministic
begin 
	declare fee double;
	select atm_fee into fee
    from Accounts as a
    where a.num = acc_num;
    return fee;
end //
delimiter ;	

drop procedure if exists get_all_acc_trans;
delimiter //
create procedure get_all_acc_trans(in acc_num nvarchar(30)) 
begin 
	declare acc_id int;
    select a.id into acc_id 
    from Accounts as a
    where a.num = acc_num;
    
	select t.num, t.acc_from,
		   t.acc_to, t.sum, t.date,
           t.is_successful, t.descript
    from Transactions as t
    where t.acc_from = acc_id OR t.acc_to = acc_id;
end //
delimiter ;




-- Transaction(
-- 		std::string num,
-- 		std::string acc_from,
-- 		std::string acc_to,
-- 		size_t sum, std::string date,
-- 		bool successful, std::string descript);

-- id	int unsigned	NO	PRI		auto_increment
-- num	varchar(30)	NO	UNI		
-- atm_id	int unsigned	YES	MUL		
-- acc_from	int unsigned	NO	MUL		
-- acc_to	int unsigned	YES	MUL		
-- sum	int unsigned	NO			
-- date	date	NO			
-- successful	tinyint	NO			
-- descript	tinytext	NO		


-- should check for correcteness of (DATE_FORMAT(NOW() ,'%Y %m 01') AND NOW();) expression
drop procedure if exists get_acc_trans_curr_month;
delimiter //
create procedure get_acc_trans_curr_month(IN acc_id INT) 
begin 
	call get_acc_trans_by_month(acc_id, DATE_FORMAT(NOW() ,'%Y %m 01'));
end //
delimiter ;

drop procedure if exists get_acc_trans_by_month;
delimiter //
create procedure get_acc_trans_by_month(IN acc_id INT, in t_month date) 
begin 
	select  acc_from, acc_to, t_sum,
			t_date, successful, off_city,
            atm_street, atm_building
    from Transactions as t
    inner join AutoTellerMachine as atm
    on atm.mach_id = t.mach_id
    inner join Offices as offs
    on offs.off_id = atm.off_id
    where (acc_from = acc_id OR 
		  acc_to   = acc_id) AND
		  month(t_date) = month(t_month) AND
          year(t_month) = year(now());
end //
delimiter ;


drop procedure if exists get_acc_trans_by_date;
delimiter //
create procedure get_acc_trans_by_date(in acc_id int, in tns_date date) 
begin 
	select  acc_from, acc_to, t_sum,
			t.t_date, successful, off_city,
            atm_street, atm_building
    from Transactions as t
    inner join AutoTellerMachine as atm
    on atm.mach_id = t.mach_id
    inner join Offices as offs
    on offs.off_id = atm.off_id
    where (acc_from = acc_id OR 
		  acc_to   = acc_id) AND
		  t.t_date = tns_date;
end //
delimiter ;
