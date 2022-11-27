
drop procedure if exists card_by_pan;
delimiter //
create procedure card_by_pan(in pan varchar(20)) 
begin 
    select c.pan, c.pin_code,
		   c.expr_date, c.cvv,
           c.given_date
    from Cards as c
    where c.pan = trim(pan);
end //
delimiter ;	

drop procedure if exists change_pin_code;
delimiter //
create procedure change_pin_code
(in id int unsigned,
in pin_code int unsigned)
begin 
	update Cards as c
    set c.pin_code = pin_code
    where c.id = id;
end //
delimiter ;

drop function if exists is_card_corr_pin;
delimiter //
create function is_card_corr_pin(card_id INT) 
returns tinyint deterministic
begin 
declare is_corr tinyint;
return is_corr;
end //
delimiter ;

drop function if exists is_card_acc_owner;
delimiter //
create function is_card_acc_owner(crd_id int)
returns tinyint deterministic
begin 
    declare is_owner tinyint;
	declare acc_id int;
	declare clnt_id int;
    
    declare found_acc_id int;
    
    select crds.acc_id, crds.clnt_id
    into acc_id, clnt_id
    from Cards as crds
    where crds.card_id = crd_id;

    select accs.acc_id
    into found_acc_id
    from Accounts as accs
    where accs.acc_id = acc_id AND
		  accs.clnt_id = clnt_id;
          
	if (found_acc_id is null)
		then set is_owner = 0;
		else set is_owner = 1;
    end if;
    
    return is_owner;
end //
delimiter ;



