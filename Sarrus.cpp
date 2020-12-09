#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <omp.h>
#include<string>

using namespace std;

int main() {
    double  matrix[3][3]={ 1.332, 5.111, -2.81,
                            8.01, 3.41, 0.14,
                            4.22, -1.31, 2.41 };
    double  matrixsarrus[3][5];
    double tempo_execucao = 0.0;
    double determinante = 0.0;
    double inicio = 0.0;
    double final = 0.0; 


    for (int exec = 0; exec < 1; exec++) {
       
        determinante = 0.0;  

        inicio += omp_get_wtime();

        for (int l = 0; l < 3; l++) {
            for (int c = 0; c < 5; c++) {

                if (c > 2) 
                    matrixsarrus[l][c] = matrix[l][(c - 3)];

                else 
                    matrixsarrus[l][c] = matrix[l][c];                
            }
        }

       double soma_local = 0;
       double sub_local = 0;

        for (int coluna = 0; coluna < 3; coluna++) 
            soma_local += matrixsarrus[0][coluna] * matrixsarrus[1][coluna + 1] * matrixsarrus[2][coluna + 2];
        
        for (int coluna = 4; coluna > 1; coluna--) 
            sub_local -= matrixsarrus[0][coluna] * matrixsarrus[1][coluna - 1] * matrixsarrus[2][coluna - 2];
        
        determinante += soma_local + sub_local;
        final += omp_get_wtime();

        for (int l = 0; l < 3; l++) {
            for (int c = 0; c < 5; c++) {
                cout << matrixsarrus[l][c] << "          ";
            }
            cout << endl << endl << endl << endl;
        }
    }

    cout << "Determinante " << determinante << endl;
    tempo_execucao += (final - inicio);
    cout << (int)tempo_execucao << "     tempo_execucao" << tempo_execucao;
}
