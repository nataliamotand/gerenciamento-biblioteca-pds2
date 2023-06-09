#include "BancoDeDados.hpp"

BancoDeDados::BancoDeDados() {
    Usuario* usuario1 = new Usuario("Luigi", "luigi@gmail.com", "1234", "Ciência da Computação", "123456789");
    Usuario* usuario2 = new Usuario("Auanny", "auanny@gmail.com", "1234", "Ciência da Computação", "987654321");
    Usuario* usuario3 = new Usuario("Paulo", "paulo@gmail.com", "1234", "Sistemas de Informação", "123556779");
    Usuario* usuario4 = new Usuario("Vitoria", "vitoria@gmail.com", "1234", "Sistemas de Informação", "987556321");
    Usuario* usuario5 = new Usuario("Natalia", "natalia@gmail.com", "1234", "Matemática Computacional", "110456789");

    usuario1->pegarLivroEmprestado(Livro("O Pequeno Príncipe", "Infantil", "Antoine de Saint-Exupéry", 1, true, "", "0011", "B1"), Data(1, 5, 2023));
    usuario2->pegarLivroEmprestado(Livro("A Menina que Roubava Livros", "Drama", "Markus Zusak", 1, true, "", "0012", "C1"), Data(2, 5, 2023));

    this->dataAtual = Data(1, 6, 2023);

    usuario1->calcularMulta(this->dataAtual);
    usuario2->calcularMulta(this->dataAtual);

    this->usuarios.push_back(usuario1);
    this->usuarios.push_back(usuario2);
    this->usuarios.push_back(usuario3);
    this->usuarios.push_back(usuario4);
    this->usuarios.push_back(usuario5);
}

std::vector<Usuario*> BancoDeDados::getUsuarios() {
    return this->usuarios;
}

bool BancoDeDados::adicionarUsuario(std::string nome, std::string email, std::string senha,
    std::string curso, std::string idEstudantil){
    bool usuarioAdicionado = true;

    // verifica se email existe antes de adicionar usuario
    for(auto usuario : this->usuarios){
        if(usuario->getEmail() == email){
            return false;
        }
    }
    Usuario* usuario = new Usuario(nome, email, senha, curso, idEstudantil);
    this->usuarios.push_back(usuario);
    return usuarioAdicionado;
}

bool BancoDeDados::atualizarUsuario(std::string nome, std::string email, std::string senha,
                std::string curso, std::string idEstudantil){
    bool usuarioAtualizado = false;
    for(auto usuario : this->usuarios){
        if(usuario->getEmail() == email){
            usuario->setNome(nome);
            usuario->setEmail(email);
            usuario->setSenha(senha);
            usuario->setCurso(curso);
            usuario->setIdEstudantil(idEstudantil);
            usuarioAtualizado = true;
        }
    }
    return usuarioAtualizado;
}

bool BancoDeDados::removerUsuario(std::string email){
    bool usuarioRemovido = false;
    for(auto it = this->usuarios.begin(); it != this->usuarios.end(); ++it){
        if((*it)->getEmail() == email){
            delete *it;
            this->usuarios.erase(it);
            usuarioRemovido = true;
            break;
        }
    }
    return usuarioRemovido;
}

void BancoDeDados::imprimeTodosUsuarios(){
    for (auto usuario : this->usuarios) {
        std::cout << usuario->getNome() << " | " << usuario->getEmail() << " | " << usuario->getCurso()
        <<std::endl;
    }
    std::cout<<std::endl;
}

bool BancoDeDados::loginAdministrador(std::string email, std::string senha) {
    Administrador administrador = Administrador();
    bool retorno = administrador.login(email, senha);
    return retorno;
 }

bool BancoDeDados::loginUsuario(std::string email, std::string senha) {
    bool retorno = false;
    for(auto usuario : this->usuarios){
        if(usuario->getEmail() == email && usuario->getSenha() == senha){
            retorno = true;
            break;
        }
    }
    return retorno;
}


Livro BancoDeDados::pesquisarLivro(std::string titulo){
    Livro livro = this->catalogoLivros.pesquisarLivro(titulo);
    return livro;
}

bool BancoDeDados::adicionarLivro(std::string titulo, std::string genero, std::string autor, int numCopias){
    bool livroAdicionado = this->catalogoLivros.adicionarLivro(titulo, genero, autor, numCopias);
    return livroAdicionado;
}

void BancoDeDados::imprimeTodosLivros(){
    this->catalogoLivros.imprimeTodosLivros();
}

bool BancoDeDados::removerLivro(std::string titulo, std::string autor){
    bool livroRemovido = this->catalogoLivros.removerLivro(titulo, autor);
    return livroRemovido;
}

