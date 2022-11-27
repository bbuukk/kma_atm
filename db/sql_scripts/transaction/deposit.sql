
-- call deposit("01234", 1, 30);
-- select * from Accounts;
-- select * from Transactions;

drop procedure if exists deposit;
delimiter //
create procedure deposit
(in atm_num nvarchar(10),
in t_id int unsigned,
in sum int unsigned) 
begin 
	declare is_successful tinyint;
	set is_successful = deposit(t_id, sum);
     
	call insert_transaction(atm_num, null, t_id, sum, is_successful, null);
	select is_successful;
end //
delimiter ;