#ifndef MODELO_HPP_INCLUDED
#define MODELO_HPP_INCLUDED

class Retangulo
{
	private:

	protected:
	int *comprimento;
	int *largura;

	public:
	Retangulo();
	Retangulo(int, int);
	~Retangulo();
	virtual int area(void);
	virtual int perimetro(void);
	void alterarLargura(int novaLargura) const;
	void alterarComprimento(int novoComprimento) const;
	virtual void mostreMe(void);
};

class Paralelepipedo : public Retangulo
{
	private:
	protected:
		int *altura;

	public:
		Paralelepipedo();
		Paralelepipedo(int, int, int);
		~Paralelepipedo();
		int area(void) override;
		int perimetro(void) override;
		void mostreMe(void) override;
};

#endif // MODELO_HPP_INCLUDED
