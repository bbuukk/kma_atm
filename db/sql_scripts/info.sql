			-- general info scripts

				-- procedures
--
-- • get_atm_info    	  -- get info about ATM by mach_id 
-- • get_acc_info    	  -- get info about bank acc by acc_id
-- • get_acc_off_info     -- get info about office by acc_id 
-- • get_acc_client_info  -- get info about client by acc_id
-- • get_acc_balance_info -- get balance & dgt_code by acc_id

--
				-- functions
--

--  procedures & functions in file  -- general info
-- 1p}} get info about ATM by mach_id 
-- 2p}} get info about bank account 
-- 3p}} get info about office by acc_id 
-- 4p}} get info about client by acc_id
-- 5p}} get balance & dgt_code by acc_id


drop procedure if exists get_atm_info;
delimiter //
create procedure get_atm_info(IN m_id INT) 
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

-- 2p}} get info about bank acc by acc_id
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

-- 3p}} get info about office by acc_id 
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

-- 4p}} get info about client by acc_id
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

-- 5p}} get balance & dgt_code by acc_id
drop procedure if exists get_acc_balance_info;
delimiter //
create procedure get_acc_balance_info(IN acc_id INT) 
begin 
	select balance, digital_code
    from Accounts as accs
    where acc_id = accs.account_id;
end //
delimiter ;
