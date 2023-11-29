#include <iostream>
#include <ctime>

int main() {
    // Semilla para generar números aleatorios
    srand(static_cast<unsigned int>(time(nullptr)));

    // Número de experimentos
    const int num_experimentos = 100;

    // Contador para contar casos favorables
    int casos_favorables = 0;

    for (int i = 0; i < num_experimentos; ++i) {
        // Lanzamiento de dos dados
        int dado1 = rand() % 6 + 1; // Números entre 1 y 6
        int dado2 = rand() % 6 + 1;

        // Verificar si la cara 6 aparece en al menos uno de los dados
        if (dado1 == 6 || dado2 == 6) {
            // Calcular la suma de los puntos
            int suma_puntos = dado1 + dado2;

            // Verificar si la suma es mayor o igual a 9
            if (suma_puntos >= 9) {
                casos_favorables++;
            }
        }
    }

    // Calcular la probabilidad
    double probabilidad = static_cast<double>(casos_favorables) / num_experimentos;

    // Mostrar resultados
    std::cout << "Número de experimentos: " << num_experimentos << std::endl;
    std::cout << "Casos favorables: " << casos_favorables << std::endl;
    std::cout << "Probabilidad P(suma >= 9 | cara 6 aparece): " << probabilidad << std::endl;

    return 0;
}
