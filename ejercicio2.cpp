#include <iostream>
#include <vector>

using namespace std;

int EnteroAleatorio(int min, int max);

int main()
{
  // Genera una semila aleatoria
  srand(time(NULL));

  int numeroSimulaciones;

  int contarSegundaBlanca = 0;
  int contarTerceraBlanca = 0;

  // Preguntar la cantidad de simulaciones
  cout << "Ingrese el número de experimentos:\n> ";
  cin >> numeroSimulaciones;

  // Por cada simulación realizar:
  for (int i = 0; i < numeroSimulaciones; ++i)
  {
    // Crear vector con las 3 bolas negras y 2 blancas en una urna
    vector<string> urna = {"negro", "negro", "negro", "blanco", "blanco"};
    // Crear vector para guardar las bolas que se vayan seleccionando
    vector<string> bolasSeleccionadas;

    // Por cada bola en la urna:
    for (string bola : urna)
    {
      // Obtener un índice entre el primer valor y la cantidad máxima de bolas existentes en la urna
      int indice = EnteroAleatorio(0, urna.size() - 1);
      // Agarrar una bola de la urna con el índice generado
      bolasSeleccionadas.push_back(urna[indice]);
      // Sacar la bola de la urna
      urna.erase(urna.begin() + indice);
    }

    // Contar el evento cuando la segunda bola sea blanca
    contarSegundaBlanca += (bolasSeleccionadas[1] == "blanco");
    // Contar el evento cuando la tercera bola sea blanca
    contarTerceraBlanca += (bolasSeleccionadas[2] == "blanco");
  }

  // Obtener las probabilidades
  double probabilidadSegundaBlanca = ((double)(contarSegundaBlanca) / numeroSimulaciones) * 100;
  double probabilidadTerceraBlanca = ((double)(contarTerceraBlanca) / numeroSimulaciones) * 100;

  cout << "* Número de experimentos: " << numeroSimulaciones << endl;

  cout << "Segunda bola sea blanca:" << endl;
  cout << "\tNúmero de veces contadas: " << contarSegundaBlanca << endl;
  cout << "\tProbabilidad empírica: " << probabilidadSegundaBlanca << "%" << endl;

  cout << "Tercera bola sea blanca:" << endl;
  cout << "\tNúmero de veces contadas: " << contarTerceraBlanca << endl;
  cout << "\tProbabilidad empírica: " << probabilidadTerceraBlanca << "%" << endl;
  cout << endl;

  return 0;
}

int EnteroAleatorio(int min, int max)
{
  return (rand() % (max - min + 1)) + min;
}