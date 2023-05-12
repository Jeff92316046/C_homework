#include <stdio.h> 
#include <stdbool.h >
unsigned int f1(unsigned int x,unsigned int y){
    if(2==y)return x;
    else return x+f1(x,y-1);
}
int main ( void ) { 
    printf("%s","input two positive number");
    unsigned int a,b;
    scanf("%u%u",&a,&b);
    printf("result:%u\n",f1(a,b));
}