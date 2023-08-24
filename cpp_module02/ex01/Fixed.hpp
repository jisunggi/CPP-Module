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
        float toFloat();
        int toInt();
        int getRawBits() const;
        void setRawBits(int const raw);
};

#endif