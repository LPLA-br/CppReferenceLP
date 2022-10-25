#ifndef PRG_HPP_INCLUDED
#define PRG_HPP_INCLUDED

/* no header: structs,
 * unions, classes, enumerações, defines
 * e campo_de_bits
 * */

/* Em C++ não existem
 * atributos e métodos
 * mas sim MEMBROS e
 * FUNÇÕES MEMBROS.*/

class Retangulo
{
	/* Dados de classe devem
	 * ser modificados externamente
	 * pelas funções membro públicas.
	 * Funções membro privadas só
	 * podem ser usadas por funções
	 * membro publicas. ENCAPSULAMENTO*/

	private: //Visível apenas por esta Classe.

		const float pi;
		int area;

	protected: //Visível para esta classe e classes Herdeiras.

		char *id;
		int largura;
		int comprimento;

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

		/* MUTABLE
		 * Se uma classe é instânciada como objeto
		 * constante então a variável membro
		 * abaixo será mutável e legível
		 * apenas por funções com a keyword const*/
		mutable int c;
	public:
		Teste();
		Teste(int, int, int);
		~Teste();
		void printNaoConst(void); //não funcionará em objetos const
		void print(void) const;
		void modificarC(int val) const;

		/* VIRTUAL → OVERRIDE
		 * função virtual que pode ser substituida
		 * assumindo ações diferenciadas
		 * na classe derivada. POLIMORFISMO*/
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

/* OPERATOR
 * Sobrecarga de operadores.
 **/
class Sobrecarga
{
	private:
	unsigned *valor;
	
	protected:
	
	public:
	Sobrecarga();
	Sobrecarga(unsigned Val);
	~Sobrecarga();
	void show(void);
	void operator ++(void);
};

/*TEMPLATES e classes*/
/* templates torna possível
 * uma espécie de "simulação
 * de tipagem dinâmica".
 * Os alvos de template só
 * existem se chamados.
 * */

template<typename T, int N>
class Matriz
{
	private:
		T m_matriz[N];
	public:
		//função INLINE da classe.
		int mostrarTamanho() const { return N; }
};

#endif //PRG_HPP_INCLUDED
