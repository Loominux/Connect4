#include <stdio.h>
#include <stdlib.h>

void show_grid(int Grid[]);
int put_piece(int *Grid, int x, int Player);
int win_condition(int *Grid, int Player, int x, int y);


int main()
{
    int *Grid;
    Grid = (int*)calloc(0,sizeof(int)*7*6);

    int win=0, Player=2, x, y;

    do
    {
        switch (Player)
        {
            case 1:
                Player = 2;
                break;

            case 2:
                Player = 1;
                break;
        }

        y = 6;
        while (y > 5)
        {
            printf("\nPlace your piece: ");
            scanf("%d", &x);
            y = put_piece(Grid, x, Player);
        }

        show_grid(Grid);

        win = win_condition(Grid, Player, x, y);
    }
    while (win == 0);

    printf("Player %d won !!", Player);

    return 0;
}

void show_grid(int *Grid)
{
    // These for loops just go through the array and print it, I count down at the y loop, because my origin is on the bottom left and c starts to print from the top.
    for (int y = 5; y >= 0; y--)
    {
        for (int x = 0; x < 7; x++)
        {
            printf("%d ", *(Grid+6*y+x));
        }
        printf("\n");
    }
}


int put_piece(int *Grid, int x, int Player)
{

    //Start count at y = -1, because I count up at the beginning of the do while loop, so I start there with 0
    int y=-1, e=0;

    //I know the x position where the place should go, now i just have to go thought the y Layers and check if there is space
    //if there is space the y value will be returned
    do
    {
        y++;
        if (*(Grid+6*y+x) == 0)
        {
            *(Grid+6*y+x) = Player;
            e = 1;
        }
    }
    while(e != 1 && y<6);

    // If y == 5 and e is still 0, then there was no space, return 6 then, because that is an impossible position
    if (e == 0 && y == 5)
    {
        y = 6;
    }

    return y;
}

int win_condition(int *Grid, int Player, int x, int y)
{
    //All checks work the same, go through a line and count, if more than 3 pieces in a row are the same, win is set to 1

    int ix, iy, count=0, win=0;

    //Horizontal
    //Go through all x lines on the y layer
    for(ix=0; ix<7; ix++)
    {
        if (count > 3)
        {
            win=1;
        }
        else if(*(Grid+6*y+ix) == Player)
        {
            count++;
        }
        else
        {
            count=0;
        }
    }

    //Vertical
    if(win != 1)
    {
        //Go through all y layers for that x line
        for (iy = 0; iy < 6; iy++)
        {
            if (count > 3)
            {
                win = 1;
            }
            else if (*(Grid + 6 * iy + x) == Player)
            {
                count++;
            }
            else
            {
                count = 0;
            }
        }
    }

    //Diagonal l to r
    //go to the most bottom left position for the current diagonal line
    if(win != 1)
    {
        ix = x;
        iy = y;
        do
        {
            ix--;
            iy--;
        }
        while (ix > 0 && iy > 0);


        //Go from the bottom left to the top right and count pieces in a row
        do
        {
            if (count > 3)
            {
                win = 1;
            }
            else if (*(Grid + 6 * iy + ix) == Player)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            ix++;
            iy++;
        }
        while (ix < 7 && iy < 6);
    }

    //Diagonal r to l
    if(win != 1)
    {
        //go to the most bottom right position for the current diagonal line
        ix = x;
        iy = y;

        do
        {
            ix++;
            iy--;
        }
        while (ix > 7 && iy > 0);

        //Go from the bottom right to the top left and count pieces in a row
        do
        {
            if (count > 3)
            {
                win = 1;
            }
            else if (*(Grid + 6 * iy + ix) == Player)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            ix--;
            iy++;
        }
        while (ix > 0 && iy < 6);
    }

    return win;
}
