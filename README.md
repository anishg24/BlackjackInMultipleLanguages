# Blackjack but in Multiple Languages
This project is made by Anish Govind. Other projects can be found at my [GitHub](https://github.com/anishg24).

![GitHub followers](https://img.shields.io/github/followers/anishg24?label=Follow&style=social)
![GitHub repo size](https://img.shields.io/github/repo-size/anishg24/BlackjackInMultipleLanguages?style=flat-square)

## Project Objective
When I try to learn a programming language, I find it really hard to truly learn the language unless I have a project to work towards.
Recently I've decided to learn C and C++, but I need a project to truly understand the programming languages and what they offer.
I decided that project I should attempt is a terminal based blackjack game, which isn't hard to have because the game logic is pretty simple, but I took it
a step further and decided to implement ASCII art among other things.
In this repo you can expect to see all my attempts at creating Blackjack in languages I plan learn. The languages are as follows:

## Planned Languages

| Language  | Status         | ASCII Cards | Input Handling\*|
| :---:     | :---:          | :---:       | :---:           |
| C         | Completed      | Yes         | Yes             |
| C++       | In Development | N/A         | N/A             |
| Java      | In Development | N/A         | N/A             |
| Python    | Not Started    | N/A         | N/A             |

\*Making sure that user input will not error out the code to the best of my ability

## Project Log
Each folder (labeled with the respective programming language) will include its own `README.md` file. A list of the ones that are available are provided below:

* [C](https://github.com/anishg24/BlackjackInMultipleLanguage/C/README.md)
* C++
* Java
* Python

## Getting Started
1. Clone this repository
2. Run the code
  * If the programming language is a compiled programming language, I will have likely included the compiled code, to which you can run with `./Blackjack`
  * If the programming language is a interpreted programming language, you will have to use the interpreter to run the code (i.e for the Python code, run `python main.py`)
3. Play blackjack!
  
## Blackjack Rules
Most of you would know how Blackjack (or 21) is played, but for those of you who don't, here is a quick rundown:

* You are playing against the dealer.
* The objective of the game is to get a score of 21 or as close to it as possible.
* Your score is determined by the sum of the card values in your hand.
* Card values are as follows:
  - Ace\* = 11
  - King = 10
  - Queen = 10
  - Jack = 10
  - Ten = 10
  - Two through Nine are worth their face values respectively.
* At the start of the game, you and the dealer get dealt 2 cards. Both of your cards are face up and one card of the dealers is up, while the other is down.
* You have the choice to either `hit` or `stand`.
* If you `hit`, you get dealt another card, and you calculate your score accordingly. If your score is over 21, you lose instantly, but if it is under 21, you can `hit` or `stand` again. If you score is equal to 21, you win instantly.
* If you `stand`, you no longer will get dealt cards, and your score right now is your final score. The dealer's turn begins.
* The dealer flips over his unflipped card and calculates the score. If the score is under 17, the dealer must `hit` until he reaches 17 or over.
* At the end if no player instantly wins or loses, then whoever is closer to 21 is the winner. If your scores are tied, then the game is a tie.

\*The value of an Ace in actual Blackjack is either 11 or 1, whichever suits your hand the best. In my games I will be implementing them as 11 only, and later on will come back to add this feature.

## My Experience
I haven't completed all the programming languages, but I have tried making blackjack in both C and Java and I have to say. Making it in Java wasn't difficult, rather it was tedious often times. 
But on the other hand, I understand why people made C++. I come from the world of high level programming languages where the language does everything for you.
C however is not as kind as the high level programming languages. I didn't realize that the lack of having objects would change so much about my style of programming, but I enjoyed it. It was annoying having to implement methods that are typically already exist in other languages (like getting a random number within a range or deleting an element in a list), but I felt that even though C was painful to code in, I learned more about the computer and how it works. I learned more about how some of the methods that I am so familiar with today work as well, and coding this game in C was a huge stepping stone in me becoming a computer engineer.

As I continue building Blackjack with more languages, I will update this section.

## Contributing
If you have a programming language that you want to use to create Blackjack in and add to this repo, please create a pull request, I am more than happy to accept all kinds of languages in this repo.

## Contributing Members

Creator: [Anish Govind](https://github.com/anishg24)

Ways to contact:
* [E-Mail](anishg24@gmail.com)

**IF YOU FIND ANY ISSUES OR BUGS PLEASE OPEN AN ISSUE**
