#include <stdio.h> 
#include <stdbool.h >
void  f2(const int a[],size_t i,size_t j){
    if(i<j){
        f2(a,i+1,j);
        printf("%d ",a[i]);
    }
}
int main ( void ) { 
    int a[10]={18,13,11,12,16,10,19,17,14,15};
    puts("result:");
    f2(a,0,10);
    puts("");
}