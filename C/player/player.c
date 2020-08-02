#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "player.h"
#include "../card/card.h"

int randRange(int n){
    time_t seconds;
    srand((unsigned)time(NULL));
    int limit;
    int r;
    limit = RAND_MAX - (RAND_MAX % n);while((r = rand()) >= limit);
    return r % n;
}

void removeCardFromDeck(Deck *deck, int index){
    for (int i = index - 1; i < deck->deckSize - 1; i++){
        deck->cards[i] = deck->cards[i + 1];
    }
    deck->deckSize --;
}

void calculateHandScore(Player *player){
    player->score = 0;
    for(int i = 0; i < player->lastIndex; i ++){
        player->score += player->hand[i].value;
    }
}

void draw(Player *player, Deck *deck, int num){
    for(int i = 0; i < num; i++){
        int randomIndex = randRange(deck->deckSize);
        player->hand[player->lastIndex] = deck->cards[randomIndex];
        player->lastIndex++;
        removeCardFromDeck(deck, randomIndex);
        calculateHandScore(player);
        if (i < num) sleep(1);               // We need to force a delay otherwise we will keep drawing the same cards.
    }
}

void printLine(char string[], int num, int doNewline){
    for(int i = 0; i < num; i++){
        printf("%s\t",string);
    }
    if (doNewline) printf("\n");
}

void printSymbolLines(Player *player, char line[], int type){
    char temp[20];
    for(int i = 0; i < player->lastIndex; i ++){
        switch (type) {
            case 0:
                sprintf(temp, line, getFaceSymbol(&player->hand[i], 0));
                break;
            case 1:
                sprintf(temp, line, getSuitSymbol(&player->hand[i]));
                break;
            case 2:
                sprintf(temp, line, getFaceSymbol(&player->hand[i], 1));
                break;
        }
        printLine(temp, 1, 0);
    }
    printf("\n");
}

char topEdge[] = "┌─────────┐";
char midEdge[] = "│         │";
char botEdge[] = "└─────────┘";

void printDealerHand(Player *player){
    printf("%s's Hand:\n", player->name);

    char topNumb[20];
    char midSymb[20];
    char botNumb[20];

    printLine(topEdge, 2, 1);

    sprintf(topNumb, "│%s       │", getFaceSymbol(&player->hand[0], 0));
    printLine(topNumb, 1, 0);
    sprintf(topNumb, "│%s       │", "? ");
    printLine(topNumb, 1, 0);
    printf("\n");

    printLine(midEdge, 2, 1);
    printLine(midEdge, 2, 1);

    sprintf(midSymb, "│    %s    │", getSuitSymbol(&player->hand[0]));
    printLine(midSymb, 1, 0);
    sprintf(midSymb, "│    %s    │", "?");
    printLine(midSymb, 1, 0);
    printf("\n");

    printLine(midEdge, 2, 1);
    printLine(midEdge, 2, 1);

    sprintf(botNumb, "│       %s│", getFaceSymbol(&player->hand[0], 1));
    printLine(botNumb, 1, 0);
    sprintf(botNumb, "│       %s│", " ?");
    printLine(botNumb, 1, 0);
    printf("\n");

    printLine(botEdge, 2, 1);

    printf("%s's score is ???\n", player->name);
}

void printHand(Player *player){
    if (player->isDealer && player->lastIndex == 2){
        printDealerHand(player);
        return;
    }
    printf("%s's Hand:\n", player->name);
    int numCards = player->lastIndex;

    char topNumb[20];
    char midSymb[20];
    char botNumb[20];

    printLine(topEdge, numCards, 1);
    printSymbolLines(player, "│%s       │", 0);
    printLine(midEdge, numCards, 1);
    printLine(midEdge, numCards, 1);
    printSymbolLines(player, "│    %s    │", 1);
    printLine(midEdge, numCards, 1);
    printLine(midEdge, numCards, 1);
    printSymbolLines(player, "│       %s│", 2);
    printLine(botEdge, numCards, 1);

    printf("%s's score is %d\n", player->name, player->score);
}

Player generatePlayer(Deck *deck, int isDealer){
    Player player;
    player.lastIndex = 0;
    player.isDealer = isDealer;
    if (isDealer) strcpy(player.name, "Dealer");
    else {
        printf("Name: ");
        fgets(player.name, sizeof(player.name), stdin);
        player.name[strlen(player.name) - 1] = '\0';
    }
    draw(&player, deck, 2);
    calculateHandScore(&player);
    printf("Dealt %s 2 cards!\n", player.name);
    return player;
}
