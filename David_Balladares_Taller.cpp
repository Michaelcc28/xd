#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
using namespace std;
void Diag_1(int t[50][50][50], int nt, int fil, int col)
{
   int i, j, k;
    for (k = 1; k < nt; k++)
    {
        cout<< "\nGrafico diagonales " <<endl;        
        cout << "Tabla N# " << (k + 0) << "\n";
        for (i = 0; i < fil; i++)
        {
            for (j = 0; j < col; j++)
            {
                
                if(i==j)
                {
                    cout<<t[k][i][j]<< "\t";
                }
                else
                {
                    cout<<" "<< "\t";
                }
            }
            cout << "\n";
        }
    }

}

void Diag_2(int t[50][50][50], int nt, int fil, int col)
{
   int i, j, k;
    for (k = 1; k < nt; k++)
    {
        cout<< "\nGrafico diagonales " <<endl;        
        cout << "Tabla N# " << (k + 1) << "\n";
        for (i = 0; i < fil; i++)
        {
            for (j = 0; j < col; j++)
            {
                
                if((i+j)==(fil-1))
                {
                    cout<<t[k][i][j]<< "\t";
                }
                else
                {
                    cout<<" "<< "\t";
                }
            }
            cout << "\n";
        }
    }

}
void Llenartablas(int t[50][50][50], int nt, int fil, int col)
{
    int i, j, k;
    srand(time(NULL));
    for (k = 0; k < nt; k++)
    {
        for (i = 0; i < fil; i++)
        {
            for (j = 0; j < col; j++)
            {
                t[k][i][j] = 1 + rand() % 10;
            }
        }
    }
}
void verlastablas(int t[50][50][50], int nt, int fil, int col)
{
    int i, j, k;
    for (k = 0; k < nt; k++)
    {
        cout << "Tabla No " << (k + 1) << "\n";
        for (i = 0; i < fil; i++)
        {
            for (j = 0; j < col; j++)
            {
                cout << t[k][i][j] << "\t";
            }
            cout << "\n";
        }
    }
}
int diagonales(int t[50][50][50], int nt, int fil, int col, int suma, int sumadiago)
{
    int i, j, k;
    for (k = 0; k < nt; k++)
    {
        suma = 0;

        for (i = 0; i < fil; i++)
        {
            for (j = 0; j < col; j++)
            {
                if (k == 0)
                {
                    if (i == j)
                    {
                        suma += t[k][i][j];
                        return suma;

                    }
                }
                else if (k == 1)
                {
                    if ((i + j) == (fil - 1))
                    {
                        sumadiago += t[k][i][j];
                        return sumadiago;
                    }
                }
            }
        }
    
 
    }
}

main()
{
    int tablas[50][50][50], nt, fil, col, i, j, k, suma, sumadiago ;
    cout << "Escribir el numero de Tablas: ";
    cin >> nt;
    cout << "Escribir el numero de Filas: ";
    cin >> fil;
    cout << "Escribir el numero de Columnas: ";
    cin >> col;
    cout << "Tablas generadas\n";
    Llenartablas(tablas, nt, fil, col);
    verlastablas(tablas, nt, fil, col);
    diagonales(tablas, nt, fil, col, suma, sumadiago);
    cout << "\nLa suma = " << suma << "\n";
    Diag_1 (tablas, nt, fil, col);
    cout << "\nLa suma = " << sumadiago << "\n";
    Diag_2 (tablas, nt, fil, col);
}