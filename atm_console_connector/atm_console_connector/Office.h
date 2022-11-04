#pragma once

#include "Office.h"

#include <mysql/jdbc.h>

class Office {
public:
	Office(void) = default;

	Office(
		size_t off_id,
		bool head_off,
		std::string off_city,
		std::string off_street,
		std::string postal);

	Office(const Office&) = default;
	Office& operator=(const Office&) = default;

	~Office() = default;

	inline size_t getOfficeId() const { return off_id; };
	inline bool getHeadOffice() const { return head_off; };
	inline std::string getOfficeCity() const { return off_city; };
	inline std::string getOfficeStreet() const { return off_street; };
	inline std::string getPostal() const { return postal; };

private:
	size_t off_id;
	bool head_off;
	std::string off_city;
	std::string off_street;
	std::string postal;
};

std::ostream& operator<<(std::ostream& os, const Office& off);

//todo
//off_id	int unsigned	NO	PRI		auto_increment
//head_off	tinyint	NO
//off_city	varchar(100)	NO
//off_street	varchar(100)	NO
//postal	varchar(10)	NO