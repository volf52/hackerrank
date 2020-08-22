#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define UINT long long int

struct triangle {
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;

double calcArea(int a, int b, int c);
void swapTr(triangle* tr1, triangle* tr2);
void sort_by_area(triangle* tr, int n);
void fillTrArr(triangle* tr, int arr[][3], int n);
void printTrArr(triangle* tr, int n);
void copyTr(triangle* from, triangle* to);

int main()
{
    int n;
    triangle* tr;
    int arr[][3] = {
        { 23, 37, 47 },
        { 22, 18, 5 },
        { 58, 31, 31 },
        { 28, 36, 40 },
        { 54, 62, 11 },
        { 31, 41, 14 },
        { 53, 18, 54 },
        { 41, 38, 55 },
        { 55, 44, 44 },
        { 44, 48, 18 },
        { 26, 41, 65 },
        { 20, 23, 21 },
        { 58, 61, 50 },
        { 28, 56, 56 },
        { 20, 39, 32 },
        { 33, 45, 49 },
        { 26, 41, 62 },
        { 31, 46, 39 },
        { 48, 49, 67 },
        { 57, 33, 45 }
    };

    n = 20;
    tr = (triangle*)malloc(sizeof(triangle) * n);
    if (!tr)
        return -1;

    fillTrArr(tr, arr, n);
    printTrArr(tr, n);
    sort_by_area(tr, n);
    printTrArr(tr, n);

    free(tr);

    return 0;
}

void sort_by_area(triangle* tr, int n)
{
    /**
	* Sort an array a of the length n
	*/
    int i, j;
    double key;
    double arr[200];
    triangle* t;
    triangle tmp;

    // arr = (int *) malloc(sizeof(int) * n);

    // Calculate areas
    for (i = 0; i < n; i++) {
        t = (tr + i);
        arr[i] = calcArea(t->a, t->b, t->c);
    }

    // Sort arrays (insertion sort)
    for (i = 1; i < n; i++) {
        key = arr[i];
        copyTr(tr + i, &tmp);
        j = i - 1;
        while ((j >= 0) && (arr[j] > key)) {
            arr[j + 1] = arr[j];
            swapTr(tr + j + 1, tr + j);
            j--;
        }
        arr[j + 1] = key;
        copyTr(&tmp, &tr[j + 1]);
    }
}

void swapTr(triangle* tr1, triangle* tr2)
{
    int tmp;

    tmp = tr1->a;
    tr1->a = tr2->a;
    tr2->a = tmp;

    tmp = tr1->b;
    tr1->b = tr2->b;
    tr2->b = tmp;

    tmp = tr1->c;
    tr1->c = tr2->c;
    tr2->c = tmp;
}

void copyTr(triangle* from, triangle* to)
{
    to->a = from->a;
    to->b = from->b;
    to->c = from->c;
}

double calcArea(int a, int b, int c)
{
    double p;
    double area;

    p = (a + b + c) / 2.0;
    area = p * (p - a) * (p - b) * (p - c);
    return area;
}

void fillTrArr(triangle* tr, int arr[][3], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        tr[i].a = arr[i][0];
        tr[i].b = arr[i][1];
        tr[i].c = arr[i][2];
    }
}

void printTrArr(triangle* tr, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d , %d , %d\n", tr[i].a, (tr + i)->b, tr[i].c);
    }
    printf("---------------\n");
}