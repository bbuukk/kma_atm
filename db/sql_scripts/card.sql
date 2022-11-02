--  procedures & functions in file  -- card
-- 1}} get bool if some card's client is cards's account owner 
-- 2}} get card_id by pan



-- 1}} get bool if some card's client is cards's account owner 
drop function if exists a;
delimiter //
create function is_card_acc_owner(crd_id int)
returns tinyint deterministic
begin 
    declare is_owner tinyint;
	declare acc_id int;
	declare clnt_id int;
    
    select crds.acc_id, crds.clnt_id
    into acc_id, clntid
    from Cards as crds
    where crds.card_id = crd_id;
    

    return is_owner;
end //
delimiter ;