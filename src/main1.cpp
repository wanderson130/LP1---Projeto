#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "funcionarios.hpp"
#include "animais.hpp"

int main (){
	int opc, matricula, id;
	std::string nome;

	CadastroFuncionarios PetFera;
	PetFera.carregarDados();

	CadastroAnimal bixo;					
	bixo.carregaDado();
	
	do
	{
  		cout << "Sistema da Loja PetFera" << endl;
  		cout << "(1) Inserir funcionarios" << endl;
  		cout << "(2) Carregar dados existentes" << endl;
  		cout << "(3) Exibir funcionarios" << endl;
		cout << "(4) Buscar e remove funcionario por matricula" << endl;
		cout << "(5) Buscar e remove funcionario por nome" << endl;
		cout << "(6) Inserir Animal no Sistema" << endl;
		cout << "(7) Lista de Animais" << endl;
		cout << "(8) Buscar e remove Animal por Id" << endl;
		cout << "(9) Buscar e remove Animal por nome" << endl;	
  		cout << "(0) Sair" << endl;
		cin >> opc;

 	    while(opc > 9 or opc < 0) 
		{
			cout << "Informe uma opção valida: ";
			cin >> opc;
		}
			system("clear");
			  switch (opc){
				case 1:
					PetFera.inserirFuncionarios();
					cout << "\nVoltando ao Menu Funcionarios, Pressione Enter para continuar.\n";
					cin.ignore().get();
				  break;
				case 2:
				  	PetFera.carregarDados();
					bixo.carregaDado();
					cout << "\nDados Carregados\n";
					cout << "\nVoltando ao Menu Funcionarios, Pressione Enter para continuar.\n";
					cin.ignore().get();
				  break;
				case 3:
					PetFera.imprimirFuncionarios();
					cout << "\nVoltando ao Menu Funcionarios, Pressione Enter para continuar.\n";
					cin.ignore().get();
				  break;
				case 4:	
					cout << "\nBuscar funcionario por matricula.\n";
					cin >> matricula;
					PetFera.buscaFuncionario(matricula);
					cin.ignore().get();	
				  break;	
				case 5:	
					cout << "\nBuscar funcionario por nome.\n";
					cin >> nome;
					PetFera.buscaNome(nome);
					cin.ignore().get();		
				  break;	
				case 6:
					cout << "\nCadastrar Animal.\n";
					bixo.inserirAnimal();	
					cin.ignore().get();	
				  break;	
				case 7:
					cout << "\nLista de Animais.\n";	
					bixo.imprimeAnimal();
					cin.ignore().get();	
				  break;
				case 8:
					cout << "\nBuscar Animal por Id.\n";
					cin >> id;
					bixo.buscaAnimal(id);
					cin.ignore().get();	
				  break;				
				case 9:
					cout << "\nBuscar Animal por Nome.\n";
					cin >> nome;				  	
					bixo.buscaNome(nome);
					cin.ignore().get();	
				  break;
				case 0:
					exit(EXIT_SUCCESS);
				default:
					cout << "Valor invalido!" << endl;	
				}
	}while(opc != 0);	
}

