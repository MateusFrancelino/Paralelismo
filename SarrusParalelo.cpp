#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <omp.h>

using namespace std;

int sorteio(int maximo, int minimo = 0) {
    int i;

    

    i = rand() % maximo + minimo;


    return i;
}


int main() {

    int matrix[3][3];
    long long int ver = 0;
    long long int azul = 0;
    int matrixsarrus[3][5];
    int total=0;
    for (int exec = 0; exec < 20; exec++) {
        ver = 0;
        azul = 0;
        total = 0;
            for (int linha = 0; linha < 3; linha++) {
                 for (int coluna = 0; coluna < 3; coluna++) {
                     matrix[linha][coluna] = sorteio(333);
                 }
         }
         
        
        /*
        matrix[0][0] = 1;
        matrix[0][1] = 5;
        matrix[0][2] = -2;
        matrix[1][0] = 8;
        matrix[1][1] = 3;
        matrix[1][2] = 0;
        matrix[2][0] = 4;
        matrix[2][1] = -1;
        matrix[2][2] = 2;
        */

        #pragma omp parallel num_threads(3)
        {

        #pragma omp single
            total = omp_get_num_threads();

            int id = omp_get_thread_num();

        for (int l = id; l < 3; l+=total) {
            for (int c = 0; c < 5; c++) {
                if (c > 2) {

                    matrixsarrus[l][c] = matrix[l][(c - 3)];
                }
                else {
                    matrixsarrus[l][c] = matrix[l][c];
                }
            }

        }
        }




    
   
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 5; c++) {
            cout << matrixsarrus[l][c]<<"          ";
        }
        cout << endl << endl << endl << endl;
    }
    
    #pragma omp parallel num_threads(3)
    {

    #pragma omp single
    total = omp_get_num_threads();

    int id = omp_get_thread_num();
    int bloco = 3 / 3;

    int soma_local = 0;
    for (int coluna = id; coluna < 3; coluna+=total) {
        cout << id;
        soma_local+= matrixsarrus[0][coluna] * matrixsarrus[1][coluna + 1] * matrixsarrus[2][coluna + 2];
    }
    #pragma omp atomic
    ver += soma_local;
    soma_local = 0;
    for (int coluna = id+2; coluna > 1; coluna-=total) {
        
        soma_local -= matrixsarrus[0][coluna] * matrixsarrus[1][coluna - 1] * matrixsarrus[2][coluna - 2];
        }
    
    #pragma omp atomic
    azul += soma_local;
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
