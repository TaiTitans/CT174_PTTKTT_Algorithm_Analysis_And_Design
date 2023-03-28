//
// Created by TaiTitans on 3/28/2023.
//Heap Sort (Vun dong)
//
#include <stdio.h>

typedef int keytype;
typedef float othertype;

typedef struct{
    keytype key;
    othertype otherfields;
}recordtype;

void swap(recordtype *x, recordtype *y){
    recordtype t;
    t = *x;
    *x = *y;
    *y = t;
}
void PushDown(recordtype a[], int first, int last){
    int r = first;
    while( r <= (last-1)/2)
        if(last == 2*r+1){
            if(a[r].key > a[last].key) swap (&a[r], &a[last]);
            r = last;
        }else
        if( (a[r].key > a[2*r+1].key) && (a[2*r+1].key <= a[2*r+2].key)){
            swap(&a[r], &a[2*r+1]);
            r = 2*r+1;
        }else
        if( (a[r].key > a[2*r+2].key) && (a[2*r+2].key < a[2*r+1].key)){
            swap(&a[r], &a[2*r+2]);
            r = 2*r+2;
        }
        else
            r = last;
}
void heapSort(recordtype a[], int n){
    int i;
    //tao heap
    for(i = (n-2)/2;i>=0;i--){
        PushDown(a,i,n-1);
    }
    for(i=n-1;i>=2;i--){
        swap(&a[0], &a[i]);
        PushDown(a,0,i-1);
    }
    swap(&a[0], &a[1]);
}
void read_Data(recordtype a[], int *n){
 FILE *f;
 f= fopen("C:\\Users\\taiti\\OneDrive - ctu.edu.vn\\Documents\\GitHub\\CT174_PTTKTT\\CT174_PTTKTT_Algorithm-Analysis-And-Design\\Buoi1\\data.txt","r");
 int i = 0;
 if(f!=NULL)
 while(!feof(f)){
     fscanf(f,"%d%f",&a[i].key,&a[i].otherfields);
     i++;
 } else printf("Loi mo file \n");
 fclose(f);
 *n=i;

}
void Print_Data( recordtype a[], int n){
    int i;
    for( i=0; i<n; i++)
        printf("%3d%5d%8.2f\n",i+1, a[i].key, a[i].otherfields);
}

int main(){
    recordtype a[20];
    int n;
    read_Data(a,&n);
    printf("Du lieu ban dau\n");
    Print_Data(a,n);
    heapSort(a,n); // O(nlogn)
    printf("\nsau khi sap xep: \n");
    Print_Data(a,n);
    return 0;
}
