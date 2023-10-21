#ifndef SPAN_HPP
# define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class  Span
{
    private :
        std::vector<int> vectorArray;
        Span();
    
    public :
        Span(unsigned int N);
        ~Span();
		Span(const Span &span);
		Span &operator=(const Span &span);

        void addNumber(int num);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        std::vector<int> getVectorArray();
    
    class noElements: public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    class fullVectorArray: public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

#endif