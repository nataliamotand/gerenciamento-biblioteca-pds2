#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <string>
#include <vector>

class Livro {
    private:
        std::string titulo;
        std::string genero;
        std::string autor;
        int numCopias;
        bool disponibilidade;
        std::string defeito;
        std::string codigo;
        std::string endereco;

    public:
        Livro();
        Livro(std::string titulo, std::string genero, std::string autor,
            int numCopias, bool disponibilidade, std::string defeito,
            std::string codigo, std::string endereco);

        std::string getTitulo();
        std::string getGenero();
        std::string getAutor();
        int getNumCopias();
        bool getDisponibilidade();
        std::string getDefeito();
        std::string getCodigo();
        std::string getEndereco();

        void setTitulo(std::string titulo);
        void setGenero(std::string genero);
        void setAutor(std::string autor);
        void setNumCopias(int numCopias);
        void setDisponibilidade(bool disponibilidade);
        void setDefeito(std::string defeito);
        void setCodigo(std::string codigo);
        void setEndereco(std::string endereco);

        void emprestarLivro();
        void devolverLivro();
};

#endif
