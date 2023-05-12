#include<stdio.h>
#include <stdlib.h> 

#include <string.h>

int main () {
    int len=0;
    char str[100] = "";
    fgets(str,100,stdin);
    printf("%s\n",str);
    
    
    const char s[] = "  ";
    char *token;
    int a[1000] ={0};
    int count=0;
    for(int i=0;str[i]!='\n';i++){
        if(str[i]==' '){
            a[count] = i;
            count++;
        }
    }
    for(int i=0;a[i]!=0;i++){
        printf("%d\n",a[i]);
    }
    for(int i=count-1;i>=0;i--){
        for(int j=a[i]+1;;j++){
            if(str[j]=='\0' || str[j]==' '||str[j]=='\n')break;
            printf("%c",str[j]);
        }
        printf(" ");
    }
    for(int j=0;;j++){
        if(str[j]=='\0' || str[j]==' ')break;
        printf("%c",str[j]);
    }
    return(0);
}