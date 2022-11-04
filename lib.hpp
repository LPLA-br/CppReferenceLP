#ifndef PRG_HPP_INCLUDED
#define PRG_HPP_INCLUDED

class Retangulo
{
	private:
		static unsigned short numObjetos;
		const float pi;
		int area;

	protected:

		char *id;
		mutable int largura;
		mutable int comprimento;

	public:


		Retangulo();
		Retangulo(int,int,const char *);
		~Retangulo();

		int obterAtualizarArea(void);
		void aumentarAltura(int novo) const;
		void aumentarLargura(int novo) const;
		void diminuirAltura(int novo);
		void diminuirLargura(int novo);
		void obterLargAlt(Retangulo Copia);
		virtual void output(void);
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
		void mudarAltura(int novAlt) const;
};

namespace SOBRECARGA
{

	class Coordenadas
	{
		private:
		unsigned* posicaoX;
		unsigned* posicaoY;
		
		protected:
		
		public:
		Coordenadas();
		Coordenadas( unsigned px, unsigned py );
		~Coordenadas();
		void show(void);
		void operator ++(void);
		Coordenadas operator--(void);
	};

}

template<typename T, int N>
class Matriz
{
	private:
		T m_matriz[N];
	public:
		int mostrarTamanho() const { return N; }
};


#endif //PRG_HPP_INCLUDED
