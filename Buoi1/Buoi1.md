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
## Thuật toán InsertionSort

![image](https://user-images.githubusercontent.com/70010376/228142584-ce3113db-741f-459c-b358-3e65d213431d.png)

```sh
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

// sap xep xen
void insertionSort(recordtype a[], int n){
    int i, j;
    for(i=1;i<=n-1;i++){
        j=i;
        while(j>0 && a[j].key < a[j-1].key){
            swap(&a[j], &a[j-1]);
            j--;
        }
    }
}


// doc du lieu

void read_Data(recordtype a[], int *n){
    FILE *f;
    f=fopen("C:\\Users\\taiti\\OneDrive - ctu.edu.vn\\Documents\\GitHub\\CT174_PTTKTT\\CT174_PTTKTT_Algorithm-Analysis-And-Design\\Buoi1\\data.txt","r");
    int i=0;
    if(f!=NULL)
            while(!feof(f)){
                fscanf(f,"%d%f", &a[i].key,&a[i].otherfields);
                i++;
            } else printf("Loi mo file \n");
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
    recordtype a[100];
    int n;
    read_Data(a, &n);
    printf("Du lieu ban dau \n");
    print_Data(a,n);
    insertionSort(a,n);
    printf("\nSau khi sap xep: \n");
    print_Data(a,n);
    return 0;
}
```
---
## Thuật toán BubbleSort

![image](https://user-images.githubusercontent.com/70010376/228142940-55edae7f-d6b3-4a2c-975f-dce9236666a9.png)

```sh
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
```
---

##Thuật toán QuickSort

![image](https://user-images.githubusercontent.com/70010376/228143194-4c88440f-8e6d-410b-aee8-3a2f8a1c3d96.png)

```sh
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
```
---

## Thuật toán HeapSort

![image](https://user-images.githubusercontent.com/70010376/228143645-a93c57dc-3c93-4b48-bb3a-79d82327a203.png)


```sh
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
```
## END

