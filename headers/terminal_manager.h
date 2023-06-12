#ifndef TERMINAL_MANAGER_H_
#define TERMINAL_MANAGER_H_

#define GOTOXY(x, y) printf("\033[%d;%dH", (y), (x))

#define PRINT_GAMEOVER                                                                   \
    GOTOXY(46, 11);                                                                      \
    printf(RED"░██████╗░░█████╗░███╗░░░███╗███████╗  ░█████╗░██╗░░░██╗███████╗██████╗░\n"); \
    GOTOXY(46, 12);                                                                      \
    printf("██║░░██╗░███████║██╔████╔██║█████╗░░  ██║░░██║╚██╗░██╔╝█████╗░░██████╔╝\n"); \
    GOTOXY(46, 13);                                                                      \
    printf("██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░  ██║░░██║░╚████╔╝░██╔══╝░░██╔══██╗\n"); \
    GOTOXY(46, 14);\
    printf("╚██████╔╝██║░░██║██║░╚═╝░██║███████╗  ╚█████╔╝░░╚██╔╝░░███████╗██║░░██║\n");\
    GOTOXY(46, 15);\
    printf("░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝  ░╚════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝\n"RESET);\
    GOTOXY(0, 0)
#define PRINT_YOU_WIN    \
    GOTOXY(46, 11);                                                                      \
    printf(GRN"██╗░░░██╗░█████╗░██╗░░░██╗  ░██╗░░░░░░░██╗██╗███╗░░██╗n"); \
    GOTOXY(46, 12);                                                                      \
    printf("╚██╗░██╔╝██╔══██╗██║░░░██║  ░██║░░██╗░░██║██║████╗░██║\n"); \
    GOTOXY(46, 13);                                                                      \
    printf("░╚████╔╝░██║░░██║██║░░░██║  ░╚██╗████╗██╔╝██║██╔██╗██║\n"); \
    GOTOXY(46, 14);\
    printf("░░╚██╔╝░░██║░░██║██║░░░██║  ░░████╔═████║░██║██║╚████║\n");\
    GOTOXY(46, 15);\
    printf("░░░██║░░░╚█████╔╝╚██████╔╝  ░░╚██╔╝░╚██╔╝░██║██║░╚███║\n");\
    GOTOXY(46, 16);\
    printf("░░░╚═╝░░░░╚════╝░░╚═════╝░  ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝\n"RESET);\
    GOTOXY(0, 0)

    #define PRINT_GAME_ENTERY \
    printf(BLU " _______           ______   _______  _                \n");\
    printf("(  ____ \\|\\     /|(  __  \\ (  ___  )| \\    /\\|\\     /|\n");\
    printf("| (    \\/| )   ( || (  \\  )| (   ) ||  \\  / /| )   ( |\n");\
    printf("| (_____ | |   | || |   ) || |   | ||  (_/ / | |   | |\n");\
    printf("(_____  )| |   | || |   | || |   | ||   _ (  | |   | |\n");\
    printf("      ) || |   | || |   ) || |   | ||  ( \\ \\ | |   | |\n");\
    printf("      ) || |   | || |   ) || |   | ||  ( \\ \\ | |   | |\n");\
    printf("/\\____) || (___) || (__/  )| (___) ||  /  \\ \\| (___) |\n");\
    printf("\\_______)(_______)(______/ (_______)|_/    \\/(_______)\n\n");\
    printf("\t\tmade with");\
    printf(RED" ♥ "RESET);\
    printf(BLU"by momen mohamed\n\n"RESET)

    #define PRINT_INSTRUCTIONS\
    GOTOXY(46, 4);\
    printf(YEL "Commands\n" RESET);\
    GOTOXY(46, 5);\
    printf(GRN "i - insert or edit number\n" RESET);\
    GOTOXY(46, 6);\
    printf(GRN "d - delete number\n" RESET);\
    GOTOXY(46, 7);\
    printf(GRN "m - main menu\n" RESET);\
    GOTOXY(46, 8);\
    printf(GRN "q - quit game\n" RESET);\
    GOTOXY(0, 18)

    #define PRINT_ENTERY_INSTRUCTIONS\
    GOTOXY(65, 4);\
    printf(YEL "Commands\n" RESET);\
    GOTOXY(65, 5);\
    printf(GRN "e - easy level\n" RESET);\
    GOTOXY(65, 6);\
    printf(GRN "m - meduim level\n" RESET);\
    GOTOXY(65, 7);\
    printf(GRN "any other key - hard level\n" RESET);\
    GOTOXY(0, 14)


void print_sudoku(void);
void print_wrongPositionMessage(char row_check, char col_check, char block_check);
void play_intro();
void play_win();
void play_correct();
void play_fail();
void play_delete();
void play_gameOver();
void play_errorBuzz();
void clrscr();

#endif
