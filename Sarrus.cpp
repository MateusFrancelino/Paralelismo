#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <omp.h>
#include<string>

using namespace std;

int sorteio(int maximo, int minimo = 0) {
    int i;



    i = rand() % maximo + minimo;


    return i;
}


int main() {
    string texto;
    int matrix[3][3];
    long long int ver = 0;
    long long int azul = 0;
    int matrixsarrus[3][5];
    int total = 0;
    long double tempo_execucao = 0.000000;
    long long int determinante = 0;
    long double inicio = 0.0;
    long double final = 0.0;

    for (int exec = 0; exec < 1; exec++) {
        ver = 0;
        azul = 0;
        total = 0;
        determinante = 0;
        /*
            for (int linha = 0; linha < 3; linha++) {
                 for (int coluna = 0; coluna < 3; coluna++) {
                     matrix[linha][coluna] = sorteio(333);
                 }
         }

       */

        matrix[0][0] = 1;
        matrix[0][1] = 5;
        matrix[0][2] = -2;
        matrix[1][0] = 8;
        matrix[1][1] = 3;
        matrix[1][2] = 0;
        matrix[2][0] = 4;
        matrix[2][1] = -1;
        matrix[2][2] = 2;

        inicio = omp_get_wtime();


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
        






            int soma_local = 0;
            int sub_local = 0;


            for (int coluna = 0; coluna < 3; coluna++) {
                soma_local += matrixsarrus[0][coluna] * matrixsarrus[1][coluna + 1] * matrixsarrus[2][coluna + 2];
           
            }

            for (int coluna = 4; coluna > 1; coluna--) {
                sub_local -= matrixsarrus[0][coluna] * matrixsarrus[1][coluna - 1] * matrixsarrus[2][coluna - 2];
                
            }


            determinante += soma_local + sub_local;

        
        final = omp_get_wtime();
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
