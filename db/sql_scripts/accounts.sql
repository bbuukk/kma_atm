		-- account relating scripts

				-- procedures
--
-- • get_acc    	  	-- get information about bank account   				 
-- • get_office     	-- get information about office of account						   
-- • block_acc          -- block account    
-- • unblock_acc        -- unblock account   
--
				-- functions
-- • get_acc_blnc   	  -- returns balance of acc 	-- by acc_id
-- • is_acc_blocked 	  -- returns is_blocked of acc 	-- by acc_id
-- • get_acc_atm_fee 	  -- returns atm_fee 			-- by acc_id
-- • get_acc_tp    	  	  -- returns acc_type 			-- by acc_id
--

drop procedure if exists get_acc;
delimiter //
create procedure get_acc(IN acc_num nvarchar(30)) 
begin 
	select a.num, a.dgt_code,
		   a.balance, a.open_date,
           a.is_blocked, a.atm_fee,
           a.intrest
    from Accounts as a
    where a.num = acc_num;
end //
delimiter ;

drop procedure if exists get_office;
delimiter //
create procedure get_office
(IN acc_num nvarchar(30)) 
begin 
	select head_off, city, street, postal
    from Offices as o
    inner join Accounts as a
    on a.off_id = o.id
    where a.num = '01234';
end //
delimiter ;

drop procedure if exists block_acc;
delimiter //
create procedure block_acc(IN acc_num nvarchar(30)) 
begin 
	update Accounts as a
	set is_blocked = 1
	where a.num = acc_num;
end //
delimiter ;

drop procedure if exists unblock_acc;
delimiter //
create procedure unblock_acc(IN acc_num nvarchar(30)) 
begin 
	update Accounts as a
	set is_blocked = 0
	where a.num = acc_num;
end //
delimiter ;

drop procedure if exists count_all_acc_trans;
delimiter //
create procedure count_all_acc_trans(in acc_num nvarchar(30)) 
begin 
	declare acc_id int;
    select a.id into acc_id 
    from Accounts as a
    where a.num = acc_num;
    
	select count(t.num) as t_amount
    from Transactions as t
    where t.acc_from = acc_id OR t.acc_to = acc_id;
end //
delimiter ;

-- =====================================================================================
									-- FUNCTIONS
-- =====================================================================================

drop function if exists is_acc_blocked;
delimiter //
create function is_acc_blocked(acc_id INT)
returns tinyint deterministic
begin 
	declare blocked double;
	select is_blocked into blocked
    from Accounts as accs
    where accs.acc_id = acc_id;
    return blocked;
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



