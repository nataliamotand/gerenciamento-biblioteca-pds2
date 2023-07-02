#include "Usuario.hpp"

Usuario::Usuario(std::string nome, std::string email, std::string senha,
                std::string curso, std::string idEstudantil)
    : Pessoa(nome, email, senha) {
    this->curso = curso;
    this->idEstudantil = idEstudantil;
}


std::string Usuario::getCurso() {
    return this->curso;
}

std::string Usuario::getIdEstudantil() {
    return this->idEstudantil;
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

void Usuario::setCurso(std::string curso) {
    this->curso = curso;
}

void Usuario::setIdEstudantil(std::string idEstudantil) {
    this->idEstudantil = idEstudantil;
}

void Usuario::setDiasAtraso(int diasAtraso) {
    this->diasAtraso = diasAtraso;
}

void Usuario::setMulta(float multa) {
    this->multa = multa;
}

void Usuario::pegarLivroEmprestado(Livro livro, Data dataEmprestimo){
    this->emprestimo.adicionarLivro(livro, dataEmprestimo);
}

std::vector<std::map<Livro, std::map<Data, Data>>> Usuario::getLivrosEmprestados(){
    return this->emprestimo.getLivros();
}