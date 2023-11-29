#include <iostream>
#include <vector>

using namespace std;

int GetRandomRange(int min, int max);

int main()
{
  // Genera una semila aleatoria
  srand(time(NULL));

  int numSimulations;

  int secondWhiteCount = 0;
  int thirdWhiteCount = 0;

  // Preguntar la cantidad de simulaciones
  cout << "Enter number of simulations:\n> ";
  cin >> numSimulations;

  // Por cada simulación realizar:
  for (int i = 0; i < numSimulations; ++i)
  {
    // Crear vector con las 3 bolas negras y 2 blancas en una urna
    vector<string> urn = {"black", "black", "black", "white", "white"};
    // Crear vector para guardar las bolas que se vayan seleccionando
    vector<string> selectedBalls;

    // Por cada bola en la urna:
    for (string ball : urn)
    {
      // Obtener un índice entre el primer valor y la cantidad máxima de bolas existentes en la urna
      int index = GetRandomRange(0, urn.size() - 1);
      // Agarrar una bola de la urna con el índice generado
      selectedBalls.push_back(urn[index]);
      // Sacar la bola de la urna
      urn.erase(urn.begin() + index);
    }

    // Contar el evento cuando la segunda bola sea blanca
    secondWhiteCount += (selectedBalls[1] == "white");
    // Contar el evento cuando la tercera bola sea blanca
    thirdWhiteCount += (selectedBalls[2] == "white");
  }

  // Obtener las probabilidades
  double secondWhiteProbability = ((double)(secondWhiteCount) / numSimulations) * 100;
  double thirdWhiteProbability = ((double)(thirdWhiteCount) / numSimulations) * 100;

  cout << "Number of simulations: " << numSimulations << endl;
  cout << "Probability of second ball is white: " << secondWhiteProbability << "%" << endl;
  cout << "Probability of third ball is white: " << thirdWhiteProbability << "%" << endl;
  cout << endl;

  return 0;
}

int GetRandomRange(int min, int max)
{
  return (rand() % (max - min + 1)) + min;
}