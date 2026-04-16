#include "Professor.h"
#include <iostream>
using namespace std;

Professor::Professor(const string& nome, int id, const string& departamento)
    : Usuario(nome, id), departamento(departamento) {}

void Professor::exibirTipoUsuario() const {
    cout << "  Usuario      : " << nome         << " (Professor)\n"
              << "  ID           : " << id           << "\n"
              << "  Departamento : " << departamento << "\n";
}

string Professor::getDepartamento() const { return departamento; }
