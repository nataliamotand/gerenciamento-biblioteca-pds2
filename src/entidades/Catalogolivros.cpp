#include "CatalogoLivros.hpp"

CatalogoLivros::CatalogoLivros() {
    Livro livrosIniciais[11] = {
        Livro("O Pequeno Príncipe", "Infantil", "Antoine de Saint-Exupéry", 1, true, "", "0011", "B1"),
        Livro("A Menina que Roubava Livros", "Drama", "Markus Zusak", 1, true, "", "0012", "C1"),
        Livro("O Senhor dos Anéis", "Fantasia", "J. R. R. Tolkien", 1, true, "", "0001", "A1"),
        Livro("O Hobbit", "Fantasia", "J. R. R. Tolkien", 1, true, "", "0002", "A2"),
        Livro("A Grande Caçada", "Fantasia", "Robert Jordan", 1, true, "", "0010", "A10"),
        Livro("O Nome do Vento", "Fantasia", "Patrick Rothfuss", 1, true, "", "0004", "A4"),
        Livro("O Temor do Sábio", "Fantasia", "Patrick Rothfuss", 1, true, "", "0005", "A5"),
        Livro("O Aprendiz de Assassino", "Fantasia", "Robin Hobb", 1, true, "", "0006", "A6"),
        Livro("O Punhal do Soberano", "Fantasia", "Robin Hobb", 1, true, "", "0007", "A7"),
        Livro("O Assassino do Rei", "Fantasia", "Robin Hobb", 1, true, "", "0008", "A8"),
        Livro("O Dragão Renascido", "Fantasia", "Robert Jordan", 1, true, "", "0009", "A9")
    };

    for (int i = 0; i < 11; i++) {
        this->livros.push_back(livrosIniciais[i]);
    }

    this->generos = {"Infantil", "Drama", "Fantasia"};
}


std::vector<Livro> CatalogoLivros::getLivros() {
    return this->livros;
}

std::vector<std::string> CatalogoLivros::getGeneros() {
    return this->generos;
}

void CatalogoLivros::setLivros(std::vector<Livro> livros) {
    this->livros = livros;
}

void CatalogoLivros::setGeneros(std::vector<std::string> generos) {
    this->generos = generos;
}

bool CatalogoLivros::adicionarLivro(std::string titulo, std::string genero, std::string autor, int numCopias) {
    Livro livro;
    livro.setTitulo(titulo);
    livro.setGenero(genero);
    livro.setAutor(autor);
    livro.setNumCopias(numCopias);
    livro.setDisponibilidade(true);
    livro.setCodigo("00" + std::to_string(this->livros.size() + 1));
    livro.setEndereco("A" + std::to_string(this->livros.size() + 1));

    this->livros.push_back(livro);
    return true;
}

bool CatalogoLivros::removerLivro(std::string titulo, std::string autor) {
    std::vector<Livro>::size_type quantidadeLivros = this->livros.size();
    for (std::vector<Livro>::size_type i = 0; i < quantidadeLivros; i++) {
        if (this->livros[i].getTitulo() == titulo && this->livros[i].getAutor() == autor) {
            this->livros.erase(this->livros.begin() + i);
            return true;
        }
    }
    return false;
}

bool CatalogoLivros::editarLivro(std::string titulo, std::string genero, std::string autor,
int numCopias, std::string defeito, std::string endereco) {
    std::vector<Livro>::size_type quantidadeLivros = this->livros.size();
    for (std::vector<Livro>::size_type i = 0; i < quantidadeLivros; i++) {
        if (this->livros[i].getTitulo() == titulo && this->livros[i].getAutor() == autor) {
            this->livros[i].setTitulo(titulo);
            this->livros[i].setGenero(genero);
            this->livros[i].setAutor(autor);
            this->livros[i].setNumCopias(numCopias);

            if(defeito != "")
                this->livros[i].setDefeito(defeito);
            if(endereco != "")
                this->livros[i].setEndereco(endereco);
            return true;
        }
    }
    return false;
}

void CatalogoLivros::adicionarGenero(std::string genero) {
    this->generos.push_back(genero);
}

void CatalogoLivros::removerGenero(std::string genero) {
    std::vector<Livro>::size_type quantidadeGeneros = this->generos.size();
    for (std::vector<std::string>::size_type i = 0; i < quantidadeGeneros; i++) {
        if (this->generos[i] == genero) {
            this->generos.erase(this->generos.begin() + i);
        }
    }
}

void CatalogoLivros::editarGenero(std::string genero, std::string novoGenero) {
    std::vector<Livro>::size_type quantidadeGeneros = this->generos.size();
    for (std::vector<std::string>::size_type i = 0; i < quantidadeGeneros; i++) {
        if (this->generos[i] == genero) {
            this->generos[i] = novoGenero;
        }
    }
}


Livro CatalogoLivros::pesquisarLivro(std::string titulo) {
    Livro livro = Livro();
    std::vector<Livro>::size_type quantidadeLivros = this->livros.size();

    for (std::vector<Livro>::size_type i = 0; i < quantidadeLivros; i++) {
        if (this->livros[i].getTitulo() == titulo) {
            livro = this->livros[i];
            break;
        }
    }

    return livro;
}

bool CatalogoLivros::livroEstaDisponivel(std::string titulo, std::string autor){
    std::vector<Livro>::size_type quantidadeLivros = this->livros.size();

    for (std::vector<Livro>::size_type i = 0; i < quantidadeLivros; i++) {
        if (this->livros[i].getTitulo() == titulo && this->livros[i].getAutor() == autor) {
            return this->livros[i].getDisponibilidade();
        }
    }
    return false;
}

void CatalogoLivros::emprestarLivro(std::string titulo, std::string autor, Data dataAtual){
    std::vector<Livro>::size_type quantidadeLivros = this->livros.size();

    for (std::vector<Livro>::size_type i = 0; i < quantidadeLivros; i++) {
        if (this->livros[i].getTitulo() == titulo && this->livros[i].getAutor() == autor) {
            this->livros[i].setDisponibilidade(false);
            this->livros[i].setNumCopias(this->livros[i].getNumCopias() - 1);
            this->livros[i].setDataDevolucao(dataAtual.adicionarDias(dataAtual, 14));
            this->livros[i].setDataEmprestimo(dataAtual);
        }
    }
}

void CatalogoLivros::imprimeTodosLivros(){
    std::vector<Livro>::size_type quantidadeLivros = this->livros.size();

    for (std::vector<Livro>::size_type i = 0; i < quantidadeLivros; i++) {
        std::cout << "Livro " << i + 1 << std::endl;
        std::cout << "Título: " << this->livros[i].getTitulo() << std::endl;
        std::cout << "Gênero: " << this->livros[i].getGenero() << std::endl;
        std::cout << "Autor: " << this->livros[i].getAutor() << std::endl;
        std::cout << "Código: " << this->livros[i].getCodigo() << std::endl;
        std::cout << "Endereço: " << this->livros[i].getEndereco() << std::endl;
        std::cout << "Disponibilidade: " << this->livros[i].getDisponibilidade() << std::endl;
        std::cout << "Número de cópias: " << this->livros[i].getNumCopias() << std::endl;
        std::cout << "--------------------------" << std::endl;
    }
}