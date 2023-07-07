/* USER STORIES

Como um usuário da biblioteca, quero poder pesquisar um livro pelo título para verificar sua disponibilidade. 
1. Ao pesquisar um título de livro válido, o sistema deverá exibir se o livro está disponível para empréstimo. 
2. Se o livro estiver disponível, o sistema deverá mostrar o status "Disponível" juntamente com o número de cópias disponíveis. 
3. Se o livro não estiver disponível, o sistema deverá exibir o status "Indisponível" e informar a data de devolução prevista. 
4. Caso não haja nenhum livro com o título pesquisado, o sistema deverá exibir uma mensagem indicando que nenhum livro foi encontrado. 


Como usuário da biblioteca, quero poder visualizar os livros que atualmente tenho emprestados para que possa ter informações sobre livros que estão sobre minha posse. 
1. O sistema deve permitir que um membro da biblioteca visualize seus livros emprestados fornecendo seu ID de membro. 
2. Se o membro tiver livros emprestados, o sistema deve exibir uma lista dos títulos dos livros, juntamente com as datas de empréstimo e devolução previstas. 
3. Se o membro não tiver nenhum livro emprestado, o sistema deve exibir uma mensagem informando que o membro não possui nenhum livro emprestado no momento. 
4. O sistema deve garantir que apenas o membro associado ao ID fornecido possa visualizar seus livros emprestados. 


Como um administrador, quero poder adicionar um novo livro ao catálogo da biblioteca, para que o catálogo esteja sempre atualizado. 
1. O sistema deve permitir que o bibliotecário adicione informações sobre o livro, como título, autor, editora, etc. 
2. Todos os campos obrigatórios devem ser preenchidos para adicionar o livro com sucesso. 
3. O sistema deve gerar automaticamente um ID exclusivo para o novo livro adicionado ao catálogo. 
4. O livro adicionado deve ter sua disponibilidade definida como "Disponível" por padrão. 
5. Após adicionar o livro com sucesso, o sistema deve exibir uma mensagem de confirmação para o administrador. 


Como um usuário da biblioteca, quero poder renovar um livro emprestado, para que, caso eu não tenha conseguido, eu possa ter tempo de terminar de ler algum livro já em minha posse. 
1. O sistema deve permitir que um membro da biblioteca forneça o ID do livro que deseja renovar. 
2. O livro deve estar em posse do membro e ainda dentro do prazo de devolução. 
3. Ao renovar o livro, a data de devolução prevista deve ser atualizada para 14 dias a partir da data de renovação. 
4. O sistema deve exibir uma mensagem de confirmação para o membro, informando que a renovação foi realizada com sucesso. 


Como um bibliotecário, quero poder gerar um relatório de membros com livros em atraso, para que eu possa ter ciencia das devoluções pendentes. 
1. O sistema deve permitir que o bibliotecário gere um relatório de membros que possuem livros em atraso. 
2. O relatório deve incluir informações sobre o membro, como nome, ID e os títulos dos livros em atraso. 
3. O sistema deve definir um limite de dias após a data de devolução para considerar um livro como atrasado. 
4. O relatório gerado deve ser apresentado de forma clara e organizada, destacando os membros com livros em atraso. 


Como usuário do sistema, eu quero poder realizar o empréstimo de um livro, para que eu possa ter acesso ao livro desejado.  
1. O sistema deve permitir que o usuário pesquise o livro no catálogo. 
2. O sistema deve registrar a data de empréstimo e a disponibilidade do livro para “Indisponível”. 
3. O sistema deve verificar se o usuário não possui livros emprestados além do limite. 
4. O sistema deve verificar as informações do usuário. 

______________________________________________________________________________________
CARTÕES CRC

Classe: Livro

Responsabilidades:
- Conhece informações sobre o livro, como título, gênero, autor. 
- Conhece número de cópias do livro e disponibilidade.
- Realiza verificação da disponibilidade do livro.
- Armazena informações específicas de cada livro, como algum possível defeito, rasura e código de cada título. 
- Armazena endereço exato onde o livro está posicionado na biblioteca.

Colaboradores: 
- Emprestimo
- CatalogoLivros
- Administrador

Classe: Usuario

Responsabilidades:
- Conhece informações do usuário da biblioteca, como nome, curso, ID estudantil.  
- Mapeia os títulos que estão em posse do usuário. 
- Verifica dias de atraso que o usuário possui.
- Armazena valor da multa por livro atrasado. 
- Solicita empréstimos de livros disponíveis.
- Verifica histórico de empréstimos.

Colaboradores:
- Livro
- Emprestimo

Classe: Administrador

Responsabilidades:
- Conhece os dados do administrador que fará a modificação. 
- Faz a manutenção dos títulos da biblioteca no sistema.
- Adiciona na especificação do livro possíveis danos e/ou acontecimentos necessários para o conhecimento do próximo usuário. 
- Realiza a efetivação do empréstimo de cada usuário.
- Entra em contato com o usuário por outros plataformas caso a devolução não ocorra. 

Colaboradores:
- Usuario
- Livro
- Emprestimo

Classe: Emprestimo

Responsabilidades:
- Conhece os dados do locador.
- Registra a data de empréstimo e de devolução. 
- Verifica a disponibilidade do livro para empréstimo. 
- Armazena os dados do locador juntamente com os dados do título, período máximo pra entrega e etc.  
- Envia mensagem de tempo restante que o usuário pode ficar com o livro. 

Colaboradores:
- Usuario
- Livro

Classe: Multas

Responsabilidades:
- Conhece o tempo padrão de aluguel de um título. 
- Registra informações de multas pendentes. 
- Calcula o valor da multa que o usuário deve pagar decorrente dos dias de atraso. 
- Notifica o usuário sobre multas em aberto.  
- Disponibiliza link para pagamento da multa de atraso.  

Colaboradores:
- Usuario
- Emprestimo

Classe: CatalogoLivros

Responsabilidades:
- Conhece todas as obras que a biblioteca possui. 
- Conhece todos os gêneros literários possíveis. 
- Armazena as separações dos títulos por gêneros literários. 
- Possibilita pesquisar o livro por título, gênero, autor ou código. 
- Possibilita retirar/inserir novos títulos no catálogo.  

Colaboradores:
- Livro
- Administrador */