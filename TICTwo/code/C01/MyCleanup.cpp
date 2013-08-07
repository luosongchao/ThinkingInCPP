#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

ofstream out("cleanup.out");
class Cleanup
{
	static int count;
	const char * name;
	int number;
public :
	Cleanup(const char *msg="array elem")
	{
		name=msg;
		number=count++;
		out<<"constructing..."<<number<<"name["<<name<<"]"<<endl;
		if(count==3)
		{
			throw int(3);
		}

		if(*name=='z')
		{
			throw char('z');
		}
	}

	~Cleanup()
	{
		out<<"destructing..."<<number<<"name["<<name<<"]"<<endl;
	}

	void *operator new[](size_t len)
	{
		out<<"new[]"<<endl;
		return ::new char[len];
	}

	void operator delete[](void *p)
	{
		out<<"delete[]"<<endl;
		::delete []p;
	}
};

int Cleanup::count=0;

int main()
{
	out<<"before array..."<<endl;
	try
	{
		Cleanup obj1("object1");
		Cleanup *array=new Cleanup[4];
	}
	catch(int i)
	{
		out<<"caught "<<i<<endl;
	}
	catch(char z)
	{
		out<<"caught "<<z<<endl;
	}
	catch(...)
	{
		out<<"caught unexpected.."<<endl;
	}

	out<<"test unexpected..."<<endl;
	try
	{
		Cleanup obj2("z");
	}
	catch(char z)
	{
		out<<"caught char "<<z<<endl;
	}
	catch(...)
	{
		out<<"caught unexpected"<<endl;
	}
}
