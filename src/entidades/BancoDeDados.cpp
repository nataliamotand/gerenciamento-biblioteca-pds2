#include "BancoDeDados.hpp"

BancoDeDados::BancoDeDados() {
    Usuario* usuario1 = new Usuario("João Paula", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    Usuario* usuario2 = new Usuario("Maria Flor", "maria@gmail.com", "1234", "Ciência da Computação", "987654321");
    Usuario* usuario3 = new Usuario("José Carlos", "jose@gmail.com", "1234", "Sistemas de Informação", "123556779");
    Usuario* usuario4 = new Usuario("Ana Paula", "ana@gmail.com", "1234", "Sistemas de Informação", "987556321");
    Usuario* usuario5 = new Usuario("Pedro Souza", "pedro@gmail.com", "1234", "Matemática Computacional", "110456789");

    this->usuarios.push_back(usuario1);
    this->usuarios.push_back(usuario2);
    this->usuarios.push_back(usuario3);
    this->usuarios.push_back(usuario4);
    this->usuarios.push_back(usuario5);

    CatalogoLivros catalogoLivros;
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
    CatalogoLivros catalogoLivros;
    Livro livro = catalogoLivros.pesquisarLivro(titulo);
    return livro;
}

BancoDeDados::~BancoDeDados(){
    for (auto usuario : this->usuarios) {
        delete usuario;
    }
    this->usuarios.clear();
}
