# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++17 -Wall --coverage -g -O0

INCLUDE_FLAGS = -I include/

# Generate executable
default: biblioteca testesUnitarios

# Compile all files
pessoa: pessoa.o
	$(CC) $(CFLAGS) -o pessoa build/pessoa.o

pessoa.o:  src/entidades/Pessoa.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Pessoa.cpp -o build/pessoa.o

data: data.o
	$(CC) $(CFLAGS) -o data build/data.o

data.o: src/entidades/Data.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Data.cpp -o build/data.o

livro: livro.o data.o
	$(CC) $(CFLAGS) -o livro build/livro.o build/data.o

livro.o: src/entidades/Livro.cpp src/entidades/Data.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Livro.cpp -o build/livro.o

emprestimo: emprestimo.o
	$(CC) $(CFLAGS) -o emprestimo build/emprestimo.o

emprestimo.o: src/entidades/Emprestimo.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Emprestimo.cpp -o build/emprestimo.o

usuario: usuario.o pessoa.o data.o emprestimo.o
	$(CC) $(CFLAGS) -o usuario build/usuario.o build/pessoa.o build/data.o build/emprestimo.o

usuario.o: src/entidades/Usuario.cpp src/entidades/Pessoa.cpp src/entidades/Data.cpp src/entidades/Emprestimo.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Usuario.cpp -o build/usuario.o

administrador:  administrador.o pessoa.o
	$(CC) $(CFLAGS) -o administrador build/administrador.o build/pessoa.o

administrador.o:  src/entidades/Administrador.cpp src/entidades/Pessoa.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Administrador.cpp -o build/administrador.o

catalogo: catalogo.o livro.o data.o
	$(CC) $(CFLAGS) -o catalogo build/catalogo.o build/livro.o build/data.o

catalogo.o: src/entidades/CatalogoLivros.cpp src/entidades/Livro.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/CatalogoLivros.cpp -o build/catalogo.o

bancoDeDados: bancoDeDados.o data.o
	$(CC) $(CFLAGS) -o bancoDeDados build/bancoDeDados.o build/data.o

bancoDeDados.o: src/entidades/BancoDeDados.cpp src/entidades/Data.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/BancoDeDados.cpp -o build/bancoDeDados.o

main: main.o
	$(CC) $(CFLAGS) -o main build/main.o

main.o: src/main.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/main.cpp -o build/main.o


# Link all files
biblioteca: pessoa.o usuario.o administrador.o livro.o catalogo.o bancoDeDados.o data.o emprestimo.o main.o
	$(CC) $(CFLAGS) -o biblioteca build/main.o build/pessoa.o build/usuario.o build/administrador.o build/livro.o build/catalogo.o build/bancoDeDados.o build/data.o build/emprestimo.o


# Compilando o executável de testes
testeAdministrador: testeAdministrador.o
	$(CC) $(CFLAGS) -o testeAdministrador build/testeAdministrador.o

testeAdministrador.o: testes/testeAdministrador.cpp
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c testes/testeAdministrador.cpp -o build/testeAdministrador.o

testeUsuario: testeUsuario.o
	$(CC) $(CFLAGS) -o testeUsuario build/testeUsuario.o

testeUsuario.o: testes/testeUsuario.cpp
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c testes/testeUsuario.cpp -o build/testeUsuario.o

testeCatalogoLivros: testeCatalogoLivros.o
	$(CC) $(CFLAGS) -o testeCatalogoLivros build/testeCatalogoLivros.o

testeCatalogoLivros.o: testes/testeCatalogoLivros.cpp
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c testes/testeCatalogoLivros.cpp -o build/testeCatalogoLivros.o

testeData: testeData.o
	$(CC) $(CFLAGS) -o testeData build/testeData.o

testeData.o: testes/testeData.cpp
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c testes/testeData.cpp -o build/testeData.o

testeEmprestimo: testeEmprestimo.o
	$(CC) $(CFLAGS) -o testeEmprestimo build/testeEmprestimo.o

testeEmprestimo.o: testes/testeEmprestimo.cpp
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c testes/testeEmprestimo.cpp -o build/testeEmprestimo.o

testeLivro: testeLivro.o
	$(CC) $(CFLAGS) -o testeLivro build/testeLivro.o

testeLivro.o: testes/testeLivro.cpp
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c testes/testeLivro.cpp -o build/testeLivro.o

testesUnitarios: testeAdministrador.o pessoa.o administrador.o testeUsuario.o usuario.o testeCatalogoLivros.o catalogo.o livro.o data.o emprestimo.o testeData.o testeEmprestimo.o testeLivro.o
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -o testesUnitarios build/testeAdministrador.o build/pessoa.o build/administrador.o build/testeUsuario.o build/usuario.o build/testeCatalogoLivros.o build/catalogo.o build/livro.o build/data.o build/emprestimo.o build/testeData.o build/testeEmprestimo.o build/testeLivro.o


# Run coverage
coverage:
	./testesUnitarios


# Clean all files
clean:
	rm -rf ./build biblioteca testesUnitarios coverage/*
