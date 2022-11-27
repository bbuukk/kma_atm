

-- check for
-- enougth funds on account being charged after t_sum is suplmented with atm_fee coefficient
-- MAYBE if trans_lim is not excedeeing (we need functions to count how many operations were made by this acc for last month)

-- should check for currencies of atm itself 

-- call withdraw("01234", 1, 30);
-- select * from Accounts;
-- select * from Transactions;

drop procedure if exists withdraw;
delimiter //
create procedure withdraw(
in atm_num nvarchar(10),
in f_id int unsigned,
in sum int unsigned) 
begin 
	declare is_successful tinyint;
	set is_successful = withdrawal(f_id, sum);
	
	call insert_transaction(atm_num, f_id, null, sum, is_successful, null);
	select is_successful;
end //
delimiter ;
