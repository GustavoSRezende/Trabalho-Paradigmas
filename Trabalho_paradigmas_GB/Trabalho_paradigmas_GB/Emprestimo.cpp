#include "Emprestimo.h"
#include "Aluno.h"
#include "Professor.h"
#include <iostream>
using namespace std;

Emprestimo::Emprestimo(Livro& livro, Usuario& usuario,
                       const string& dataEmprestimo,
                       const string& dataDevolucao)
    : livro(livro), usuario(usuario),
      dataEmprestimo(dataEmprestimo),
      dataDevolucao(dataDevolucao),
      ativo(false) {}

bool Emprestimo::realizarEmprestimo() {
    ativo = livro.emprestar();
    return ativo;
}

void Emprestimo::realizarDevolucao() {
    if (ativo) {
        livro.devolver();
        ativo = false;
    } else {
        cout << "Nenhum emprestimo ativo pra esse registro.\n";
    }
}

void Emprestimo::exibirResumoEmprestimo() const {
    cout << "Resumo do Emprestimo:\n"
              << "  Livro             : " << livro.getTitulo()  << "\n"
              << "  Usuario           : " << usuario.getNome()
              << " (" << tipoUsuario() << ")\n"
              << "  Data do Emprestimo: " << dataEmprestimo     << "\n"
              << "  Data de Devolucao : " << dataDevolucao      << "\n"
              << "  Situacao          : " << (ativo ? "Ativo" : "Encerrado") << "\n";
}

string Emprestimo::tipoUsuario() const {
    if (dynamic_cast<const Aluno*>(&usuario))     return "Aluno";
    if (dynamic_cast<const Professor*>(&usuario)) return "Professor";
    return "Usuario";
}
