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