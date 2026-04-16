#pragma once
#include <string>
using namespace std;

// classe que representa um livro do acervo
class Livro {
private:
    string titulo;
    string autor;
    string isbn;
    bool disponivel; // true = ta na prateleira, false = emprestado

public:
    Livro(const string& titulo, const string& autor, const string& isbn);

    bool emprestar();   // tenta emprestar, retorna false se ja estiver fora
    void devolver();    // devolve e marca como disponivel de novo
    void exibirInformacoes() const;

    // getters
    std::string getTitulo()    const;
    bool        isDisponivel() const;
};
