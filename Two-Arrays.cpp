#include <iostream>
#include <iomanip>
using namespace std;

//---------------------------------------
int SummaStrok(int** a, int n, int m)
{
    int i, j;
    int k = 0;
    int s = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++) {
            if ((a[i][j]) % 2 != 0) {
                k++;
            }
        }
        if (k == m)  s++;
        k = 0;
    }
    return s;
}
//---------------------------------------
void Vyvod(int** a, int n, int m)
{
    int i, j; cout << "матрица" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << setw(4) << a[i][j] << " ";
        cout << endl;
    }
}
//---------------------------------------
int** Sdvig(int** a, int n, int m, int l) {
    int temp, mmin;
    for (int k = 0; k < l; k++) {
        for (int j = 0; j < m - 1; j++) {
            mmin = j + 1;
            for (int i = 0; i < n; i++) {
                temp = a[i][j];
                a[i][j] = a[i][mmin];
                a[i][mmin] = temp;
            }
        }
    }
    return a;
}

int** Create(int** a, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++) // под матрицу
        a[i] = new int[m];
    cout << endl << "Введите Элементы матрицы: " << endl;
    for (i = 0; i < n; i++) // ввод матрицы
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    cout << endl;
    return a;
}

//---------------------------------------  
int main() {
    int m, n, i, j, k, f;
    cout << "Введите количество строк(n) и столбцов матрицы(m):";
    cout << endl << "n=";
    cin >> n;
    cout << endl << "m=";
    cin >> m;
    int** a = new int* [n]; // выделение памяти
       while (1) {
        cout << "\n             Главное меню            \n ";
        cout << "Введите номер функции для её выполнения\n";
        cout << "1 --- Ввод массива\n";
        cout << "2 --- Вывод массива\n";
        cout << "3 --- Определить количество строк матрицы, не содержащих ни одного четного элемента.\n";
        cout << "4 --- Осуществить циклический сдвиг элементов прямоугольной матрицы на k элементов влево, k может быть больше количества элементов в строке или столбце\n";
        cin >> f;
    
        switch (f) {
        case 1:
        {
            a = Create(a, n, m);
            break;
        }
        case 2:
        {
            Vyvod(a, n, m);
            break;
        }
        case 3:
        {
            k = SummaStrok(a, n, m); // суммирование элементов строк
            cout << "Количество строк= " << k << endl;
            break;
        }
        case 4:
        {
            int temp, l, mmin;
            cout << "Введите количество сдвигов= " << endl;
            cin >> l;
            a = Sdvig(a, n, m, l);
            break;
        }
        }

    }
    for (i = 0; i < n; i++) // под матрицу
        delete[]a[i]; // освобождение памяти
    delete[]a;
    return 0;
}
