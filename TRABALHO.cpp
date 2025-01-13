#include <iostream>
#include <vector>

using namespace std;

class ItemBiblioteca {
protected:
    int id_, ano_;
    string titulo_;
    bool emprestado_;

public:
	ItemBiblioteca(int id, string titulo, int ano);

    virtual void exibirDetalhes();
    int getId();
    bool isEmprestado();
    void emprestar();
    void devolver();
};

class Livro : public ItemBiblioteca {
protected:
	string autor_;
	string genero_;

public:
    Livro(int id, string titulo, int ano, string autor, string genero);
    void exibirDetalhes() override;
};

class Usuario {
protected:
    int id_, limiteEmprestimos_, emprestimosAtuais_;
    string nome_;

public:
    Usuario(int id, string nome, int limiteEmprestimos);

    virtual void exibirUsuario();

    bool podeEmprestar();
    void realizarEmprestimo(); //incrementar emprestimos atuais ++1
    void realizarDevolucao(); //incrementar emprestimos atuais --1
    int getId();
};

class Aluno : public Usuario {
public:
    Aluno(int id, string nome);
};

class Professor : public Usuario {
public:
    Professor(int id, string nome);
};

class Biblioteca {
    vector<Livro> livros;
    vector<Aluno> alunos;
    vector<Professor> professores;

public:
    void adicionarLivro();
    void listarLivros();
    void adicionarUsuario(){
    	
    	string tipo, nome;
    	int id;
    	
    	cout << "Tipo (Aluno/Professor): ";
    	cin >> tipo;
    	
    	if (tipo == "Aluno"){
    		alunos.push_back(Aluno(1, "Lara")); // pedir os dados aqui dentro para criar objeto, cria todos os cadastros assim
		}
    	
	}
    void listarUsuarios();
    void emprestarLivro();
    void devolverLivro();
    void menu();
};

int main() {
	int escolha;

	while (true){
	cout << "---------Sistema de Biblioteca---------" << endl;
	cout << "1. Adicionar Livro" << endl;
	cout << "2. Listar Livros" << endl;
	cout << "3. Adicionar usuário" << endl;
	cout << "4. Listar Usuários" << endl;
	cout << "5. Emprestar Livro" << endl;
	cout << "6. Devolver Livro" << endl;
	cout << "0. Sair" << endl;
	cout << "Escolha uma opção: ";
	cin >> escolha;

  	switch(escolha){
			case 0:
			cout << "Você saiu do programa.";
			break;

			case 1:
			cout << "Adicionar Livro" << enld;
			break;

			case 2:
			cout << "Listar Livros" << enld;
			break;

			case 3:
			cout << "Adicionar usuário" << endl;
			break;

			case 4:
			cout << "Listar Usuários" << endl;
			break;

			case 5:
			cout << "Emprestar Livro" << endl;
			break;

			case 6:
			cout << "Devolver Livro" << endl;
			break;

			default:
			cout << "Numero invalido!";
			break;
	}
}
    return 0;
}

ItemBiblioteca::ItemBiblioteca (int id, string titulo, int ano):
	id_(id), ano_(ano), titulo_(titulo), emprestado_(false){}
	
Livro::Livro (int id, string titulo, int ano, string autor, string genero):
	ItemBiblioteca (id, titulo, ano), autor_(autor), genero_(genero){}

Usuario::Usuario(int id, string nome, int limiteEmprestimos):
	id_(id), nome_(nome), limiteEmprestimos_(limiteEmprestimos){}

Aluno::Aluno(int id, string nome):
	Usuario(id, nome, 3){}
		
Professor::Professor (int id, string nome):
	Usuario (id, nome, 5){}

