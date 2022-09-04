#ifndef PRG_HPP_INCLUDED
#define PRG_HPP_INCLUDED

/*no header: structs, unions, classes, enumerações, defines
 *e campo_de_bits*/

/* Em C++ não existem
 * atributos e métodos
 * mas sim MEMBROS e
 * FUNÇÕES MEMBROS.*/

class Retangulo
{
	/*Dados de classe devem
	 *ser modificados externamente
	 *pelas funções membro públicas.
	 *Funções membro privadas só
	 *podem ser usadas por funções
	 *membro publicas. ENCAPSULAMENTO*/

	private: //Visível apenas por esta Classe.

		const float pi;
		int area;

	protected: //Visível para esta classe e classes Herdeiras.

		char *id;
		int largura;
		int cumprimento;

	public: //Acessível em todo programa.

		/*Construtor sem argumentos
		 *chama-se default/padrão.
		 *Abaixo construtor seguido
		 *de destrutor*/
		Retangulo(); //constutor default
		Retangulo(int,int,const char *); //sobrecarga do construtor
		~Retangulo();

		int obterAtualizarArea(void);
		void aumentarAltura(int novo);
		void aumentarLargura(int novo);
		void diminuirAltura(int novo);
		void diminuirLargura(int novo);
		virtual void output(void);

};

class Teste
{
	private:
		int *a;
		int b;

		/*Se a classe é instânciada como objeto
		 *constante então a variável membro
		 *abaixo será mutável e legível/modificável
		 apenas por funções com a keyword const*/
		mutable int c;
	public:
		Teste(); //default
		Teste(int, int, int);
		/*destrutor é necessário apenas quando
		 *houver alocação de memória*/
		~Teste();

		void printNaoConst(void); //não funcionará em objetos const
		void print(void) const;
		void modificarC(int val) const;

		/*função virtual que pode ser substituida
		 *assumindo ações diferenciadas
		 *na classe derivada. POLIMORFISMO*/
		virtual void polimorfo();
};

class Teste2 : public Teste
{
	public:
		void polimorfo() override;
};

class Casa : public Retangulo
{
	private:
		int altura;
	public:
		Casa();
		Casa(int Alt);
		Casa(int Alt, int Cump, int Lar, const char *Id);
		void output(void) override;
};

#endif //PRG_HPP_INCLUDED
