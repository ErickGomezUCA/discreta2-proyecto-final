#include <iostream>
#include <ctime>

int main() {
    // Semilla para generar números aleatorios
    srand(static_cast<unsigned int>(time(nullptr)));

    // Número de experimentos
     int NumExperimentos;

     std::cout << "Ingrese el numero de expeimrentos a realizar: "<<std::endl;
     std::cin >> NumExperimentos;

    // Contador para contar casos favorables
    int CasosFavorables = 0;

    for (int i = 0; i < NumExperimentos; ++i) {
        // Lanzamiento de dos dados
        int dado1 = rand() % 6 + 1; // Números entre 1 y 6
        int dado2 = rand() % 6 + 1;

        // Verificar si la cara 6 aparece en al menos uno de los dados
        if (dado1 == 6 || dado2 == 6) {
            // Calcular la suma de los puntos
            int SumaPuntos = dado1 + dado2;

            // Verificar si la suma es mayor o igual a 9
            if (SumaPuntos >= 9) {
                CasosFavorables++;
            }
        }
    }

    // Calcular la probabilidad
    double probabilidad = static_cast<double>(CasosFavorables) / NumExperimentos;

    // Mostrar resultados
    std::cout << "Número de experimentos: " << NumExperimentos << std::endl;
    std::cout << "Casos favorables: " << CasosFavorables << std::endl;
    std::cout << "Probabilidad P(suma >= 9 | cara 6 aparece): " << probabilidad << std::endl;

    return 0;
}
