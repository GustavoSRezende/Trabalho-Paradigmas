#pragma once
#include "Usuario.h"
using namespace std;

// professor herda de usuario e adiciona o departamento
class Professor : public Usuario {
private:
    string departamento;

public:
    Professor(const string& nome, int id, const string& departamento);

    void exibirTipoUsuario() const override;
    string getDepartamento() const;
};
