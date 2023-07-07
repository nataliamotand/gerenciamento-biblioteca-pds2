#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

class Pessoa {
    private:
        /**
         * Nome da pessoa
         */
        std::string nome;
        /**
         * Email da pessoa
         */
        std::string email;
        /**
         * Senha da pessoa
         */
        std::string senha;

    public:
        /**
         * Construtor da classe Pessoa
         * @param nome nome da pessoa
         * @param email email da pessoa
         * @param senha senha da pessoa
         */
        Pessoa(std::string nome, std::string email, std::string senha);

        /**
         * Obtem o nome da pessoa
         * @return nome da pessoa
         */
        std::string getNome();

        /**
         * Obtem o email da pessoa
         * @return email da pessoa
         */
        std::string getEmail();

        /**
         * Obtem a senha da pessoa
         * @return senha da pessoa
         */
        std::string getSenha();

        /**
         * Altera o nome da pessoa
         * @param nome novo nome da pessoa
         */
        void setNome(std::string nome);

        /**
         * Altera o email da pessoa
         * @param email novo email da pessoa
         */
        void setEmail(std::string email);

        /**
         * Altera a senha da pessoa
         * @param senha nova senha da pessoa
         */
        void setSenha(std::string senha);

        /**
         * Verifica se o email e a senha passados como parametro sao iguais aos da pessoa
         * @param email email a ser verificado
         * @param senha senha a ser verificada
         * @return true se o email e a senha forem iguais aos da pessoa, false caso contrario
         */
        bool login(std::string email, std::string senha);

        /**
         * Verifica se o email passado como parametro e igual ao da pessoa
         * @param email email a ser verificado
         * @return true se o email for igual ao da pessoa, false caso contrario
         */
        bool verificarEmail(std::string email);

        /**
         * Verifica se a senha passada como parametro e igual a da pessoa
         * @param senha senha a ser verificada
         * @return true se a senha for igual a da pessoa, false caso contrario
         */
        bool verificarSenha(std::string senha);
};

#endif