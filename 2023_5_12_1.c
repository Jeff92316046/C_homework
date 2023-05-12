#include <stdio.h> 
#include <stdbool.h >
bool func2 ( int A [ ] , int x , int y ) { 
    if ( x > y ) return false ; 
    else {  
        int m = ( x + y ) / 2 ; 
        printf ( "%3d%3d%3d\n" , x , m , y ) ;
        if ( A[m] == m ) return true ; 
        else if ( A[m] > m ) return func2 ( A , x , m - 1 ) ; 
        else return func2 ( A , m + 1 , y ) ; 
    } 
}
int main ( void ) { 
    int a [ ] = { 35 , 60 , 45 , 7 , 10 , 22 , 2 , 50 , 14 , 3 , 66  };
    printf ( "%3d" , func2 ( a , 1 , 10 ) ) ;
}