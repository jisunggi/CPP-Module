#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack()
		{};
		~MutantStack()
		{};
		MutantStack(const MutantStack &mutantstack)
		{
            *this = mutantstack;
		};
		MutantStack &operator=(const MutantStack &mutantstack)
		{
			if (this != &mutantstack)
			{
                *this = mutantstack;
			}
			return *this;
        }

        typedef typename MutantStack<T>::stack::container_type::iterator iterator;
        iterator begin()
        {
            return c.begin();
        }
        iterator end()
        {
            return c.end();
        }

        typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
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