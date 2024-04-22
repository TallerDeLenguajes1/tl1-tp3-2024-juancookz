#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 5
#define COLS 12
void cargarMatriz(int *matriz, int filas, int columnas);
void mostrarMatriz(int matriz[FILAS][COLS]);
void promedioAnual(int matriz[FILAS][COLS]);
void valorMinMax(int matriz[FILAS][COLS]);
char *numeroAMes(int num);
int main()
{
    int matriz[FILAS][COLS];
    cargarMatriz(&(matriz[0][0]), FILAS, COLS);
    mostrarMatriz(matriz);
    promedioAnual(matriz);
    valorMinMax(matriz);
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
            n = (rand() % 40001) + 10000;
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
void promedioAnual(int matriz[FILAS][COLS])
{
    int anio = 2025;
    float promedio;
    printf("\nPromedio de ganancias por anio:\n");
    for (int i = 0; i < FILAS; i++)
    {
        printf("%d: ", anio);
        for (int j = 0; j < COLS; j++)
        {
            promedio += matriz[i][j];
        }
        promedio = promedio / COLS;
        printf("%.1f", promedio);
        anio++;
        promedio = 0;
        printf("\n");
    }
}
void valorMinMax(int matriz[FILAS][COLS])
{
    int num, mayor, menor = 50000, mesMayor, anioMayor, mesMenor, anioMenor;
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            num = matriz[i][j];
            if (num > mayor)
            {
                mayor = num;
                mesMayor = j + 1;
                anioMayor = i + 2025;
            }
            if (num < menor)
            {
                menor = num;
                mesMenor = j + 1;
                anioMenor = i + 2025;
            }
        }
    }
    char *nombreMes;

    nombreMes = numeroAMes(mesMenor);
    printf("\nMenor: %d\n %s/%d", menor, nombreMes, anioMenor);

    nombreMes = numeroAMes(mesMayor);
    printf("\nMayor: %d\n %s/%d", mayor, nombreMes, anioMayor);
}
char *numeroAMes(int num)
{
    switch (num)
    {
    case 1:
        return "Enero";
    case 2:
        return "Febrero";
    case 3:
        return "Marzo";
    case 4:
        return "Abril";
    case 5:
        return "Mayo";
    case 6:
        return "Junio";
    case 7:
        return "Julio";
    case 8:
        return "Agosto";
    case 9:
        return "Septiembre";
    case 10:
        return "Octubre";
    case 11:
        return "Noviembre";
    case 12:
        return "Diciembre";
        break;
    default:
        return "Mes invalido";
        break;
    }
}