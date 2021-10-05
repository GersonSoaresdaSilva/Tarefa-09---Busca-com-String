/*Faça o código fonte estruturado de algoritmo que contenha uma estrutura (STRUCT) chamada CLIENTE criada para armazenar até 10 elementos, com os atributos NOME, SALÁRIO e TELEFONE. O programa será comandado por um menu com select case com as seguintes opções: no Case 1 Ler Dados, case 2 Listar Registros, case 3 classificar por nome, case 4 busca sequencial por NOME, case 5 busca binária por nome e case 6 sair*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#define max 10  //definir tamanho da estrutura de armazenamento

using namespace std;
//criar STRUCT
typedef struct CLIENTE cli; //cli é o alias p/ struct CLIENTE
struct CLIENTE {
  int topo;
  string nome [max];
  double salario [max];
  int telefone [max];
};
cli c; //c é o tipo de struct p/ alias cli

//subrotinas
string ler_nome ();
double ler_salario ();
int ler_telefone ();
void inserir ();
void listar ();
void bubble_sort_nom (); //organizar dados pelo nome
void controle_pesq (); //submenu para controlar pesquisa
void pesq_nome (int item_pesq); //pesquisa por string. A estrutura deve ser organizada antes
int busca_seq_nom (string nom); //busca sequencial por nome
int busca_bin_nom (string nom); //busca binária por nome
bool cheia (); //verifica o limite da estrutura
bool vazia (); //verifica se há registros preenchidos
void controle (); //menu de controle

int main () {
  setlocale(LC_ALL, "Portuguese"); //configurar idioma
  controle (); //função p/ controlar menu
  return 0;
}

string ler_nome () {
  string nome;
  cin.ignore ();
  cout << "\nDigite o nome.....: ";
  getline(cin, nome);
  return nome;
}

double ler_salario () {
  double salario;
  cout << "Digite o salário..: ";
  cin >> salario;
  return salario;
}

int ler_telefone () {
  int telefone;
  while (telefone < 50000000 || telefone > 999999999) {
    cout << "Digite o telefone.: ";
    cin >> telefone;
    if (telefone < 50000000 || telefone > 999999999) {
      cout << "\nERRO: formato de telefone inválido!\n" << endl;
    }
  }
  return telefone;
}

void inserir () {
if (cheia() == true) {
  cout << "\nERRO: Limite de Dados foi atingidos!" << endl;
}
else {
  string aux_nome = ler_nome();
  c.nome [c.topo] = aux_nome;
  c.salario [c.topo] = ler_salario();
  c.telefone [c.topo] = ler_telefone();
  c.topo++;
}
  system ("sleep 4");
}


void listar () {
  if (vazia() == true) {
    cout << "\nERRO: Lista Vazia!" << endl;
  }
  else {
    system ("clear");
    cout << "\n***  Listar Resultados  ***" << endl;
    for (int i = 0; i <= max- 1; i++) {
      cout << "\nPosição [" << i << "]" << endl;
      cout << "Nome.....: " << c.nome [i] << endl;
      cout << "Salario..: " << c.salario [i] << endl;
      cout << "Telefone.: " << c.telefone [i] << endl;
  }
  }
  system ("sleep 4");
}

void bubble_sort_nom () {
    if (vazia() == true) {
    cout << "\nERRO: Lista Vazia!" << endl;
    }
    else {
      string aux_nome;
      int aux_telefone;
      double aux_salario;
      for (int i = 0; i <= max -2; i++) {
        for (int j = i; j <= max -1; j ++) {
          if (c.nome [i] > c.nome [j]) {
            aux_nome = c.nome [i];
            c.nome [i] = c.nome [j];
            c.nome [j] = aux_nome;

            aux_salario = c.salario [i];
            c.salario [i] = c.salario [j];
            c.salario [j] = aux_salario;

            aux_telefone = c.telefone [i];
            c.telefone [i] = c.telefone [j];
            c.telefone [j] = aux_telefone;
          }
        }
      }
    cout << "\nDados organizados com Sucesso!" << endl;  
    } 
  system ("sleep 4");
}

void controle_pesq () {
    if (vazia() == true) {
      cout << "\nERRO: Lista Vazia!" << endl;
    }
    else {
      int item_pesq;
      while (true) {
        system ("clear");
        cout << "\n*** Menu de Pesquisa ***" << endl;
        cout << "\n1 - Pesquisa Sequencial \n2 - Pesquisa Binária \n3 - Retornar \n4 - Sair \nOpção.: ";
        cin >> item_pesq;
      switch (item_pesq) {
        case 1: pesq_nome(item_pesq); break;
        case 2: pesq_nome(item_pesq); break;
        case 3: controle(); break;
        case 4: exit (0); break;
        default: cout << "\nERRO: Opção Inválida!" << endl; system ("sleep 4"); break;
      }
      }
    }
system ("sleep 4");
}

void pesq_nome (int item_pesq) {
  string nome_pesq;
  int busca_nome;

  if (item_pesq == 1) {
    cout << "\n*** Pesquisa Sequencial ***" << endl;
    cin.ignore ();
    cout << "\nDigite o nome.: ";
    getline(cin, nome_pesq);
    busca_nome = busca_seq_nom(nome_pesq);
  }
  else if (item_pesq == 2) {
    cout << "\n*** Pesquisa Binária ***" << endl;
    cin.ignore();
    cout << "\nDigite o nome.: ";
    getline(cin, nome_pesq);
    busca_nome = busca_bin_nom(nome_pesq);
  }

  if (busca_nome == -1) {
    cout << "\nNome pesquisado: " << nome_pesq << ", não foi localizado!" << endl;
  }
  else {
    cout << "\n*** Nome localizado com Sucesso! ***" << endl;
    cout << "\nPosição [" << busca_nome << "]" << endl;
    cout << "Nome.....: " << c.nome [busca_nome] << endl;
    cout << "Salario..: " << c.salario [busca_nome] << endl;
    cout << "Telefone.: " << c.telefone [busca_nome] << endl;
  }
system ("sleep 4");
} 

int busca_seq_nom (string nom) {
  for (int i = 0; i < max; i++) {
    if (nom == c.nome [i]) {
      return i;
    }
  }
  return -1;
}

int busca_bin_nom (string nom) {
  int esq = 0, mei, dir = max;
    for (int i = esq; i <= max; i++) {  
      mei = (esq + dir) / 2;
      if (nom == c.nome [mei]) {
        return mei;
      }
      else if (nom > c.nome [mei]) {
        esq = mei;
      }
      else {
        dir = mei;
      }
    }
return -1;
}

bool cheia () {
  if (c.topo >= max) {
    return true;
  }
  return false;
}

bool vazia () {
  if (c.topo == 0) {
    return true;
  }
  return false;
}

void controle () {
  int item_menu;
  while (true) {
    system ("clear");
    cout << "\n***  Menu de Controle  ***"<< endl;
    cout << "\n1 - Ler Dados \n2 - Listar Registros \n3 - Classificar por Nome \n4 - Busca por Nome \n5 - Sair \nOpção.: ";
    cin >> item_menu;
    switch (item_menu) {
      case 1: inserir(); break;
      case 2: listar (); break;
      case 3: bubble_sort_nom(); break;
      case 4: controle_pesq(); break;
      case 5: exit (0); break;
      default: cout << "\nERRO: Opção Inválida!" << endl; system ("sleep 4"); break;
    }
  }
}