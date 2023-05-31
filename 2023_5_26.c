#include<stdio.h>

int main(){
    FILE *fptr;
    int map[50][50] = {0};

    fptr = fopen("robot.in","r");
    int n;
    int x_max,y_max;
    fscanf(fptr,"%d",&n);
    fscanf(fptr,"%d",&x_max);
    fscanf(fptr,"%d",&y_max);
    int x,y,lost_flag=0,ignore_flag=0;
    char direction[2];
    char move[100];
    
    while (!feof(fptr)){
        fscanf(fptr,"%d%d%s%s",&x,&y,direction,move);
        lost_flag = 0;
        for(int i=0;move[i]!='\0';i++){
            //printf("%s %d %d\n",direction,x,y);
            if(direction[0] =='E'){
                if(move[i]=='R'){
                    direction[0] = 'S';
                }else if(move[i]=='L'){
                    direction[0]  = 'N';
                }else if(move[i]=='F'){
                    x++;
                }
            }else if(direction[0] =='N'){
                if(move[i]=='R'){
                    direction[0]  = 'E';
                }else if(move[i]=='L'){
                    direction[0]  = 'W';
                }else if(move[i]=='F'){
                    y++;
                }
            }else if(direction[0] =='W'){
                if(move[i]=='R'){
                    direction[0]  = 'N';
                }else if(move[i]=='L'){
                    direction[0]  = 'S';
                }else if(move[i]=='F'){
                    x--;
                }
            }else if(direction[0] =='S'){
                if(move[i]=='R'){
                    direction[0]  = 'W';
                }else if(move[i]=='L'){
                    direction[0]  = 'E';
                }else if(move[i]=='F'){
                    y--;
                }
            }
            for(int i=0;i<y_max+1;i++){
                for(int j=0;j<x_max+1;j++){
                    if(map[i][j]==1){
                        if(x>x_max){
                            x=x_max;
                            ignore_flag = 1;
                            break;
                        }
                        if(x<0){
                            x=0;
                            ignore_flag = 1;
                            break;
                        }
                        if(y>y_max){
                            y=y_max;
                            ignore_flag = 1;
                            break;
                        }
                        if(y<0){
                            y=0;
                            ignore_flag = 1;
                            break;
                        }
                        
                        
                    }
                }
                if(ignore_flag==1)break;
            }
            if(ignore_flag==1){
                ignore_flag = 0;
                //printf("owo");
                continue;
            }
            if(x>x_max){
                map[x][y] = 1;
                x--;
                lost_flag = 1;
                //printf("xm");
                break;

            }
            if(x<0){
                map[x][y] = 1;
                x++;
                lost_flag = 1;
                //printf("x0");
                break;
            }
            if(y>y_max){
                map[x][y] = 1;
                y--;
                lost_flag = 1;
                //printf("ym");
                break;
            }
            if(y<0){
                map[x][y] = 1;
                y++;
                lost_flag = 1;
                //printf("y0");
                break;
            }
            
        }
        if(lost_flag == 1){
            printf("%d %d %s LOST\n",x,y,direction);
            lost_flag = 0;
        }else{
            printf("%d %d %s\n",x,y,direction);
            lost_flag = 0;
        }    
        lost_flag = 0;
    }
    

    fclose(fptr);
    
}