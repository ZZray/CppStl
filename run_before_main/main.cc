#include <iostream>
#include <iostream>
#include <memory>
class A
{
public:
	A()
	{
		std::cout << __FUNCTION__ << std::endl;
	}
	~A()
	{
		std::cout << __FUNCTION__ << std::endl;
	}
};

A a;
int function1()
{
	return 1;
}
int b = function1();

int main()
{
	std::cout << "b: " << b << std::endl;
	std::cout << __FUNCTION__ << std::endl;
	return 0;
}
