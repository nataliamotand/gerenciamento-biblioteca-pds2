#include "Livro.hpp"

Livro::Livro(std::string titulo, std::string genero, std::string autor,
    int numCopias, bool disponibilidade, std::string defeito,
    std::string codigo, std::string endereco) {
    this->titulo = titulo;
    this->genero = genero;
    this->autor = autor;
    this->numCopias = numCopias;
    this->disponibilidade = disponibilidade;
    this->defeito = defeito;
    this->codigo = codigo;
    this->endereco = endereco;
}

std::string Livro::getTitulo() {
    return this->titulo;
}

std::string Livro::getGenero() {
    return this->genero;
}

std::string Livro::getAutor() {
    return this->autor;
}

int Livro::getNumCopias() {
    return this->numCopias;
}

bool Livro::getDisponibilidade() {
    return this->disponibilidade;
}

std::string Livro::getDefeito() {
    return this->defeito;
}

std::string Livro::getCodigo() {
    return this->codigo;
}

std::string Livro::getEndereco() {
    return this->endereco;
}


void Livro::setTitulo(std::string titulo) {
    this->titulo = titulo;
}

void Livro::setGenero(std::string genero) {
    this->genero = genero;
}

void Livro::setAutor(std::string autor) {
    this->autor = autor;
}

void Livro::setNumCopias(int numCopias) {
    this->numCopias = numCopias;
}

void Livro::setDisponibilidade(bool disponibilidade) {
    this->disponibilidade = disponibilidade;
}

void Livro::setDefeito(std::string defeito) {
    this->defeito = defeito;
}

void Livro::setCodigo(std::string codigo) {
    this->codigo = codigo;
}

void Livro::setEndereco(std::string endereco) {
    this->endereco = endereco;
}

// Fazer lógica para verificar disponibilidade do livro
void Livro::emprestarLivro() {
    this->numCopias--;
}

void Livro::devolverLivro() {
    this->numCopias++;
}
