#include <stdio.h>
int *compare(int *a, int *b);
void a(){
   printf("a");
}
void b(){
   printf("b");
}
void c(){
   printf("c");
}
void aa(void (*output)()){
   output();

}
int main(){
   void (*f)() = a;
   
}
int *compare(int *a,int *b){
   return a;
}