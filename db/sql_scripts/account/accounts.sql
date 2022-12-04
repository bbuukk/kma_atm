

drop procedure if exists acc_by_num;
delimiter //
create procedure acc_by_num(IN acc_num nvarchar(30)) 
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

drop procedure if exists acc_by_id;
delimiter //
create procedure acc_by_id
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

drop procedure if exists acc_by_card_id;
delimiter //
create procedure acc_by_card_id
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
    from Cards as c
    inner join Accounts as a
    on c.acc_id = a.id
    where c.id = id;
end //
delimiter ;

drop procedure if exists acc_office;
delimiter //
create procedure acc_office
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

drop procedure if exists acc_type;
delimiter //
create procedure acc_type(IN acc_num nvarchar(30)) 
begin 
	select a.acc_type
    from Accounts as a
    where a.num = acc_num;
end //
delimiter ;

drop procedure if exists acc_trans;
delimiter //
create procedure acc_trans
(in acc_id int unsigned) 
begin 
	select t.num, t.acc_from,
		   t.acc_to, t.sum, t.date,
           t.successful, t.descript
    from Transactions as t
    where t.acc_from = acc_id OR t.acc_to = acc_id;
end //
delimiter ;





