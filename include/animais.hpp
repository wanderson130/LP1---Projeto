#ifndef ANIMAIS_HPP
#define ANIMAIS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib> 

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
	Animal() = default;
	//~Animais();
	
	void setId(const int id){ this->id = id;}
	int getId(){ return this->id;}

	string getClasse(){ return this->classe;}
	void setClasse(const string classe){ this->classe = classe;}

	string getNome(){return this->nome;}
	void setNome( const string nome ) {this->nome = nome;}

	string getCientifico(){ return this->cientifico;}
	void setCientifico( string cientifico){ this->cientifico = cientifico;}

	char getSexo(){return this->sexo;}
	void setSexo( const char sexo ) {this->sexo = sexo;}

	float getTamanho(){ return this->tamanho;}
	void setTamanho(const float tamanho){ this->tamanho = tamanho;}

	string getDieta(){return this->dieta;}
	void setDieta( const string dieta ) {this->dieta = dieta;}

	string getBatismo(){return this->batismo;}
	void setBatismo( const string batismo ) {this->batismo = batismo;}
};

class CadastroAnimal {
private:
  vector<Animal*> lista;

public:
  CadastroAnimal();
  void inserirAnimal();
  void imprimeAnimal();
  void buscaNome(std::string nome);
  void buscaAnimal(int id);
  void atualizaDado();
  void salvaDado();
  void carregaDado();
};

#endif /* PRODUTOS_HPP */
