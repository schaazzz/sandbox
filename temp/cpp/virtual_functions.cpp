#include <iostream>

class Base
{
	public:
	virtual void whoAmI(void)
	{
		std::cout << "Base\r\n";
	}
};

class Derived : public Base
{
	public:
	void whoAmI(void)
	{
		std::cout << "Derived\r\n";
	}
};

int who_is(Base* pb)
{
	pb->whoAmI();
}

int main(void)
{
	Base b;
	Derived d;
	Base* pb = new Base;
	Derived* pd = new Derived;
	Base *pbd = new Derived;
	b.whoAmI();
	d.whoAmI();
	pb->whoAmI();
	pd->whoAmI();
	pbd->whoAmI();
	who_is(&b);
	who_is(&d);
	who_is(pb);
	who_is(pd);
}
