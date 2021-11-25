#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int Character(int** a, const int k, const int j)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        if (a[i][j] < 0 && a[i][j] % 2 != 0)
            sum += abs(a[i][j]);
    }
    return sum;
}

void Change(int** a, const int col1, const int col2, const int rowCount)
{
    int tmp;
    for (int i = 0; i < rowCount; i++)
    {
        tmp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = tmp;
    }
}

void Replace(int** a, const int k, const int n, const int i)
{
    for (int j0 = 0; j0 < n; j0++)
        for (int j1 = 0; j1 < n; j1++)
            if ((Character(a, k, j0)) > (Character(a, k, j1)))
                Change(a, j0, j1, k);
}
int Sum(int** a, const int k, int n)
{
    for (int j = 0; j < n; j++)
    {
        bool ok = 0;
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            if (a[i][j] < 0 && abs(a[i][j]) % 2 == 1)
            {
                sum += abs(a[i][j]);
                ok = 1;
            }
        }
        if (ok)cout << j << ' ' << sum << '\n';

    }
}

int main()
{
    srand((unsigned)time(NULL));
    int Low = -10;
    int High = 30;
    int k, n;
    cout << "rowCount = "; cin >> k;
    cout << "colCount = "; cin >> n;
    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    //Input(a, k, n);
    cout << "a[" << k << "][" << n << "] = " << endl;
    Print(a, k, n);
    Replace(a, k, n, n);
    cout << "ћатриц€, розсташована в≥дпов≥дно до зростанн€ характеристик " << endl;
    cout << "a[" << k << "][" << n << "] = " << endl;
    Print(a, k, n);
    cout << "—ума елемент≥в в тих стовпц€х, €к≥ м≥ст€ть хоч би один в≥дТЇмний елемент: " << endl;
    Sum(a, k, n);

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
