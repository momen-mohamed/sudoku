#ifndef LEVELS_H_
#define LEVELS_H_
#define EASY 0
#define MEDUIM 1
#define HARD 2
extern char (*selected_level)[9][2];
void reset_level();
void set_level(char selection);
int get_level_emptyPlaces_count();
char get_currentSelectedLevel();
#endif