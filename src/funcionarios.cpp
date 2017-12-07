#include "funcionarios.hpp"

/** Funcao que e responsavel pelo cadastro dos funcionarios no sistema */
void CadastroFuncionarios::carregarDados() {

	loja.clear(); // Limpando o vector
	
	fstream myfile("funcionarios.txt");
    
    std::string line, nome;
	int pos, div, tam, conv, i;
	int cont{0};

	if(!myfile)	// Verifica se já existe um arquivo chamado funcionarios.
		return;
	
  	// Faz a contagem do numero de linhas de um aquivo
    while (!myfile.eof()) {
		getline (myfile, line);
		cont++;
  	}
  	cont--;
  	myfile.close();
  	div = cont / 5;
  	
  	myfile.open("funcionarios.txt");

		for (i = 0; i < div ; i++) {
			
			Funcionarios* informacoes = new Funcionarios();

			//--- ID ---
			getline (myfile,line);
			pos =  line.find(":",0);
			tam = pos+1;
			nome = line.substr(tam,pos-tam);
			conv = stoi(nome);
			informacoes->setId(conv);	
		
			//--- NOME ---
			getline (myfile,line);
			pos =  line.find(":", 0);
			tam = pos + 1;
			nome = line.substr(tam, pos - tam);
			informacoes->setNome(nome);

			// --- CPF ---
			getline (myfile,line);
			pos =  line.find(":",0);
			tam = pos+1;
			nome = line.substr(tam,pos-tam);
			informacoes->setCPF(nome);

			// --- DATA DE CONTRATAÇÃO ---
			getline (myfile,line);
			pos =  line.find(":",0);
			tam = pos+1;
			nome = line.substr(tam,pos-tam);
			conv = stoi(nome); 
			informacoes->setDataContratacao(conv);

			// --- SALARIO ---
			getline (myfile,line);
			pos =  line.find(":",0);
			tam = pos+1;
			nome = line.substr(tam,pos-tam);
			conv = stoi(nome);
			informacoes->setSalario(conv);

			//--- TIPO SANGUINEO ---
			getline (myfile,line);
			pos =  line.find(":",0);
			tam = pos+1;
			nome = line.substr(tam,pos-tam);
			conv = stoi(nome);
			informacoes->setTipo_Sanguineo(conv);

			//--- FATORRH ---
			getline (myfile,line);
			pos =  line.find(":", 0);
			tam = pos + 1;
			nome = line.substr(tam, pos - tam);
			informacoes->setFatorRH(nome);				
			
			//--- IDADE ---
			getline (myfile,line);
			pos =  line.find(":",0);
			tam = pos+1;
			nome = line.substr(tam,pos-tam);
			conv = stoi(nome);
			informacoes->setIdade(conv);							
			
			//--- ESPECIALIDADE ---
			getline (myfile,line);
			pos =  line.find(":", 0);
			tam = pos + 1;
			nome = line.substr(tam, pos - tam);
			informacoes->setEspecialidade(nome);
		
			loja.push_back(informacoes);
	    }

	myfile.close(); 
}

/** Funcao que e carrega dados armazenados no arquivo.txt dos funcionarios */
void CadastroFuncionarios::atualizarDados() 
{
	ofstream myfile;
	myfile.open ("funcionarios.txt", ios::out | ios::app | ios::binary);

	for( unsigned i = 0; i < loja.size(); i++ )
	{
			myfile << "ID:"					  << loja[i]->getId() << endl; 	
	        myfile << "Nome:"  				  << loja[i]->getNome() << endl;
	        myfile << "CPF:" 				  << loja[i]->getCPF() << endl;
	        myfile << "Data de Contratacao:"  << loja[i]->getDataContratacao() << endl;
	        myfile << "Salario:" 			  << loja[i]->getSalario() << endl;
			myfile << "Tipo Sanguineo:"       << loja[i]->getTipo_Sanguineo() << endl;
			myfile << "FatorRH:" 			  << loja[i]->getFatorRH() << endl;
			myfile << "Idade:" 				  << loja[i]->getIdade() << endl;
			myfile << "Especialidade:"		  << loja[i]->getEspecialidade() << endl;
	}
	myfile.close();
}

