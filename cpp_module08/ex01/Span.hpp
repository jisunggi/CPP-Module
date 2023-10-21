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

        std::vector<int> getVectorArray() const;

        template <typename T>
        void addManyNumbers(T &container)
        {
            if (std::distance(container.begin(), container.end()) > static_cast<int>(vectorArray.capacity() - vectorArray.size()))
                throw Span::fullVectorArray();
            typename T::iterator iter = container.begin();
            while (iter != container.end())
            {
                vectorArray.push_back(*iter);
                iter++;
            }
        }
    
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