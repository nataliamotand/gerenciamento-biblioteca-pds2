#include "Usuario.hpp"

Usuario::Usuario(std::string nome, std::string email, std::string senha,
                std::string curso, std::string idEstudantil) {
    this->nome = nome;
    this->email = email;
    this->senha = senha;
    this->curso = curso;
    this->idEstudantil = idEstudantil;
}

std::string Usuario::getNome() {
    return this->nome;
}

std::string Usuario::getCurso() {
    return this->curso;
}

std::string Usuario::getIdEstudantil() {
    return this->idEstudantil;
}

std::vector<Livro> Usuario::getLivros() {
    return this->livros;
}

int Usuario::getDiasAtraso() {
    return this->diasAtraso;
}

float Usuario::getMulta() {
    return this->multa;
}

std::string Usuario::getLinkPagamento() {
    return this->linkPagamento;
}

void Usuario::setNome(std::string nome) {
    this->nome = nome;
}

void Usuario::setCurso(std::string curso) {
    this->curso = curso;
}

void Usuario::setIdEstudantil(std::string idEstudantil) {
    this->idEstudantil = idEstudantil;
}

void Usuario::setLivros(std::vector<Livro> livros) {
    this->livros = livros;
}

void Usuario::setDiasAtraso(int diasAtraso) {
    this->diasAtraso = diasAtraso;
}

void Usuario::setMulta(float multa) {
    this->multa = multa;
}
