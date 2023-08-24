#include "Fixed.hpp"

Fixed::Fixed()
{
    fixValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    this->fixValue = value << bit;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    this->fixValue = roundf(value * (1 << this->bit));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixValue = fixed.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat() const
{
    return (float)fixValue / (1 << this->bit);
}

int Fixed::toInt() const
{
    return fixValue >> bit;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->fixValue = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    return this->fixValue;
}

void Fixed::setRawBits(int const raw)
{
    this->fixValue = raw;
}

bool	Fixed::operator>(Fixed const &fixed) const
{
    return this->fixValue > fixed.getRawBits();
}

bool	Fixed::operator<(Fixed const &fixed) const
{
    return this->fixValue < fixed.getRawBits();
}

bool	Fixed::operator>=(Fixed const &fixed) const
{
    return this->fixValue >= fixed.getRawBits();
}

bool	Fixed::operator<=(Fixed const &fixed) const
{
    return this->fixValue <= fixed.getRawBits();
}

bool	Fixed::operator==(Fixed const &fixed) const
{
    return this->fixValue == fixed.getRawBits();
}

bool	Fixed::operator!=(Fixed const &fixed) const
{
    return this->fixValue != fixed.getRawBits();
}

Fixed	Fixed::operator+(Fixed const &fixed) const
{
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(Fixed const &fixed) const
{
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(Fixed const &fixed) const
{
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(Fixed const &fixed) const
{
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed	&Fixed::operator++(void)
{
    this->fixValue++;
    return *this;
}

const Fixed	Fixed::operator++(int)
{
    Fixed temp(*this);
    this->fixValue++;
    return temp;
}

Fixed	&Fixed::operator--(void)
{
    this->fixValue--;
    return *this;
}

const Fixed	Fixed::operator--(int)
{
    Fixed temp(*this);
    this->fixValue--;
    return temp;
}

Fixed	&Fixed::min(Fixed &ref1, Fixed &ref2)
{
    if (ref1 <= ref2)
		return ref1;
	else
		return ref2;
}

const Fixed	&Fixed::min(Fixed const &ref1, Fixed const &ref2)
{
    if (ref1 <= ref2)
		return ref1;
	else
		return ref2;
}

Fixed	&Fixed::max(Fixed &ref1, Fixed &ref2)
{
    if (ref1 >= ref2)
		return ref1;
	else
		return ref2;
}

const Fixed	&Fixed::max(Fixed const &ref1, Fixed const &ref2)
{
    if (ref1 >= ref2)
		return ref1;
	else
		return ref2;
}