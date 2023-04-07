#include<stdio.h>
#include <stdlib.h> 
#include <time.h>   

int gcd(int x,int y){
    if(y==0){
        return x;
    }else{
        return gcd(y,x%y);
    }
}
int lcm(int x,int y){
    int gcd_num = gcd(x,y);
    
    return (x*y)/gcd_num;
}
int main(){
    int x,y;
    printf("Enter two integers :");
    scanf("%d %d",&x,&y);

    printf("%d",lcm(x,y));

    

    
}