#include<stdio.h>
int main(){
    
    
    int acc=16,ex=3;
    float fac=1,e=0,temp,temp2=1;
    for(int i=1;i<=acc;i++){
        temp = temp2/fac;
        temp2 *= ex;
        fac *= i;
        e += temp;
    }
    printf("%f\n",e);

    
}