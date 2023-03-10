#include<stdio.h>
int main(){
    
    for(;;)
    {
        int n=0,sum=1;
        printf("enter n (-1 to end )\n");
        
        scanf("%d", &n);
        if(n==-1){
            break;
        }
        for(int i=1;i<=n;i++){
            sum *= i;
        }
        printf("%d\n",sum);
    }
    
}