#include <iostream>
#include <list>
#include <stdlib.h>
#include <string>
#include <vector>

/*
    Author: 
    Daniel Acco Maroni
    169481@upf.br
*/

using namespace std;
const char esc_char = 27;

int randomNum(int menor, int maior) {
  return rand() % (maior - menor + 1) + menor;
}

void printOriginalList(int memList[], int memLength) {
  cout << "Original [";

  for (int i = 0; i < memLength; i++) {
    if (i == memLength - 1) {
      cout << memList[i];
    } else {
      cout << memList[i] << " - ";
    }
  }

  cout << "]" << endl;
}

void semEspacoParaAlocacao(int numAtual) {
  cout << "[0 - " << numAtual << "] " << esc_char << "[1m"
       << "Solicitação não pode ser atendida" << esc_char << "[0m" << endl;
}

void printStringList(string numbers, int perfect, int numAtual) {

  string perfectPhrase = "";
  if (perfect > 0) {
    perfectPhrase = perfectPhrase + esc_char + "[1m" + " Encaixe perfeito" +
                    esc_char + "[0m";
  }

  cout << "[0 - " << numAtual << "] "
       << "[" << numbers << "]" << perfectPhrase << endl;
}

string getLastSpace(int index, int length) {

  string lastSpace = " - ";
  if (index == length - 1)
    lastSpace = "";

  return lastSpace;
}

void firstOrNext(int listaMem[], int listaLength, int next) {

  int lastPosition = 0;
  for (int j = 1; j <= 10; j++) {

    int numAtual = randomNum(1, 100);

    int flag = 0;
    int perfect = 0;

    string stringListNumbers = "";

    for (int k = 0; k < listaLength; k++) {
      if (listaMem[k] == 0)
        continue;

      string lastSpace = getLastSpace(k, listaLength);

      if (listaMem[k] > numAtual && flag == 0 && k >= lastPosition) {

        int calcNumber = listaMem[k] - numAtual;
        listaMem[k] = calcNumber;
        lastPosition = next == 1 ? k : 0;
        stringListNumbers = stringListNumbers + esc_char + "[1m" +
                            to_string(calcNumber) + lastSpace + esc_char +
                            "[0m";
        flag = 1;
      } else if (listaMem[k] == numAtual && flag == 0 && k >= lastPosition) {

        lastPosition = next == 1 ? k : 0;
        flag = 1;
        perfect = k;
        listaMem[k] = 0;

      } else {

        stringListNumbers =
            stringListNumbers + to_string(listaMem[k]) + lastSpace;
      }
    }

    if (flag == 0) {
      semEspacoParaAlocacao(numAtual);
      continue;
    }

    printStringList(stringListNumbers, perfect, numAtual);
  }
}

void bestOrWorst(int listaMem[], int listaLength, int worst) {

  for (int j = 1; j <= 10; j++) {

    int numAtual = randomNum(1, 100);
    int perfect = 0;
    int indexBestFit = 0;
    int findedBestFit = 0;
    int existeMemoriaComEspaco = 0;
    string stringListNumbers = "";

    for (int k = 0; k < listaLength; k++) {
      if (listaMem[k] > numAtual) {
        indexBestFit = k;
        break;
      }
    }

    for (int k = 0; k < listaLength; k++) {
      if (listaMem[k] == 0)
        continue;

      int memCalcNew = listaMem[k] - numAtual;
      int memCalcOld = listaMem[indexBestFit] - numAtual;

      if (listaMem[k] >= numAtual)
        existeMemoriaComEspaco = 1;

      if (worst == 1) {
        int holder = memCalcNew;
        memCalcNew = memCalcOld;
        memCalcOld = holder;
      }

      if (memCalcNew <= memCalcOld && memCalcNew >= 0) {
        indexBestFit = k;
        findedBestFit = 1;

        if (memCalcNew == 0 && perfect == 0) {
          perfect = k;
          listaMem[k] = 0;
        }
      }
    }

    if (existeMemoriaComEspaco == 0) {
      semEspacoParaAlocacao(numAtual);
      continue;
    }

    for (int l = 0; l < listaLength; l++) {
      if (listaMem[l] == 0)
        continue;

      string lastSpace = getLastSpace(l, listaLength);

      if (l == indexBestFit) {

        if (perfect != 1) {

          listaMem[l] = listaMem[l] - numAtual;
          stringListNumbers = stringListNumbers + esc_char + "[1m" +
                              to_string(listaMem[l]) + lastSpace + esc_char +
                              "[0m";
        }

      } else {
        stringListNumbers =
            stringListNumbers + to_string(listaMem[l]) + lastSpace;
      }
    }

    printStringList(stringListNumbers, perfect, numAtual);
  }
}

int main() {

  cout << "Gerenciador de memória por partições dinâmicas" << endl;
  srand(5);

  int memLength = randomNum(8, 15);
  int memList[memLength];

  for (int i = 0; i < memLength; i++) {
    memList[i] = randomNum(1, 100);
  }

  cout << "Escolha um dos algoritmos:" << endl;
  cout << "First-fit = 0" << endl;
  cout << "Best-fit = 1" << endl;
  cout << "Worst-fit = 2" << endl;
  cout << "Circular-fit = 3" << endl;

  int n;
  cin >> n;

  printOriginalList(memList, memLength);

  switch (n) {
  case 0:
    cout << "Algoritmo First-fit!" << endl;
    firstOrNext(memList, memLength, 0);
    break;
  case 1:
    cout << "Algoritmo Best-fit!" << endl;
    bestOrWorst(memList, memLength, 0);
    break;
  case 2:
    cout << "Algoritmo Worst-fit!" << endl;
    bestOrWorst(memList, memLength, 1);
    break;
  case 3:
    cout << "Algoritmo Circular-fit (next)!" << endl;
    firstOrNext(memList, memLength, 1);
    break;
  default:
    cout << "Algoritmo não encontrado" << endl;
  }

  return 0;
}
