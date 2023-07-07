#include "Usuario.hpp"

Usuario::Usuario(std::string nome, std::string email, std::string senha,
                std::string curso, std::string idEstudantil)
    : Pessoa(nome, email, senha) {
    this->curso = curso;
    this->idEstudantil = idEstudantil;
    this->multa = 0;
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

void Usuario::calcularMulta(Data dataAtual){
    this->emprestimo.calcularMulta(dataAtual);
    this->multa = this->emprestimo.getMulta();
}

void Usuario::pegarLivroEmprestado(Livro livro, Data dataEmprestimo){
    this->emprestimo.adicionarLivro(livro, dataEmprestimo);
}

std::vector<std::map<Livro, std::map<Data, Data>>> Usuario::getLivrosEmprestados(){
    return this->emprestimo.getLivros();
}

bool Usuario::renovarLivro(std::string titulo, Data dataAtual){
    return this->emprestimo.renovarLivro(titulo, dataAtual);
}

bool Usuario::podePegarLivroEmprestado(){
    return this->emprestimo.podePegarLivroEmprestado();
}

void Usuario::imprimeHistoricoAtividade(){
    std::cout << "Nome: " << this->getNome() << std::endl;
    std::cout << "Livros emprestados: " << std::endl;
    std::vector<std::map<Livro, std::map<Data, Data>>> livros = this->emprestimo.getLivros();
    for (auto livro : livros){
        std::cout << "Titulo: " << livro.begin()->first.getTitulo() << std::endl;
        std::cout << "Data emprestimo: ";
        Data data = livro.begin()->second.begin()->first;
        data.imprimeData();
        std::cout << "Data devolucao: ";
        Data data2 = livro.begin()->second.begin()->second;
        data2.imprimeData();
        std::cout << "-----------------" << std::endl;
    }
    if(this->multa > 0){
        std::cout << "Multas a pagar totalizando: " << this->multa << std::endl;
        std::cout << "--------------------//--------------------" << std::endl;
    }
}

void Usuario::imprimeRelatorioUsuariosComLivrosAtrasados(){
    std::cout << "Nome: " << this->getNome() << std::endl;
    std::cout << "ID Estudantil: " << this->getIdEstudantil() << std::endl;
    std::cout << "Livros atrasados: " << std::endl;
    std::vector<std::map<Livro, std::map<Data, Data>>> livros = this->emprestimo.getLivros();
    for (auto livro : livros){
        std::cout << "Titulo: " << livro.begin()->first.getTitulo() << std::endl;
        std::cout << "Data emprestimo: ";
        Data data = livro.begin()->second.begin()->first;
        data.imprimeData();
        std::cout << "Data devolucao: ";
        Data data2 = livro.begin()->second.begin()->second;
        data2.imprimeData();
        std::cout << "-----------------" << std::endl;
    }

    std::cout << "Multas a pagar totalizando: " << this->multa << std::endl;
    std::cout << "--------------------//--------------------" << std::endl;
}