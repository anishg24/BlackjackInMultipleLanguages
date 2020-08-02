#ifndef CARD_DOT_H
#define CARD_DOT_H
#define SPADE_SYMBOL "\u2660"
#define DIAMOND_SYMBOL "\u2666"
#define HEART_SYMBOL "\u2665"
#define CLUB_SYMBOL "\u2663"

typedef enum Suit {DIAMOND, HEARTS, SPADES, CLUBS} Suit;
typedef enum Face {ACE = 11,
                    KING = 14,
                    QUEEN = 13,
                    JACK = 12,
                    TEN = 10,
                    NINE = 9,
                    EIGHT = 8,
                    SEVEN = 7,
                    SIX = 6,
                    FIVE = 5,
                    FOUR = 4,
                    THREE = 3,
                    TWO = 2,
                    } Face;

typedef struct Card {
    Suit suit;
    Face face;
    int value;
} Card;

Card generateCard(Suit *suit,Face *face);

void printCard(Card *card);

char *getSuitSymbol(Card *card);

char *getFaceSymbol(Card *card, int isBottom);

#endif