#include <stdio.h>
#include <stdlib.h>
#include "headers/terminal_color.h"
#include "headers/terminal_manager.h"
#include "headers/levels.h"
#include "headers/sudoku_brain.h"
#include "headers/sudokou_configuration.h"


static char mistakes;
static int empty_place_count;
static int current_count;

void insialize_level()
{
    empty_place_count = get_level_emptyPlaces_count();
}

void set_number(char num, int row, int col)
{
    char row_check = check_row(num, row);
    char col_check = check_col(num, col);
    char block_check = check_block(num, row, col);

    if (selected_level[row][col][1] == 1 && row_check == 0 && col_check == 0 && block_check == 0)
    {
        if (selected_level[row][col][0] == 0)
        {
            current_count++;
        }
        selected_level[row][col][0] = num;
        play_correct();
    }
    else if (selected_level[row][col][1] == 0)
    {
        printf(RED "|CANNOT SET NUMBER AT THIS POSITION|\n" RESET);
        play_errorBuzz();
    }
    else
    {
        print_wrongPositionMessage(row_check, col_check, block_check);
        play_fail();
        mistakes++;
    }
}

void delete_number(int row, int col)
{
    if (selected_level[row][col][1] == 0)
    {
        printf(RED "|YOU CANNOT DELETE NUMBER AT THIS POSITION|\n" RESET);
        play_errorBuzz();
    }
    else if (selected_level[row][col][0] == 0)
    {
        printf(RED "|THRER IS NO NUMBER AT THIS POSITION|\n" RESET);
        play_errorBuzz();
    }
    else
    {
        selected_level[row][col][0] = 0;
        play_delete();
        current_count--;
    }
}

char check_row(char num, int row)
{
    int i, result = 0;
    for (i = 0; i < COLS; i++)
    {
        if (num == selected_level[row][i][0])
        {
            result = 1;
        }
    }
    return result;
}

char check_col(char num, int col)
{
    int i, result = 0;
    for (i = 0; i < COLS; i++)
    {
        if (num == selected_level[i][col][0])
        {
            result = 1;
        }
    }
    return result;
}

char check_block(char num, int row, int col)
{
    int i, j, result = 0, flag = 0;
    row = (row / 3) * 3;
    col = (col / 3) * 3;

    for (i = 0; i < BLOCK_ROWS && flag == 0; i++)
    {
        for (j = 0; j < BLOCK_COLS && flag == 0; j++)
        {
            if (num == selected_level[row + i][col + j][0])
            {
                result = 1;
                flag = 1;
            }
        }
    }
    return result;
}

char get_mistakes_number()
{
    return mistakes;
}

void reset_mistakes()
{
    mistakes = 0;
}

void reset_currentCount()
{
    current_count = 0;
}

char didWin()
{
    char win = 0;
    if (current_count == empty_place_count)
    {
        win = 1;
    }
    return win;
}