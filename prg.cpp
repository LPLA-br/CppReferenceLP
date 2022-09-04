/* Implementação das Funções Membro
 * Das classes no header*/

/*Estas inclusões devem ser
 *as mesmas no programa que inclui
 *estas implementações de funções
 *membro.*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "prg.hpp"

//---------CLASSE Retangulo-----------//

//construtor default abaixo
/* A inicialização, após os dois pontos, deve seguir
 * a mesma ordem das variavéis membro da classe.*/
Retangulo::Retangulo() : pi(3.14), area(0), id(new char[10]), largura(0), cumprimento(0)
{
	std::strcpy(this->id, "padrão");
}
//sobrecarga do construtor.
Retangulo::Retangulo(int Cump, int Lar, const char *Id) : pi(3.14), area(0)
{
	/*matenha os nome dos parâmetros com nomes
	 *diferentes das var membros.*/
	cumprimento = Cump;
	largura = Lar;
	this->id = new char[std::strlen(Id) + 1];
	std::strcpy( this->id, Id); //this. ou this->
}
//destrutor para desalocar variáveis alocadas.
Retangulo::~Retangulo()
{
	delete[] id;
}
int Retangulo::obterAtualizarArea(void)
{
	this->area = (cumprimento*largura);
	return this->area;
}
void Retangulo::aumentarAltura(int novo)
{
	cumprimento += novo;
}
void Retangulo::aumentarLargura(int novo)
{
	largura += novo;
}
void Retangulo::diminuirAltura(int novo)
{
	cumprimento -= novo;
}
void Retangulo::diminuirLargura(int novo)
{
	largura -= novo;
}
void Retangulo::output(void)
{
	std::cout << " cumprimento " << cumprimento << " largura " << largura << '\n';
	std::cout << " area " << area << '\n';
	std::cout << " id " << id << '\n';
}


//---------CLASSE Teste-----------//

//sobrecarga do construtor.
Teste::Teste() : a(new int), b(0), c(0)
{
	*a = 0;
}
Teste::Teste(int v1, int v2, int v3)
{
	a = new int;
	*a = v1;

	b = v2;
	c = v3;
}
Teste::~Teste()
{
	delete a;
}
void Teste::printNaoConst(void)
{
	std::cout << c << '\n';
}
void Teste::print(void) const
{
	std::cout << *a << ' ' << b << ' ' << c << '\n';
}
void Teste::modificarC(int val) const
{
	c = val;
}
void Teste::polimorfo()
{
	std::cout << "Classe Base\n";
}

//--------CLASSE Teste2 derivada de Teste----------//

//POLIMORFISMO override da função virtual "polimorfo" na classe Teste.
void Teste2::polimorfo()
{
	std::cout << "Classe derivada\n";
}

//-------CLASSE Casa herdeira de Retangulo---------//

Casa::Casa() : Retangulo()
{
	altura = 0;
}

/*As sobrecargas abaixo chamam contrutor da base */

Casa::Casa(int Alt) : Retangulo()
{
	altura = Alt;
}

Casa::Casa(int Alt, int Cump, int Lar, const char *Id) : Retangulo(Cump, Lar, Id)
{
	altura = Alt;
}

//POLIMORFISMO override da função virtual output da classe Retangulo.
void Casa::output(void)
{	
	std::cout << " cumprimento " << cumprimento << " largura " << largura << '\n';
	std::cout << "altura " << altura;
	std::cout << " id" << id << '\n';
}

