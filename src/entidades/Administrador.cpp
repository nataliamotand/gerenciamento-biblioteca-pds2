#include "Administrador.hpp"

std::string Administrador::getNome() {
    return this->nome;
}

std::string Administrador::getEmail() {
    return this->email;
}

std::string Administrador::getSenha() {
    return this->senha;
}


void Administrador::setNome(std::string nome) {
    this->nome = nome;
}

void Administrador::setEmail(std::string email) {
    this->email = email;
}

void Administrador::setSenha(std::string senha) {
    this->senha = senha;
}

bool Administrador::login(std::string email, std::string senha) {
    if (this->email == email && this->senha == senha) {
        return true;
    }
    return false;
}

void cadastrarUsuario(std::string nome, std::string email, std::string senha, std::string curso, std::string idEstudantil) {
    Usuario usuario = Usuario(nome, email, senha, curso, idEstudantil);
    usuarios.push_back(usuario);
}
