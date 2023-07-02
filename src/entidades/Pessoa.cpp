#include "Pessoa.hpp"

Pessoa::Pessoa(std::string nome, std::string email, std::string senha) {
    this->nome = nome;
    this->email = email;
    this->senha = senha;
}

std::string Pessoa::getNome() {
    return this->nome;
}

std::string Pessoa::getEmail() {
    return this->email;
}

std::string Pessoa::getSenha() {
    return this->senha;
}

void Pessoa::setNome(std::string nome) {
    this->nome = nome;
}

void Pessoa::setEmail(std::string email) {
    this->email = email;
}

void Pessoa::setSenha(std::string senha) {
    this->senha = senha;
}

bool Pessoa::verificarEmail(std::string email) {
    if (this->getEmail() == email) {
        return true;
    }
    return false;
}

bool Pessoa::verificarSenha(std::string senha) {
    if (this->getSenha() == senha) {
        return true;
    }
    return false;
}

bool Pessoa::login(std::string email, std::string senha) {
    if (this->verificarEmail(email) == true && this->verificarSenha(senha) == true) {
        return true;
    }
    return false;
}
