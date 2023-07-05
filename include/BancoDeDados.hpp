
#ifndef BANCODEDADOS_HPP
#define BANCODEDADOS_HPP

#include "Usuario.hpp"
#include "Administrador.hpp"
#include "CatalogoLivros.hpp"

#include <vector>
#include <string>
#include <iostream>


class BancoDeDados {
    private:
        std::vector<Usuario*> usuarios;

        CatalogoLivros catalogoLivros;

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
        bool loginUsuario(std::string email, std::string senha);
        Livro pesquisarLivro(std::string titulo);
        bool adicionarLivro(std::string titulo, std::string genero, std::string autor, int numCopias);
        void imprimeTodosLivros();
        bool removerLivro(std::string titulo, std::string autor);
        bool editarLivro(std::string titulo, std::string genero, std::string autor, int numCopias,
                        std::string defeito, std::string endereco);
        ~BancoDeDados();
};

#endif
