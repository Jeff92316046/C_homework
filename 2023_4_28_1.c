// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], const char *wFace[], 
   const char *wSuit[],int a[],int b[]); // dealing doesn't modify the arrays

int main(void)
{
   // initialize deck array
   unsigned int deck[SUITS][FACES] = { 0 };

   srand(time(NULL)); // seed random-number generator

   shuffle(deck); // shuffle the deck

   // initialize suit array                       
   const char *suit[SUITS] =            
      {"Hearts", "Diamonds", "Clubs", "Spades"};
   
   // initialize face array                   
   const char *face[FACES] =
      {"Ace", "Deuce", "Three", "Four",         
       "Five", "Six", "Seven", "Eight",         
       "Nine", "Ten", "Jack", "Queen", "King"};
   int a[5]={0},b[5]={0};
   int num_times[13] = {0};
   int t[5] = {0};
   deal(deck, face, suit,a,b); // deal the deck
   for(int i=0;i<5;i++){
      num_times[b[i]]++;
   }
   for(int i=0;i<13;i++){
      t[num_times[i]]++;
   }
   if(t[2]==1 && t[3]==0){
      printf("pair\n");
   }else if(t[2]==2){
      printf("two pair\n");
   }
   if(t[3]==1 && t[2]==0){
      printf("three\n");
   }else if(t[3]==1 && t[2]==1){
      printf("fullhouse\n");
   }
   if(t[4]==1){
      printf("four\n");
   }
   if(t[2]==0 && t[3]==0 && t[4]==0){
      printf("nothing\n");
   }


   
} 

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
   // for each of the cards, choose slot of deck randomly
   for (size_t card = 1; card <= CARDS; ++card) {
      size_t row; // row number
      size_t column; // column number

      // choose new random location until unoccupied slot found
      do {                                                        
         row = rand() % SUITS;                                   
         column = rand() % FACES;                             
      } while(wDeck[row][column] != 0); // end do...while

      // place card number in chosen slot of deck
      wDeck[row][column] = card;
   } 
}

// deal cards in deck
void deal(unsigned int wDeck[][FACES], const char *wFace[],const char *wSuit[],int a[],int b[]){
   // deal each of the cards
   for (size_t card = 1; card <= 5; ++card) {
      // loop through rows of wDeck
      for (size_t row = 0; row < SUITS; ++row) {
         // loop through columns of wDeck for current row
         for (size_t column = 0; column < FACES; ++column) {
            // if slot contains current card, display card
            if (wDeck[row][column] == card) {
               a[card-1]=row;
               b[card-1]=column;
               printf("%5s of %-8s%c", wFace[column], wSuit[row],
                  card % 1 == 0 ? '\n' : '\t'); // 2-column format
            } 
            
         } 
      } 
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

