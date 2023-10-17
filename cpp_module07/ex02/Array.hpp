#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class OutOfBounds : public std::exception {
  public:
    const char* what() const throw() {
      return "Array - Out of range";
    }
};

template <class T>
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
			this->n = object.size();
			if (array != NULL)
				delete [] array;
			array = new T[n];
			for (unsigned int i = 0; i < n; i++)
        		array[i] = object.array[i];
    	};
		Array &operator=(const Array &object)
		{
			if (this != &object)
			{
				this->n = object.size();
				if (array != NULL)
					delete [] array;
				array = new T[n];
				for (unsigned int i = 0; i < n; i++)
        			array[i] = object.array[i];
			}
			return *this;
		};
		T &operator[](unsigned int n)
		{
			if (n >= this->size())
				throw OutOfBounds;
			return array[n];
		};
		const T &operator[](unsigned int n) const
		{
			if (n >= this->size())
				throw OutOfBounds;
			return array[n];
		};

		unsigned int size() const
		{
			return this->n;
		};	
};

#endif