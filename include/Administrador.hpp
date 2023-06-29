#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

// #include "Livro.hpp"
#include "Usuario.hpp"
// #include "Emprestimo.hpp"
#include "BancoDeDados.hpp"

#include <string>

class Administrador {
    private:
        std::string nome = "Biblioteca";
        std::string email = "biblioteca@ufmg.br";
        std::string senha = "1234";

    public:
        std::string getNome();
        std::string getSenha();
        std::string getEmail();

        void setNome(std::string nome);
        void setSenha(std::string senha);
        void setEmail(std::string email);

        bool login(std::string email, std::string senha);
        bool logout();
    
        void cadastrarUsuario(std::string nome, std::string email,
                              std::string senha, std::string curso,
                              std::string idEstudantil);
};

#endif