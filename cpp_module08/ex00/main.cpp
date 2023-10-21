#include "easyfind.hpp"

int main (void)
{
    std::vector<int> vectorArray;
    std::list<int> listArray;
    std::decue<int> decueArray;

    for (int i = 0; i < 10; i++)
    {
        vector.push_back(i);
        list.push_back(i);
        decue.push_back(i);
    }
    std::cout << *easyfind(vector, 3) << std::endl;
    std::cout << *easyfind(list, 7) << std::endl;
    std::cout << *easyfind(decue, 10) << std::endl;

}