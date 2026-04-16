#include "Aluno.h"
#include "Emprestimo.h"
#include "Livro.h"
#include "Professor.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {

  // --- 1. cadastro de livros ---

  Livro livro1("Introducao a POO", "Grady Booch", "978-85-001");
  Livro livro2("Clean Code", "Robert C. Martin", "978-85-002");
  Livro livro3("The Pragmatic Programmer", "Hunt & Thomas", "978-85-003");

  vector<Livro *> acervo = {&livro1, &livro2, &livro3};
  for (size_t i = 0; i < acervo.size(); i++) {
    cout << "\n[Livro cadastrado]\n";
    acervo[i]->exibirInformacoes();
  }

  // --- 2. cadastro de usuarios ---

  Aluno aluno1("Joao Silva", 101, "Ciencia da Computacao");
  Professor prof1("Dra. Ana Pereira", 201, "Sistemas de Informacao");

  cout << "\n[Aluno cadastrado]\n";
  aluno1.exibirTipoUsuario();

  cout << "\n[Professor cadastrado]\n";
  prof1.exibirTipoUsuario();

  // --- 3. emprestimos ---

  Emprestimo emp1(livro1, aluno1, "10/04/2026", "24/04/2026");
  Emprestimo emp2(livro2, prof1, "10/04/2026", "24/04/2026");

  cout << "\n[Emprestimo - Joao Silva -> \"Introducao a POO\"]\n";
  emp1.realizarEmprestimo();

  cout << "\n[Emprestimo - Dra. Ana Pereira -> \"Clean Code\"]\n";
  emp2.realizarEmprestimo();

  // testa o caso de tentar pegar um livro que ja ta emprestado
  cout << "\n[Tentativa de emprestimo duplicado - livro ja emprestado]\n";
  Emprestimo empDup(livro1, prof1, "10/04/2026", "24/04/2026");
  empDup.realizarEmprestimo();

  // --- 4. exibicao dos dados ---

  cout << "\n--- Emprestimo 1 ---\n";
  emp1.exibirResumoEmprestimo();

  cout << "\n--- Emprestimo 2 ---\n";
  emp2.exibirResumoEmprestimo();

  // --- 5. devolucao ---

  cout << "\n[Devolucao - Joao Silva devolve \"Introducao a POO\"]\n";
  emp1.realizarDevolucao();

  // confirma que voltou pra disponivel
  cout << "\n[Status atualizado do livro]\n";
  livro1.exibirInformacoes();

  // agora consegue emprestar de novo
  cout << "\n[Novo emprestimo do mesmo livro apos devolucao]\n";
  Emprestimo emp3(livro1, prof1, "14/04/2026", "28/04/2026");
  emp3.realizarEmprestimo();

  cout << "\n--- Emprestimo 3 ---\n";
  emp3.exibirResumoEmprestimo();

  return 0;
}
