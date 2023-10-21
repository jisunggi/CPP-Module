#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <string>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T container, int value)
{
    try
    {
        typename T::iterator iter;

        iter = std::find(container.begin(), container.end(), value);
        if (iter == container.end())
            throw notFound();
        return iter;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
};

class notFound : public std::exception
{
    public:
		virtual const char* what() const throw()
        {
            return "value was not found";
        };
};

#endif