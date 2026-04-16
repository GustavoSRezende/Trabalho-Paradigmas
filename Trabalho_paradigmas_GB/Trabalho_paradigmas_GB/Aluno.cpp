#include "Aluno.h"
#include <iostream>
using namespace std;

Aluno::Aluno(const string& nome, int id, const string& curso)
    : Usuario(nome, id), curso(curso) {}

void Aluno::exibirTipoUsuario() const {
    cout << "  Usuario : " << nome  << " (Aluno)\n"
              << "  ID      : " << id    << "\n"
              << "  Curso   : " << curso << "\n";
}

string Aluno::getCurso() const { return curso; }
