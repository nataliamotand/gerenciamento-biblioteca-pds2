#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "test_config.h"

#include "Administrador.hpp"


TEST_CASE("Testa se o email e a senha estão corretos"){
    Administrador administrador = Administrador();
    CHECK_EQ(administrador.verificarEmail("biblioteca@ufmg.br"), true);
    CHECK_EQ(administrador.verificarSenha("1234"), true);
}

TEST_CASE("Testando se o email é diferente dos dados corretos"){
    Administrador administrador = Administrador();
    CHECK_EQ(administrador.verificarEmail("biblioteca@gmail.com"), false);
}

TEST_CASE("Testando se a senha é diferente dos dados corretos"){
    Administrador administrador = Administrador();
    CHECK_EQ(administrador.verificarSenha("4321"), false);
}

TEST_CASE("Testa se o administrador consegue logar"){
    Administrador administrador = Administrador();
    CHECK_EQ(administrador.login("biblioteca@ufmg.br", "1234"), true);
}

TEST_CASE("Testa se o administrador não consegue logar"){
    Administrador administrador = Administrador();
    CHECK_EQ(administrador.login("biblioteca@gmail.com", "1234"), false);
}

TEST_CASE("Testa se o administrador não consegue logar"){
    Administrador administrador = Administrador();
    CHECK_EQ(administrador.login("biblioteca@ufmg.br", "4231"), false);
}