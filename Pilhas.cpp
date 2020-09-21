#include <iostream>
#include <cstddef>
using namespace std;

class No
{
	friend class Lista;

private:
	int valor;
	No *Pproximo;

public:
	No(int val) //Forma diferente de fazer o construtor
		: valor(val), Pproximo(NULL)
	{

	}

};

class Lista
{
private:
	No *PCabeca;
	No *PCalda;

	No *PegaNo(int v);

public:
	Lista(void);
	//Lista(int val);

	//adiciona um no
	void AdicionaNoFront(int val);

	//remove No
	bool RemoveNoFront();

	//bool ListaVazia();
	void Imprimir();
};

Lista::Lista() :PCabeca(NULL), PCalda(NULL)
{
}

void Lista::AdicionaNoFront(int val)
{
	No *AuxP = PegaNo(val);

	if (PCabeca == NULL)
	{
		PCabeca = PCalda = AuxP;
	}
	else
	{
		AuxP->Pproximo = PCabeca;
		PCabeca = AuxP;
	}
}

bool Lista::RemoveNoFront()
{
	if (PCabeca == NULL)
	{
		return false;
	}
	else
	{
		No * Ptemp = PCabeca;

		if (PCabeca == PCalda)
		{
			PCabeca = PCalda = NULL;
		}
		else
		{
			PCabeca = PCabeca->Pproximo;
		}

		delete Ptemp;
		return true;
	}
}

No *Lista::PegaNo(int valor)
{
	No *aux = new No(valor);
	return aux;
}

void Lista::Imprimir()
{
	No *p = PCabeca;

	if (PCabeca == NULL) {
		cout << "Fila vazia" << endl;
	}

	cout << "Fila: ";
	while (p != NULL) {
		cout << p->valor;
		p = p->Pproximo;
	}
	cout << endl;
}

class Pilhas :private Lista
{
public:
	void entra(int val)
	{
		AdicionaNoFront(val);
	}

	bool sai()
	{
		return RemoveNoFront();
	}

	void imprimeF()
	{
		Imprimir();
	}

};

int main()
{
	Pilhas pilha;

	pilha.entra(1);
	pilha.entra(2);
	pilha.entra(3);
	pilha.entra(4);

	pilha.imprimeF();

	pilha.sai();
	pilha.sai();

	pilha.imprimeF();

	system("pause");
	return 0;
}