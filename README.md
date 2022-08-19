# About
I wanted to get back into programming and thought this simple game is a good start.

This will eventually be turned into a Discord bot.

## How to play
The Game is played by two players, each player is placing a single piece on a colum, the piece falls down to the most
bottom free space.

If a player has 4 or more pieces in a horizontal, vertical or diagonal line they win.


## The Playfield

Right now the playfield simple, the most top row are the 7 column.

- The Free Spaces are represented as a 0
- Player 1 pieces are a 1
- Player 2 pieces are a 2


| __1__ | __2__ | __3__ | __4__ | __5__ | __6__ | __7__ |
|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|
|   0   |   0   |   0   |   0   |   0   |   0   |   0   |
|   0   |   0   |   0   |   0   |   0   |   0   |   0   |
|   0   |   0   |   0   |   1   |   0   |   0   |   0   |
|   0   |   0   |   1   |   1   |   0   |   0   |   0   |
|   0   |   1   |   2   |   2   |   0   |   0   |   0   |
|   1   |   2   |   2   |   1   |   0   |   0   |   0   |

In this example Player 1 would have won, because they have 4 pieces in a diagonal line

# Compiling

This is a pretty simple C Code, you should be able to compile it in any modern C Compiler
(I used the C99 standard).

if you use gcc, you can just clone this repository and `gcc main.c -o connect4`, 
to launch the game you have to type `.connect4`