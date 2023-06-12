#ifndef SUDOKU_BRAIN_H_
#define SUDOKU_BRAIN_H_
void insialize_level();
void set_number(char num, int row, int col);
void delete_number(int row, int col);
char check_row(char num, int row);
char check_col(char num, int col);
char check_block(char num, int row, int col);
char get_mistakes_number();
void reset_mistakes();
void reset_currentCount();
char didWin();
#endif