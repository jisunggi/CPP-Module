#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	std::cout << "---test---" << std::endl;
	{
		const Animal *animal = new Animal();
		const Animal *dog = new Dog();
		const Animal *cat = new Cat();

		std::cout << "type : " << animal->getType() << " " << std::endl;
		std::cout << "type : " << dog->getType() << " " << std::endl;
		std::cout << "type : " << cat->getType() << " " << std::endl;

		animal->makeSound();
		dog->makeSound();
		cat->makeSound();

		delete animal;
		delete dog;
		delete cat;
	}
	std::cout << std::endl;
	std::cout << "---Wrong test---" << std::endl;
	{
		const WrongAnimal *wrongAnimal = new WrongAnimal();
		const WrongAnimal *wrongCat = new WrongCat();

		std::cout << "type : " << wrongAnimal->getType() << " " << std::endl;
		std::cout << "type : " << wrongCat->getType() << " " << std::endl;

		wrongAnimal->makeSound();
		wrongCat->makeSound();

		delete wrongAnimal;
		delete wrongCat;
	}
	return 0;
}