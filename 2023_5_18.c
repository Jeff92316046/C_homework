#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

// card structure definition                  
struct card {                                 
   const char *face; // define pointer face   
   const char *suit; // define pointer suit 
   const char *color;  
}; 

typedef struct card Card; // new type name for struct card   

// prototypes
void fillDeck(Card * const wDeck, const char * wFace[], 
   const char * wSuit[],const char *wColor[]);
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck);

int main(void)
{ 
    Card deck[CARDS]; // define array of Cards

    // initialize array of pointers
    const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten",
        "Jack", "Queen", "King"};

    // initialize array of pointers
    const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};
    const char *color[] = { "Red", "Black" };
    srand(time(NULL)); // randomize

    fillDeck(deck, face, suit, color); // load the deck with Cards
    shuffle(deck); // put Cards in random order
    deal(deck); // deal all 52 Cards
} 

// place strings into Card structures
void fillDeck(Card * const wDeck, const char * wFace[], 
   const char * wSuit[],const char *wColor[])
{ 
   // loop through wDeck
   for (size_t i = 0; i < CARDS; ++i) { 
      wDeck[i].face = wFace[i % FACES];
      wDeck[i].suit = wSuit[i / FACES];
      wDeck[i].color = wColor[(i / FACES)>=2?1:0];
   } 
} 

// shuffle cards
void shuffle(Card * const wDeck)
{ 
   // loop through wDeck randomly swapping Cards
   for (size_t i = 0; i < CARDS; ++i) { 
      size_t j = rand() % CARDS;
      Card temp = wDeck[i];      
      wDeck[i] = wDeck[j];
      wDeck[j] = temp;      
   } 
} 

// deal cards
void deal(const Card * const wDeck)
{ 
   // loop through wDeck
    for (size_t i = 0; i < CARDS; ++i) {
        printf("%5s : %5s of %-8s%s",wDeck[i].color, wDeck[i].face, wDeck[i].suit,
            (i + 1) % 2 ? "  " : "\n");
        
    } 
} 
