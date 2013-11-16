#ifndef __ARIANRHOD_CONTROLS_C__
#define __ARIANRHOD_CONTROLS_C__

void draw_controls(int mode)
{
  int i;

  init_pair(1, COLOR_BLACK, COLOR_GREEN);
  init_pair(2, COLOR_GREEN, -1);

  attron(COLOR_PAIR(1));
  for(i = 0; i < COLS; ++i) mvaddch(LINES - 2, i, ' ');
  attroff(COLOR_PAIR(1));

  switch(mode)
    {
    case 0:
      mvprintw(LINES - 2, 0, "");
      break;
    }

  return;
}

void draw_help()
{
  int i;

  mvprintw(LINES - 1, 0, "h: Change HP\tm: Change MP\tf: Change Fate\td: Roll"
           " Dice\tq: Quit");
}

#endif
