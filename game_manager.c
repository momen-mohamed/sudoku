#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include "headers/terminal_color.h"
#include "headers/terminal_manager.h"
#include "headers/sudoku_brain.h"
#include "headers/levels.h"
#include "headers/game_manager.h"
#include "headers/sudokou_configuration.h"

void start_game()
{
    char user_entery_result;
    while (1)
    {
        clrscr();
        PRINT_GAME_ENTERY;
        play_intro();
        PRINT_ENTERY_INSTRUCTIONS;
        select_level();
        insialize_level();
        while (1)
        {
            clrscr();
            print_sudoku();
            PRINT_INSTRUCTIONS;
            user_entery_result = get_user_entery();
            if (user_entery_result == 0)
            {
                return;
            }
            else if (user_entery_result == 2)
            {
                reset_game();
                break;
            }
            if (get_mistakes_number() == 3)
            {
                PRINT_GAMEOVER;
                play_gameOver();
                reset_game();
            }
            else if (didWin() == 1)
            {
                PRINT_YOU_WIN;
                play_win();
                reset_game();
                break;
            }
        }
    }
}

char get_user_entery()
{
    char result = 1;
    char command;
    fflush(stdin);
    printf(BLU "please enter your command: " RESET);
    scanf("%c%*c", &command);
    fflush(stdin);
    switch (command)
    {
    case 'i':
        insert_command();
        break;
    case 'd':
        delete_command();
        break;
    case 'm':
        result = 2;
        break;
    case 'q':
        result = 0;
        break;
    default:
        printf(RED "ERROR:INCOREECT COMMAND\n" RESET);
        play_errorBuzz();
        char c =1 ;
        int i;
        tcflush(0,TCIFLUSH);
        // while (c != 10) { 
        //     i = fflush(stdin);
        //     printf("%d\n",i);
        //     scanf("%c%*c",&c); 
        //     printf("%d\n",c);
        //     printf("hello\n");         
        // }
        printf("after\n");
        break;
    }

    return result;
}

void select_level()
{
    char level;
    printf("please enter the level: ");
    fflush(stdin);
    scanf("%c", &level);
    fflush(stdin);
    set_level(level);
}

void insert_command()
{
    int num, row, col;

    printf(GRN "please enter the number you want to insert: " RESET);
    scanf("%d", &num);
    if (num >= LOWEST_NUMBER && num <= HIGHEST_NUMBER)
    {
        printf(YEL "please enter row position: " RESET);
        scanf("%d", &row);
        printf(YEL "please enter column position: " RESET);
        scanf("%d", &col);
        if ((row < LOWEST_NUMBER || row > HIGHEST_NUMBER) || (col < LOWEST_NUMBER || col > HIGHEST_NUMBER))
        {
            printf(RED "ERROR:|INCORRECT COLUMN OR ROW NUMBER|\n" RESET);
            play_errorBuzz();
        }
        else
        {
            set_number((char)num, row - 1, col - 1);
        }
    }
    else
    {
        printf(RED "ERROR:| NUMBER RANGE IS BETWEEN [1-9]|\n" RESET);
        play_errorBuzz();
    }
}

void delete_command()
{
    int row, col;

    printf(YEL "please enter row position: " RESET);
    scanf("%d", &row);
    printf(YEL "please enter column position: " RESET);
    scanf("%d", &col);
    if ((row < LOWEST_NUMBER || row > HIGHEST_NUMBER) || (col < LOWEST_NUMBER || col > HIGHEST_NUMBER))
    {
        printf(RED "ERROR:|INCORRECT COLUMN OR ROW NUMBER|\n" RESET);
    }
    else
    {
        delete_number(row - 1, col - 1);
    }
}

void reset_game()
{
    reset_currentCount();
    reset_mistakes();
    reset_level();
}