/** Funcao que salva os dados dos funcionarios em um arquivo.txt */
void CadastroFuncionarios::salvarDados() 
{
	ofstream myfile ("funcionarios.txt");
	if (myfile.is_open())
	{
		for( unsigned i = 0; i < loja.size(); i++ )
		{
			myfile << "ID:" 				  << loja[i]->getId() << endl;
	        myfile << "Nome:"  				  << loja[i]->getNome() << endl;
	        myfile << "CPF:" 				  << loja[i]->getCPF() << endl;
	        myfile << "Data de Contratacao:"  << loja[i]->getDataContratacao() << endl;
	        myfile << "Salario:" 			  << loja[i]->getSalario() << endl;
			myfile << "Tipo Sanguineo:"       << loja[i]->getTipo_Sanguineo() << endl;
			myfile << "FatorRH:" 			  << loja[i]->getFatorRH() << endl;
			myfile << "Idade:" 				  << loja[i]->getIdade() << endl;
			myfile << "Especialidade:"		  << loja[i]->getEspecialidade() << endl;
		}
	}
	myfile.close();
}

CadastroFuncionarios::CadastroFuncionarios() {
	//ofstream myfile ("funcionarios.txt");

}

/** Funcao que permite a insercao manual de funcionarios no vetor */
void CadastroFuncionarios::inserirFuncionarios() {
  	
  	int i, n, quant;
	cout << "Informe quantos Funcionarios voce quer cadastrar:";
	cin >> quant;
	string nome;
    
    for(i = 0; i < quant; i++)
    {
  		Funcionarios *informacoes = new Funcionarios();
			
    	cout << "Infome o ID do Funcionario: ";
    	cin >> n;
    	informacoes->setId(n);	

    	cout << "Informe o nome do Funcionario: ";
    	cin.ignore();
    	getline(cin, nome);
    	informacoes->setNome(nome);
    	
    	cout << "Infome o CPF do Funcionario: ";
    	cin.ignore();
    	getline(cin, nome);
    	informacoes->setCPF(nome);

    	cout << "Infome o salario do Funcionario: ";
    	cin >> n;
    	informacoes->setSalario(n);

    	cout << "Infome Data de contratacao do Funcionario: ";
    	cin >> n;
    	informacoes->setDataContratacao(n);

		cout << "Informe o Tipo Sanguíneo: ";
		cin >> n;
    	informacoes->setTipo_Sanguineo(n);

		cout << "Infome o FatorRH: ";
    	cin.ignore();
    	getline(cin, nome);
    	informacoes->setFatorRH(nome);

		cout << "Informe a Idade: ";
		cin >> n;
    	informacoes->setIdade(n);
	
		cout << "Infome a Especialidade dele: ";
    	cin.ignore();
    	getline(cin, nome);
    	informacoes->setEspecialidade(nome);
		
    	cout << "\n";  	

		loja.push_back(informacoes);
		
	  }
	salvarDados();
}

/** Funcao que imprime vetor de funcionarios */
void CadastroFuncionarios::imprimirFuncionarios() {	
	for(unsigned i = 0; i < loja.size(); i++)
		{
			cout << setw(20) << left << "ID:" 				  << "\t" << loja[i]->getId() << endl;
	        cout << setw(20) << left << "Nome:"  			  << "\t" << loja[i]->getNome() << endl;
	        cout << setw(20) << left << "CPF:" 				  << "\t" << loja[i]->getCPF() << endl;
	        cout << setw(20) << left << "Data de Contratacao:"<< "\t" << loja[i]->getDataContratacao() << endl;
	        cout << setw(20) << left << "Salario:" 			  << "\t" << loja[i]->getSalario() << endl;
			cout << setw(20) << left << "Tipo Sanguineo:"     << "\t" << loja[i]->getTipo_Sanguineo() << endl;
			cout << setw(20) << left << "FatorRH:" 			  << "\t" << loja[i]->getFatorRH() << endl;
			cout << setw(20) << left << "Idade:" 			  << "\t" << loja[i]->getIdade() << endl;
			cout << setw(20) << left << "Especialidade:"      << "\t" << loja[i]->getEspecialidade() << endl;
		}
}

