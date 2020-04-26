//Clare Minnerath
//Creating namespaces

#include <iostream>
using namespace std;

namespace alpha
{
	void hello()
	{
		cout << "Hola\n";
	}

	namespace beta
	{
		void hello()
		{
			cout << "Bonjour\n";
		}
	}
}

int main()
{
	//CODE BLOCKS
	{
		using namespace alpha;
		hello();
	}
	{
		using namespace beta;
		hello();
	}

	//Directly call a function in a namespace
	beta::hello();
	alpha::hello();

	return 0;
}