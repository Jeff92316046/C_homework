#include<stdio.h>
int main(){
    float interest=0,principal=0,rate=0,days=0;
    for(;;)
    {
        interest=0;
        principal=0;
        rate=0;
        days=0;
        printf("enter loan principal(-1 to end )\n");
        scanf("%f", &principal);
        if(principal == -1)break;
        printf("enter interest rate\n");
        scanf("%f", &rate);
        printf("enter term of the loan in days\n");
        scanf("%f", &days);
        interest = principal* rate * days /365;
        printf("The interest charge is %2f \n" ,interest);
        printf("\n");
        
    }
    
}