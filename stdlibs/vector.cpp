#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	//matrizes dinâmicas, funções membro:
	//begin() end() rbegin() rend() cbegin() cend() crbegin() crend()
	//capacidade
	//size() max_size() capacity() resize() empty() shrink_to_fit() reserve()
	//acesso a elemento
	//reference operator instancia[posicao]
	//at(g) front() back() data()
	//Modificadores
	//assign() push_back() pop_back() insert() erase() swap() clear()
	//emplace() emplace_back()

	std::vector<int> mat;
	
	unsigned char val = 65;
	while( val != 90 )
	{
		mat.push_back( static_cast<int>(val) );
		++val;
	}

	for( auto a = mat.begin(); a != mat.end(); ++a )
	{
		std::cout << *a << " ";
		if( a == (mat.end() - 1) )
		{
			std::cout << '\n';
			break;
		}
		else
		{
			continue;
		}
	}



	return 0;
}
