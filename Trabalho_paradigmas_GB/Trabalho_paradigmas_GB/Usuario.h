#pragma once
#include <string>
using namespace std;

// classe base abstrata — todo usuario tem nome e id
// nao da pra instanciar direto, tem que usar Aluno ou Professor
class Usuario {
protected:
    string nome;
    int id;

public:
    Usuario(const string& nome, int id);
    virtual ~Usuario() = default;

    // cada subclasse implementa do seu jeito
    virtual void exibirTipoUsuario() const = 0;

    string getNome() const;
    int         getId()   const;
};
