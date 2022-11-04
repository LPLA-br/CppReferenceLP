/* referência prática
 * compilável e executável
 * do C++ */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <string.h>
#include "lib.hpp"


inline unsigned short letraE(char* valor)
{
	std::cout << '\n' << *valor << '\n';
	*valor = 'b';
	std::cout << "\n O ponteiro tem o endereço:  " << &valor;
	std::cout << '\n' << *valor << '\n';
	return 0;
}

inline short operation(short val)
{
	return (val*10);
}

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

short divisao(void)
{
	return 0;
}


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

int main(int argc, char* argv[])
{

	if(argc < 2)
	{
		char str[10];
		std::cout << "\nInput < 10: ";
		std::cin >> str;
		std::cout << str;
	}

	switch( argc )
	{
		case 0:
		case 1:
			break;
		case 2:
			if( !strcmp("--sobrecarga",argv[1]) )
			{
				SOBRECARGA::Coordenadas a(10, 10);
				a.show();
				++a;
				a.show();
				SOBRECARGA::Coordenadas b(0, 0);
				b = --a;
				b.show();
				(--b).show();
			}
			else if( !strcmp("--ponteiro",argv[1]) )
			{
				//vale a pena ver denovo.

				char valor = 'a';
				letraE( &valor );

				const char** string;
				const char matriz[10] = "shit\0";
			}
			else if( !strcmp("--tratamento-erro",argv[1]) )
			{
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
			}
			else if( !strcmp("--namespace",argv[1]) )
			{
				espaco::verso::contagem(1, 10);
				espaco::reverso::contagem(1, 10);
				std::cout << "\n\n";
			}
			else if( !strcmp("--classes",argv[1]) )
			{
				Retangulo ret(30, 20, "001");
				Retangulo retDois;
				const Retangulo retTres(25, 25, "002");

				ret.aumentarAltura(20);
				ret.obterAtualizarArea();

				ret.obterLargAlt(retDois);

				retTres.aumentarAltura(1);
				retTres.aumentarLargura(1);

				ret.output();
				retDois.output();
				//retTres.output();

				std::cout << "\n\nCasa\n";
				Casa pocilga(2, 10, 10, "777");
				pocilga.mudarAltura(15);
				pocilga.output();
				std::cout << "\n\n";
			}
			else if( !strcmp("--sobrecarga-func",argv[1]) )
			{
				int a=20, b=1;
				float aa=200.30, bb=1.5;
				
				float& referencia = aa;
				referencia = 200.75;

				std::cout << divisao() << '\n';
				std::cout << divisao(a, b) << '\n';
				std::cout << divisao(aa, bb) << '\n';
			}
			else if( !strcmp("--templates-func",argv[1]) )
			{
				int a=20, b=1;
				float aa=200.30, bb=1.5;
				
				float retval1 = somaDinamica<float>(a, aa);
				unsigned short retval2 = somaDinamica<unsigned short>(a, b);
				std::string retval3 = somaDinamica<std::string>("segmentation ","fault TROLEI!kk");

				std::cout << retval1 << '\n';
				std::cout << retval2 << '\n';
				std::cout << retval3 << '\n';
			}
			else if( !strcmp("--templates-classes",argv[1]) )
			{
				std::cout << "\n\ntemplates e classes\n";
				Matriz<int,5> mat;
				std::cout << mat.mostrarTamanho();
				Matriz<unsigned short, 10> mat2;
				std::cout << mat2.mostrarTamanho();
				Matriz<std::string, 50> mat3;
				std::cout << mat3.mostrarTamanho();
				std::cout << "\n\n";
			}
			else
			{
				std::cout << "\nOpção desconhecida.\n";
				std::cout << "OPCÕES:\n";
				std::cout << "      --sobrecarga \n";
				std::cout << "      --ponteiro\n";
				std::cout << "      --namespace\n";
				std::cout << "      --classes\n";
				std::cout << "      --sobrecarga-func\n";
				std::cout << "      --templates-func\n";
				std::cout << "      --templates-classes\n";
			}
			break;
		default:
			std::cout << "Excesso de Opções!";
			break;
	}
	exit(0);
}
