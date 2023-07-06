#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "Pessoa.hpp"
#include "Usuario.hpp"

#include <string>

class Administrador : public Pessoa {
    private:


    public:
        /*
        * Construtor da classe Administrador
        * 
        * Inicializa o administrador com um nome, email e senha padrão
        * nome: Biblioteca
        * email: biblioteca@ufmg.br
        * senha: 1234
        */
        Administrador();
};

#endif