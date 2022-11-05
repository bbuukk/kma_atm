		-- card relating scripts

				-- procedures
--
-- • get_card_id_by_pan    	  -- get card_id                      -- by pan
-- • update_card    	      -- update procedure for card table  -- by * from card table
--
				-- functions
-- • is_card_corr_pin    	  -- returns bool if pin code is correct to card     -- by card_id, pin_code
-- • is_card_acc_owner    	  -- returns bool if card client own card's account  -- by card_id
--

show columns from Cards;

drop procedure if exists get_card;
delimiter //
create procedure get_card(pan varchar(20)) 
begin 
    select pan, pin_code,
		   expr_date, cvv,
           given_date
    from Cards as crds
    where crds.pan = trim(pan);
end //
delimiter ;		

drop procedure if exists update_card;
delimiter //
create procedure update_card
(in card_id int unsigned, in acc_id int unsigned,
in clnt_id int unsigned, in pan varchar(20),
in pin_code int unsigned, in expr_date date,
in cvv int unsigned, in given_date date)
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

select * from Cards where card_id = 1;
call update_card(1, 1, 1, "5313532532254855", 9308, "2024-02-18", 674, "2021-11-18");

-- card_id	int unsigned	NO	PRI		auto_increment
-- acc_id	int unsigned	NO	MUL		
-- clnt_id	int unsigned	NO	MUL		
-- pan	varchar(20)	NO	UNI		
-- pin_code	int unsigned	NO			
-- expr_date	date	NO			
-- cvv	int unsigned	NO			
-- given_date	date	NO	

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



