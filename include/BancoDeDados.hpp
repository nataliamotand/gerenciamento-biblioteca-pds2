#ifndef BANCODEDADOS_HPP
#define BANCODEDADOS_HPP


#include "Usuario.hpp"
#include "Administrador.hpp"
#include "CatalogoLivros.hpp"
#include "Data.hpp"

#include <vector>
#include <string>
#include <iostream>


class BancoDeDados {
    private:
        /**
         * Vetor de usuarios do banco de dados
         */
        std::vector<Usuario*> usuarios;

        /**
         * Catalogo de livros do banco de dados
         */
        CatalogoLivros catalogoLivros;

        /**
         * Data atual do banco de dados
         */
        Data dataAtual;

    public:
        /**
        * Construtor da classe BancoDeDados
        */
        BancoDeDados();

        /**
        * Retorna o vetor de usuarios salvos no banco de dados
        * @return vetor de usuarios
        */
        std::vector<Usuario*> getUsuarios();

        /**
        * Adiciona um usuario ao vetor de usuarios do banco de dados
        * @param nome nome do usuario
        * @param email email do usuario
        * @param senha senha do usuario
        * @param curso curso do usuario
        * @param idEstudantil id estudantil do usuario
        * @return true se o usuario foi adicionado com sucesso, false caso contrario
        */
        bool adicionarUsuario(std::string nome, std::string email, std::string senha,
                std::string curso, std::string idEstudantil);

        /**
         * Atualiza os dados de um usuario
         * @param nome nome do usuario
         * @param email email do usuario
         * @param senha senha do usuario
         * @param curso curso do usuario
         * @param idEstudantil id estudantil do usuario
         * @return true se o usuario foi atualizado com sucesso, false caso contrario
         */
        bool atualizarUsuario(std::string nome, std::string email, std::string senha,
                std::string curso, std::string idEstudantil);

        /**
         * Remove um usuario do vetor de usuarios do banco de dados
         * @param email email do usuario
         * @return true se o usuario foi removido com sucesso, false caso contrario
         */
        bool removerUsuario(std::string email);

        /**
         * Imprime todos os usuarios do banco de dados
         */
        void imprimeTodosUsuarios();

        /**
         * Verifica os dados de login de um administrador
         * @param email email do administrador
         * @param senha senha do administrador
         * @return true se os dados de login estiverem corretos, false caso contrario
         */
        bool loginAdministrador(std::string email, std::string senha);

        /**
         * Verifica os dados de login de um usuario
         * @param email email do usuario
         * @param senha senha do usuario
         * @return true se os dados de login estiverem corretos, false caso contrario
         */
        bool loginUsuario(std::string email, std::string senha);

        /**
         * Pesquisa por um livro no catalogo de livros
         * @param titulo titulo do livro
         * @return livro encontrado
        */
        Livro pesquisarLivro(std::string titulo);

        /**
         * Adiciona um livro ao catalogo de livros
         * @param titulo titulo do livro
         * @param genero genero do livro
         * @param autor autor do livro
         * @param numCopias numero de copias do livro
         * @return true se o livro foi adicionado com sucesso, false caso contrario
         */
        bool adicionarLivro(std::string titulo, std::string genero, std::string autor, int numCopias);

        /**
         * Imprime todos os livros do catalogo de livros
         */
        void imprimeTodosLivros();

        /**
         * Remove um livro do catalogo de livros
         * @param titulo titulo do livro
         * @param autor autor do livro
         * @return true se o livro foi removido com sucesso, false caso contrario
         */
        bool removerLivro(std::string titulo, std::string autor);

        /**
         * Edita os dados de um livro
         * @param titulo titulo do livro
         * @param genero genero do livro
         * @param autor autor do livro
         * @param numCopias numero de copias do livro
         * @param defeito defeito do livro
         * @param endereco endereco do livro
         * @return true se o livro foi editado com sucesso, false caso contrario
         */
        bool editarLivro(std::string titulo, std::string genero, std::string autor, int numCopias,
                        std::string defeito, std::string endereco);

        /**
         * Verifica se um livro esta disponivel para emprestimo. Se estiver, o livro e emprestado
         * @param titulo titulo do livro
         * @param autor autor do livro
         * @param email email do usuario
         * @return true se o livro foi emprestado com sucesso, false caso contrario
         */
        bool emprestarLivro(std::string titulo, std::string autor, std::string email);

        /**
         * Imprime todos os livros emprestados de todos os usuarios
         * @param email email do usuario
         * @return vetor de mapas de livros emprestados
         */
        std::vector<std::map<Livro, std::map<Data, Data>>> visualizarLivrosEmprestados(std::string email);

        /**
         * Faz a renovacao de um livro emprestado
         * @param titulo titulo do livro
         * @param email email do usuario
         * @return true se o livro foi renovado com sucesso, false caso contrario
         */
        bool renovarLivro(std::string titulo, std::string email);

        /**
         * Verifica se usuario pode pegar um livro emprestado
         * @param email email do usuario
         * @return true se o usuario pode pegar um livro emprestado, false caso contrario
         */
        bool usuarioPodePegarLivroEmprestado(std::string email);

        /**
         * Imprime o histórico de atividades dos usuarios para todos usuarios com alguma multa
         * ou algum livro emprestado
         */
        void imprimeHistoricoAtividadeUsuarios();

        /**
         * Imprime o relatório de usuários com livros atrasados
         */
        void imprimeRelatorioUsuariosComLivrosAtrasados();

        /**
         * Imprime o relatório de estatisticas de demanda de livros ao longo dos meses
         */
        void imprimeRelatorioEstatisticoDemanda();

        /*
        * Destrutor da classe BancoDeDados
        */
        ~BancoDeDados();
};

#endif