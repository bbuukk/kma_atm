
drop procedure if exists atm_by_num;
delimiter //
create procedure atm_by_num(IN num nvarchar(10)) 
begin 
	select a.num, o.city, a.street
	from ATMs as a
    inner join Offices as o
    on a.off_id = o.id
    where a.num = num;
end //
delimiter ;

drop function if exists atm_by_id;
delimiter //
create function atm_by_id(num nvarchar(10))
returns int unsigned deterministic
begin 
	declare id int unsigned;
	select atms.id into id
    from ATMs as atms
    where atms.num = num;
    return id;
end //
delimiter ;	


-- //ATM(
-- //    std::string num,
-- //    std::string city,
-- //    std::string street);

-- id	int unsigned	NO	PRI		
-- num	varchar(45)	NO	UNI		
-- off_id	int unsigned	NO	MUL		
-- street	varchar(100)	NO			




