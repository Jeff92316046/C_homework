#include<stdio.h>
#include <stdlib.h> 
#include <time.h>   


int main(){
    srand(time(NULL));
    int arr[13] = {0};
    float arr2[13] = {0};
    int rd;
    for(int i=0;i<36000;i++){
        rd = 2 + (rand()%11);
        arr[rd]++;
    }
    for(int i=0;i<11;i++){
        arr2[i+2] = (6-abs(5-i))/36;
    }
    for(int i=0;i<11;i++){
        printf("%f",arr2[i]);
    }
    
                                                                                                           

    

    
}