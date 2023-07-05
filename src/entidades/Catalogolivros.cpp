#include "CatalogoLivros.hpp"

CatalogoLivros::CatalogoLivros() {
    Livro livrosIniciais[11] = {
        Livro("O Pequeno Príncipe", "Infantil", "Antoine de Saint-Exupéry", 10, true, "", "0011", "B1"),
        Livro("A Menina que Roubava Livros", "Drama", "Markus Zusak", 9, true, "", "0012", "C1"),
        Livro("O Senhor dos Anéis", "Fantasia", "J. R. R. Tolkien", 9, true, "", "0001", "A1"),
        Livro("O Hobbit", "Fantasia", "J. R. R. Tolkien", 10, true, "", "0002", "A2"),
        Livro("A Grande Caçada", "Fantasia", "Robert Jordan", 6, true, "", "0010", "A10"),
        Livro("O Nome do Vento", "Fantasia", "Patrick Rothfuss", 5, true, "", "0004", "A4"),
        Livro("O Temor do Sábio", "Fantasia", "Patrick Rothfuss", 6, true, "", "0005", "A5"),
        Livro("O Aprendiz de Assassino", "Fantasia", "Robin Hobb", 3, true, "", "0006", "A6"),
        Livro("O Punhal do Soberano", "Fantasia", "Robin Hobb", 4, true, "", "0007", "A7"),
        Livro("O Assassino do Rei", "Fantasia", "Robin Hobb", 1, true, "", "0008", "A8"),
        Livro("O Dragão Renascido", "Fantasia", "Robert Jordan", 2, true, "", "0009", "A9")
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

void CatalogoLivros::adicionarLivro(Livro livro) {
    this->livros.push_back(livro);
}

void CatalogoLivros::removerLivro(Livro livro) {
    std::vector<Livro>::size_type quantidadeLivros = this->livros.size();
    for (std::vector<Livro>::size_type i = 0; i < quantidadeLivros; i++) {
        if (this->livros[i].getCodigo() == livro.getCodigo()) {
            this->livros.erase(this->livros.begin() + i);
        }
    }
}

void CatalogoLivros::editarLivro(Livro livro) {
    std::vector<Livro>::size_type quantidadeLivros = this->livros.size();
    for (std::vector<Livro>::size_type i = 0; i < quantidadeLivros; i++) {
        if (this->livros[i].getCodigo() == livro.getCodigo()) {
            this->livros[i] = livro;
        }
    }
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

void CatalogoLivros::editarGenero(std::string genero) {
    std::vector<Livro>::size_type quantidadeGeneros = this->generos.size();
    for (std::vector<std::string>::size_type i = 0; i < quantidadeGeneros; i++) {
        if (this->generos[i] == genero) {
            this->generos[i] = genero;
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
