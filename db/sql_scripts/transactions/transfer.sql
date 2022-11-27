

-- !!make transaction
-- making ATMtransaction we need:
-- 	if acc_from balance >= sum
-- 	if acc_from currency == acc_to currency
--  \withdraw/ acc_from currency == atm currency
-- take current_date and use it for current row

-- should make dangling transaction? (коли не вдалось провести транзакцію, чи повинен я в деяких випадках просто відкладати її??)
-- need to check if one branched if works fine

-- call transfer("01234", 2, 1, 1000, "For cocaine");
-- select * from Accounts;

drop procedure if exists transfer;
delimiter //
create procedure transfer(
in atm_num nvarchar(10),
in f_id int unsigned,
in t_id int unsigned,
in sum int unsigned,
in descript tinytext) 
begin 
	declare is_successful tinyint;
    
	if withdrawal(f_id, sum)
		then set is_successful = deposit(t_id, sum);
	end if;
    
	call insert_transaction(atm_num, f_id, t_id, sum, is_successful, descript);
	select is_successful;
end //
delimiter ;

