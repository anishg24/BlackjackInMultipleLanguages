#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "card/card.h"
#include "player/player.h"
#include "card/deck.h"

void lowercase(char string[]){
    for(int i = 0; string[i]; i++){
        string[i] = (char) tolower((int) string[i]);
    }
}

int doHit(){
    char action[10];
    printf("Do you want to hit or stand? (Type 'hit' to hit or anything else to stand.)\n");
    printf("> ");
    fgets(action, sizeof(action), stdin);
    action[strlen(action) - 1] = '\0';
    lowercase(action);
    return !strcmp(action, "hit");
}


int main() {
    Deck deck = generateDeck();
    Player player = generatePlayer(&deck, 0);
    Player dealer = generatePlayer(&deck, 1);
    printHand(&dealer);
    printHand(&player);
    while(doHit()){
        draw(&player, &deck, 1);
        printHand(&player);
        if (player.score > 21){
            printf("YOU BUSTED! DEALER WINS!");
            exit(0);
        }
    }

    while(dealer.score < 17){
        draw(&dealer, &deck, 1);
        printHand(&dealer);
        if (dealer.score > 21){
            printf("DEALER BUSTS! YOU WIN");
            exit(0);
        }
    }

    if (player.score == dealer.score){
        printf("YOU PUSHED WITH THE DEALER! YOU TIED!");
        exit(0);
    } else if (21 - player.score > 21 - dealer.score){
        printf("YOU WERE CLOSER TO 21! YOU WIN!");
        exit(0);
    } else {
        printf("DEALER WAS CLOSER TO 21! YOU LOSE!");
        exit(0);
    }
    return 0;
}
