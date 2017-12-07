#include "../include/includes.hpp"

Animal::Animal()
{
	this->id = 0, this->classe = "", this->nome = "", this->cientifico = "", this->sexo = 0, this->tamanho = 0, this->dieta ="", this->batismo ="";
}

Animal::Animal(int id, string classe, string nome, string cientifico, char sexo, float tamanho, string dieta, string batismo)
{
	this->id = id;
	this->classe = classe;
	this->nome = nome;
	this->cientifico = cientifico;
	this->sexo = sexo;
	this->tamanho = tamanho;
	this->dieta = dieta;
	this->batismo = batismo;	
}

int Animal::getId(){ return this->id;}
void Animal::setId(const int id){ this->id = id;}

string Animal::getClasse(){ return this->classe;}
void Animal::setClasse(const string classe){ this->classe = classe;}

string Animal::getNome(){return this->nome;}
void Animal::setNome( const string nome ) {this->nome = nome;}

string Animal::getCientifico(){ return this->cientifico;}
void Animal::setCientifico( string cientifico){ this->cientifico = cientifico;}

char Animal::getSexo(){return this->sexo;}
void Animal::setSexo( const char sexo ) {this->sexo = sexo;}

float Animal::getTamanho(){ return this->tamanho;}
void Animal::setTamanho(const float tamanho){ this->tamanho = tamanho;}

string Animal::getDieta(){return this->dieta;}
void Animal::setDieta( const string dieta ) {this->dieta = dieta;}

string Animal::getBatismo(){return this->batismo;}
void Animal::setBatismo( const string batismo ) {this->batismo = batismo;}

ostream& operator<<(ostream& out, const Animal* a) {
	a->escrever(out);
	return out;
}

void CadastroAnimal::inserirAnimal()
{
  	int n, quant;
	float valor;
	string nome;
	char ch;	
	
    cout << "Informe quantos produtos deseja cadastrar: ";
    cin >> quant;
    
    for(int i = 0; i < quant; i++) {
    	
      Animal* animal = new Animal();
	
	  cout << "Informe o ID do Animal: ";
	  cin >> n;
      animal->setId(n);

	  cout << "Informe a Classe do Animal: ";
      cin.ignore(0);
      getline(cin, nome);
      animal->setClasse(nome);			

      cout << "Informe o Nome do Animal: ";
      cin.ignore(0);
      getline(cin, nome);
      animal->setNome(nome);		

      cout << "Infome o Nome Cientifico do Animal: ";
      cin.ignore();
      getline(cin, nome);
      animal->setCientifico(nome);
		
	  cout << "Infome o Sexo do Animal: ";
      cin.ignore();
      cin >> ch;
      animal->setSexo(ch);		
	
	  cout << "Informe o Tamanho do Animal: ";
	  cin >> valor;
      animal->setTamanho(valor);

	  cout << "Infome a Dieta do Animal: ";
      cin.ignore();
      getline(cin, nome);
      animal->setDieta(nome);

	  cout << "Infome o Nome de Batismo do Animal: ";
      cin.ignore();
      getline(cin, nome);
      animal->setBatismo(nome);
    	
      cout << "\n--- Animal Cadastrado  ----\n\n";

      cout << animal;

      cout << "\n-----------------------------" << endl;

	  cout << "Pressione Enter para continuar.\n";

	  cin.ignore().get();

	  lista.push_back(animal);
	}

	if(quant > 0)
		this->salvaDado();

}

void CadastroAnimal::salvaDado() {
	ofstream myfile ("./files/animais.txt");

	if (myfile.is_open())
	{
		for( unsigned int i = 0; i < lista.size(); i++ )
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

void CadastroAnimal::carregaDado() {

	lista.clear();

    std::string line, nome;

	char ch;
	int pos;
	int cont =0;
	int div;
	int tam;
	int conv;
	float tamanho;
	int i;

  	fstream myfile("./files/animais.txt");
  	
    while (!myfile.eof()) {
		getline (myfile, line);
		cont++;
  	}

  	cont--;

  	myfile.close();
  	div = cont / 8;
  	
  	myfile.open("./files/animais.txt");
  	
		for (i = 0; i < div ; i++) {
				
			Animal* informacoes = new Animal();
						
			// --- ID --- 
			getline (myfile,line);
			pos =  line.find(":",0);
			tam = pos+1;
			nome = line.substr(tam,pos-tam);
			conv = stoi(nome); //Convertemos o codigo para inteiro
			informacoes->setId(conv);

			// --- CLASSE ---
			getline (myfile,line);
			pos =  line.find(":",0);
			tam = pos+1;
			nome = line.substr(tam,pos-tam);
			informacoes->setClasse(nome);

			// --- NOME ---
			getline (myfile,line);
			pos =  line.find(":",0);
			tam = pos+1;
			nome = line.substr(tam,pos-tam);
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
			informacoes->setSexo(ch);
			
			// --- TAMANHO ---
			getline (myfile,line);
			pos =  line.find(":",0);
			tam = pos+1;
			nome = line.substr(tam,pos-tam);
			tamanho = stof(nome); //Convertemos o valor unitario para float.
			informacoes->setTamanho(tamanho);
			
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
//------------------------------------------------------------------
// Função que retorna o indice onde o produto se encontra
int CadastroAnimal::buscarAnimal(int id) const {
 	for(unsigned int i = 0; i < lista.size(); i++)
 	{	

 		if(lista[i]->getId() == id)
 		{
			return i;  
		}
 	}

 	return -1;
}

void CadastroAnimal::escrever(ostream& out) const {


	cout << "  ---------------------\n";
	cout << " | Animais Registrados :|\n";
	cout << "  ---------------------\n\n";

 	for(unsigned int i = 0; i < lista.size(); i++)
 	{	
	        out << setw(20) << left <<  "ID:"   			 << "\t" << lista[i]->getId() << endl;
			out << setw(20) << left <<  "Classe:" 			 << "\t" << lista[i]->getClasse() << endl;
			out << setw(20) << left <<  "Nome:" 			 << "\t" << lista[i]->getNome() << endl;
			out << setw(20) << left <<  "Cientifico:" 		 << "\t" << lista[i]->getCientifico() << endl;
			out << setw(20) << left <<  "Sexo:"     		 << "\t" << lista[i]->getSexo() << endl;
			out << setw(20) << left <<  "Tamanho:" 			 << "\t" << lista[i]->getTamanho() << endl;
			out << setw(20) << left <<  "Dieta:" 			 << "\t" << lista[i]->getDieta() << endl;
			out << setw(20) << left <<  "Batismo:" 			 << "\t" << lista[i]->getBatismo() << endl;			
			out << setw(20) << left <<  "-----------------------------" << endl;   
 	}
}

ostream& operator<<(ostream& out,const CadastroAnimal& a) 
{
    a.escrever(out);
    return out;
}
