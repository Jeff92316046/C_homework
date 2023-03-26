#include<stdio.h>
#include <stdlib.h> 
#include <time.h>   
int random(int shift,int scale){
    return shift + (rand()%scale);
}
int main(){
    srand(time(NULL));
    int head=0,tail=0;
    for(int i=0;i<100;i++){
        int rd = random(1,2);
        if(rd == 1){
            printf("%s","Head ");
            head++;
        }else{
            printf("%s","Tail ");
            tail++;
        }
    }
    printf("\n");
    printf("Head : %d\n",head);
    printf("Tail : %d\n",tail);
    

    
}