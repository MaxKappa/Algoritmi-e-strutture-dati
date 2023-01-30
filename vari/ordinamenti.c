#include <stdio.h>
#include <stdlib.h>
#define N 4

void stampa(int a[], int lung);
void scambia(int a[], int i, int j);
void selectionsort(int a[], int n);
void Mergesort(int a[], int sx, int dx);
void merge(int a[], int sx, int dx, int m);


void stampa(int a[], int lung){
    printf("[ ");
    for (int i = 0; i < lung; i++){
        printf("%d ", a[i]);
    }
    printf("]\n");
}

void scambia(int a[], int i, int j){
    int temp = 0;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void selectionsort(int a[], int n){
    if (n == 1){
        return;
    }
    int max = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > a[max]){
            max = i;
        }
    }
    scambia(a, max, n-1);
    selectionsort(a, n-1);
}

void Mergesort(int a[], int sx, int dx){
    if (sx < dx) {
    int m = (sx + dx) /2;
    Mergesort(a, sx, m);
    Mergesort(a, m+1, dx);
    merge(a, sx, dx, m);
    }
    return;
}

void merge(int a[], int sx, int dx, int m){
    int n = dx-sx+1;
    int *arr = calloc(n, sizeof(int));
    int i = sx; int j = m+1; int count = 0;
    while(i <= m && j <= dx){
        if (a[i] <= a[j]){
            printf("a[i] = %d, a[j] = %d, count = %d\n", a[i], a[j], count);
            arr[count] = a[i];
            i++;
            count++;
        } else if (a[i] > a[j]){
            printf("a[i] = %d, a[j] = %d, count = %d   else\n", a[i], a[j], count);
            arr[count] = a[j];
            j++;
            count++;
        }
    }
        while(i <= m){
            arr[count] = a[i];
            count++;
            i++;
        }
        while(j <= dx){
            arr[count] = a[j];
            count++;
            j++;
        }


    for (int i = sx; i <= dx; i++){
        a[i] = arr[i-sx];
    }
}

int main(){
    int a[N] = {7, 9, 2, 4};
    int n = 0;
/*
    for (int i = 0; i < N; i++){
        scanf("%d", &n);
        a[i] = n;
    }
*/
    stampa(a, N);
    Mergesort(a, 0, 3);
    stampa(a, N);
}