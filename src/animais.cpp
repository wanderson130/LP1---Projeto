#include "animais.hpp"

/** Funcao que e responsavel pelo cadastro dos animais no sistema */
void CadastroAnimal::carregaDado() {

	lista.clear(); // Limpando o vector
	
	fstream myfile("animais.txt");
    
    std::string line, nome;
	int pos, div, tam, conv, i;
	int cont{0};

	if(!myfile)	// Verifica se já existe um arquivo chamado animais.
		return;
	
  	// Faz a contagem do numero de linhas de um aquivo
    while (!myfile.eof()) {
		getline (myfile, line);
		cont++;
  	}
  	cont--;
  	myfile.close();
  	div = cont / 5;
  	
  	myfile.open("animais.txt");

		for (i = 0; i < div ; i++) {
			
			Animal* informacoes = new Animal();

			//--- ID ---
			getline (myfile,line);
			pos =  line.find(":",0);
			tam = pos+1;
			nome = line.substr(tam,pos-tam);
			conv = stoi(nome);
			informacoes->setId(conv);	
		
			//--- CLASSE ---
			getline (myfile,line);
			pos =  line.find(":", 0);
			tam = pos + 1;
			nome = line.substr(tam, pos - tam);
			informacoes->setClasse(nome);			
			
			//--- NOME ---
			getline (myfile,line);
			pos =  line.find(":", 0);
			tam = pos + 1;
			nome = line.substr(tam, pos - tam);
			informacoes->setNome(nome);

			// --- CIENTIFICO ---
			getline (myfile,line);
			pos =  line.find(":",0);
			tam = pos+1;
			nome = line.substr(tam,pos-tam);
			informacoes->setCientifico(nome);
						
			// --- SEXO ---
			getline (myfile,line);
			pos =  line.find(":",0);
			tam = pos+1;
			nome = line.substr(tam,pos-tam);
			conv = stoi(nome);
			informacoes->setSexo(conv);

			//--- TAMANHO ---
			getline (myfile,line);
			pos =  line.find(":",0);
			tam = pos+1;
			nome = line.substr(tam,pos-tam);
			conv = stoi(nome);
			informacoes->setTamanho(conv);

			// --- DIETA ---
			getline (myfile,line);
			pos =  line.find(":",0);
			tam = pos+1;
			nome = line.substr(tam,pos-tam);
			informacoes->setDieta(nome);
			
			// --- BATISMO ---
			getline (myfile,line);
			pos =  line.find(":",0);
			tam = pos+1;
			nome = line.substr(tam,pos-tam);
			informacoes->setBatismo(nome);
		
			lista.push_back(informacoes);
	    }

	myfile.close(); 
}

/** Funcao que e carrega dados armazenados no arquivo.txt dos animais */
void CadastroAnimal::atualizaDado() 
{
	ofstream myfile;
	myfile.open ("animais.txt", ios::out | ios::app | ios::binary);

	for( unsigned i = 0; i < lista.size(); i++ )
	{
	        myfile << "Id:"  				  	<< lista[i]->getId() << endl;
			myfile << "Classe:"  			  	<< lista[i]->getClasse() << endl;
			myfile << "Nome:"  				  	<< lista[i]->getNome() << endl;
			myfile << "Cientifico:"			  	<< lista[i]->getCientifico() << endl;
			myfile << "Sexo:"					<< lista[i]->getSexo() << endl; 
			myfile << "Tamanho:"			  	<< lista[i]->getTamanho() << endl;
			myfile << "Dieta:"  				<< lista[i]->getDieta() << endl;
			myfile << "Batismo:"  			 	<< lista[i]->getBatismo() << endl;
	}
	myfile.close();
}

/** Funcao que salva os dados dos animais em um arquivo.txt */
void CadastroAnimal::salvaDado() 
{
	ofstream myfile ("animais.txt");
	if (myfile.is_open())
	{
		for( unsigned i = 0; i < lista.size(); i++ )
		{
			myfile << "Id:"  				  	<< lista[i]->getId() << endl;
			myfile << "Classe:"  			  	<< lista[i]->getClasse() << endl;
			myfile << "Nome:"  				  	<< lista[i]->getNome() << endl;
			myfile << "Cientifico:"			  	<< lista[i]->getCientifico() << endl;
			myfile << "Sexo:"					<< lista[i]->getSexo() << endl; 
			myfile << "Tamanho:"			  	<< lista[i]->getTamanho() << endl;
			myfile << "Dieta:"  				<< lista[i]->getDieta() << endl;
			myfile << "Batismo:"  			 	<< lista[i]->getBatismo() << endl;
		}
	}
	myfile.close();
}

CadastroAnimal::CadastroAnimal() {
	//ofstream myfile ("animais.txt");

}

