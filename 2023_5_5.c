#include<stdio.h>
#include <stdlib.h> 

#include <string.h>

int main () {
    char str[100] = "";
    const char s[] = "() -";
    char *token;
    fgets(str,100,stdin);
    /* 获取第一个子字符串 */
    long a,b;
    token = strtok(str, s);
    a = atol(token);
    token = strtok(NULL, s);
    b = atol(token)*10000;
    token = strtok(NULL, s);
    b += atol(token);
    int first = 0;
    printf("%ld\n",a);
    printf("%ld\n",b);
    /* 继续获取其他的子字符串 */
    
    
    return(0);
}