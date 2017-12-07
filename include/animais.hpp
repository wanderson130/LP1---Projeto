#ifndef ANIMAIS_HPP
#define ANIMAIS_HPP

#include "includes.hpp"

using namespace std;

class Animal {
private:
	int id;
    string classe;	
    string nome;
	string cientifico;
	char sexo;
	float tamanho;
    string dieta;
	string batismo;

public:
	Animal();
	Animal(int id, string classe, string nome, string cientifico, char sexo, float tamanho, string dieta, string batismo);

	int getId();
	void setId(const int id);	

	string getClasse();
	void setClasse(const string classico);
	
	string getNome();
	void setNome(const string nome);
	
	string getCientifico();
	void setCientifico(const string cientifico);
	
	char getSexo();
	void setSexo(const char sexo);

	float getTamanho();
	void setTamanho(const float tamanho);
	
	string getDieta();
	void setDieta(const string dieta);

	string getBatismo();
	void setBatismo(const string batismo);

	void escrever(ostream& out) const
	{	        
		out << "Id:"  				  		<<      id     << endl;		
		out << "Classe:"  				  	<<    classe   << endl;
		out << "Nome:"					 	<<     nome    << endl;
		out << "Cientifico:"  				<<  cientifico << endl;
		out << "Sexo:"  				  	<<     sexo    << endl;
		out << "Tamanho:"  				  	<<   tamanho   << endl;
		out << "Dieta:"  				  	<<    dieta    << endl;
		out << "Batismo:"  				  	<<   batismo   << endl;
	}
};


class CadastroAnimal {
	friend class Cadastro;

private:
  vector<Animal*> lista;

public:
  void inserirAnimal();
  int  buscarAnimal(int id) const;
  void escrever(ostream& out) const;
  void atualizarLista();
  void salvaDado();
  void carregaDado();
};

ostream& operator<<(ostream& out, const CadastroAnimal& a);

#endif /* PRODUTOS_HPP */
