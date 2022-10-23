#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "oop.hpp"

int main(int argc, char *argv[])
{
	Retangulo terreno(10, 10);
	printf("\n area: %i \n", terreno.area() );
	printf("\n perimetro: %i \n", terreno.perimetro() );
	terreno.mostreMe();

	Paralelepipedo construcao(10, 10, 10);
	printf("\n area: %i \n", construcao.area() );
	printf("\n perimetro: %i \n", construcao.perimetro() );
	construcao.mostreMe();

	exit(0);
}
