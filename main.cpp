#include <iostream>

using namespace std;

void construtor(int hash[5][5]) {
  int i, j;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      hash[i][j] = -1;
    }
  }
}

int Funcao_Posicao(int numero) {
  numero = numero / 2 + 1;
  numero %= 5;
  return numero;
}

int main() {
  int j = 0;
  int num, op, i = 0;
  int tabela[5][5];
  construtor(tabela);
  while (1) {
    getchar();
    getchar();
    cout << endl
         << "Opcoes:" << endl
         << "1 - Inserir" << endl
         << "2 - Buscar" << endl
         << "3 - Excluir" << endl;
    cin >> op;
    switch (op) {
    case 1:
      cout << "Digite um numero para inserir: ";
      cin >> num;
      i = Funcao_Posicao(num);
      while (1) {
        if (tabela[i][j] == -2 || tabela[i][j] == -1) {
          break;
        } else
          j++;
      }

      tabela[i][j] = num;
      j = 0;
      break;

    case 2:
      cout << "Digite um numero para procurar: ";
      cin >> num;
      i = Funcao_Posicao(num);
      while (j < 5) {
        if (tabela[i][j] != num) {
          j++;
        } else {
          cout << "O numero " << tabela[i][j] << " foi achado na posicao [" << i
               << "][" << j << "]" << endl;
          break;
        }
      }
      if (j == 5)
        cout << "O numero nao foi achado" << endl;

      j = 0;
      break;
case 3:
      cout << "Digite um numero para excluir: ";
      cin >> num;
      i = Funcao_Posicao(num);
      while (j < 5) {
        if (tabela[i][j] != num) {
          j++;
        } else {

          if (tabela[i][j] == num) {
            cout << "O numero excluido foi " << tabela[i][j] << endl;
            tabela[i][j] = -2;

          } else {
            cout << "O numero desejado nao foi encontrado" << endl;
          }
          break;
        }
      }
      while (j < 5) {
        if (tabela[i][j] != num) {
          j++;
        } else {
          cout << "O numero excluido foi " << tabela[i][j] << endl;
          tabela[i][j] = -2;
          break;
        }
      }
      if (j == 5)
        cout << "O numero desejado nao foi encontrado" << endl;

      j = 0;
      break;
    }
    int a, b;
    for (a = 0; a < 5; a++) {
      for (b = 0; b < 5; b++) {
        cout << tabela[a][b] << " ";
      }
      cout << endl;
    }
  }
}
