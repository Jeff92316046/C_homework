#include<stdio.h>
#include <stdlib.h> 

#include <string.h>
int funcl(int a,int b){
    printf("%3d%3d\n",a,b);
    if(b==0)return a;
    else if(a%2&&b%2)return funcl((a+b)/2,(a-b)/2);
    else if(a%2&&!b%2)return funcl(a,b/2);
    else if(!a%2&&b%2)return funcl(a/2,b);
    else return 2*funcl(a/2,b/2);
}
int main () {
    int x=19,y=2;
    printf("%3d",funcl(x,y));
}