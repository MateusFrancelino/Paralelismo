#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

int sorteio(int maximo, int minimo = 0) {
    int i;

    

    i = rand() % maximo + minimo;


    return i;
}


int main() {

    int matrix[3][3];
    for (int exec = 0; exec < 31;exec++) {
   
        for (int linha = 0; linha < 3; linha++) {
            for (int coluna = 0; coluna < 3; coluna++) {
                matrix[linha][coluna] = sorteio(333);
            }
    }

    long long int ver = 0;
    long long int azul = 0;
    int matrixsarrus [3][5];
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 5; c++) {
            if (c > 2) {
                
                matrixsarrus[l][c] = matrix[l][(c - 3)];
            }
            else {
                matrixsarrus[l][c] = matrix[l][c];
            }
        }
        
    }
   
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 5; c++) {
            cout << matrixsarrus[l][c]<<"          ";
        }
        cout << endl << endl << endl << endl;
    }

    for (int coluna = 0; coluna < 3; coluna++) {
        ver += matrixsarrus[0][coluna] * matrixsarrus[1][coluna + 1] * matrixsarrus[2][coluna + 2];
    }

    for (int coluna = 4; coluna > 1; coluna--) {
        azul -= matrixsarrus[0][coluna] * matrixsarrus[1][coluna - 1] * matrixsarrus[2][coluna - 2];
    }
    cout << endl << endl << "resultado" << endl;
    cout << ver;
    cout << endl << endl << "resultado" << endl;
    cout << azul;

    long long int determinante = ver + azul;
    cout << endl << endl << "determinante" << endl;
    cout << determinante;
    cout << endl << endl << endl << endl << endl << endl;
    }
    return 0;
}
