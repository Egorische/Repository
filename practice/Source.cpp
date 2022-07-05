#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int n, m;
    cout << "Enter n: "; cin >> n;
    cout << "Enter m: "; cin >> m;

    double** A = new double* [n], mult;
    for (int i = 0; i < n; i++)
        A[i] = new double[m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = rand() % 19 - 9;
            cout << setw(4) << A[i][j] << " ";
        }
        cout << endl;
    }

    for (int j = 0; j < m; j++)
    {
        mult = 1.0;
        int k = 0;
        for (int i = 0; i < n; i++)
            if (A[i][j] > 0) { k++; mult *= A[i][j]; }
        if (k != 0) cout << "column " << j + 1 << "  mult pos:" << mult << "\n";
        else cout << "column " << j + 1 << "  positive elements are absent\n";
    }

    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;
    system("pause");
    return 0;
}