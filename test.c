#include<stdio.h>
int fuck = 0;
// int a(int (*)(int ,int ));

// int sum(int a,int b){
//     return a+b;
// }
int *test(){
    return &fuck;
}
int main(){
    // int (*a)(int, int) = &sum;
    // int h=0;
    // printf("%p",test(h));
    printf("%p",test());
}
// int a(int (*b)(int ,int )){
//     return (*b)(6,3);
// }