/** Funcao que permite a insercao manual de animais no vetor */
void CadastroAnimal::inserirAnimal() {
  	
  	int i, n, quant;
	float k;
	char c;
	cout << "Informe quantos Animais voce quer cadastrar:";
	cin >> quant;
	string nome;
    
    for(i = 0; i < quant; i++)
    {
  		Animal *informacoes = new Animal();
			
    	cout << "Infome o ID do Animal: ";
    	cin >> n;
    	informacoes->setId(n);	
		
		cout << "Informe a Classe: ";
    	cin.ignore();
    	getline(cin, nome);
    	informacoes->setClasse(nome);

    	cout << "Informe o nome do Animal: ";
    	cin.ignore();
    	getline(cin, nome);
    	informacoes->setNome(nome);

		cout << "Informe o nome Cientifico: ";
    	cin.ignore();
    	getline(cin, nome);
    	informacoes->setCientifico(nome);

		cout << "Infome o Sexo do Animal: ";
    	cin >> c;
    	informacoes->setSexo(c);	

		cout << "Infome o Tamanho: ";
    	cin >> k;
    	informacoes->setTamanho(k);			

		cout << "Informe a Dieta: ";
    	cin.ignore();
    	getline(cin, nome);
    	informacoes->setDieta(nome);

		cout << "Informe o nome de Batismo: ";
    	cin.ignore();
    	getline(cin, nome);
    	informacoes->setBatismo(nome);

    	cout << "\n";  	

		lista.push_back(informacoes);
		
	  }
	salvaDado();
}

/** Funcao que imprime vetor de animais */
void CadastroAnimal::imprimeAnimal() {	
	for(unsigned i = 0; i < lista.size(); i++)
		{
			cout << setw(20) << left <<  "ID:"   			 << "\t" << lista[i]->getId() << endl;
			cout << setw(20) << left <<  "Classe:" 			 << "\t" << lista[i]->getClasse() << endl;
			cout << setw(20) << left <<  "Nome:" 			 << "\t" << lista[i]->getNome() << endl;
			cout << setw(20) << left <<  "Cientifico:" 		 << "\t" << lista[i]->getCientifico() << endl;
			cout << setw(20) << left <<  "Sexo:"     		 << "\t" << lista[i]->getSexo() << endl;
			cout << setw(20) << left <<  "Tamanho:" 			 << "\t" << lista[i]->getTamanho() << endl;
			cout << setw(20) << left <<  "Dieta:" 			 << "\t" << lista[i]->getDieta() << endl;
			cout << setw(20) << left <<  "Batismo:" 			 << "\t" << lista[i]->getBatismo() << endl;			
			cout << setw(20) << left <<  "-----------------------------" << endl;  
		}
}

/** Funcao que busca animas pelo numero de id */
void CadastroAnimal::buscaAnimal(int id)
{
	for(unsigned i = 0; i < lista.size(); i++)
	{
		if( id == lista[i]->getId())
		{
			cout << "		 -------------------\n";
			cout << "		| Animal Encontrado |\n";
			cout << " 		 -------------------\n\n";
			cout << setw(20) << left <<  "ID:"   			 << "\t" << lista[i]->getId() << endl;
			cout << setw(20) << left <<  "Classe:" 			 << "\t" << lista[i]->getClasse() << endl;
			cout << setw(20) << left <<  "Nome:" 			 << "\t" << lista[i]->getNome() << endl;
			cout << setw(20) << left <<  "Cientifico:" 		 << "\t" << lista[i]->getCientifico() << endl;
			cout << setw(20) << left <<  "Sexo:"     		 << "\t" << lista[i]->getSexo() << endl;
			cout << setw(20) << left <<  "Tamanho:" 			 << "\t" << lista[i]->getTamanho() << endl;
			cout << setw(20) << left <<  "Dieta:" 			 << "\t" << lista[i]->getDieta() << endl;
			cout << setw(20) << left <<  "Batismo:" 			 << "\t" << lista[i]->getBatismo() << endl;			
			cout << setw(20) << left <<  "-----------------------------" << endl;  
			
			lista.erase(lista.begin()+i);
			atualizaDado();
			salvaDado();
			
			/* remove animal encontrado na posicao i */	
			cout << setw(20) << left <<  "Animal removido com sucesso" << endl;  
			break;

		}
	}
}

/** Funcao que busca animais pelo nome */
void CadastroAnimal::buscaNome(std::string nome)
{
	for(unsigned i = 0; i < lista.size(); i++)
	{
		if( nome == lista[i]->getNome())
		{
			cout << "		 -------------------\n";
			cout << "		| Animal Encontrado |\n";
			cout << " 		 -------------------\n\n";
			cout << setw(20) << left <<  "ID:"   			 << "\t" << lista[i]->getId() << endl;
			cout << setw(20) << left <<  "Classe:" 			 << "\t" << lista[i]->getClasse() << endl;
			cout << setw(20) << left <<  "Nome:" 			 << "\t" << lista[i]->getNome() << endl;
			cout << setw(20) << left <<  "Cientifico:" 		 << "\t" << lista[i]->getCientifico() << endl;
			cout << setw(20) << left <<  "Sexo:"     		 << "\t" << lista[i]->getSexo() << endl;
			cout << setw(20) << left <<  "Tamanho:" 			 << "\t" << lista[i]->getTamanho() << endl;
			cout << setw(20) << left <<  "Dieta:" 			 << "\t" << lista[i]->getDieta() << endl;
			cout << setw(20) << left <<  "Batismo:" 			 << "\t" << lista[i]->getBatismo() << endl;			
			cout << setw(20) << left <<  "-----------------------------" << endl;  
			
			lista.erase(lista.begin()+i);
			atualizaDado();
			salvaDado();			

			/* remove animal encontrado na posicao i */			
			cout << setw(20) << left <<  "Animal removido com sucesso" << endl;  			
			break;
		}
	}
}
