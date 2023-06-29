#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "Livro.hpp"

#include <string>
#include <vector>

class Usuario {
    private:
        std::string nome;
        std::string email;
        std::string senha;
        std::string curso;
        std::string idEstudantil;
        std::vector<Livro> livros;
        int diasAtraso;
        float multa;
        std::string linkPagamento;

    public:
        Usuario(std::string nome, std::string email, std::string senha,
                std::string curso, std::string idEstudantil);

        std::string getNome();
        std::string getCurso();
        std::string getIdEstudantil();
        std::vector<Livro> getLivros();
        int getDiasAtraso();
        float getMulta();
        std::string getLinkPagamento();

        void setNome(std::string nome);
        void setCurso(std::string curso);
        void setIdEstudantil(std::string idEstudantil);
        void setLivros(std::vector<Livro> livros);
        void setDiasAtraso(int diasAtraso);
        void setMulta(float multa);
        void setLinkPagamento(std::string linkPagamento);

        void adicionarLivro(Livro livro);
        void removerLivro(Livro livro);
        void calcularMulta();
        void gerarLinkPagamento();
};

#endif