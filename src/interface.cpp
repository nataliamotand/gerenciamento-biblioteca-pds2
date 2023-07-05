#include "Administrador.hpp"
#include "BancoDeDados.hpp"

#include <iostream>

BancoDeDados bancoDeDados = BancoDeDados();

bool loginAdministrador() {
    std::string email, senha;

    std::cout<<"Digite o seu email: ";
    std::cin>>email;
    std::cout<<"Digite a sua senha: ";
    std::cin>>senha;

    bool retorno = bancoDeDados.loginAdministrador(email, senha);
    return retorno;
}

bool loginUsuario() {
    std::string email, senha;

    std::cout<<"Digite o seu email: ";
    std::cin>>email;
    std::cout<<"Digite a sua senha: ";
    std::cin>>senha;

    bool retorno = bancoDeDados.loginUsuario(email, senha);
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
                std::cin.ignore();
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
                std::cin.ignore();
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


void AdministradorGerenciarLivros(){
    int escolha;
    do{
        std::cout << "1 - Ver todos livros cadastrados" << std::endl;
        std::cout << "2 - Adicionar livro no sistema" << std::endl;
        std::cout << "3 - Editar livro no sistema" << std::endl;
        std::cout << "4 - Excluir livro no sistema" << std::endl;
        std::cout << "5 - Sair" << std::endl;
        std::cin >> escolha;
        switch (escolha){
            case 1:
                bancoDeDados.imprimeTodosLivros();
                break;
            case 2:{
                std::string titulo, genero, autor;
                int numCopias;
                std::cout << "Digite o título: ";
                std::cin.ignore();
                std::getline(std::cin, titulo);
                std::cout << "Digite o gênero: ";
                std::getline(std::cin, genero);
                std::cout << "Digite o autor: ";
                std::getline(std::cin, autor);
                std::cout << "Digite o número de cópias: ";
                std::cin >> numCopias;
                bool retorno = bancoDeDados.adicionarLivro(titulo, genero, autor, numCopias);
                if(retorno == false){
                    std::cout << "Livro já estava cadastrado" << std::endl;
                }else{
                    std::cout << "Livro cadastrado com sucesso" << std::endl;
                }
                break;
            }  
            case 3:{
                std::string titulo, genero, autor, defeito, endereco;
                int numCopias;
                std::cout << "Confirme os dados do livro a ser editado" << std::endl;
                std::cout << "Digite o título: ";
                std::cin.ignore();
                std::getline(std::cin, titulo);
                std::cout << "Digite o gênero: ";
                std::getline(std::cin, genero);
                std::cout << "Digite o autor: ";
                std::getline(std::cin, autor);
                std::cout << "Digite o número de cópias: ";
                std::cin >> numCopias;
                std::cout << "Digite o defeito: ";
                std::cin.ignore();
                std::getline(std::cin, defeito);
                std::cout << "Digite o endereço: ";
                std::getline(std::cin, endereco);
                bool retorno = bancoDeDados.editarLivro(titulo, genero, autor, numCopias, defeito, endereco);
                if(retorno == false){
                    std::cout << "Livro não encontrado" << std::endl;
                }else{
                    std::cout << "Livro atualizado com sucesso" << std::endl;
                }
                break;
            }
            case 4:{
                std::string titulo, autor;
                std::cout << "Digite o título do livro a ser removido: ";
                std::cin.ignore();
                std::getline(std::cin, titulo);
                std::cout << "Digite o autor do livro a ser removido: ";
                std::getline(std::cin, autor);
                bool retorno = bancoDeDados.removerLivro(titulo, autor);
                if(retorno == false){
                    std::cout << "Livro não encontrado" << std::endl;
                }else{
                    std::cout << "Livro removido com sucesso" << std::endl;
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
                    AdministradorGerenciarLivros();
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


void UsuarioPesquisarLivro(){
    std::string titulo;
    std::cout << "Digite o título do livro: ";
    std::cin.ignore();
    std::getline(std::cin, titulo);
    Livro livro = bancoDeDados.pesquisarLivro(titulo);
    if(livro.getTitulo() == ""){
        std::cout << "Nenhum livro encontrado" << std::endl;
    }else{
        if(livro.getDisponibilidade()){
            std::cout << "Livro disponível" << std::endl;
            std::cout << "Número de cópias disponíveis: " << livro.getNumCopias() << std::endl;
        }else{
            std::cout << "Livro indisponível" << std::endl;
            // std::cout << "Data de devolução prevista: " << livro.getDataDevolucao() << std::endl;
        }
    }
}

void interfaceUsuario(){
    int escolha;
    bool login = loginUsuario();
    if(login){
        do{
            std::cout << "1 - Pesquisar livro pelo título" << std::endl;
            std::cout << "2 - Visualizar livros emprestados" << std::endl;
            std::cout << "3 - Renovar livro emprestado" << std::endl;
            std::cout << "4 - Realizar empréstimo de livro" << std::endl;
            std::cout << "5 - Sair" << std::endl;
            std::cin >> escolha;
            switch (escolha){
                case 1:
                    UsuarioPesquisarLivro();
                    break;
                case 2:
                    // UsuarioVisualizarLivros();
                    break;
                case 3:
                    // UsuarioRenovarLivro();
                    break;
                case 4:
                    // UsuarioRealizarEmprestimo();
                    break;
                case 5:
                    break;
                default:
                    std::cout << "Opção inválida" << std::endl;
                    break;
            }
        }while(escolha != 5);
    }
}
