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
