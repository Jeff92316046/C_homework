#include<stdio.h>
#include <stdlib.h> 
#include <time.h>   
int random(int shift,int scale){
    return shift + (rand()%scale);
}

void fst_random(int arr[]){
    int temp,flag=0;
    for(int i=0;i<6;i++){   
        temp = random(1,38);
        for(int j=0;j<6;j++){
            if(arr[j]==temp)flag=1;
        }
        if(flag==1){
            i--;
            flag=0;
            continue;
        }
        arr[i]=temp;
    }
}

void sort(int arr[]){
    int temp ;
    for(int i=0;i<7;i++){
        for(int j=i+1;j<7;j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

float avg(int arr[]){
    float sum;
    for(int i=0;i<7;i++){
        sum += arr[i];
    }
    return sum/7;
}

int main(){
    srand(time(NULL));
    int mode = 0 ;
    int fst[6]={0},sec=0;
    int total[7]={0};
    fst_random(fst);
    sec = random(1,8);
    for(int i=0;i<6;i++){
        total[i] = fst[i];
    }
    total[6] = sec;
    
    for(;;){
        
        printf("1. first area 6 number(1~38):\n");
        printf("2. second area 1 number(1~8):\n");
        printf("3. first area and second area (7 number) average:\n");
        printf("4. first area and second area (7 number) middle:\n");
        printf("5. exit\n");
        scanf("%d", &mode);
        if(mode==1){
            fst_random(fst);
            for(int i=0;i<6;i++){
                total[i] = fst[i];
            }
            printf("first area 6 number(1~38):\n");
            for(int i=0;i<6;i++){
                printf("%d ",fst[i]);
            }
            printf("\n");
        }else if(mode==2){
            printf("%d",sec);
            sec = random(1,8);
            total[6] = sec;
            printf("\n");
        }else if(mode==3){
            printf("%f",avg(total));
            printf("\n");
        }else if(mode==4){
            printf("origin number:\n");
            for(int i=0;i<6;i++){
                printf("%d ",fst[i]);
            }
            printf("%d\n",sec);
            for(int i=0;i<6;i++){
                total[i] = fst[i];
            }
            total[6] = sec;
            sort(total);
            printf("sorted number:\n");
            for(int i=0;i<7;i++){
                printf("%d ",total[i]);
            }
            printf("\n");
            printf("mid : %d \n",total[3]);
        }else if(mode==5){
            printf("exit\n");
            break;
        }
    }
    
}