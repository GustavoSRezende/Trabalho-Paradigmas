#include "Livro.h"
#include <iostream>

Livro::Livro(const std::string& titulo, const std::string& autor, const std::string& isbn)
    : titulo(titulo), autor(autor), isbn(isbn), disponivel(true) {}

bool Livro::emprestar() {
    if (disponivel) {
        disponivel = false;
        std::cout << "Livro emprestado com sucesso!\n";
        return true;
    }
    // se cair aqui, o livro ja ta com alguem
    std::cout << "Erro: o livro \"" << titulo << "\" nao esta disponivel.\n";
    return false;
}

void Livro::devolver() {
    if (!disponivel) {
        disponivel = true;
        std::cout << "Livro \"" << titulo << "\" devolvido! Disponibilidade atualizada.\n";
    } else {
        // so pra evitar bug se chamar devolver duas vezes
        std::cout << "Aviso: o livro \"" << titulo << "\" ja estava disponivel.\n";
    }
}

void Livro::exibirInformacoes() const {
    std::cout << "  Titulo : " << titulo << "\n"
              << "  Autor  : " << autor  << "\n"
              << "  ISBN   : " << isbn   << "\n"
              << "  Status : " << (disponivel ? "Disponivel" : "Emprestado") << "\n";
}

std::string Livro::getTitulo()    const { return titulo; }
bool        Livro::isDisponivel() const { return disponivel; }
