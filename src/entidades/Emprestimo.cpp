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

Data Emprestimo::calcularDataDevolucao(Data dataEmprestimo){
    Data dataDevolucao = dataDevolucao.adicionarDias(dataEmprestimo, this->diasPadraoEmprestimo);
    return dataDevolucao;
}

std::vector<std::map<Livro, std::map<Data, Data>>> Emprestimo::getLivros(){
    return this->livros;
}
