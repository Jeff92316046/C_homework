#include<stdio.h>
#include<math.h>
int main(){
    
    double pi=0,temp;
    int m1=0,m2=0,m3=0,m4=0;
    for(int i=1;i<=400000;i++){
        temp = 4.0/(2*i-1);
        if(i%2==1){
            pi +=  temp;
        }else{
            pi -=  temp;
        }
        
        printf("%d   %lf \n",i,pi);
        if((int)trunc(pi*100) == 314 &&  m1==0){
            m1=i;
        }
        if((int)trunc(pi*1000)== 3141 &&  m2==0){
            m2=i;
        }
        if((int)trunc(pi*10000)== 31415 &&  m3==0){
            m3=i;
        }
        if((int)trunc(pi*100000)== 314159 &&  m4==0){
            m4=i;
        }
    }

    printf("3.14:%d\n3.141:%d\n3.1415:%d\n3.14159:%d\n",m1,m2,m3,m4);
}