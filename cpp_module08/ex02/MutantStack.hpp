#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <iterator>

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
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }

        typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin()
        {
            return this->c.rbegin();
        }
        reverse_iterator rend()
        {
            return this->c.rend();
        }
};

#endif