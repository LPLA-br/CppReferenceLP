#include <string>
#include <iostream>
#include <cstdlib>

int main(int argc,char *argv[])
{
	std::string password;
	std::cout << "Insira a \"senha\": ";
	std::cin >> password;

	if( password == "demostracao" )
	{
		std::string a = "UNIX ";
		std::string b = "is the way";

		std::cout << a + b << '\n';

		//size é um alias de length.
		std::cout << a.length() << '\n';
		std::cout << b.size() << '\n';
	}
	else
	{
		std::cout << "senha errada meu chapa.";
		exit(0);
	}

	exit(0);
}
