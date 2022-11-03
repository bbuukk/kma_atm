		-- atm relating scripts

				-- procedures
--
-- • get_atm_info    	  --  get info about ATM  -- by mach_id 
--
				-- functions
--

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
