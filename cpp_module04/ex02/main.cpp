#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	std::cout << "---test---" << std::endl;
	//const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << "type : " << dog->getType() << " " << std::endl;
	std::cout << "type : " << cat->getType() << " " << std::endl;

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;

	return 0;
}