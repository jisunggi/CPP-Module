#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T max (T &a, T &b)
{
	return b >= a ? b : a;
}

template <typename T>
T min (T &a, T &b)
{
	return b <= a ? b : a;
}

#endif