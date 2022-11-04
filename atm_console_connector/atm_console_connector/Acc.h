#pragma once

#include <string>
#include <ostream>

#include <mysql/jdbc.h>

//Account
class Acc {
public:
	Acc(void);

	Acc(size_t acc_id, size_t dgt_code,
		size_t off_id, size_t clnt_id,
		size_t acc_type, std::string acc_num,
		double balance, std::string  open_date,
		bool is_blocked, double atm_fee,
		double intrest);
	
	Acc(const Acc&);
	Acc& operator=(const Acc&);

	//Acc& operator=(Acc&&) = default;
	//Acc(Acc&&) noexcept = default;
	
	virtual ~Acc() = default;

	//getters
	inline size_t getAccId() const { return acc_id; };
	inline size_t getDgtCode() const { return dgt_code; }; //get currency digital code
	inline size_t getOffId() const { return off_id; }; // get office id
	inline size_t getClntId() const { return clnt_id; }; //get client id
	inline size_t getAccType() const { return acc_type; };

	inline std::string getAccNum() const { return acc_num; };
	inline double getBalance() const { return balance; };
	inline std::string getOpenDate() const { return open_date; };
	inline bool getIsBlocked() const { return is_blocked; };

	inline double getAtmFee() const { return atm_fee; };
	inline double getIntrest() const { return intrest; };

	friend std::ostream& operator<<(std::ostream& os, const Acc& acc) {
		return acc.print(os);
	}

protected:
	virtual std::ostream& print(std::ostream& os) const;

	void swap(Acc& first, Acc& second); // nothrow
	

	size_t acc_id;
	size_t dgt_code;
	size_t off_id;
	size_t clnt_id;
	size_t acc_type;

	std::string acc_num;
	double balance;
	std::string open_date;
	bool is_blocked;
	
	double atm_fee;
	double intrest;
};

