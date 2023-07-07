# gerenciamento-biblioteca-pds2

## Descrição do projeto
O projeto consiste em um sistema para biblioteca, onde é possível cadastrar livros, autores, editoras, usuários e empréstimos. O usuário pode realizar o empréstimo de um livro, devolução, renovação e reserva. O sistema também permite a geração de relatórios.

# Como compilar e executar o programa
## Para compilar
- Digitar o comando `make` no terminal
## Para executar
- Digitar `./biblioteca` no terminal
## Para executar os testes
- Digitar `./testesUnitarios` no terminal. Na execução, é possível ver o resultado para todos testes unitários
## Para gerar o relatório de cobertura e visualizar o resultado
> Você tem que ter instalado o `gcovr` no seu computador
- Digitar o comando `make coverage -B` no terminal.
    - O `-B` é para forçar um novo build toda vez que o comando é executado
- Digitar o comando `gcovr -r . --html --html-details -o coverage/coverage.html` no terminal
- Abrir o arquivo `coverage.html` na pasta `coverage/` para visualizar o resultado no navegador

## Para gerar a documentação do código
> Você tem que ter instalado o `doxygen` no seu computador
- Digitar o comando `doxygen` no terminal
- Abrir o arquivo `index.html` na pasta `docs/html` para visualizar a documentação no navegador

## Para exclusão dos arquivos objeto, executável e relatório de cobertura
- Digitar o comando `make clean` no terminal
