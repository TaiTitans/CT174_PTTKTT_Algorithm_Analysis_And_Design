//
// Created by TaiTitans on 3/28/2023.
// Quick Sort
//
#include <stdio.h>

typedef int keytype;
typedef float othetype;

typedef struct{
    keytype key;
    othetype othefields;
}recordtype;

void swap(recordtype *x, recordtype *y){
    recordtype t;
    t = *x;
    *x = *y;
    *y = t;
}
// sap xep nhanh
// tim chot

int findPivot(recordtype a[], int i, int j){
    keytype firstkey = a[i].key;
    int k = i+1;
    while(k<=j && a[k].key == firstkey) k++;
    if(k>j) return -1;
    if(a[k].key > firstkey) return k;

    return i;
}

//ham phan hoach partition

int partition(recordtype a[], int i, int j, keytype pivot){
    int L, R;
    L= i;
    R = j;
    while(L<=R){
        while(a[L].key < pivot) L++;
        while(a[R].key >= pivot) R--;

        if(L<R) swap(&a[L], &a[R]);
    }
    return L;
}

void quickSort(recordtype a[], int i, int j){
    keytype pivot;
    int pivotindex, k;
    pivotindex = findPivot(a,i,j);
    if(pivotindex != -1){
        pivot = a[pivotindex].key;
        k = partition(a,i,j,pivot);
        quickSort(a,i,k-1);
        quickSort(a,k,j);
    }
}
void read_Data(recordtype a[], int *n){
    FILE *f;
    f=fopen("C:\\Users\\taiti\\OneDrive - ctu.edu.vn\\Documents\\GitHub\\CT174_PTTKTT\\CT174_PTTKTT_Algorithm-Analysis-And-Design\\Buoi1\\data.txt","r");
    int i = 0;
    if(f!=NULL)
    while(!feof(f)){
        fscanf(f,"%d%f", &a[i].key,&a[i].othefields);
        i++;
    }else printf("\nLoi mo file.");
    fclose(f);
    *n=i;
}

void print_Data(recordtype a[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%3d%5d%8.2f\n",i+1,a[i].key,a[i].othefields);
    }
}

int main(){
    recordtype a[100];
    int n;
    read_Data(a, &n);
    printf("\nDu lieu ban dau la: \n");
    print_Data(a,n);
    quickSort(a,0,n-1);
    printf("\nSau khi sap xep: \n");
    print_Data(a,n);
    return 0;
}