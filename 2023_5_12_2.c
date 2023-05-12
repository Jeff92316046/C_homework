#include <stdio.h> 
#include <stdbool.h >
int main ( void ) { 
    int x=4,y=2;
    for(int i=1;i<=x;i++){
        for(int j=1;j<i;j++){
            printf("%d",y);
            y++;
        }
        printf("\n");
    }
}