#ifndef __ARIANRHOD_MANAGER_H__
#define __ARIANRHOD_MANAGER_H__

#include "MT.h"
#include <time.h>
#include "types.h"
#include "parse.h"
#include "parse.c"
#include "bonus.h"
#include "bonus.c"
#include "class.h"
#include "class.c"
#include "stats.h"
#include "stats.c"


void draw_chara(char* dirname);
void draw_stats(char* dirname);
void draw_skill(char* dirname);
char* open_minibuffer(char* prompt);
int prompt_minibuffer(char* prompt);
void change_hp();
void change_mp();
void change_fate();
void add_hp();
void red_hp();
void add_mp();
void red_mp();
void add_fate();
void red_fate();
void inc_hp();
void dec_hp();
void inc_mp();
void dec_mp();
void inc_fate();
void dec_fate();

#endif
