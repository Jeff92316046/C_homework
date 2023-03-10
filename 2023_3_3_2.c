#include<stdio.h>
int main(){
    
    
    int acc=10;
    float fac=1,e=0,temp;
    for(int i=1;i<=acc;i++){
        
        temp = 1/fac;
        fac *= i;
        e += temp;
    }
    printf("%f\n",e);

    
}