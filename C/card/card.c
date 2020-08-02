#include "card.h"
#include <stdio.h>
#include <stdlib.h>

Card generateCard(Suit *suit, Face *face){
    Card card;
    card.suit = (Suit) suit;
    card.face = (Face) face;
    if (card.face == KING || card.face == QUEEN || card.face == JACK) card.value = 10;
    else card.value = (int) face;
    return card;
}

char* getSuitSymbol(Card *card){
    switch ((int) card->suit){
        case 0:
            return DIAMOND_SYMBOL;
        case 1:
            return HEART_SYMBOL;
        case 2:
            return SPADE_SYMBOL;
        case 3:
            return CLUB_SYMBOL;
    }
}

char* getFaceSymbol(Card *card, int isBottom){
    if (card->face == ACE){
        if (!isBottom) return "A ";
        else return " A";
    } else if (card->face == (Face) KING){
        if (!isBottom) return "K ";
        else return " K";
    } else if (card->face == (Face) QUEEN){
        if (!isBottom) return "Q ";
        else return " Q";
    } else if (card->face == (Face) JACK){
        if (!isBottom) return "J ";
        else return " J";
    } else if (card->face == (Face) TEN){
        static char result[4];
        sprintf(result, "%d", card->value);
        return result;
    } else {
        static char result[4];
        if (!isBottom) sprintf(result, "%d ", card->value);
        else sprintf(result, " %d", card->value);
        return result;
    }
}

void printCard(Card *card){
    char topEdge[] = "┌─────────┐\n";
    char topNumb[20];
    char midEdge[] = "│         │\n";
    char midSymb[20];
    char botNumb[20];
    char botEdge[] = "└─────────┘\n";

    sprintf(topNumb, "│%s       │\n", getFaceSymbol(card, 0));
    sprintf(midSymb, "│    %s    │\n", getSuitSymbol(card));
    sprintf(botNumb, "│       %s│\n", getFaceSymbol(card, 1));

    printf("%s", topEdge);
    printf("%s", topNumb);
    printf("%s", midEdge);
    printf("%s", midEdge);
    printf("%s", midSymb);
    printf("%s", midEdge);
    printf("%s", midEdge);
    printf("%s", botNumb);
    printf("%s", botEdge);
//    " ┌─────────┐  ┌─────────┐  ┌─────────┐\n"
//    " │1        │  │2        │  │3        │\n"
//    " │         │  │         │  │         │\n"
//    " │         │  │         │  │         │\n"
//    " │    1    │  │    2    │  │    3    │\n"
//    " │         │  │         │  │         │\n"
//    " │         │  │         │  │         │\n"
//    " │        1│  │        2│  │        3│\n"
//    " └─────────┘  └─────────┘  └─────────┘"
}