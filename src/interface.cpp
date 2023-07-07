#include "BancoDeDados.hpp"

#include <iostream>

BancoDeDados bancoDeDados = BancoDeDados();
std::string emailLogado = "";

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
    if(retorno){
        emailLogado = email;
    }
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

void AdministradorGerenciarEmprestimos(){
    int escolha;
    do{
        std::cout << "1 - Ver histórico de atividades dos usuários" << std::endl;
        std::cout << "2 - Gerar relatório de usuários com livros atrasados" << std::endl;
        std::cout << "3 - Gerar relatório estatístico de demandas" << std::endl;
        std::cout << "4 - Sair" << std::endl;
        std::cin >> escolha;
        switch (escolha){
            case 1:
                bancoDeDados.imprimeHistoricoAtividadeUsuarios();
                break;
            case 2:
                bancoDeDados.imprimeRelatorioUsuariosComLivrosAtrasados();
                break;
            case 3:
                bancoDeDados.imprimeRelatorioEstatisticoDemanda();
                break;
            case 4:
                break;
            default:
                break;
        }
    } while (escolha != 4);
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
                    AdministradorGerenciarEmprestimos();
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
            Data data = livro.getDataDevolucao();
            std::cout << "Data de devolução prevista: ";
            data.imprimeData();
        }
    }
}

void UsuarioRealizarEmprestimo(){
    std::string titulo, autor;
    std::cout << "Digite o título do livro: ";
    std::cin.ignore();
    std::getline(std::cin, titulo);
    std::cout << "Digite o autor do livro: ";
    std::getline(std::cin, autor);
    Livro livro = bancoDeDados.pesquisarLivro(titulo);
    if(livro.getTitulo() == ""){
        std::cout << "Nenhum livro encontrado" << std::endl;
    }else{
        if(livro.getDisponibilidade()){
            std::cout << "Livro disponível" << std::endl;
            std::cout << "Número de cópias disponíveis: " << livro.getNumCopias() << std::endl;
            std::cout << "Deseja realizar o empréstimo? (1 - Sim, 2 - Não)" << std::endl;
            int escolha;
            std::cin >> escolha;
            if(escolha == 1){
                bool podeEmprestar = bancoDeDados.usuarioPodePegarLivroEmprestado(emailLogado);
                if(podeEmprestar == false){
                    std::cout << "Usuário não pode pegar mais livros emprestados" << std::endl;
                    std::cout << "Limite máximo de 2 livros emprestados" << std::endl;
                    return;
                }
                int retorno = bancoDeDados.emprestarLivro(titulo, autor, emailLogado);
                if(retorno == true)
                    std::cout << "Livro emprestado com sucesso" << std::endl;
            }
        }else{
            std::cout << "Livro indisponível" << std::endl;
        }
    }
}

void UsuarioVisualizarLivrosEmprestados(){
    std::vector<std::map<Livro, std::map<Data, Data>>> livros = bancoDeDados.visualizarLivrosEmprestados(emailLogado);
    if(livros.size() == 0){
        std::cout << "Nenhum livro emprestado no momento" << std::endl;
    }else{
        for(std::vector<std::map<Livro, std::map<Data, Data>>>::size_type i = 0; i < livros.size(); i++){
            std::map<Livro, std::map<Data, Data>> livro = livros[i];
            if(livro.empty()) {
                continue;
            }
            std::map<Livro, std::map<Data, Data>>::iterator it;
            for(it = livro.begin(); it != livro.end(); it++){
                std::cout << "Título: " << it->first.getTitulo() << std::endl;
                std::cout << "Data de empréstimo: " << const_cast<Data&>(it->second.begin()->first).getDia() << "/" <<
                const_cast<Data&>(it->second.begin()->first).getMes() << "/" << const_cast<Data&>(it->second.begin()->first).getAno() << std::endl;
                std::cout << "Data de devolução prevista: " << const_cast<Data&>(it->second.begin()->second).getDia() << "/" <<
                const_cast<Data&>(it->second.begin()->second).getMes() << "/" << const_cast<Data&>(it->second.begin()->second).getAno() << std::endl;
                std::cout << "------------------------------------------" << std::endl;
            }
        }
    }
}

void UsuarioRenovarLivro(){
    std::string titulo;
    std::cout << "Digite o título do livro: ";
    std::cin.ignore();
    std::getline(std::cin, titulo);

    std::vector<std::map<Livro, std::map<Data, Data>>> livros = bancoDeDados.visualizarLivrosEmprestados(emailLogado);
    if(livros.size() == 0){
        std::cout << "Nenhum livro emprestado no momento" << std::endl;
    }
    for(std::vector<std::map<Livro, std::map<Data, Data>>>::size_type i = 0; i < livros.size(); i++){
            std::map<Livro, std::map<Data, Data>> livro = livros[i];
            if(livro.empty()) {
                continue;
            }
            std::map<Livro, std::map<Data, Data>>::iterator it;
            for(it = livro.begin(); it != livro.end(); it++){
                if(it->first.getTitulo() == titulo){
                    std::cout << "Deseja renovar o empréstimo? (1 - Sim, 2 - Não)" << std::endl;
                    int escolha;
                    std::cin >> escolha;
                    if(escolha == 1){
                        int retorno = bancoDeDados.renovarLivro(titulo, emailLogado);
                        if(retorno == true)
                            std::cout << "Livro renovado com sucesso" << std::endl;
                    }else{
                        return;
                    }
                }
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
                    UsuarioVisualizarLivrosEmprestados();
                    break;
                case 3:
                    UsuarioRenovarLivro();
                    break;
                case 4:
                    UsuarioRealizarEmprestimo();
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