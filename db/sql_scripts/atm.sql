			-- atm relating scripts

				-- procedures
--
-- • get_atm_info    	  --  get info about ATM  			-- by mach_id 
-- • get_atm    	  	  --  get ATM all data members	 	-- by mach_id 

--
				-- functions
--

drop procedure if exists get_atm_info;
delimiter //
create procedure get_atm_info(IN mach_id INT) 
begin 
	select concat('ATM is located in ', off_city,
				  ' at ',atm_street, '.\n',
                  'Office is located at ', off_street,
                  ' and it\'s postal is ', postal ,'.') as atm_info
	from ATMs as atms
    inner join Offices as offs
    on offs.off_id =atms.off_id
    where atms.mach_id = mach_id;
end //
delimiter ;

-- off_id	int unsigned	NO	PRI		auto_increment
-- head_off	tinyint	NO			
-- off_city	varchar(100)	NO			
-- off_street	varchar(100)	NO			
-- postal	varchar(10)	NO			

-- mach_id	int unsigned	NO	PRI		
-- off_id	int unsigned	NO	MUL		
-- atm_street	varchar(255)	NO			

drop procedure if exists get_atm;
delimiter //
create procedure get_atm(IN m_id INT) 
begin 

end //
delimiter ;



