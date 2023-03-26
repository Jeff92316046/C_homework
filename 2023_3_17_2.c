#include<stdio.h>
#include <stdlib.h> 
#include <time.h>   

int random(int shift,int scale){
    return shift + (rand()%scale);
}

int main(){
    srand(time(NULL));
    int n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,now=0;
    for(int i=0;i<6;i++){
        int rd = random(1,49);
        if(now == 0){
            n1=rd;
        }else if (now == 1){
            if(n1!=rd){
                n2=rd;
            }else{
                i--;
                continue;
            }
        }else if (now == 2){
            if(n1!=rd && n2!=rd){
                n3=rd;
            }else{
                i--;
                continue;
            }
        }else if (now == 3){
            if(n1!=rd && n2!=rd && n3!=rd){
                n4=rd;
            }else{
                i--;
                continue;
            }
        }else if (now == 4){
            if(n1!=rd && n2!=rd && n3!=rd && n4!=rd){
                n5=rd;
            }else{
                i--;
                continue;
            }
        }else if (now == 5){
            if(n1!=rd && n2!=rd && n3!=rd && n4!=rd && n5!=rd){
                n6=rd;
            }else{
                i--;
                continue;
            }
        }
        now++;
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d\n",n1,n2,n3,n4,n5,n6);
    

    
}