/** Funcao que busca funcionarios pelo numero de id */
void CadastroFuncionarios::buscaFuncionario(int id)
{
	for(unsigned i = 0; i < loja.size(); i++)
	{
		if( id == loja[i]->getId())
		{
			cout << "		 ------------------------\n";
			cout << "		| Funcionario Encontrado |\n";
			cout << " 		 ------------------------\n\n";
			cout << setw(20) << left << "ID:" 				  << "\t" << loja[i]->getId() << endl;
	        cout << setw(20) << left << "Nome:"  			  << "\t" << loja[i]->getNome() << endl;
	        cout << setw(20) << left << "CPF:" 				  << "\t" << loja[i]->getCPF() << endl;
	        cout << setw(20) << left << "Data de Contratacao:"<< "\t" << loja[i]->getDataContratacao() << endl;
	        cout << setw(20) << left << "Salario:" 			  << "\t" << loja[i]->getSalario() << endl;
			cout << setw(20) << left << "Tipo Sanguineo:"     << "\t" << loja[i]->getTipo_Sanguineo() << endl;
			cout << setw(20) << left << "FatorRH:" 			  << "\t" << loja[i]->getFatorRH() << endl;
			cout << setw(20) << left << "Idade:" 			  << "\t" << loja[i]->getIdade() << endl;
			cout << setw(20) << left << "Especialidade:"      << "\t" << loja[i]->getEspecialidade() << endl;
			cout << setw(20) << left <<  "-----------------------------" << endl;  
			
			loja.erase(loja.begin()+i);
			atualizarDados();
			salvarDados();
			
			/* remove funcionario encontrado na posicao i */	
			cout << setw(20) << left <<  "Funcionario removido com sucesso" << endl;  
			break;

		}
	}
}

/** Funcao que busca funcionarios pelo nome */
void CadastroFuncionarios::buscaNome(std::string nome)
{
	for(unsigned i = 0; i < loja.size(); i++)
	{
		if( nome == loja[i]->getNome())
		{
			cout << "		 ------------------------\n";
			cout << "		| Funcionario Encontrado |\n";
			cout << " 		 ------------------------\n\n";
			cout << setw(20) << left << "ID:" 				  << "\t" << loja[i]->getId() << endl;
	        cout << setw(20) << left << "Nome:"  			  << "\t" << loja[i]->getNome() << endl;
	        cout << setw(20) << left << "CPF:" 				  << "\t" << loja[i]->getCPF() << endl;
	        cout << setw(20) << left << "Data de Contratacao:"<< "\t" << loja[i]->getDataContratacao() << endl;
	        cout << setw(20) << left << "Salario:" 			  << "\t" << loja[i]->getSalario() << endl;
			cout << setw(20) << left << "Tipo Sanguineo:"     << "\t" << loja[i]->getTipo_Sanguineo() << endl;
			cout << setw(20) << left << "FatorRH:" 			  << "\t" << loja[i]->getFatorRH() << endl;
			cout << setw(20) << left << "Idade:" 			  << "\t" << loja[i]->getIdade() << endl;
			cout << setw(20) << left << "Especialidade:"      << "\t" << loja[i]->getEspecialidade() << endl;
			cout << setw(20) << left <<  "-----------------------------" << endl;  
			
			loja.erase(loja.begin()+i);
			atualizarDados();
			salvarDados();			

			/* remove funcionario encontrado na posicao i */			
			cout << setw(20) << left <<  "Funcionario removido com sucesso" << endl;  			
			break;
		}
	}
}
