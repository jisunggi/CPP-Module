#ifndef MUTANSTACK_HPP
# define MUTANSTACK_HPP

#include <iostream>
#include <algorithm>

template <typename T>
class MutanStack : public std::stack<>
{
	public :
		MutanStack()
		{};
		~MutanStack()
		{};
		MutanStack(const MutanStack &object)
		{
            *this = object;
		};
		MutanStack &operator=(const MutanStack &object)
		{
			if (this != &object)
			{
                *this = object;
			}
			return *this;
        }

        typedef typename MutanStack<T>::stack::container_type::iterator iterator;
        iterator begin()
        {
            return c.begin();
        }
        iterator end()
        {
            return c.end();
        }

        typedef typename MutanStack<T>::stack::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin()
        {
            return c.rbegin();
        }
        reverse_iterator rend()
        {
            return c.rend();
        }
}

#endif