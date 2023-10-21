#include "easyfind.hpp"

int main (void)
{
    std::vector<int> vectorArray;
    std::list<int> listArray;
    std::deque<int> dequeArray;

    for (int i = 0; i < 10; i++)
    {
        vectorArray.push_back(i);
        listArray.push_back(i);
        dequeArray.push_back(i);
    }
    try
    {
        std::cout << *easyfind(vectorArray, 3) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << *easyfind(listArray, 7) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << *easyfind(dequeArray, 10) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

}