#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class bigint {
	private:
	std::string num;
	void remove_leading_zeros();
	
	public:
	bigint();
	bigint(const std::string &str);
	bigint(unsigned long long nom);
	bigint(const bigint &other);
	
	bigint operator+(const bigint &nom) const;
	bigint& operator+=(const bigint &nom);
	bigint operator-(const bigint &nom) const;
	
	bigint operator<<(size_t shift) const;
	bigint& operator<<=(size_t shift);
	bigint operator>>(size_t shift) const;
	bigint& operator>>=(size_t shift);
	
	bool operator<(const bigint &other) const;
	bool operator>(const bigint &other) const;
	bool operator<=(const bigint &other) const;
	bool operator>=(const bigint &other) const;
	bool operator==(const bigint &other) const;
	bool operator!=(const bigint &other) const;
	
	bigint& operator++();
	bigint operator++(int);
	
	friend std::ostream& operator<<(std::ostream &os, const bigint &nom);

};
