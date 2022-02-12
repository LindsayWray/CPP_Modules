#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed{
public:
	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed(void);
	Fixed(const Fixed& original);
	~Fixed(void);

	Fixed& operator=(Fixed const& original);

private:
	static const int 	_fractionalBits;
	
	int					_fixedPointValue;
};

#endif
