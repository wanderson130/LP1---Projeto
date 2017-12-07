#ifndef FUNCIONARIOS_HPP
#define FUNCIONARIOS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib> 

using namespace std;

/*
 *  Classe Pessoa
 */
class Pessoa {
private:
	string nome;
	string CPf;
	short idade;
	short tipo_sanguineo;
	string fatorRH;
	
public:
	Pessoa() = default;
	//~Pessoa();

	void setNome(string nome){this->nome = nome;}
	string getNome(){return this->nome;}

	void setCPF(string CPf){this->CPf = CPf;}
	string getCPF(){return this->CPf;}

	void setIdade(short idade){this->idade = idade;}
	short getIdade(){return this->idade;}		
		
	void setTipo_Sanguineo(short tipo_sanguineo){this->tipo_sanguineo = tipo_sanguineo;}
	short getTipo_Sanguineo(){return this->tipo_sanguineo;}	
	
	void setFatorRH(string fatorRH){this->fatorRH = fatorRH;}
	string getFatorRH(){return this->fatorRH;}
};

/*
 * Classe Puncionarios que herda da classe Pessoa
 */
class Funcionarios : public Pessoa
{
private:
	int id;
	int salario;
	int data_contratacao;
	string especialidade;	

public:
	Funcionarios() = default;
	//Funcionarios() : pessoa{} {}
	//~Funcionarios();
	
	void setId(int id){this->id = id;}
	int getId(){return this->id;}	

	void setSalario(int salario){this->salario = salario;}
	int getSalario(){return this->salario;}
		
	void setDataContratacao(int data_contratacao){this->data_contratacao = data_contratacao;}
	int getDataContratacao(){return this->data_contratacao;}
		
	void setEspecialidade(string especialidade){this->especialidade = especialidade;}
	string getEspecialidade(){return this->especialidade;}
};

/*
 * Classe para cadastrar funcionarios
 */
class CadastroFuncionarios {
private:
  vector<Funcionarios*> loja;

public:
  CadastroFuncionarios();
  void inserirFuncionarios();
  void buscaFuncionario(int id);
  void buscaNome(std::string nome);
  void imprimirFuncionarios();
  void salvarDados();
  void atualizarDados();
  void carregarDados();
};

#endif
