#include "Administrador.hpp"
#include "BancoDeDados.hpp"

#include <iostream>

BancoDeDados bancoDeDados = BancoDeDados();
Administrador administrador = Administrador();

bool loginAdministrador() {
    std::string email, senha;

    std::cout<<"Digite o seu email: ";
    std::cin>>email;
    std::cout<<"Digite a sua senha: ";
    std::cin>>senha;

    bool retorno = administrador.login(email, senha);
    return retorno;
}

void AdministradorGerenciarUsuarios(){
    int escolha;
    do{
        std::cout << "1 - Ver todos usuários cadastrados" << std::endl;
        std::cout << "2 - Adicionar usuário no sistema" << std::endl;
        std::cout << "3 - Editar usuário no sistema" << std::endl;
        std::cout << "4 - Excluir usuário no sistema" << std::endl;
        std::cout << "5 - Sair" << std::endl;
        std::cin >> escolha;
        switch (escolha){
            case 1:
                bancoDeDados.imprimeTodosUsuarios();
                break;
            case 2:{
                std::string nome, email, senha, curso, idEstudantil;
                std::cout << "Digite o nome: ";
                std::getline(std::cin, nome);
                std::cout << "Digite o email: ";
                std::cin >> email;
                std::cout << "Digite a senha: ";
                std::getline(std::cin, senha);
                std::cout << "Digite o curso: ";
                std::getline(std::cin, curso);
                std::cout << "Digite o ID Estudantil: ";
                std::cin >> idEstudantil;
                bool retorno = bancoDeDados.adicionarUsuario(nome, email, senha, curso, idEstudantil);
                if(retorno == false){
                    std::cout << "Usuario já cadastrado" << std::endl;
                }else{
                    std::cout << "Usuario cadastrado com sucesso" << std::endl;
                }
                break;
            }  
            case 3:{
                std::string nome, email, senha, curso, idEstudantil;
                std::cout << "Confirme os dados do usuario a ser editado" << std::endl;
                std::cout << "Digite o nome: ";
                std::getline(std::cin, nome);
                std::cout << "Digite o email: ";
                std::getline(std::cin, email);
                std::cout << "Digite a senha: ";
                std::getline(std::cin, senha);
                std::cout << "Digite o curso: ";
                std::getline(std::cin, curso);
                std::cout << "Digite o ID Estudantil: ";
                std::cin >> idEstudantil;
                bool retorno = bancoDeDados.atualizarUsuario(nome, email, senha, curso, idEstudantil);
                if(retorno == false){
                    std::cout << "Usuario não encontrado" << std::endl;
                }else{
                    std::cout << "Usuario atualizado com sucesso" << std::endl;
                }
                break;
            }
            case 4:{
                std::string email;
                std::cout << "Digite o email do usuario a ser removido: ";
                std::cin >> email;
                bool retorno = bancoDeDados.removerUsuario(email);
                if(retorno == false){
                    std::cout << "Usuario não encontrado" << std::endl;
                }else{
                    std::cout << "Usuario removido com sucesso" << std::endl;
                }
                break;
            }
            case 5:
                break;
            default:
                break;
        }
    } while (escolha != 5);
    
}


void interfaceAdministrador(){
    int escolha;
    bool login = loginAdministrador();
    if(login){
        do{
            std::cout << "1 - Gerenciar usuários" << std::endl;
            std::cout << "2 - Gerenciar livros" << std::endl;
            std::cout << "3 - Gerenciar empréstimos" << std::endl;
            std::cout << "4 - Sair" << std::endl;
            std::cin >> escolha;
            switch (escolha){
                case 1:
                    AdministradorGerenciarUsuarios();
                    break;
                case 2:
                    // AdministradorGerenciarLivros();
                    break;
                case 3:
                    // AdministradorGerenciarEmprestimos();
                    break;
                case 4:
                    break;
                default:
                    std::cout << "Opção inválida" << std::endl;
                    break;
            }
        }while(escolha != 4);
    }else{
        std::cout<<"Email ou senha incorretos"<<std::endl;
    }
}
