// Fig. 12.19: fig12_19.c
// Creating and traversing a binary tree 
// preorder, inorder, and postorder
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// self-referential structure                            
struct treeNode {                                           
   struct treeNode *leftPtr; // pointer to left subtree 
   char* data; // node value                               
   struct treeNode *rightPtr; // pointer to right subtree
}; 

typedef struct treeNode TreeNode; // synonym for struct treeNode
typedef TreeNode *TreeNodePtr; // synonym for TreeNode*

// prototypes
void insertNode(TreeNodePtr *treePtr, char* value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

// function main begins program execution
int main(void)
{ 
   TreeNodePtr rootPtr = NULL; // tree initially empty

   puts("The numbers being placed in the tree are:");

   // insert random values between 0 and 14 in the tree
    char str[100] = "";
    const char s[] = " ";
    char *token;

    fgets(str,100,stdin);

    token = strtok(str, s);
    while( token != NULL ) {
        printf( "%s\n", token );
        insertNode(&rootPtr, token);
        token = strtok(NULL, s);
    }
    
   

   // traverse the tree preOrder
   puts("\n\nThe preOrder traversal is:");
   preOrder(rootPtr);

   // traverse the tree inOrder
   puts("\n\nThe inOrder traversal is:");
   inOrder(rootPtr);

   // traverse the tree postOrder
   puts("\n\nThe postOrder traversal is:");
   postOrder(rootPtr);
} 

// insert node into tree
void insertNode(TreeNodePtr *treePtr, char* value)
{ 
   // if tree is empty
   if (*treePtr == NULL) {   
      *treePtr = malloc(sizeof(TreeNode));

      // if memory was allocated, then assign data
      if (*treePtr != NULL) { 
         (*treePtr)->data = value;
         (*treePtr)->leftPtr = NULL;
         (*treePtr)->rightPtr = NULL;
      } 
      else {
         printf("%d not inserted. No memory available.\n", value);
      } 
   } 
   else { // tree is not empty
      // data to insert is less than data in current node
      if (strcmp(value ,(*treePtr)->data)<0)  {                   
         insertNode(&((*treePtr)->leftPtr), value);   
      }                                         

      // data to insert is greater than data in current node
      else if (strcmp(value ,(*treePtr)->data)>0) {                 
         insertNode(&((*treePtr)->rightPtr), value);     
      }                                        
      else { // duplicate data value ignored
         printf("%s", "dup");
      } 
   } 
} 

// begin inorder traversal of tree
void inOrder(TreeNodePtr treePtr)
{ 
   // if tree is not empty, then traverse
   if (treePtr != NULL) {                
      inOrder(treePtr->leftPtr);         
      printf("%3s", treePtr->data);      
      inOrder(treePtr->rightPtr);        
   }                           
} 

// begin preorder traversal of tree
void preOrder(TreeNodePtr treePtr)
{ 
   // if tree is not empty, then traverse
   if (treePtr != NULL) {                
      printf("%3s", treePtr->data);      
      preOrder(treePtr->leftPtr);        
      preOrder(treePtr->rightPtr);       
   }                           
} 

// begin postorder traversal of tree
void postOrder(TreeNodePtr treePtr)
{ 
   // if tree is not empty, then traverse
   if (treePtr != NULL) {                
      postOrder(treePtr->leftPtr);       
      postOrder(treePtr->rightPtr);      
      printf("%3s", treePtr->data);      
   }                           
} 



/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