bool BancoDeDados::editarLivro(std::string titulo, std::string genero, std::string autor, int numCopias,
                        std::string defeito, std::string endereco){
    bool livroEditado = this->catalogoLivros.editarLivro(titulo, genero, autor, numCopias, defeito, endereco);
    return livroEditado;
}

bool BancoDeDados::emprestarLivro(std::string titulo, std::string autor, std::string email){
    if(this->catalogoLivros.livroEstaDisponivel(titulo, autor)){
        for(auto usuario : this->usuarios){
            if(usuario->getEmail() == email){
                Livro livro = this->catalogoLivros.pesquisarLivro(titulo);
                usuario->pegarLivroEmprestado(livro, this->dataAtual);
                this->catalogoLivros.emprestarLivro(titulo, autor, this->dataAtual);
                return true;
            }
        }
    }
    return false;
}

std::vector<std::map<Livro, std::map<Data, Data>>> BancoDeDados::visualizarLivrosEmprestados(std::string email){
    std::vector<std::map<Livro, std::map<Data, Data>>> livrosEmprestados;
    for(auto usuario : this->usuarios){
        if(usuario->getEmail() == email){
            livrosEmprestados = usuario->getLivrosEmprestados();
            break;
        }
    }
    return livrosEmprestados;
}

bool BancoDeDados::renovarLivro(std::string titulo, std::string email){
    bool livroRenovado = false;
    for(auto usuario : this->usuarios){
        if(usuario->getEmail() == email){
            livroRenovado = usuario->renovarLivro(titulo, this->dataAtual);
            break;
        }
    }
    return livroRenovado;
}

bool BancoDeDados::usuarioPodePegarLivroEmprestado(std::string email){
    bool usuarioPodePegarLivroEmprestado = false;
    for(auto usuario : this->usuarios){
        if(usuario->getEmail() == email){
            usuarioPodePegarLivroEmprestado = usuario->podePegarLivroEmprestado();
            break;
        }
    }
    return usuarioPodePegarLivroEmprestado;
}

void BancoDeDados::imprimeHistoricoAtividadeUsuarios(){
    for(auto usuario : this->usuarios){
        if(usuario->getMulta() > 0 || usuario->getLivrosEmprestados().size() > 0)
            usuario->imprimeHistoricoAtividade();
    }
}

void BancoDeDados::imprimeRelatorioUsuariosComLivrosAtrasados(){
    for(auto usuario : this->usuarios){
        if(usuario->getMulta() > 0)
            usuario->imprimeRelatorioUsuariosComLivrosAtrasados();
    }
}

void BancoDeDados::imprimeRelatorioEstatisticoDemanda(){
    std::vector<std::map<Livro, std::map<Data, Data>>> livrosEmprestados;
    std::map<std::string, int> livrosEmprestadosPorMes;
    std::map<std::string, int> livrosEmprestadosPorMesPorLivro;
    std::string mes;
    int quantidadeLivrosEmprestados = 0;
    int quantidadeLivrosEmprestadosPorLivro = 0;
    for(auto usuario : this->usuarios){
        livrosEmprestados = usuario->getLivrosEmprestados();
        for(auto livro : livrosEmprestados){
            mes = std::to_string(livro.begin()->second.begin()->first.getMes());
            quantidadeLivrosEmprestadosPorLivro = livrosEmprestadosPorMesPorLivro[mes + " " + livro.begin()->first.getTitulo()];
            livrosEmprestadosPorMesPorLivro[mes + " " + livro.begin()->first.getTitulo()] = quantidadeLivrosEmprestadosPorLivro + 1;
            quantidadeLivrosEmprestados = livrosEmprestadosPorMes[mes];
            livrosEmprestadosPorMes[mes] = quantidadeLivrosEmprestados + 1;
        }
    }
    std::cout << "Relatorio estatistico de demanda" << std::endl;
    std::cout << "Quantidade de emprestimos por mes: " << std::endl;
    for(auto mes : livrosEmprestadosPorMes){
        std::cout << "Mes: " << mes.first << " Quantidade: " << mes.second << std::endl;
    }
    std::cout << "Quantidade de emprestimos por mes por livro: " << std::endl;
    for(auto mes : livrosEmprestadosPorMesPorLivro){
        std::cout << "Mes: " << mes.first << " Quantidade: " << mes.second << std::endl;
    }
    std::cout << "--------------------//--------------------" << std::endl;
}

BancoDeDados::~BancoDeDados(){
    for (auto usuario : this->usuarios) {
        delete usuario;
    }
    this->usuarios.clear();
}
