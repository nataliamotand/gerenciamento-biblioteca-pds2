// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "test_config.h"

#include "Usuario.hpp"


TEST_CASE("Testa se o email e a senha estão corretos"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    CHECK_EQ(usuario.verificarEmail("joao@gmail.com"), true);
    CHECK_EQ(usuario.verificarSenha("1234"), true);
}

TEST_CASE("Testando se o email é diferente dos dados corretos"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    CHECK_EQ(usuario.verificarEmail("joao@ufmg.br"), false);
}

TEST_CASE("Testando se a senha é diferente dos dados corretos"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    CHECK_EQ(usuario.verificarSenha("4321"), false);
}

TEST_CASE("Testa se o usuario consegue logar"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    CHECK_EQ(usuario.login("joao@gmail.com", "1234"), true);
}

TEST_CASE("Testa se o usuario não consegue logar"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    CHECK_EQ(usuario.login("joao@gmail.com", "12345"), false);
}

TEST_CASE("Testa se o usuario não consegue logar"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    CHECK_EQ(usuario.login("joao@ufmg.br", "1234"), false);
}

TEST_CASE("Testa se curso do usuario está correto"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    CHECK_EQ(usuario.getCurso(), "Ciência da Computação");
}

TEST_CASE("Testa se matricula do usuario está correta"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    CHECK_EQ(usuario.getIdEstudantil(), "123456789");
}

TEST_CASE("Testa se o nome do usuario está correto"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    CHECK_EQ(usuario.getNome(), "João");
}

TEST_CASE("Testa se o email do usuario está correto"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    CHECK_EQ(usuario.getEmail(), "joao@gmail.com");
}

TEST_CASE("Testa se a senha do usuario está correta"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    CHECK_EQ(usuario.getSenha(), "1234");
}

TEST_CASE("Testa se o usuario consegue alterar o nome"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    usuario.setNome("João Pedro");
    CHECK_EQ(usuario.getNome(), "João Pedro");
}

TEST_CASE("Testa se o usuario consegue alterar o email"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    usuario.setEmail("joao@ufmg.br");
    CHECK_EQ(usuario.getEmail(), "joao@ufmg.br");
}

TEST_CASE("Testa se o usuario consegue alterar a senha"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    usuario.setSenha("4321");
    CHECK_EQ(usuario.getSenha(), "4321");
}

TEST_CASE("Testa se o usuario consegue alterar o curso"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    usuario.setCurso("Engenharia de Software");
    CHECK_EQ(usuario.getCurso(), "Engenharia de Software");
}

TEST_CASE("Testa set e get de dias de atraso"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    usuario.setDiasAtraso(5);
    CHECK_EQ(usuario.getDiasAtraso(), 5);
}

TEST_CASE("Testa set e get de multa"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    usuario.setMulta(10);
    CHECK_EQ(usuario.getMulta(), 10);
}

TEST_CASE("Testa set de ID estudantil"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    usuario.setIdEstudantil("987654321");
    CHECK_EQ(usuario.getIdEstudantil(), "987654321");
}

TEST_CASE("Testa se o usuario consegue pegar um livro emprestado e se o get de livros emprestados está funcionando"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    usuario.pegarLivroEmprestado(Livro("O Pequeno Príncipe", "Infantil", "Antoine de Saint-Exupéry", 1, true, "", "0011", "B1"), Data(1, 5, 2023));
    CHECK_EQ(usuario.getLivrosEmprestados().size(), 1);
}

TEST_CASE("Testa se o usuario consegue calcular multa de livro atrasado e se o get de multa está funcionando"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    usuario.pegarLivroEmprestado(Livro("O Pequeno Príncipe", "Infantil", "Antoine de Saint-Exupéry", 1, true, "", "0011", "B1"), Data(1, 5, 2023));
    usuario.calcularMulta(Data(16, 5, 2023));
    CHECK_EQ(usuario.getMulta(), 1);
}

TEST_CASE("Testa se o usuario consegue renovar um livro emprestado"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    usuario.pegarLivroEmprestado(Livro("O Pequeno Príncipe", "Infantil", "Antoine de Saint-Exupéry", 1, true, "", "0011", "B1"), Data(1, 5, 2023));
    CHECK_EQ(usuario.renovarLivro("O Pequeno Príncipe", Data(1, 6, 2023)), true);
}

TEST_CASE("Testa se o usuario pode pegar livro emprestado"){
    Usuario usuario = Usuario("João", "joao@gmail.com", "1234", "Ciência da Computação", "123456789");
    usuario.pegarLivroEmprestado(Livro("O Pequeno Príncipe", "Infantil", "Antoine de Saint-Exupéry", 1, true, "", "0011", "B1"), Data(1, 5, 2023));
    CHECK_EQ(usuario.podePegarLivroEmprestado(), true);
}
