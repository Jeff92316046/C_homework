#include<stdio.h>
#include <stdlib.h> 
#include <time.h>   

int gcd(int x,int y){
    if(y==0){
        return x;
    }else{
        gcd(y,x%y);
    }
}

int main(){
    int x=0,y=0;
    printf("Enter two integers :");
    scanf("%d,%d",&x,&y);
    printf("%d",gcd(x,y));

    

    
}