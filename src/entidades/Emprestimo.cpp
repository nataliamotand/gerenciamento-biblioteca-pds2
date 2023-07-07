#include "Emprestimo.hpp"

Emprestimo::Emprestimo(){}

void Emprestimo::adicionarLivro(Livro livro, Data dataEmprestimo){
    std::map<Livro, std::map<Data, Data>> livroData;
    livroData[livro] = std::map<Data, Data>();
    livroData[livro][dataEmprestimo] = calcularDataDevolucao(dataEmprestimo);
    this->livros.push_back(livroData);
}

int Emprestimo::getDiasPadraoEmprestimo(){
    return this->diasPadraoEmprestimo;
}

int Emprestimo::getMaximoLivrosEmprestados(){
    return this->maximoLivrosEmprestados;
}

Data Emprestimo::calcularDataDevolucao(Data dataEmprestimo){
    Data dataDevolucao = dataDevolucao.adicionarDias(dataEmprestimo, this->diasPadraoEmprestimo);
    return dataDevolucao;
}

std::vector<std::map<Livro, std::map<Data, Data>>> Emprestimo::getLivros(){
    return this->livros;
}

bool Emprestimo::renovarLivro(std::string titulo, Data dataAtual){
    for (std::vector<std::map<Livro, std::map<Data, Data>>>::size_type i = 0; i < this->livros.size(); i++){
        for (auto it = this->livros[i].begin(); it != this->livros[i].end(); it++){
            if (it->first.getTitulo() == titulo){
                it->second.begin()->second = calcularDataDevolucao(dataAtual);
                return true;
            }
        }
    }
    return false;
}

bool Emprestimo::podePegarLivroEmprestado(){
    return static_cast<int>(this->livros.size()) < this->maximoLivrosEmprestados;
}
