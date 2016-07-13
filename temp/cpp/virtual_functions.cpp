#include <iostream>

class Base
{
private:
	static int count;

public:
	Base(void)
	{
		std::cout << " ------> New Base object created\r\n";
		count++;
	}

	virtual void whoAmI(void)
	{
		std::cout << "whoami === Base\r\n";
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
                std::cout << " ------> New Derived object created\r\n";
                count++;
        }

	void whoAmI(void)
	{
		std::cout << "whoami === Derived\r\n";
	}

        static void objCount(void)
        {
                std::cout << count << std::endl;
        }
};
int Derived::count = 0;

int who_is(Base* pb)
{
        printf("who_is === ");
	pb->whoAmI();
}

int main(void)
{
	
        printf("\nBase b ::: \n");Base b;
	b.whoAmI();
	who_is(&b);
	
        printf("\nDerived d ::: \n");Derived d;
	d.whoAmI();
	who_is(&d);
	
        printf("\nBase* pb = new Base ::: \n");Base* pb = new Base;
	pb->whoAmI();
	who_is(pb);
        
        printf("\nDerived* pd = new Derived ::: \n");Derived* pd = new Derived;
	pd->whoAmI();
	who_is(pd);
	
        printf("\nBase *pbd = new Derived::: \n");Base *pbd = new Derived;
	pbd->whoAmI();
        who_is(pbd);

	Base::objCount();
	Derived::objCount();
}
