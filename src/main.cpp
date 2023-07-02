#include "interface.cpp"

#include <iostream>

int main() {
    int escolha;

    do {
        std::cout << "1 - Logar administrador" << std::endl;
        std::cout << "2 - Logar usuario" << std::endl;
        std::cout << "3 - Sair" << std::endl;
        std::cout << "Escolha: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1:{
                interfaceAdministrador();
                break;
            }
            case 2: {
                interfaceUsuario();
                break;
            }
            case 3:{
                std::cout << "Encerrando sistema da biblioteca" << std::endl;
                break;
            }
            default:{
                std::cout << "Opcao invalida" << std::endl;
                break;
            }
        }
    } while (escolha != 3);
    
    return 0;
}
