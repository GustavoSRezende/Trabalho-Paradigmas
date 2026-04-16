#pragma once
#include "Usuario.h"
using namespace std;

class Aluno : public Usuario {
private:
    string curso;

public:
    Aluno(const string& nome, int id, const string& curso);

    void exibirTipoUsuario() const override;
    string getCurso() const;
};
