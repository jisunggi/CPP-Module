#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private :
        int fixValue;
        static const int bit = 8;

    public :
        Fixed();
        ~Fixed();
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);
        int getRawBits() const;
        void setRawBits(int const raw);
};

#endif