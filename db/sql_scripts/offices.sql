		-- offices relating scripts

				-- procedures
--
-- • get_acc_off_info    	  --  get info about office by acc_id 
--
				-- functions
--

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