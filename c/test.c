#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct treeNode{
    struct treeNode *leftNode;
    struct treeNode *rightNode;
    int score;
};
typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodeptr;

void addNode(TreeNodeptr *treeptr,int n){
    if(*treeptr == NULL){
        *treeptr = malloc(sizeof(TreeNode));

        if(*treeptr != NULL){
            (*treeptr)->score = n;
            (*treeptr)->leftNode = NULL;
            (*treeptr)->rightNode = NULL;
        }
        
    }else{
        if(n < (*treeptr)->score){
            addNode(&((*treeptr)->leftNode),n);
        }else if(n > (*treeptr)->score){
            addNode(&((*treeptr)->rightNode),n);
        }
    }

}
void preOrder(TreeNodeptr treeptr){
    if(treeptr != NULL){
        printf("%3d ",treeptr->score);
        preOrder(treeptr->leftNode);
        preOrder(treeptr->rightNode);
    }
}
void inOrder(TreeNodeptr treeptr){
    if(treeptr != NULL){
        inOrder(treeptr->leftNode);
        printf("%3d ",treeptr->score);
        inOrder(treeptr->rightNode);
    }
}
void postOrder(TreeNodeptr treeptr){
    if(treeptr != NULL){
        postOrder(treeptr->leftNode);
        postOrder(treeptr->rightNode);
        printf("%3d ",treeptr->score);
    }
}
void fpreOrder(TreeNodeptr treeptr,FILE *fptr){
    
    if(treeptr != NULL){
        fprintf(fptr,"%3d",treeptr->score);
        fpreOrder(treeptr->leftNode,fptr);
        fpreOrder(treeptr->rightNode,fptr);
    }
}
void finOrder(TreeNodeptr treeptr,FILE *fptr){
    if(treeptr != NULL){
        finOrder(treeptr->leftNode,fptr);
        fprintf(fptr,"%3d",treeptr->score);
        finOrder(treeptr->rightNode,fptr);
    }
}
void fpostOrder(TreeNodeptr treeptr,FILE *fptr){
    if(treeptr != NULL){
        fpostOrder(treeptr->leftNode,fptr);
        fpostOrder(treeptr->rightNode,fptr);
        fprintf(fptr,"%3d",treeptr->score);
    }
}
float average(int arr[],int len){
    float sum=0;
    for(int i=0;i<len;i++){
        sum += arr[i];
    }
    return sum/len;
}
float calsd(int arr[],int len,float avg){
    float temp = 0;
    for(int i=0;i<len;i++){
        temp += ((arr[i]-avg)*(arr[i]-avg));
    }
    temp /= (len-1);
    return sqrt(temp);
}
int main(){
    FILE *fptr,*fptr2;
    TreeNodeptr firstNode = NULL;
    int studentNum = 0;
    float avg,sd;
    char fileName[100] = "";
    int studentScore[100] = {};
    for(;;){
        int mode ;
        printf("1.read file\n2.build binary tree\n3.preorder\n4.midorder\n5.postorder\n6.average\n7.standard deviation\n8.build and output file\n9.exit\n");
        scanf("%d",&mode);
        

        if(mode == 1){
            printf("enter file name\n");
            scanf("%s",fileName);
            fptr = fopen(fileName,"r");
            for(int i=0;!(feof(fptr));i++){
                fscanf(fptr,"%d",&studentScore[i]);
                studentNum++;
            }
            for(int i=0;i<studentNum;i++){
                printf("%d.%d\n",i+1,studentScore[i]);
            }
        }else if(mode == 2){
            for(int i=0;i<studentNum;i++){
                addNode(&firstNode,studentScore[i]);
               
            }
            printf("builded\n");
        }else if(mode == 3){
            printf("\npreorder");
            preOrder(firstNode);
            printf("\n");
        }else if(mode == 4){
            printf("\ninorder");
            inOrder(firstNode);
            printf("\n");
        }else if(mode == 5){
            printf("\npostorder");
            postOrder(firstNode);
            printf("\n");
        }else if(mode == 6){
            avg = average(studentScore,studentNum);
            printf("%f\n",avg);
        }else if(mode == 7){
            sd = calsd(studentScore,studentNum,avg);
            printf("%f\n",sd);
        }else if(mode == 8){
            printf("enter file name\n");
            scanf("%s",fileName);
            fptr2 = fopen(fileName,"w");
            fpreOrder(firstNode,fptr2);
            fprintf(fptr2,"\n");
            finOrder(firstNode,fptr2);
            fprintf(fptr2,"\n");
            fpostOrder(firstNode,fptr2);
            fprintf(fptr2,"\n");
            fprintf(fptr2,"%f\n",avg);
            fprintf(fptr2,"%f\n",sd);
            fclose(fptr2);
        }else if(mode == 9){
            break;
        }


    }


   
    
    
}