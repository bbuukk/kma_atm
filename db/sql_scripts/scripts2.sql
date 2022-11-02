--  procedures & functions in file  -- script2.file
-- 1.1p}} show account's all history of transactions
-- 1.2p}} show account's all history of transactions in current month
-- 1.3p}} show account's all history of transactions in exact month
-- 1.4p}} show account's all history of transactions by exact date
-- 2p}} block account


-- 1.1p}} show account's all history of transactions
drop procedure if exists get_all_acc_trans;
delimiter //
create procedure get_all_acc_trans(IN acc_id INT) 
begin 
	select  acc_from, acc_to, t_sum,
			t_date, successful, off_city,
            atm_street, atm_building
    from Transactions as t
	inner join AutoTellerMachine as atm
    on atm.mach_id = t.mach_id
    inner join Offices as offs
    on offs.off_id = atm.off_id
    where acc_from = acc_id OR 
		  acc_to   = acc_id;
end //
delimiter ;

-- 1.2p}} show account's all history of transactions in current month
-- should check for correcteness of (DATE_FORMAT(NOW() ,'%Y %m 01') AND NOW();) expression
drop procedure if exists get_acc_trans_curr_month;
delimiter //
create procedure get_acc_trans_curr_month(IN acc_id INT) 
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
		  t_date between
          DATE_FORMAT(NOW() ,'%Y %m 01') AND NOW();
end //
delimiter ;


-- 1.3p}} show account's all history of transactions in exact month
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
		  month(t_date) = month(t_month);
end //
delimiter ;

-- 1.4p}} show account's all history of transactions by exact date
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

-- 2.1p}} block account 
drop procedure if exists a;
delimiter //
create procedure block_acc(IN acc_id INT) 
begin 
	update Accounts as accs
	set is_blocked = 1
	where acc_id = accs.acc_id;
end //
delimiter ;

-- 2.2f}} get atm_fee by acc_id
drop function if exists is_acc_blocked;
delimiter //
create function is_acc_blocked(acc_id INT)
returns tinyint deterministic
begin 
	declare blocked double;
	select is_blocked into blocked
    from Accounts as accs
    where accs.account_id = acc_id;
    return blocked;
end //
delimiter ;

-- }} 
-- drop procedure if exists a;
-- delimiter //
-- create procedure a(IN acc_id INT) 
-- begin 

-- end //
-- delimiter ;



