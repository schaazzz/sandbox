#include <iostream>

class Base
{
private:
	static int count;

public:
	Base(void)
	{
		std::cout << "New Base object created\r\n";
		count++;
	}

	virtual void whoAmI(void)
	{
		std::cout << "Base\r\n";
	}

	static void objCount(void)
	{
		std::cout << count << std::endl; 
	}
};
int Base::count = 0;


class Derived : public Base
{
private:
	static int count;

public:
        Derived(void)
        {
                std::cout << "New Derived object created\r\n";
                count++;
        }

	void whoAmI(void)
	{
		std::cout << "Derived\r\n";
	}

        static void objCount(void)
        {
                std::cout << count << std::endl;
        }
};
int Derived::count = 0;

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

	Base::objCount();
	Derived::objCount();
}
