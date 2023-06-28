#ifndef BANCODEDADOS_HPP
#define BANCODEDADOS_HPP

#include "Usuario.hpp"

#include <vector>


class BancoDeDados {
    private:
        std::vector<Usuario> usuarios;

    public:
        BancoDeDados();

        std::vector<Usuario> getUsuarios();

        bool adicionarUsuario(Usuario usuario);
        bool atualizarUsuario(Usuario usuario);
        bool removerUsuario(Usuario usuario);
};

#endif
