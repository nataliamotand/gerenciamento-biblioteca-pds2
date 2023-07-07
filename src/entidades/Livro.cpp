#include "Livro.hpp"

Livro::Livro() {
    this->titulo = "";
    this->genero = "";
    this->autor = "";
    this->numCopias = 0;
    this->disponibilidade = false;
    this->defeito = "";
    this->codigo = "";
    this->endereco = "";
}

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

std::string Livro::getTitulo() const{
    return this->titulo;
}

bool Livro::operator<(const Livro& other) const {
    return this->titulo < other.titulo;
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

Data Livro::getDataDevolucao() {
    return this->dataDevolucao;
}

Data Livro::getDataEmprestimo(){
    return this->dataEmprestimo;
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

void Livro::setDataDevolucao(Data dataDevolucao){
    this->dataDevolucao = dataDevolucao;
}
void Livro::setDataEmprestimo(Data dataEmprestimo){
    this->dataEmprestimo = dataEmprestimo;
}

void Livro::emprestarLivro() {
    this->numCopias--;
    this->disponibilidade = false;
}

void Livro::devolverLivro() {
    this->numCopias++;
    this->disponibilidade = true;
}
