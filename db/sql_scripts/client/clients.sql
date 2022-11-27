
drop procedure if exists acc_client_info;
delimiter //
create procedure acc_client_info(IN acc_id INT) 
begin 
	select account_id, first_name,
		   last_name, mobile_phone
    from Accounts as accs
	inner join Clients as clnts
    on clnts.client_id = accs.client_id
    where acc_id = accs.account_id;
end //
delimiter ;