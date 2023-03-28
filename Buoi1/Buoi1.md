# Buổi 1:
* [Tham khảo tại đây](https://visualgo.net/en/sorting)
---
## Thuật toán Selection Sort

![image](https://user-images.githubusercontent.com/70010376/228141805-76634e28-9907-4650-ba01-2f3e8cf241c4.png)


```sh
#include <stdio.h>

typedef int keytype; // bien so nguyen
typedef float othertype; // bien so thuc

typedef struct{
    keytype key;
    othertype otherfields;
}recordtype;    //khai bao cau truc

void swap(recordtype *x, recordtype *y){
    recordtype  t;
    t = *x;
    *x = *y;
    *y = t;
}       //ham swap


//sap xep chon

void selectionSort(recordtype a[], int n){
    int i, j, lowindex;
    keytype lowkey;

    for(i=0;i<=n-2;i++){
        lowkey = a[i].key;
        lowindex = i;
        for(j=i+1;j<=n-1;j++){
            if(a[j].key < lowkey){
                lowkey = a[j].key;
                lowindex = j;
            }
        }
        swap(&a[i], &a[lowindex]);
    }
}
void read_Data(recordtype a[], int *n){
    FILE *f;
    f=fopen("D:\\Workspace\\C\\PTTKTT\\Buoi1\\data.txt","r");
    int i=0;
    if(f!=NULL)
        while(!feof(f)){
            fscanf(f,"%d%f",&a[i].key,&a[i].otherfields);
            i++;
        }else printf("Loi mo file\n");
        fclose(f);
        *n=i;
}
void print_Data(recordtype a[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%3d%5d%8.2f\n",i+1,a[i].key,a[i].otherfields);
    }
}
int main(){
    recordtype  a[100];
    int n;
    read_Data(a, &n);
    printf("Du lieu ban dau\n");
    print_Data(a,n);
    selectionSort(a,n);
    printf("\nSau khi sap xep: \n");
    print_Data(a,n);
    return 0;
}
```
---
