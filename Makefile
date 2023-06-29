# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++17 -Wall

INCLUDE_FLAGS = -I include/

# Generate executable
default: biblioteca

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

administrador:  administrador.o
	$(CC) $(CFLAGS) -o administrador build/administrador.o

administrador.o:  src/entidades/Administrador.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Administrador.cpp -o build/administrador.o

main: main.o
	$(CC) $(CFLAGS) -o main build/main.o

main.o: src/main.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/main.cpp -o build/main.o


# Link all files
biblioteca: pessoa.o usuario.o administrador.o main.o
	$(CC) $(CFLAGS) -o biblioteca build/main.o build/pessoa.o build/usuario.o build/administrador.o


# Clean all files
clean:
	rm -rf ./build biblioteca
