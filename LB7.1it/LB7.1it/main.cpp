#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** P, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** P, const int rowCount, const int colCount);
void Sort(int** P, const int rowCount, const int colCount);
void Change(int** P, const int col1, const int col2, const int rowCount);
void Calc(int** P, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -21;
    int High = 24;
    int rowCount = 9;
    int colCount = 6;
    int** P = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        P[i] = new int[colCount];

    Create(P, rowCount, colCount, Low, High);
    Print(P, rowCount, colCount);
    Sort(P, rowCount, colCount);
    Print(P, rowCount, colCount);

    int S = 0; 
    int k = 0; 
    Calc(P, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    Print(P, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] P[i];
    delete[] P;
    return 0;
}

void Create(int** P, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            P[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** P, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << P[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** P, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < colCount - 1; i0++)
        for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
            if ((P[0][i1] < P[0][i1 + 1]) 
                ||
                (P[0][i1] == P[0][i1 + 1] && P[1][i1] < P[1][i1 + 1]) 
                ||
                (P[0][i1] == P[0][i1 + 1] && P[1][i1] == P[1][i1 + 1] && P[2][i1] > P[2][i1 + 1])) 
                Change(P, i1, i1 + 1, rowCount);
}

void Change(int** P, const int col1, const int col2, const int rowCount)
{
    int tmp;
    for (int j = 0; j < rowCount; j++)
    {
        tmp = P[j][col1];
        P[j][col1] = P[j][col2];
        P[j][col2] = tmp;
    }
}

void Calc(int** P, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (P[i][j] % 3 == 0 && !( P[i][j] < 0)) 
            {
                S += P[i][j];
                k++;
                P[i][j] = 0; 
            }
}
