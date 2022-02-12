#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed{
public:
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;

	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& original);
	~Fixed(void);

	Fixed& operator=(Fixed const& original);

private:
	static const int	_fractionalBits;
	
	int					_fixedPointValue;
};

// passing as a (const) reference prevents unnecessary copies, since you can still access the required memory without duplicating.
// declare this prototype outside the class because it's altering an instance of another class (ostream). You can't call this function on a Fixed instance
std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif
