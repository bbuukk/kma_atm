		-- account relating scripts

				-- procedures
--
-- • get_acc    	  -- get info about bank account   				   -- by acc_id
-- • get_acc_off     -- get info about office 						   -- by acc_id 
-- • //not realized // get_acc_balance_info -- get balance & dgt_code 	   				   -- by acc_id
-- • block_acc            -- change is_blocked in account record to true   -- by acc_id
--
				-- functions
-- • get_acc_blnc   	  -- returns balance of acc 	-- by acc_id
-- • is_acc_blocked 	  -- returns is_blocked of acc 	-- by acc_id
-- • get_acc_atm_fee 	  -- returns atm_fee 			-- by acc_id
-- • get_acc_tp    	  	  -- returns acc_type 			-- by acc_id
--


drop procedure if exists get_acc;
delimiter //
create procedure get_acc(IN acc_id INT) 
begin 
	select acc_num, balance, open_date, is_blocked
    from Accounts as accs
    where acc_id = accs.acc_id;
end //
delimiter ;



show columns from Offices;

drop procedure if exists get_acc_off;
delimiter //
create procedure get_acc_off(IN acc_id INT) 
begin 
	select head_off, off_city,
		   off_street, postal
    from Accounts as accs
	inner join Offices as offs
    on offs.off_id = accs.off_id
    where acc_id = accs.acc_id;
end //
delimiter ;

call get_acc_off(2);


-- drop procedure if exists get_acc_balance_info;
-- delimiter //
-- create procedure get_acc_balance_info(IN acc_id INT) 
-- begin 
-- 	select balance, dgt_code
--     from Accounts as accs
--     where acc_id = accs.acc_id;
-- end //
-- delimiter ;

drop procedure if exists block_acc;
delimiter //
create procedure block_acc(IN acc_id INT) 
begin 
	update Accounts as accs
	set is_blocked = 1
	where acc_id = accs.acc_id;
end //
delimiter ;

drop procedure if exists unblock_acc;
delimiter //
create procedure unblock_acc(IN acc_id INT) 
begin 
	update Accounts as accs
	set is_blocked = 0
	where acc_id = accs.acc_id;
end //
delimiter ;

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


drop function if exists get_acc_atm_fee;
delimiter //
create function get_acc_atm_fee(acc_id INT)
returns double deterministic
begin 
	declare fee double;
	select atm_fee into fee
    from Accounts as accs
    where accs.account_id = acc_id;
    return fee;
end //
delimiter ;

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



