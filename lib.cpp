/* Implementação das Funções Membro
 * Das classes no header*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "lib.hpp"

//---------CLASSE Retangulo-----------//

Retangulo::Retangulo() : pi(3.14), area(0), id(new char[10]), largura(0), comprimento(0)
{
	std::strcpy(this->id, "padrão");
	numObjetos++;
}

Retangulo::Retangulo(int Cump, int Lar, const char *Id) : pi(3.14), area(0)
{
	comprimento = Cump;
	largura = Lar;
	this->id = new char[std::strlen(Id) + 1];
	std::strcpy( this->id, Id); //this. ou this->
	numObjetos++;
}

//tempo de compilação.
unsigned short Retangulo::numObjetos = 0;

Retangulo::~Retangulo()
{
	delete[] id;
	numObjetos--;
}

int Retangulo::obterAtualizarArea(void)
{
	this->area = (comprimento*largura);
	return this->area;
}

void Retangulo::aumentarAltura(int novo) const
{
	comprimento += novo;
}

void Retangulo::aumentarLargura(int novo) const
{
	largura += novo;
}

void Retangulo::diminuirAltura(int novo)
{
	comprimento -= novo;
}

void Retangulo::diminuirLargura(int novo)
{
	largura -= novo;
}

void Retangulo::obterLargAlt(Retangulo Copia)
{
	std::cout << "RecebeObjetoNosArgumentos";
	Copia.output();
}

void Retangulo::output(void)
{
	std::cout << " comprimento " << comprimento << " largura " << largura << '\n';
	std::cout << " area " << area << '\n';
	std::cout << " id " << id << '\n';
}

//-------CLASSE Casa herdeira de Retangulo---------//

Casa::Casa() : Retangulo()
{
	altura = 0;
}

Casa::Casa(int Alt) : Retangulo()
{
	altura = Alt;
}

Casa::Casa(int Alt, int Cump, int Lar, const char *Id) : Retangulo(Cump, Lar, Id)
{
	altura = Alt;
}

void Casa::output(void)
{	
	std::cout << " comprimento " << comprimento << " largura " << largura << '\n';
	std::cout << "altura " << altura;
	std::cout << " id" << id << '\n';
}

void Casa::mudarAltura(int novAlt) const
{
	//altura = novAlt;	
}

/*---------CLASSE Teste de sobrecarga---------*/

SOBRECARGA::Coordenadas::Coordenadas()
: posicaoX(new unsigned), posicaoY(new unsigned)
{
	*posicaoX = 0;
	*posicaoY = 0;
}

SOBRECARGA::Coordenadas::Coordenadas( unsigned px, unsigned py)
: posicaoX(new unsigned), posicaoY(new unsigned)
{
	*posicaoX = px;
	*posicaoY = py;
}

SOBRECARGA::Coordenadas::~Coordenadas()
{
	delete posicaoX;
	delete posicaoY;
}

void SOBRECARGA::Coordenadas::show(void)
{
	std::cout << *posicaoX << 'x' << *posicaoY << 'y' << '\n';
}

void SOBRECARGA::Coordenadas::operator++(void)
{
	++(*posicaoY);
	++(*posicaoX);
}

SOBRECARGA::Coordenadas SOBRECARGA::Coordenadas::operator--(void)
{
	--(*posicaoY);
	--(*posicaoX);
	SOBRECARGA::Coordenadas retorno(*posicaoX, *posicaoY);
	return retorno;
}

