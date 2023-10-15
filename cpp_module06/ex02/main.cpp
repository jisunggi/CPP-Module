#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	srand((unsigned int)time(NULL));
	int num = rand() % 3;
	if (num == 0)
	{
		std::cout << "A class created" << std::endl;
		return (new A);
	}
	else if (num == 1)
	{
		std::cout << "B class created" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "C class created" << std::endl;
		return (new C);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "pointer is A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "pointer is B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "pointer is C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "reference is A" << std::endl;
	}
	catch (std::exception &)
	{}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "reference is B" << std::endl;
	}
	catch (std::exception &)
	{}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "reference is C" << std::endl;
	}
	catch (std::exception &)
	{}
}

int main (void)
{
	Base *base;
	Base *baseNo = 0;

	base = generate();
	identify(base);
	identify(*base);
	identify(baseNo);

	delete base;
}