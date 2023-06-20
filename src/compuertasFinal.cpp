#include <iostream>
#include <vector>

class LogicOperations {
public:
    // Función que implementa la operación lógica AND
    static bool logicalAnd(bool a, bool b) {
        return a && b;
    }

    // Función que implementa la operación lógica OR
    static bool logicalOr(bool a, bool b) {
        return a || b;
    }

    // Función que implementa la operación lógica NOT
    static bool logicalNot(bool a) {
        return !a;
    }

    // Función que implementa la operación lógica XOR
    static bool logicalXor(bool a, bool b) {
        return (a && !b) || (!a && b);
    }

    // Función que implementa la operación lógica NAND
    static bool logicalNand(bool a, bool b) {
        return !(a && b);
    }
};

int main() {
    int n;
    std::cout << "Ingrese la cantidad de datos a procesar: ";
    std::cin >> n;

    std::vector<bool> inputs(n);
    for (int i = 0; i < n; i++) {
        std::cout << "Ingrese el valor para el input " << i + 1 << " (0 o 1): ";
        std::cin >> inputs[i];
    }

    int option;
    do {
        std::cout << "\nSeleccione una opción para las operaciones lógicas:\n";
        std::cout << "1. AND\n";
        std::cout << "2. OR\n";
        std::cout << "3. NOT\n";
        std::cout << "4. XOR\n";
        std::cout << "5. NAND\n";
        std::cout << "0. Salir\n";
        std::cout << "Opción: ";
        std::cin >> option;

        // Verificar la opción seleccionada y realizar la operación correspondiente
        switch (option) {
            case 1: // AND
                for (int i = 0; i < n; i++) {
                    bool result = LogicOperations::logicalAnd(inputs[i], inputs[(i + 1) % n]);
                    std::cout << "AND: " << result << std::endl;
                }
                break;
            case 2: // OR
                for (int i = 0; i < n; i++) {
                    bool result = LogicOperations::logicalOr(inputs[i], inputs[(i + 1) % n]);
                    std::cout << "OR: " << result << std::endl;
                }
                break;
            case 3: // NOT
                for (int i = 0; i < n; i++) {
                    bool result = LogicOperations::logicalNot(inputs[i]);
                    std::cout << "NOT: " << result << std::endl;
                }
                break;
            case 4: // XOR
                for (int i = 0; i < n; i++) {
                    bool result = LogicOperations::logicalXor(inputs[i], inputs[(i + 1) % n]);
                    std::cout << "XOR: " << result << std::endl;
                }
                break;
            case 5: // NAND
                for (int i = 0; i < n; i++) {
                    bool result = LogicOperations::logicalNand(inputs[i], inputs[(i + 1) % n]);
                    std::cout << "NAND: " << result << std::endl;
                }
                break;
            case 0: // Salir
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción inválida. Intente nuevamente.\n";
                break;
        }
    } while (option != 0);

    return 0;
}
