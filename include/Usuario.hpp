

#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "Pessoa.hpp"
#include "Emprestimo.hpp"

#include <string>
#include <vector>

class Usuario : public Pessoa {
    private:
        /**
         * Curso do usuario
         */
        std::string curso;
        /**
         * Id estudantil do usuario
         */
        std::string idEstudantil;
        /**
         * Dias de atraso do usuario
         */
        int diasAtraso;
        /**
         * Multa do usuario
         */
        float multa;
        /**
         * Objeto da classe Emprestimo
         */
        Emprestimo emprestimo = Emprestimo();

    public:
        /**
         * Construtor
         * @param nome nome do usuario
         * @param email email do usuario
         * @param senha senha do usuario
         * @param curso curso do usuario
         * @param idEstudantil id estudantil do usuario
         * @param diasAtraso dias de atraso do usuario
         */
        Usuario(std::string nome, std::string email, std::string senha,
                std::string curso, std::string idEstudantil);

        /**
         * Obtem o curso do usuario
         * @return curso do usuario
         */
        std::string getCurso();

        /**
         * Obtem o id estudantil do usuario
         * @return id estudantil do usuario
         */
        std::string getIdEstudantil();

        /**
         * Obtem os dias de atraso do usuario
         * @return dias de atraso do usuario
         */
        int getDiasAtraso();

        /**
         * Obtem a multa do usuario
         * @return multa do usuario
         */
        float getMulta();

        /**
         * Altera o curso do usuario
         * @param curso novo curso do usuario
         */
        void setCurso(std::string curso);

        /**
         * Altera o id estudantil do usuario
         * @param idEstudantil novo id estudantil do usuario
         */
        void setIdEstudantil(std::string idEstudantil);

        /**
         * Altera os dias de atraso do usuario
         * @param diasAtraso novos dias de atraso do usuario
         */
        void setDiasAtraso(int diasAtraso);

        /**
         * Altera a multa do usuario
         * @param multa nova multa do usuario
         */
        void setMulta(float multa);

        /**
         * Calcula a multa do usuario
         * @param dataAtual data atual
         */
        void calcularMulta(Data dataAtual);

        /**
         * Pega um livro emprestado
         * @param livro livro a ser emprestado
         * @param dataEmprestimo data do emprestimo
         */
        void pegarLivroEmprestado(Livro livro, Data dataEmprestimo);

        /**
         * Obtem os livros emprestados pelo usuario
         * @return livros emprestados pelo usuario
         */
        std::vector<std::map<Livro, std::map<Data, Data>>> getLivrosEmprestados();

        /**
         * Renova um livro
         * @param titulo titulo do livro a ser renovado
         * @param dataAtual data atual
         * @return true se o livro foi renovado, false caso contrario
         */
        bool renovarLivro(std::string titulo, Data dataAtual);

        /**
         * Verifica se o usuario pode pegar um livro emprestado
         * @return true se o usuario pode pegar um livro emprestado, false caso contrario
         */
        bool podePegarLivroEmprestado();

        /**
         * Imprime o historico de atividade do usuario
         */
        void imprimeHistoricoAtividade();

        /**
         * Imprime o relatorio de usuarios com livros atrasados
         */
        void imprimeRelatorioUsuariosComLivrosAtrasados();
};

#endif