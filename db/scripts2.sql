--  procedures & functions in file  -- script2.file
-- 1}} show account's history of transactions

-- 1}} show account's history of transactions
drop procedure if exists get_ATM_info;
delimiter //
create procedure get_all_acc_trans(IN acc_id INT) 
begin 
	select  acc_from, acc_to, t_sum,
			t_date, successful, off_city
            atm_street, atm_building
    from Transactions as t
	inner join AutoTellerMachine as atm
    on atm.mach_id = trans.mach_id
    inner join Offices as offs
    on offs.off_id = atm.off_id
    where acc_from = acc_id OR 
		  acc_to   = acc_id;
end //
delimiter ;

call get_all_acc_trans(1);

-- }} 
drop procedure if exists get_ATM_info;
delimiter //
create procedure a(IN acc_id INT) 
begin 

end //
delimiter ;

-- }} 
drop procedure if exists get_ATM_info;
delimiter //
create procedure b(IN acc_id INT) 
begin 

end //
delimiter ;

