#include <iostream>
#include <vector>
#include <string>
#include <cmath>

// Función para limpiar el búfer de entrada
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Función para imprimir un mensaje de bienvenida
void printWelcomeMessage() {
    std::cout << "Bienvenido al programa de compuertas lógicas.\n";
}

// Función para imprimir el menú
void printMenu() {
    std::cout << "\nSeleccione una opción:\n";
    std::cout << "1. Cambiar valores de entrada\n";
    std::cout << "2. Mostrar operadores lógicos\n";
    std::cout << "3. Realizar operaciones lógicas\n";
    std::cout << "4. Generar ecuaciones de mapas de Karnaugh\n";
    std::cout << "0. Salir\n";
}

// Función para esperar la pulsación de la tecla Enter
void waitForEnter() {
    std::cout << "\nPresione Enter para continuar...";
    clearInputBuffer();
    std::cin.get();
}

// Función para obtener la opción del usuario
int getOption() {
    int option;
    std::cout << "\nOpción: ";
    std::cin >> option;
    clearInputBuffer();
    return option;
}

// Función para cambiar los valores de entrada
void performChangeValues(std::vector<bool>& inputs) {
    for (int i = 0; i < inputs.size(); i++) {
        std::cout << "Ingrese el nuevo valor para el input " << i + 1 << " (0 o 1): ";
        char value;
        std::cin >> value;
        clearInputBuffer();

        if (value != '0' && value != '1') {
            std::cout << "Valor inválido.\n";
            return;
        }

        inputs[i] = value == '1';
    }

    std::cout << "Valores de entrada cambiados con éxito.\n";
}

// Función para mostrar los operadores lógicos
void displayBooleanOperators() {
    std::cout << "\nOperadores lógicos disponibles:\n";
    std::cout << "& : AND lógico (conexión en serie)\n";
    std::cout << "| : OR lógico (conexión en paralelo)\n";
    std::cout << "! : NOT lógico (inversión)\n";
    std::cout << "^ : XOR lógico (OR exclusivo)\n";
    std::cout << "!& : NAND lógico (AND lógico seguido de una inversión)\n";
}

// Función para realizar la operación AND lógico
bool performAND(bool input1, bool input2) {
    bool result = input1 && input2;
    std::cout << "Operación AND lógico:\n";
    std::cout << "Input 1: " << input1 << "\n";
    std::cout << "Input 2: " << input2 << "\n";
    std::cout << "Resultado: " << result << "\n";
    return result;
}

// Función para realizar la operación OR lógico
bool performOR(bool input1, bool input2) {
    bool result = input1 || input2;
    std::cout << "Operación OR lógico:\n";
    std::cout << "Input 1: " << input1 << "\n";
    std::cout << "Input 2: " << input2 << "\n";
    std::cout << "Resultado: " << result << "\n";
    return result;
}

// Función para realizar la operación NOT lógico
bool performNOT(bool input) {
    bool result = !input;
    std::cout << "Operación NOT lógico:\n";
    std::cout << "Input: " << input << "\n";
    std::cout << "Resultado: " << result << "\n";
    return result;
}

// Función para realizar la operación XOR lógico
bool performXOR(bool input1, bool input2) {
    bool result = input1 != input2;
    std::cout << "Operación XOR lógico:\n";
    std::cout << "Input 1: " << input1 << "\n";
    std::cout << "Input 2: " << input2 << "\n";
    std::cout << "Resultado: " << result << "\n";
    return result;
}

// Función para realizar la operación NAND lógico
bool performNAND(bool input1, bool input2) {
    bool result = !(input1 && input2);
    std::cout << "Operación NAND lógico:\n";
    std::cout << "Input 1: " << input1 << "\n";
    std::cout << "Input 2: " << input2 << "\n";
    std::cout << "Resultado: " << result << "\n";
    return result;
}

// Función para realizar las operaciones lógicas
void performBooleanOperations(const std::vector<bool>& inputs) {
    char operation;
    std::cout << "\nIngrese la operación lógica a realizar: ";
    std::cin >> operation;
    clearInputBuffer();

    bool result;

    switch (operation) {
        case '&':
            result = performAND(inputs[0], inputs[1]);
            break;
        case '|':
            result = performOR(inputs[0], inputs[1]);
            break;
        case '!':
            result = performNOT(inputs[0]);
            break;
        case '^':
            result = performXOR(inputs[0], inputs[1]);
            break;
        case '!&':
            result = performNAND(inputs[0], inputs[1]);
            break;
        default:
            std::cout << "Operación inválida.\n";
            return;
    }

    std::cout << "El resultado de la operación es: " << result << "\n";
}

// Función para generar las ecuaciones de mapas de Karnaugh
void generateKarnaughEquations(const std::vector<bool>& inputs) {
    int numVariables = inputs.size();
    int numTerms = pow(2, numVariables);

    std::vector<std::string> equations(numTerms);

    for (int i = 0; i < numTerms; i++) {
        std::cout << "Ingrese el valor de la salida para la combinación de entradas ";
        for (int j = numVariables - 1; j >= 0; j--) {
            std::cout << ((i >> j) & 1);
        }
        std::cout << ": ";
        char value;
        std::cin >> value;
        clearInputBuffer();

        if (value != '0' && value != '1') {
            std::cout << "Valor inválido.\n";
            return;
        }

        equations[i] = std::string(1, value);
    }

    std::cout << "\nEcuaciones de mapas de Karnaugh:\n";

    for (int i = 0; i < numTerms; i++) {
        std::cout << "Para la combinación de entradas ";
        for (int j = numVariables - 1; j >= 0; j--) {
            std::cout << ((i >> j) & 1);
        }
        std::cout << ", la salida es: " << equations[i] << "\n";
    }
}

int main() {
    std::vector<bool> inputs(2, false);

    printWelcomeMessage();

    int option;
    do {
        printMenu();
        option = getOption();

        switch (option) {
            case 1:
                performChangeValues(inputs);
                waitForEnter();
                break;
            case 2:
                displayBooleanOperators();
                waitForEnter();
                break;
            case 3:
                performBooleanOperations(inputs);
                waitForEnter();
                break;
            case 4:
                generateKarnaughEquations(inputs);
                waitForEnter();
                break;
            case 0:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
                waitForEnter();
                break;
        }
    } while (option != 0);

    return 0;
}
