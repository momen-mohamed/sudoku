#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "headers/terminal_color.h"
#include "headers/levels.h"
#include "headers/terminal_manager.h"
#include "headers/sudoku_brain.h"
#include "headers/sudokou_configuration.h"

void print_sudoku(void)
{
    int i, j;

    char current_level = get_currentSelectedLevel();
    printf(YEL "DIFFICULTY\tMISTAKES\n" RESET);
    if (current_level == EASY)
    {
        printf(GRN "EASY" RESET);
    }
    else if (current_level == MEDUIM)
    {
        printf(YEL "MEDUIM" RESET);
    }
    else
    {
        printf(RED "HARD" RESET);
    }
    printf("\t\t%d/3\n\n", get_mistakes_number());

    printf("   ");
    for (i = 0; i < COLS; i++)
    {
        printf(CYN " %d " RESET, i + 1);
        if (((i + 1) % 3) == 0)
        {
            printf(CYN "|" RESET);
        }
    }
    printf("\n");

    printf(CYN "-------------------------------\n" RESET);
    for (i = 0; i < ROWS; i++)
    {
        printf(CYN " %d " RESET, i + 1);
        for (j = 0; j < COLS; j++)
        {
            if (selected_level[i][j][1] == 0)
            {
                printf(MAG " %d " RESET, selected_level[i][j][0]);
            }
            else
            {
                if (selected_level[i][j][0] == 0)
                {
                    printf(" - ");
                }
                else
                {
                    printf(GRN " %d " RESET, selected_level[i][j][0]);
                }
            }
            if (((j + 1) % 3) == 0)
            {
                printf(CYN "|" RESET);
            }
        }
        if (((i + 1) % 3) == 0)
        {
            printf("\n");
            printf(CYN "-------------------------------" RESET);
        }
        printf("\n");
    }
}

void print_wrongPositionMessage(char row_check, char col_check, char block_check)
{
    if (row_check == 0 && col_check == 0 && block_check == 1)
    {
        printf(RED "|NUMBER IS REPEATED AT THE SAME BLOCK|\n" RESET);
    }
    else if (row_check == 0 && col_check == 1 && block_check == 0)
    {
        printf(RED "|NUMBER IS REPEATED AT THE SAME COLUMN|\n" RESET);
    }
    else if (row_check == 0 && col_check == 1 && block_check == 1)
    {
        printf(RED "|NUMBER IS REPEATED AT THE SAME BLOCK AND COLUMN|\n" RESET);
    }
    else if (row_check == 1 && col_check == 0 && block_check == 0)
    {
        printf(RED "|NUMBER IS REPEATED AT THE SAME ROW|\n" RESET);
    }
    else if (row_check == 1 && col_check == 0 && block_check == 1)
    {
        printf(RED "|NUMBER IS REPEATED AT THE SAME ROW AND BLOCK|\n" RESET);
    }
    else if (row_check == 1 && col_check == 1 && block_check == 0)
    {
        printf(RED "|NUMBER IS REPEATED AT THE SAME ROW AND COLUMN|\n" RESET);
    }
    else
    {
        printf(RED "|NUMBER IS REPEATED AT THE SAME ROW,COLUMN AND BLOCK|\n" RESET);
    }
}

void clrscr()
{
#ifdef __APPLE__
    system("clear");
#else
    system("@cls||clear");
#endif
}

void play_intro()
{
#ifdef __APPLE__
    system("afplay sounds/intro.wav");
#else
    system("powershell -c (New-Object Media.SoundPlayer 'sounds/intro.wav').PlaySync();");
#endif
}

void play_win()
{

#ifdef __APPLE__
    system("afplay sounds/win.wav");
#else
    system("powershell -c (New-Object Media.SoundPlayer 'sounds/win.wav').PlaySync();");
#endif
}

void play_correct()
{

#ifdef __APPLE__
    system("afplay sounds/correct.wav");
#else
    system("powershell -c (New-Object Media.SoundPlayer 'sounds/correct.wav').PlaySync();");
#endif
}

void play_errorBuzz()
{
#ifdef __APPLE__
    system("afplay sounds/error_buzz.wav");
#else
    system("powershell -c (New-Object Media.SoundPlayer 'sounds/error_buzz.wav').PlaySync();");
#endif
}

void play_fail()
{
#ifdef __APPLE__
    system("afplay sounds/fail.wav");
#else
    system("powershell -c (New-Object Media.SoundPlayer 'sounds/fail.wav').PlaySync();");
#endif
}

void play_delete()
{
#ifdef __APPLE__
    system("afplay sounds/delete.wav");
#else
    system("powershell -c (New-Object Media.SoundPlayer 'sounds/delete.wav').PlaySync();");
#endif
}

void play_gameOver()
{
#ifdef __APPLE__
    system("afplay sounds/game_over.wav");
#else
    system("powershell -c (New-Object Media.SoundPlayer 'sounds/game_over.wav').PlaySync();");
#endif
}