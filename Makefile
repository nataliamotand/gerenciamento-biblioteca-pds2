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

usuario: usuario.o pessoa.o
	$(CC) $(CFLAGS) -o usuario build/usuario.o build/pessoa.o

usuario.o: src/entidades/Usuario.cpp src/entidades/Pessoa.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Usuario.cpp -o build/usuario.o

administrador:  administrador.o pessoa.o
	$(CC) $(CFLAGS) -o administrador build/administrador.o build/pessoa.o

administrador.o:  src/entidades/Administrador.cpp src/entidades/Pessoa.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Administrador.cpp -o build/administrador.o

livro: livro.o
	$(CC) $(CFLAGS) -o livro build/livro.o

livro.o: src/entidades/Livro.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Livro.cpp -o build/livro.o

catalogo: catalogo.o
	$(CC) $(CFLAGS) -o catalogo build/catalogo.o

catalogo.o: src/entidades/CatalogoLivros.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/CatalogoLivros.cpp -o build/catalogo.o

bancoDeDados: bancoDeDados.o
	$(CC) $(CFLAGS) -o bancoDeDados build/bancoDeDados.o

bancoDeDados.o: src/entidades/BancoDeDados.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/BancoDeDados.cpp -o build/bancoDeDados.o

main: main.o
	$(CC) $(CFLAGS) -o main build/main.o

main.o: src/main.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/main.cpp -o build/main.o


# Link all files
biblioteca: pessoa.o usuario.o administrador.o livro.o catalogo.o bancoDeDados.o main.o
	$(CC) $(CFLAGS) -o biblioteca build/main.o build/pessoa.o build/usuario.o build/administrador.o build/livro.o build/catalogo.o build/bancoDeDados.o


# Compilando o executável de testes
testeAdministrador: testeAdministrador.o
	$(CC) $(CFLAGS) -o testeAdministrador build/testeAdministrador.o

testeAdministrador.o: testes/testeAdministrador.cpp
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c testes/testeAdministrador.cpp -o build/testeAdministrador.o

testeUsuario: testeUsuario.o
	$(CC) $(CFLAGS) -o testeUsuario build/testeUsuario.o

testeUsuario.o: testes/testeUsuario.cpp
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c testes/testeUsuario.cpp -o build/testeUsuario.o

testesUnitarios: testeAdministrador.o pessoa.o administrador.o testeUsuario.o usuario.o
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -o testesUnitarios build/testeAdministrador.o build/pessoa.o build/administrador.o build/testeUsuario.o build/usuario.o


# Run coverage
coverage:
	./testesUnitarios


# Clean all files
clean:
	rm -rf ./build biblioteca testesUnitarios coverage/*
