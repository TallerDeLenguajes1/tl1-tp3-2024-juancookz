#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 5
#define COLS 12
void cargarMatriz(int *matriz, int filas, int columnas);
void mostrarMatriz(int matriz[FILAS][COLS]);
int main()
{
    int matriz[FILAS][COLS];
    cargarMatriz(&(matriz[0][0]), FILAS, COLS);
    mostrarMatriz(matriz);
    return 0;
}
void cargarMatriz(int *matriz, int filas, int columnas)
{
    srand(time(NULL));
    int n, *dir;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            n = (rand() % 40000) + 10000;
            dir = (matriz + i * columnas + j);
            *dir = n;
        }
    }
}
void mostrarMatriz(int matriz[FILAS][COLS])
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d|", matriz[i][j]);
        }
        printf("\n");
    }
}
