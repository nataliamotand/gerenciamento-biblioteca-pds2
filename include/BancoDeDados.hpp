#ifndef BANCODEDADOS_HPP
#define BANCODEDADOS_HPP

#include "Usuario.hpp"
#include "Administrador.hpp"

#include <vector>
#include <string>
#include <iostream>


class BancoDeDados {
    private:
        std::vector<Usuario*> usuarios;



    public:
        BancoDeDados();

        std::vector<Usuario*> getUsuarios();

        bool adicionarUsuario(std::string nome, std::string email, std::string senha,
                std::string curso, std::string idEstudantil);
        bool atualizarUsuario(std::string nome, std::string email, std::string senha,
                std::string curso, std::string idEstudantil);
        bool removerUsuario(std::string email);
        void imprimeTodosUsuarios();

        bool loginAdministrador(std::string email, std::string senha);


        ~BancoDeDados();
};

#endif
