#include "oop.hpp"
#include <iostream>

Retangulo::Retangulo() : comprimento(new int), largura(new int)
{
	*comprimento = 10;
	*largura = 5;
}

Retangulo::Retangulo(int Cump, int Larg) : comprimento(new int), largura(new int)
{
	*comprimento = Cump;
	*largura = Larg;
}

Retangulo::~Retangulo()
{
	delete comprimento;
	delete largura;
}

int Retangulo::area(void)
{
	return (*comprimento)*(*largura);
}

int Retangulo::perimetro(void)
{
	return ((*comprimento) * 2) + ((*largura) * 2);
}

void Retangulo::alterarLargura(int novaLargura) const
{
	*largura += novaLargura;
	std::cout << *largura << "<0 Nova largura.\n";
}

void Retangulo::alterarComprimento(int novoComprimento) const
{
	*comprimento += novoComprimento;
	std::cout << *comprimento << "<0 Novo comprimento.\n";
}

void Retangulo::mostreMe(void)
{
	std::cout << "comprimento: " << *comprimento << "largura: " << *largura << '\n';
}

//--X--

Paralelepipedo::Paralelepipedo() : Retangulo()
{
	altura = new int;
	*altura = 10;
}

Paralelepipedo::Paralelepipedo(int Alt, int Cump, int Larg) : Retangulo(Cump, Larg)
{
	altura = new int;
	*altura = Alt;
}

Paralelepipedo::~Paralelepipedo()
{
	delete altura;
	delete comprimento;
	delete largura;
}

int Paralelepipedo::area()
{
	return 2*((*altura)*(*largura)) + 2*((*comprimento)*(*altura)) + 2*((*comprimento)*(*largura));
}

int Paralelepipedo::perimetro()
{
	return ((*altura)*3) + ((*comprimento)*3) + ((*largura)*3);
}

void Paralelepipedo::mostreMe(void)
{
	std::cout << "altura: " << *altura << "comprimento: " << *comprimento << "largura: " << *largura << '\n';
}

