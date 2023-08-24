#include "Fixed.hpp"

Fixed::Fixed()
{
    fixValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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