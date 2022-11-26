			-- atm relating scripts

				-- procedures
--
-- • get_atm_info    	  --  get info about ATM  			-- by mach_id 
-- • get_atm    	  	  --  get ATM all data members	 	-- by mach_id 

--
				-- functions
--

drop procedure if exists get_atm1;
delimiter //
create procedure get_atm1(IN num nvarchar(10)) 
begin 
	select a.num, o.city, a.street
	from ATMs as a
    inner join Offices as o
    on a.off_id = o.id
    where a.num = num;
end //
delimiter ;

drop procedure if exists get_atm2;
delimiter //
create procedure get_atm2(IN id int unsigned) 
begin 
	select a.num, o.city, a.street
	from ATMs as a
    inner join Offices as o
    on a.off_id = o.id
    where a.num = num;
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




