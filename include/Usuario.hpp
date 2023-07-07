

#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "Pessoa.hpp"
#include "Emprestimo.hpp"

#include <string>
#include <vector>

class Usuario : public Pessoa {
    private:
        std::string curso;
        std::string idEstudantil;
        int diasAtraso;
        float multa;

        Emprestimo emprestimo = Emprestimo();

    public:
        Usuario(std::string nome, std::string email, std::string senha,
                std::string curso, std::string idEstudantil);

        std::string getCurso();
        std::string getIdEstudantil();
        int getDiasAtraso();
        float getMulta();

        void setCurso(std::string curso);
        void setIdEstudantil(std::string idEstudantil);
        void setDiasAtraso(int diasAtraso);
        void setMulta(float multa);
        void calcularMulta(Data dataAtual);

        void pegarLivroEmprestado(Livro livro, Data dataEmprestimo);
        std::vector<std::map<Livro, std::map<Data, Data>>> getLivrosEmprestados();
        bool renovarLivro(std::string titulo, Data dataAtual);
        bool podePegarLivroEmprestado();
        void imprimeHistoricoAtividade();
        void imprimeRelatorioUsuariosComLivrosAtrasados();
};

#endif