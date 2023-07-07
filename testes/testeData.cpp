#include "test_config.h"

#include "Data.hpp"

TEST_CASE("Testando construtor da classe Data") {
    Data data = Data(1, 6, 2023);
    REQUIRE(data.getDia() == 1);
    REQUIRE(data.getMes() == 6);
    REQUIRE(data.getAno() == 2023);
}

TEST_CASE("Testando get de data") {
    Data data = Data(1, 6, 2023);
    Data data2 = data.getData();
    REQUIRE(data2.getDia() == 1);
    REQUIRE(data2.getMes() == 6);
    REQUIRE(data2.getAno() == 2023);
}

TEST_CASE("Testando get de dia") {
    Data data = Data(1, 6, 2023);
    REQUIRE(data.getDia() == 1);
}

TEST_CASE("Testando get de mes") {
    Data data = Data(1, 6, 2023);
    REQUIRE(data.getMes() == 6);
}

TEST_CASE("Testando get de ano") {
    Data data = Data(1, 6, 2023);
    REQUIRE(data.getAno() == 2023);
}

TEST_CASE("Testando set de dia") {
    Data data = Data(1, 6, 2023);
    data.setDia(2);
    REQUIRE(data.getDia() == 2);
}

TEST_CASE("Testando set de mes") {
    Data data = Data(1, 6, 2023);
    data.setMes(7);
    REQUIRE(data.getMes() == 7);
}

TEST_CASE("Testando set de ano") {
    Data data = Data(1, 6, 2023);
    data.setAno(2024);
    REQUIRE(data.getAno() == 2024);
}

TEST_CASE("Testando adição de dias") {
    Data data = Data(1, 6, 2023);
    Data data2 = data.adicionarDias(data, 1);
    REQUIRE(data2.getDia() == 2);
    REQUIRE(data2.getMes() == 6);
    REQUIRE(data2.getAno() == 2023);
}