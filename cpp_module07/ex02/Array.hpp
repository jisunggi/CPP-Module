#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{
	private :
		unsigned int n;
		T *array;

	public :
		Array()
		{
			n = 0;
			array = new T[n];
		};
		Array(unsigned int n)
		{
			this->n = n;
			array = new T[n];
		};
		~Array()
		{
			if (this->array != NULL)
				delete [] array;
			array = 0;
		};
		Array(const Array &object)
		{	
			this->n = object.n;
			array = new T[n];
			for (unsigned int i = 0; i < n; i++)
        		array[i] = object.array[i];
			*this = object;
		};
		Array &operator=(const Array &object)
		{
			if (this != &object)
			{
				this->n = object.n;
				if (array != NULL)
					delete[] array;
				array = new T[n];
				for (unsigned int i = 0; i < n; i++)
        			array[i] = object.array[i];
			}
			return *this;
		};
		T &operator[](unsigned int index)
		{
			if (index >= this->n)
				throw Array<T>::OutOfBounds();
			return array[index];
		};
		const T &operator[](unsigned int index) const
		{
			if (index >= this->n)
				throw Array<T>::OutOfBounds();
			return array[index];
		};

		unsigned int size() const
		{
			return this->n;
		};

		class OutOfBounds : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

template <typename T>
const char * Array<T>::OutOfBounds::what() const throw()
{
	return "Array out of bounds";
}

#endif