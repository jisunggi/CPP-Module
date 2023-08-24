#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private :
        int fixValue;
        static const int bit = 8;

    public :
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &fixed);
        ~Fixed();
        Fixed &operator=(const Fixed &fixed);
        float toFloat() const;
        int toInt() const;
        int getRawBits() const;
        void setRawBits(int const raw);

        bool	operator>(Fixed const &fixed) const;
        bool	operator<(Fixed const &fixed) const;
        bool	operator>=(Fixed const &fixed) const;
        bool	operator<=(Fixed const &fixed) const;
        bool	operator==(Fixed const &fixed) const;
        bool	operator!=(Fixed const &fixed) const;

        Fixed	operator+(Fixed const &fixed) const;
        Fixed	operator-(Fixed const &fixed) const;
        Fixed	operator*(Fixed const &fixed) const;
        Fixed	operator/(Fixed const &fixed) const;

        Fixed	&operator++(void);
        const Fixed	operator++(int);
        Fixed	&operator--(void);
        const Fixed	operator--(int);

        static Fixed	&min(Fixed &ref1, Fixed &ref2);
        static const Fixed	&min(Fixed const &ref1, Fixed const &ref2);
        static Fixed	&max(Fixed &ref1, Fixed &ref2);
        static const Fixed	&max(Fixed const &ref1, Fixed const &ref2);
};

#endif