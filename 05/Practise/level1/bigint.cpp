#include "bigint.hpp"

bigint::bigint() : num("0") {}

bigint::bigint(const std::string &str)
{
	if (str.empty() || !std::all_of(str.begin(), str.end(), isdigit))
	{
		throw std::invalid_argument("Invalid number string");
	}
	num = str;
	remove_leading_zeros();
}

bigint::bigint(unsigned long long nom): num(std::to_string(nom)) {}

bigint::bigint(const bigint &other) : num(other.num) {}

void bigint::remove_leading_zeros()
{
	num.erase(0, num.find_first_not_of('0'));
	if (num.empty())
		num = "0";
}

bigint bigint::operator+(const bigint &nom) const
{
	std::string result;
	int carry = 0;
	
	std::string::const_reverse_iterator it1 = num.rbegin();
	std::string::const_reverse_iterator it2 = nom.num.rbegin();
	
	while (it1 != num.rend() || it2 != nom.num.rend() || carry)
	{
		int digit1 = (it1 != num.rend() ? *it1++ - '0' : 0);
		int digit2 = (it2 != nom.num.rend() ? *it2++ - '0' : 0);
		
		int sum = digit1 + digit2 + carry;
		result.push_back((sum % 10) + '0');
		carry = sum / 10;
	}
	std::reverse(result.begin(), result.end());
	return bigint(0);
}

bigint& bigint::operator+=(const bigint &nom)
{
	*this = *this + nom;
	return *this;
}

bigint bigint::operator-(const bigint &nom) const
{
	(void) nom;
	return bigint();
}
	
bigint bigint::operator<<(size_t shift) const
{
	return bigint(num + std::string(shift, '0'));
}

bigint& bigint::operator<<=(size_t shift)
{
	num += std::string(shift, '0');
	return *this;
}


bigint bigint::operator>>(size_t shift) const
{
	if (shift >= num.size())
	{
		return bigint(0);
	}
	return bigint(num.substr(0, num.size() - shift));
}

bigint& bigint::operator>>=(size_t shift)
{
	if (shift >= num.size())
	{
		num = "0";
	}
	else
	{
		num = num.substr(0, num.size() - shift);
	}
	return *this;
}
	
bool bigint::operator<(const bigint &other) const 
{
	if (num.size() != other.num.size())
		return num.size() < other.num.size();
	return num < other.num;
}

bool bigint::operator>(const bigint &other) const
{
	return num > other.num;
}


bool bigint::operator<=(const bigint &other) const
{
	return (*this < other || *this == other);
}

bool bigint::operator>=(const bigint &other) const
{
	return (*this > other || *this == other);
}

bool bigint::operator==(const bigint &other) const
{
	return (num == other.num);
}

bool bigint::operator!=(const bigint &other) const
{
	return (num != other.num);
}
	
bigint& bigint::operator++()
{
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int)
{
	bigint temp = *this;
	++(*this);
	return temp;
}
	
std::ostream& operator<<(std::ostream &os, const bigint &nom)
{
	os << nom.num;
	return os;
}
