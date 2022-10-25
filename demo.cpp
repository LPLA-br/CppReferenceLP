/* referência prática
 * compilável e executável
 * do C++ */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "lib.hpp"

/* Compilação e linkedição desta referência:
 * g++ -Wall -Wextra teste.cpp prg.cpp -o teste */

/*Em C++, Ao contrário de C, protótipos de
funções não são necessários.*/

/* SOBRECARGA DE FUNÇÃO
 * Uma função pode ser sobrecarregada
 * como na demostração abaixo.*/

int divisao(int a, int b)
{
	return (a/b);
}

float divisao(float a, float b)
{
	return (a/b);
}

short divisao(short a, short b)
{
	return (a/b);
}

// TEMPLATES e funções (pode ser em func. membros)
/* Torna possível a escrita de uma função
 * capaz de lidar com vários tipos de dados
 * (incluindo dados definidos pelo programador
 * em classes).
 */

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

	//template funções e classes.
	std::cout << "\n\nTemplate\n";

	float retval1 = somaDinamica<float>(a, aa);
	unsigned short retval2 = somaDinamica<unsigned short>(a, b);
	std::string retval3 = somaDinamica<std::string>("segmentation ","fault TROlmao");

	std::cout << retval1 << '\n';
	std::cout << retval2 << '\n';
	std::cout << retval3 << '\n';

	//template na classe exemplo "Matriz"
	Matriz<int,5> mat;
	std::cout << mat.mostrarTamanho();
	Matriz<unsigned short, 10> mat2;
	std::cout << mat2.mostrarTamanho();
	Matriz<std::string, 50> mat3;
	std::cout << mat3.mostrarTamanho();

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

	//sobrecarga de operador
	std::cout << "\n\nSobrecarga\n";
	Sobrecarga teste(10);
	teste.show();
	++teste;
	teste.show();
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
