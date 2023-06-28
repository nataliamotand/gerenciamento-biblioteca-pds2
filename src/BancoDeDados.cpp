#include "BancoDeDados.hpp"

bool BancoDeDados::adicionarUsuario(Usuario usuario) {
    this->usuarios.push_back(usuario);
    return true;
}
