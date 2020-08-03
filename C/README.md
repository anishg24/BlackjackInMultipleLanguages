# Blackjack in C

If you haven't already, I recommend you to read the repository's [README.md](https://github.com/anishg24/BlackjackInMultipleLanguages/README.md).

## Project Log
I've decided that it was high time that I learn how to program in C. So I set off and learned the syntax on a bunch of sites. I learned stuff I knew before like
`for` loops and `if` statements, as well as new topics like `struct`, `enum`, and most importantly, `*pointers`. Before I wanted to learn C I was watching
[Crash Course Computer Science](https://www.youtube.com/playlist?list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo) (if you haven't watched it and are interested in
computer science I recommend it, its a fun watch) and learned all about how the CPU works and operates, that too alongside the RAM. So, when I encountered 
pointers, the concept wasn't too hard for me to grasp. What I did struggle on however, was the lack of object functionality (which is expected in C) and the
lack of library support for concepts in C. For example, if I wanted to generate a random number, I would do the following:
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("%d", rand());
  return 0;
}
```
I would hope that every time that I run the code, I would get a different random number, but that is simply not the case in C. If you ran that
code multiple times over, you would get the same exact value printed out. So naturally the next step is to change the seed of the random number, using `srand`.
But what to see `srand` with? Well for simplicity sake I used the current time in seconds as the seed for the `rand` function, resulting in something like this:
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand((unsigned)time(NULL));
  printf("%d", rand());
  return 0;
}
```
which would produce a random number between executions, but if I were to do this consecutively in a short amount of time, I would yield the same random value again.
This is an issue as I rely on calling the `rand` function twice to deal the hand to a player. This means that the player would get the exact same card twice as
their hand which is an obvious problem. To remedy this, I force the program to delay its execution a second everytime a user picks up a card, so that the drawn
card is as random as possible with the default libraries in C.

The next issue I faced is in removing an element from an array. In all honesty, I have gotten to used to using functions to remove elements for me, like in Python
where I can just:
```python
my_list = [1, 2]
my_list.remove(2)
```
In C however, I need to create this method myself. So I wrote the following (which granted isn't computationally 
efficient but C is a step above machine code so execution speed isn't a concern here):
```c
void removeCardFromDeck(Deck *deck, int index){
    for (int i = index - 1; i < deck->deckSize - 1; i++){
        deck->cards[i] = deck->cards[i + 1];
    }
    deck->deckSize --;
}
```
That code piece is well integrated into my program, so you will likely have to read through my code to truly understand it, but in a nutshell, `Deck` is a
struct which has 2 values, an array of `Card` with default size 52, and an integer that tracks how many cards are in the deck. I'm not to proficient in manual
garbage collection yet so I need a seperate variable that will keep track of how many cards are there in the deck instead of using `sizeof(deck->cards)/12`)
(12 is the amount of space 1 card takes). With this complete however, I am able to 'remove' a card from the deck.

Aside from these problems, C wasn't too hard to understand and utilize to the fullest. All in all, I am glad that I learned this language because it provided
me an opportunity to create the functions that I use in higher level programming languages. That being said, I can't wait to get back into object oriented
programming because I feel a lot of the mess in my code can be cleared by using objects and classes.
