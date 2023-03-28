//
// Created by TaiTitans on 3/28/2023.
// Bubble Sort
//

#include <stdio.h>

typedef int keytype;
typedef float othertype;

typedef struct{
    keytype key;
    othertype othefields;
}recordtype;

void swap(recordtype *x, recordtype *y){
    recordtype t;
    t = *x;
    *x = *y;
    *y =t;
}
//sap xep noi bot
void bubbleSort(recordtype a[], int n) {
    int i, j;
    for (i = 0; i <= n - 2; i++) {
        for (j = n - 1; j >= i + 1; j--) {
            if (a[j].key < a[j - 1].key)
                swap(&a[j], &a[j - 1]);
        }
    }
}

// doc du lieu

void read_data(recordtype a[], int *n){
    FILE *f;
    f=fopen("C:\\Users\\taiti\\OneDrive - ctu.edu.vn\\Documents\\GitHub\\CT174_PTTKTT\\CT174_PTTKTT_Algorithm-Analysis-And-Design\\Buoi1\\data.txt","r");
    int i =0;
    if(f!=NULL)
    while(!feof(f)){
        fscanf(f,"%d%f",&a[i].key,&a[i].othefields);
        i++;
    }else printf("Loi mo file \n");
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
     read_data(a, &n);
     printf("Du lieu ban dau \n");
     print_Data(a,n);
     bubbleSort(a,n);
     printf("\nSau khi sap xep: \n");
     print_Data(a,n);
     return 0;
    }