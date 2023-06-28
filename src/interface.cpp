#include "Administrador.hpp"

#include <iostream>

Administrador administrador = Administrador();

bool loginAdministrador() {
    std::string email, senha;

    std::cout<<"Digite o seu email: ";
    std::cin>>email;
    std::cout<<"Digite a sua senha: ";
    std::cin>>senha;

    bool retorno = administrador.login(email, senha);
    return retorno;
}

bool cadastrarUsuario() {
    std::string nome, email, senha, curso, idEstudantil;

    std::cout<<"Digite o nome do usuario: ";
    std::cin>>nome;
    std::cout<<"Digite o email do usuario: ";
    std::cin>>email;
    std::cout<<"Digite a senha do usuario: ";
    std::cin>>senha;
    std::cout<<"Digite o curso do usuario: ";
    std::cin>>curso;
    std::cout<<"Digite o idEstudantil do usuario: ";
    std::cin>>idEstudantil;

    bool retorno = administrador.cadastrarUsuario(nome, email, senha, curso, idEstudantil);
    return retorno;
}
