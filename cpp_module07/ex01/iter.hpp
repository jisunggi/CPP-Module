#ifndef ITER_HPP
# define ITER_HPP

#include "iostream"
#include "string"

template <typename T>
void iter(T *array, size_t length, T (*function)(T&))
{
	for (size_t i = 0; i < length; i++)
	{
		(*function)(array[i]);
	}
}

template <typename T>
void iter(T *array, size_t length, T (*function)(const T&))
{
	for (size_t i = 0; i < length; i++)
	{
		(*function)(array[i]);
	}
}

#endif