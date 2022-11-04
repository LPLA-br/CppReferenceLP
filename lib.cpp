/* Implementação das Funções Membro
 * Das classes no header*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "lib.hpp"

//---------CLASSE Retangulo-----------//

GEOMETRICOS::Retangulo::Retangulo() : pi(3.14), area(0), id(new char[10]), largura(0), comprimento(0)
{
	std::strcpy(this->id, "padrão");
	//numObjetos++;
}

//unsigned short Retangulo::numObjetos = 0;

GEOMETRICOS::Retangulo::Retangulo(int Cump, int Lar, const char *Id) : pi(3.14), area(0)
{
	comprimento = Cump;
	largura = Lar;
	this->id = new char[std::strlen(Id) + 1];
	std::strcpy( this->id, Id); //this. ou this->
	//numObjetos++;
}

GEOMETRICOS::Retangulo::~Retangulo()
{
	delete[] id;
	//numObjetos--;
}

int GEOMETRICOS::Retangulo::obterAtualizarArea(void)
{
	this->area = (comprimento*largura);
	return this->area;
}

void GEOMETRICOS::Retangulo::aumentarAltura(int novo) const
{
	comprimento += novo;
}

void GEOMETRICOS::Retangulo::aumentarLargura(int novo) const
{
	largura += novo;
}

void GEOMETRICOS::Retangulo::diminuirAltura(int novo)
{
	comprimento -= novo;
}

void GEOMETRICOS::Retangulo::diminuirLargura(int novo)
{
	largura -= novo;
}

void GEOMETRICOS::Retangulo::obterLargAlt(GEOMETRICOS::Retangulo *Copia)
{
	std::cout << "RecebeObjetoNosArgumentos";
	Copia->output();
}

void GEOMETRICOS::Retangulo::output(void)
{
	std::cout << " comprimento " << comprimento << " largura " << largura << '\n';
	std::cout << " area " << area << '\n';
	std::cout << " id " << id << '\n';
}

//-------CLASSE Casa herdeira de Retangulo---------//

GEOMETRICOS::Casa::Casa() : Retangulo()
{
	altura = 0;
}

GEOMETRICOS::Casa::Casa(int Alt) : Retangulo()
{
	altura = Alt;
}

GEOMETRICOS::Casa::Casa(int Alt, int Cump, int Lar, const char *Id) : Retangulo(Cump, Lar, Id)
{
	altura = Alt;
}

void GEOMETRICOS::Casa::output(void)
{	
	std::cout << " comprimento " << comprimento << " largura " << largura << '\n';
	std::cout << "altura " << altura;
	std::cout << " id" << id << '\n';
}

void GEOMETRICOS::Casa::mudarAltura(int novAlt) const
{
	//altura = novAlt;	
}

/*---------CLASSE Coordenadas---------*/

Coordenadas::Coordenadas()
: posicaoX(new unsigned), posicaoY(new unsigned)
{
	*posicaoX = 0;
	*posicaoY = 0;
}

Coordenadas::Coordenadas( unsigned px, unsigned py)
: posicaoX(new unsigned), posicaoY(new unsigned)
{
	*posicaoX = px;
	*posicaoY = py;
}

Coordenadas::~Coordenadas()
{
	delete posicaoX;
	delete posicaoY;
}

void Coordenadas::show(void)
{
	std::cout << *posicaoX << 'x' << *posicaoY << 'y' << '\n';
}

void Coordenadas::operator++(void)
{
	++(*posicaoY);
	++(*posicaoX);
}

Coordenadas Coordenadas::operator--(void)
{
	//malloc(): unaligned tcache chunk detected.
	--(*posicaoY);
	--(*posicaoX);
	Coordenadas retorno(*posicaoX, *posicaoY);
	return retorno;
}

/*---------CLASSE Coordenadas---------*/
//Coordenadas sem ponteiros.

NoPointerCoordenadas::NoPointerCoordenadas()
: posicaoX(10), posicaoY(10)
{}

NoPointerCoordenadas::NoPointerCoordenadas( unsigned px, unsigned py)
: posicaoX(px), posicaoY(py)
{}

NoPointerCoordenadas::~NoPointerCoordenadas()
{}

void NoPointerCoordenadas::show(void)
{
	std::cout << posicaoX << 'x' << posicaoY << 'y' << '\n';
}

void NoPointerCoordenadas::operator++(void)
{
	++posicaoY;
	++posicaoX;
}

NoPointerCoordenadas NoPointerCoordenadas::operator--(void)
{
	--posicaoY;
	--posicaoX;
	NoPointerCoordenadas retorno(posicaoX, posicaoY);
	return retorno;
}


NoPointerCoordenadas NoPointerCoordenadas::operator+(NoPointerCoordenadas& a) const
{
	NoPointerCoordenadas retorno;
	retorno.posicaoX = posicaoX + a.posicaoX;
	retorno.posicaoY = posicaoY + a.posicaoY;
	return retorno;
}

