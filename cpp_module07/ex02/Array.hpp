#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

template <class T>
class Array
{
	private :
		unsigned int n;
		T *array;

	public :
		Array()
		{
			array = new T;
		};
		Array(unsigned int n)
		{
			this->n = n;
			array = new T[n];
		};
		~Array()
		{
			delete [] array;
		};
		Array(const Array &object)
		{
			this->n = object.size();
			if (array != NULL)
				delete array;
			array = new T[n];
			for (unsigned int i = 0; i < n; i++)
        		array[i] = object[i];
    	};
		Array &operator=(const Array &object)
		{
			if (this != &object)
			{
				this->n = object.size();
				if (array != NULL)
					delete array;
				array = new T[n];
				for (unsigned int i = 0; i < n; i++)
        			array[i] = object[i];

			}
			return *this;
		};
		T &operator[](unsigned int n)
		{
			if (n >= this->size())
				throw std::exception();
			return array[n];
		};

		unsigned int size() const
		{
			return this->n;
		};
		T *getArray() const
		{
			return this->array;
		}
		
};

#endif