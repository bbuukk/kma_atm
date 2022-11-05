		-- clients relating scripts

				-- procedures
--
-- • get_acc_client_info    	  --  get info about client  -- by acc_id
--
				-- functions
--

show columns from Transactions;

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