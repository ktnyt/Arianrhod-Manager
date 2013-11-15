#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <locale.h>
#include "arianrhod.h"

void run(char* dirname)
{
  int ch, x, y, i;

  curs_set(0);

  x = 0;
  y = 0;

  for(;;)
    {
      draw_chara(dirname);
      draw_stats(dirname);
      draw_skill(dirname);
      draw_controls(0);
      move_cursor(y);
      cbreak();
      noecho();
      ch = getch();
      for(i = 0; i < COLS; ++i) mvaddch(LINES - 1, i, ' ');
      mvaddch(LINES - 1, COLS - 1, ch);

      if(ch == 'q') break;
      if(ch == 'j') y = move_cursor(y + 1) ? y + 1 : y;
      if(ch == 'k') y = move_cursor(y - 1) ? y - 1 : y;
      if(ch == 'h') change_hp();
      if(ch == 'm') change_mp();
      if(ch == 'f') change_fate();
      if(ch == 'd') ndice();
      if(ch == '?') draw_help();
    }

  return;
}

int main(int argc, char* argv[])
{
  initscr();
  noecho();
  keypad(stdscr, TRUE);
  setlocale(LC_ALL, "ja_JP.UTF-8");
  start_color();
  use_default_colors();

  run(argv[1]);

  endwin();
  return 0;
}
