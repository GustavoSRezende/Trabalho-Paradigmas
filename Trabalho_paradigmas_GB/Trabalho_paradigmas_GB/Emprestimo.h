#pragma once
#include <string>
#include "Livro.h"
#include "Usuario.h"

// emprestimo tem composicao com Livro e Usuario
// ou seja, nao faz sentido existir sem os dois
class Emprestimo {
private:
    Livro&      livro;
    Usuario&    usuario;
    std::string dataEmprestimo;
    std::string dataDevolucao;
    bool        ativo;

    std::string tipoUsuario() const; // helper interno pra saber se e aluno ou professor

public:
    Emprestimo(Livro& livro, Usuario& usuario,
               const std::string& dataEmprestimo,
               const std::string& dataDevolucao);

    bool realizarEmprestimo();
    void realizarDevolucao();
    void exibirResumoEmprestimo() const;
};
