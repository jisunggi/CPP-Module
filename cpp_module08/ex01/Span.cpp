#include "Span.hpp"

Span::Span() {}

Span::Span(unsigend int N)
{
	this->vectorArray.reserve(N);
}

Span::~Span()
{
}

Span::Span(const Span &span)
{
	this->vectorArray.reserve(span.getVectorArray().capacity());
	std::copy(span.getVectorArray().begin(), span.getVectorArray().end(), std::back_inserter(this->vectorArray));
}

Span &Span::operator=(const Span &span)
{
	if (this != &span)
	{
		this->vectorArray.reserve(span.getVectorArray().capacity());
		std::copy(span.getVectorArray().begin(), span.getVectorArray().end(), std::back_inserter(this->vectorArray));
	}
    return *this;
}

std::vector<int> Span::getVectorArray()
{
	return this->vectorArray;
}

void Span::addNumber(int num)
{
	vector.push_back(num);
}

unsigned int Span::longestSpan()
{
	if (vectorArray.size() < 2)
		throw ;
	return (*std::max_element(vectorArray.begin(), vectorArray.end())
				- *std::min_element(vectorArray.begin(), vectorArray.end()));
}

unsigned int Span::shortestSpan()
{
	if (vectorArray.size() < 2)
		throw ;
	
	std::vector<int> sortVectorArray;
	std::vector<int>::iterator iter;
	unsigned int returnValue;

	sortVectorArray = this->getVectorArray();
	std::sort(sortVectorArray.begin(), sortVectorArray.end());
	iter = sortVectorArray.begin() + 1;
	returnValue = std::abs(*iter - *(iter - 1));
	while (iter != sortVectorArray.end())
	{
		if (returnValue > std::abs(*iter - *(iter - 1)))
			returnValue = std::abs(*iter - *(iter - 1));
		iter++;
	}
	return returnValue;
}

virtual const char* Span::noElements::what() const throw()
{
	return "More than one element is needed";
}

virtual const char* Span::fullVectorArray::what() const throw()
{
	return "Can't save it anymore";
}