#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;


//№1(сумма четных положительных элементов массива)
int main()
{
    const int size = 10;
    int *a = new int [size];
    int sum = 0;
    srand(time(NULL));
    
    
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 20 - 10;
        printf("%d ", a[i]);
        if (a[i] % 2 == 0 and a[i] > 0) {
            sum += a[i];
        }
    }
    printf("\n%d ", sum);
    delete [] a;
    return 0;
}

//№2(нахождение максимального элемента с четным индексом)
int main()
{
    const int size = 20;
    int *a = new int [size];
    srand(time(NULL));
    int max = a[0];
    
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 20 - 10;
        printf("%d ", a[i]);
        if (i != 0 and i % 2 == 0 and a[i] > max) {
            max = a[i];
        }
    }
    printf("\n%d ", max);
    delete [] a;
    return 0;
}

//№3(нахождение элементов массива, значение которых меньше среднего арифметического, взятого от всех элементов массива)
int main()
{
    const int size = 20;
    int *a = new int [size];
    srand(time(NULL));
    int sum = 0, n, i, avg;
    
    for (i = 0; i < size; i++) {
        a[i] = rand() % 99 + 1;
        sum += a[i];
        n += 1;
        printf("%d ", a[i]);
    }
    printf("\n");
    
    avg = sum / n;
    printf("\n%d\n", avg);
    for (i = 0; i < size; i++) {
        if (a[i] < avg) {
            printf("%d ", a[i]);
        }
    }
    delete [] a;
    return 0;
}

//№4(определение двух наименьших элементов массива)
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    const int size = 20;
    int *a = new int [size];
    srand(time(NULL));
    int i, min1, min2, k;
    
    for (i = 0; i < size; i++) {
        a[i] = rand() % 99 + 1;
        printf("%d ", a[i]);
    }
    printf("\n");
    
    if (a[0] < a[1]) {
        min1 = 0;
        min2 = 1;
    }
    else {
        min1 = 1;
        min2 = 0;
    }
    
    for (i = 2; i < size; i++) {
        if (a[i] < a[min1]) {
            k = min1;
            min1 = i;
            if (a[min1] < a[min2]) {
                min2 = k;
            }
        }
        else if (a[i] < a[min2]) {
            min2 = i;
        }
    }
    printf("\n\n%d %d", a[min1], a[min2]);
    delete [] a;
    return 0;
}

//№5(сжатие массива и удаление из него элементов, величина которых находится в интервале [а, b])
int main()
{
    const int size = 10;
    int *a = new int [size];
    srand(time(NULL));
    int i, a1 = 10, b = 70, n, p;
    
    for (i = 0; i < size; i++) {
        a[i] = rand() % 99 + 1;
        printf("%d ", a[i]);
    }
    printf("\n");
    
    i = 0;
    p = size;
    while (i < p) {
        if (a1 <= a[i] && a[i] <= b) {
            p -= 1;
            for (n = i; n < p; n++) {
                a[n] = a[n + 1];
            }
        } else
            i += 1;
    }
    
    for (i; i < size; i++) {
        a[i] = 0;
    }
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    
    delete [] a;
    return 0;
}

//№6(сумма модулей элементов массива, расположенных после первого отрицательного элемента)
int main()
{
    const int size = 10;
    int *a = new int [size];
    srand(time(NULL));
    int i, sum;
    
    for (i = 0; i < size; i++) {
        a[i] = rand() % 10 - 5;
        printf("%d ", a[i]);
    }
    printf("\n");
    
    sum = 0;
    for (i = 0; i < size; i++) {
        if (a[i] < 0) {
            for (i = i + 1; i < size; i++) {
                sum += abs(a[i]);
            }
        }
    }
    
    printf("\n%d ", sum);
    delete [] a;
    return 0;
}
  
//№7(нахождение номера минимального по модулю элемента массива)
int main()
{
    const int size = 10;
    int *a = new int [size];
    srand(time(NULL));
    int i, minabs;
    
    for (i = 0; i < size; i++) {
        a[i] = rand() % 20 - 10;
        printf("%d ", a[i]);
    }
    printf("\n");
    
    minabs = 0;
    for (i = 1; i < size; i++)
        if (abs(a[i]) < abs(a[minabs]))
            minabs = i;
    
    printf("%s%d", "Индекс минимального модуля элемента: ", minabs);
    
    delete [] a;
    return 0;
}

//№8(сумма всех цифр целочисленного массива)
int main()
{
    const int size = 10;
    int *a = new int [size];
    srand(time(NULL));
    int i, sum, h;
    printf("%s\n", "Введите правую границу интервала[0, x < 1000]");
    scanf("%d", &h);
        
    for (i = 0; i < size; i++) {
        a[i] = rand() % (h + 1);
        printf("%d ", a[i]);
    }
    printf("\n");
    
    sum = 0;
    for (i = 0; i < size; i++) {
        if ((a[i] / 100) != 0)
            sum += a[i] / 100 + a[i] % 10 + ((a[i] % 100) % 10);
        else if (a[i] / 10 != 0)
            sum += a[i] / 10 + a[i] % 10;
        else sum += a[i] % 10;
    }
    
    printf("%s%d ", "Сумма:", sum);
    
    delete [] a;
    return 0;
}

//№9(замена всех элементов массива их квадратами)
int main()
{
    const int size = 4;
    srand(time(NULL));
    int i, j;
    
    int **a = new int *[size];
    for (j = 0; j < size; j++) {
        a[j] = new int [size];
    }
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            a[i][j] = rand() % 19 + 1;
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            a[i][j] *= a[i][j];
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < size; i++) {
        delete [] a[i];
    }
    delete [] a;
    return 0;
}

//№10(заполнение двумерного массива и вычисление суммы его элементов в каждой строчке, определение максимального значения строчки и ее номера)
int main()
{
    const int size = 4;
    srand(time(NULL));
    int i, j, sum, maxsum, maxstr;
    
    int **a = new int *[size];
    for (j = 0; j < size; j++) {
        a[j] = new int [size];
    }
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            a[i][j] = rand() % 90 + 10;
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    
    sum = 0;
    maxsum = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            sum += a[i][j];
        }
        printf("%s%d%s%d\n", "Сумма ", i + 1, "-ой строки: ", sum);
        if (sum > maxsum) {
            maxsum = sum;
            maxstr = i + 1;
        }
        sum = 0;
    }
    printf("\n%s%d%s%d", "Максимальная сумма у ", maxstr, "-ой(ей) строки: ", maxsum);
    
    for (i = 0; i < size; i++) {
        delete [] a[i];
    }
    delete [] a;
    return 0;
}
