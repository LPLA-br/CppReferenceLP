/* referência prática
 * compilável e executável
 * do C++ */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "prg.hpp"

/* Compilação e linkedição desta referência:
 * g++ -Wall -Wextra teste.cpp prg.cpp -o teste */

/*Em C++, Ao contrário de C, protótipos de
funções não são necessários.*/

//Sobrecarga de funções.
int divisao(int a, int b)
{
	return (a/b);
}

float divisao(float a, float b)
{
	return (a/b);
}

//Função com template

template <class Tipo>
Tipo somaDinamica(Tipo a, Tipo b)
{
	return (a+b);
}

namespace espaco
{
	namespace verso
	{
		unsigned short contagem(unsigned short inicio, unsigned short fim)
		{
			for(; inicio <= fim; inicio++)
			{
				std::cout << inicio << '\n';
			}
			return inicio;
		}
	}
	namespace reverso
	{
		unsigned short contagem(unsigned short inicio, unsigned short fim)
		{
			for(; fim >= inicio; fim--)
			{
				std::cout << fim << '\n';
			}
			return fim;
		}
	}
}

//Ao descomentar abaixo declarar espaco:: não será necessário.
//using namespace espaco;

int main(int argc, char *argv[])
{
	int a=20, b=1;
	float aa=200.30, bb=1.5;

	//sobrecarga
	std::cout << "\n\nSobrecarga de função\n";
	std::cout << divisao(a, b) << '\n';
	std::cout << divisao(aa, bb) << '\n';
	std::cout << "\n\n";

	//template
	std::cout << "\n\nTemplate\n";
	std::cout << somaDinamica<float>(a, aa) << '\n';
	std::cout << somaDinamica<unsigned short>(a, b) << '\n';
	std::cout << "\n\n";

	//OBJETOS
	//Classe Retangulo
	Retangulo ret(30, 20, "001");
	Retangulo retDois;

	std::cout << "Retangulo\n";
	ret.aumentarAltura(20);
	ret.obterAtualizarArea();
	ret.output();

	retDois.output();

	//Classe Teste
	Teste axsonius, rutiferus(10, 20 ,30);
	const Teste pelarum(10, 20, 30);
	Teste2 objeto;
	
	std::cout << "\n\nTeste Teste2\n";

	axsonius.print();
	axsonius.polimorfo();
	rutiferus.print();

	pelarum.print();
	pelarum.modificarC(1982); //objeto constante veja(const, mutable)

	objeto.polimorfo();

	std::cout << "\n\nCasa\n";
	Casa pocilga(2, 10, 10, "777");
	pocilga.output();
	std::cout << "\n\n";

	//Namespace
	std::cout << "Namespace\n";
	espaco::verso::contagem(1, 10);
	espaco::reverso::contagem(1, 10);
	std::cout << "\n\n";

//---------TRATAMENTO DE EXCESSÃO LÓGICA-----------//
	try
	{
		unsigned short idadeMae = 30;
		unsigned short idadeFilho = -60;
		if(idadeMae < 0 || idadeFilho < 0)
			throw 99;
		else if(idadeFilho > idadeMae)
			throw 98;
	} catch(int x)
	{
		if( x == 99 )
			std::cout << "\nNão existe filho mais velho que a mãe ! exceçãoN:\n" << x << '\n';
		else if( x == 98 )
			std::cout << "\nNão existe pessoa com idade negativa ! exceçãoN:\n" << x << '\n';
	}
//---------------------------------------------------//
	exit(0);
}
