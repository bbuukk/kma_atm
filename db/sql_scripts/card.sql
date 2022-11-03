		-- card relating scripts

				-- procedures
--
-- • get_card_id_by_pan    	  -- get card_id by pan
-- • update_card    	      -- update procedure for card table by * from card table
--
				-- functions
-- • is_card_corr_pin    	  -- returns bool if pin code is correct to card by card_id, pin_code
-- • is_card_acc_owner    	  -- returns bool if card client own card's account by card_id
--

drop procedure if exists get_card_id_by_pan;
delimiter //
create function get_card_id_by_pan(pan nvarchar(20)) 
returns int deterministic
begin 
	declare card_id int;
    select crds.card_id into card_id
    from Cards as crds
    where crds.pan = pan;
    return card_id;
end //
delimiter ;

drop procedure if exists update_card;
delimiter //
create procedure update_card
(in card_id int, in acc_id int,
in clnt_id int, in pan nvarchar(20),
in pin_code int, in expr_date date,
in cvv int, in given_date date)
begin 
	update Cards as c
    set
    c.card_id = card_id,
	c.acc_id = acc_id,
	c.clnt_id = clnt_id,
    c.pan = pan,
    c.pin_code = pin_code,
    c.expr_date = expr_date,
    c.cvv = cvv,
    c.given_date = given_date
    where c.card_id = card_id;
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



