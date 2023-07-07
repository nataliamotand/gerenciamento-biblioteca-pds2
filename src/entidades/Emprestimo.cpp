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

void Emprestimo::calcularMulta(Data dataAtual){
    // calcula multa de acordo com livros atrasados
    for (std::vector<std::map<Livro, std::map<Data, Data>>>::size_type i = 0; i < this->livros.size(); i++){
        for (auto it = this->livros[i].begin(); it != this->livros[i].end(); it++){
            if (it->second.begin()->second < dataAtual){
                int diasAtrasados = dataAtual.calcularDiferenca(it->second.begin()->second);
                float multa = diasAtrasados * this->multaPorDia;

                std::map<Livro, int> livroDiasAtrasados;
                livroDiasAtrasados[it->first] = diasAtrasados;
                this->diasAtrasados.push_back(livroDiasAtrasados);
                std::map<Livro, float> livroMulta;
                livroMulta[it->first] = multa;
                this->multa.push_back(livroMulta);
            }
        }
    }
}

float Emprestimo::getMulta(){
    // checa todas multas e retorna a soma delas
    float multa = 0;
    for (auto livroMulta : this->multa){
        for (auto it = livroMulta.begin(); it != livroMulta.end(); it++){
            multa += it->second;
        }
    }
    return multa;
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
