#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	std::cout << "---test---" << std::endl;
	{
		Animal *animal[10];

		for (size_t i = 0; i < 10; i++)
		{
			if (i % 2)
			{
				animal[i] = new Dog();
			}
			else
			{
				animal[i] = new Cat();
			}
		}
		std::cout << "----------" <<std::endl;
		
		for (size_t i = 0; i < 10; i++)
		{
			delete animal[i];
		}
	}
	std::cout << std::endl;
	std::cout << "----------" <<std::endl;
	{
		Dog *dog = new Dog();
		Dog *copyDog = new Dog();

		*dog = *copyDog;
		std::cout << "dog idea : " << dog->getBrain()->getIdea(0) << std::endl;
		std::cout << "copyDog idea : " << dog->getBrain()->getIdea(0) << std::endl;

		std::cout <<std::endl;
		copyDog->getBrain()->setIdea(0, "change");
		std::cout << "dog idea : " << dog->getBrain()->getIdea(0) << std::endl;
		std::cout << "copyDog idea : " << copyDog->getBrain()->getIdea(0) << std::endl;

		std::cout <<std::endl;
		delete dog;
		delete copyDog;
	}
	return 0;
}