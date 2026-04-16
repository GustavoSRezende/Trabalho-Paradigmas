#include "Usuario.h"
using namespace std;

// construtor basico, so passa pra cima nas subclasses
Usuario::Usuario(const string& nome, int id)
    : nome(nome), id(id) {}

string Usuario::getNome() const { return nome; }
int         Usuario::getId()   const { return id; }
