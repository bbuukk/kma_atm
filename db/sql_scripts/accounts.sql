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

select * from Accounts;

select * from Acc_types;

drop procedure if exists get_acc;
delimiter //
create procedure get_acc(IN acc_num nvarchar(30)) 
begin 
	select a.id, a.off_id,
		   a.clnt_id, a.acc_type,
           a.num, a.dgt_code,
		   a.balance, a.open_date,
           a.is_blocked, a.overdraft_lim,
           a.atm_fee, a.intrest, a.trans_lim,
           a.crd_taken, a.loc_lim,
           a.crd_return
    from Accounts as a
    where a.num = acc_num;
end //
delimiter ;

drop procedure if exists get_acc_by_id;
delimiter //
create procedure get_acc_by_id
(in id int unsigned)
begin 
	select a.id, a.off_id,
		   a.clnt_id, a.acc_type,
           a.num, a.dgt_code,
		   a.balance, a.open_date,
           a.is_blocked, a.overdraft_lim,
           a.atm_fee, a.intrest, a.trans_lim,
           a.crd_taken, a.loc_lim,
           a.crd_return
    from Accounts as a
    where a.id = id;
end //
delimiter ;

-- (
-- 			size_t id, size_t off_id,
-- 			size_t clnt_id, size_t acc_type,
-- 			std::string num, size_t dgt_code,
-- 			double balance, std::string open_date,
-- 			bool blocked, double atm_fee,
-- 			double intrest)

drop procedure if exists get_office;
delimiter //
create procedure get_office
(in acc_id int unsigned) 
begin 
	select head_off, city, street, postal
    from Offices as o
    inner join Accounts as a
    on a.off_id = o.id
    where a.id = acc_id;
end //
delimiter ;

drop procedure if exists block_acc;
delimiter //
create procedure block_acc
(in acc_id int unsigned) 
begin 
	update Accounts as a
	set is_blocked = 1
	where a.id = acc_id;
end //
delimiter ;

drop procedure if exists unblock_acc;
delimiter //
create procedure unblock_acc
(in acc_id int unsigned) 
begin 
	update Accounts as a
	set is_blocked = 0
	where a.id = acc_id;
end //
delimiter ;

drop procedure if exists get_acc_type;
delimiter //
create procedure get_acc_type(IN acc_num nvarchar(30)) 
begin 
	select a.acc_type
    from Accounts as a
    where a.num = acc_num;
end //
delimiter ;

select * from Accounts;



-- =====================================================================================
									-- FUNCTIONS
-- =====================================================================================




