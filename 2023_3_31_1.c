#include<stdio.h>
#include <stdlib.h> 
#include <time.h>   

int main(){
    int arr[6][6]={0};
    int arr2[6][6]={0};
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            arr[i][j]=i+j+2;
        }
    }
    for(int i=0;i<36000;i++){
        int r1 = rand()%6;
        int r2 = rand()%6;
        arr2[r1][r2]++;
    }
    int a[11]={0};
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            a[i+j] += arr2[i][j];
        }
    }
    for(int i=0;i<11;i++){
        float temp = (a[i]/36000.0)*100;
        printf("%3d %3d %3f%%\n",i+2,a[i],temp);
    }

    
}