#include<stdio.h>
int main(){
    float weight,height;
    printf("enter weight(kg) and height(m)\n");
    scanf("%f %f",&weight,&height);
    float bmi = weight/(height*height);
    
    if (bmi<18.4){
        printf("your BIM is underweight,%f",bmi);
    } else if (bmi>18.5 && bmi<24.9){
        printf("your BIM is normal,%f",bmi);
    } else if (bmi>25.0 && bmi<29.9){
        printf("your BIM is overweight,%f",bmi);
    } else if (bmi>30.0 ){
        printf("your BIM is obese,%f",bmi);
    }
    
}