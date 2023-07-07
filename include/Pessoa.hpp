#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

class Pessoa {
    private:
        std::string nome;
        std::string email;
        std::string senha;

    public:
        Pessoa(std::string nome, std::string email, std::string senha);

        std::string getNome();
        std::string getEmail();
        std::string getSenha();

        void setNome(std::string nome);
        void setEmail(std::string email);
        void setSenha(std::string senha);

        bool login(std::string email, std::string senha);

        bool verificarEmail(std::string email);
        bool verificarSenha(std::string senha);
};

#endif