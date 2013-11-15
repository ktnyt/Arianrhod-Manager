#include "manager.h"

static chara  params_chara;
static stats  params_stats;
static stats  params_main;
static stats  params_sub;
static stats  params_bonus;
static Pskill params_skill;
static int pos = 0;
static int max = 0;
static int hp  = 0;
static int mp  = 0;
static int mhp = 0;
static int mmp = 0;
static int fate  = 0;
static int mfate = 0;

void draw_chara(char* dirname) {
  params_chara = get_chara(dirname);

  int i;

  char* name = params_chara.name;
  char* main = params_chara.main;
  char* sub  = params_chara.sub;
  char* spec = params_chara.spec;

  int level = params_chara.level;
  int exp   = params_chara.exp;

  mhp   = hp   = params_chara.hp;
  mmp   = mp   = params_chara.mp;
  mfate = fate = params_chara.fate;

  init_pair(1, COLOR_BLACK, COLOR_GREEN);
  init_pair(2, COLOR_GREEN, -1);

  mvprintw(0, 0, "Name  : %s", name);
  mvprintw(1, 0, "Main  : %s", main);
  mvprintw(2, 0, "Sub   : %s", sub);
  mvprintw(3, 0, "Spec  : %s", spec);
  mvprintw(4, 0, "Level :% 3d (% 4d)", level, exp);
  mvprintw(5, 0, "HP    :% 4d /% 4d", hp, mhp);  
  mvprintw(6, 0, "MP    :% 4d /% 4d", mp, mmp);
  mvprintw(7, 0, "Fate  :% 4d /% 4d", fate, fate);

  return;
}

void draw_stats(char* dirname)
{
  params_stats = get_stats(dirname);
  params_bonus = get_bonus(dirname);
  params_main  = class_stats(params_chara.main);
  params_sub   = class_stats(params_chara.sub);

  int i;

  attron(COLOR_PAIR(2));
  for(i = 0; i < 7; ++i) mvaddch(1 + i, 18, '|');
  attroff(COLOR_PAIR(2));

  int strba = params_stats.str;
  int dexba = params_stats.dex;
  int agiba = params_stats.agi;
  int inlba = params_stats.inl;
  int senba = params_stats.sen;
  int spiba = params_stats.spi;
  int lukba = params_stats.luk;

  int strbo = strba / 3;
  int dexbo = dexba / 3;
  int agibo = agiba / 3;
  int inlbo = inlba / 3;
  int senbo = senba / 3;
  int spibo = spiba / 3;
  int lukbo = lukba / 3;

  int strcm = params_main.str;
  int dexcm = params_main.dex;
  int agicm = params_main.agi;
  int inlcm = params_main.inl;
  int sencm = params_main.sen;
  int spicm = params_main.spi;
  int lukcm = params_main.luk;

  int strcs = params_sub.str;
  int dexcs = params_sub.dex;
  int agics = params_sub.agi;
  int inlcs = params_sub.inl;
  int sencs = params_sub.sen;
  int spics = params_sub.spi;
  int lukcs = params_sub.luk;

  int strsk = params_bonus.str;
  int dexsk = params_bonus.dex;
  int agisk = params_bonus.agi;
  int inlsk = params_bonus.inl;
  int sensk = params_bonus.sen;
  int spisk = params_bonus.spi;
  int luksk = params_bonus.luk;

  int str = strbo + strcm + strcs + strsk;
  int dex = dexbo + dexcm + dexcs + dexsk;
  int agi = agibo + agicm + agics + agisk;
  int inl = inlbo + inlcm + inlcs + inlsk;
  int sen = senbo + sencm + sencs + sensk;
  int spi = spibo + spicm + spics + spisk;
  int luk = lukbo + lukcm + lukcs + luksk;

  attron(COLOR_PAIR(1));
  for(i = 18; i < COLS; ++i) mvprintw(0, i, " ");
  mvprintw(0, 18, "Stats:");
  attroff(COLOR_PAIR(1));

  mvprintw(1, 20, "Str |% 3d |% 3d | +%d |% 3d |% 3d", strba, strbo, strcm + strcs, strsk, str);
  mvprintw(2, 20, "Dex |% 3d |% 3d | +%d |% 3d |% 3d", dexba, dexbo, dexcm + dexcs, dexsk, dex);
  mvprintw(3, 20, "Agi |% 3d |% 3d | +%d |% 3d |% 3d", agiba, agibo, agicm + agics, agisk, agi);
  mvprintw(4, 20, "Int |% 3d |% 3d | +%d |% 3d |% 3d", inlba, inlbo, inlcm + inlcs, inlsk, inl);
  mvprintw(5, 20, "Sen |% 3d |% 3d | +%d |% 3d |% 3d", senba, senbo, sencm + sencs, sensk, sen);
  mvprintw(6, 20, "Spi |% 3d |% 3d | +%d |% 3d |% 3d", spiba, spibo, spicm + spics, spisk, spi);
  mvprintw(7, 20, "Luk |% 3d |% 3d | +%d |% 3d |% 3d", lukba, lukbo, lukcm + lukcs, luksk, luk);

  attron(COLOR_PAIR(2));
  for(i = 0; i < 7; ++i) mvaddch(1 + i, 49, '|');
  attroff(COLOR_PAIR(2));

  int acuba = dex;
  int atkba = 0;
  int avoba = agi;
  int defba = 0;
  int durba = spi;
  int spdba = agi + sen;
  int mobba = str + 5;

  int acubo = 0;
  int atkbo = 0;
  int avobo = 0;
  int defbo = 0;
  int durbo = 0;
  int spdbo = 0;
  int mobbo = 0;

  int acusk = 0;
  int atksk = 0;
  int avosk = 0;
  int defsk = 0;
  int dursk = 0;
  int spdsk = 0;
  int mobsk = 0;

  int acu = acuba + acubo + acusk;
  int atk = atkba + atkbo + atksk;
  int avo = avoba + avobo + avosk;
  int def = defba + defbo + defsk;
  int dur = durba + durbo + dursk;
  int spd = spdba + spdbo + spdsk;
  int mob = mobba + mobbo + mobsk;

  int acudr = 0;
  int atkdr = 0;
  int avodr = 0;
  int defdr = 0;
  int durdr = 0;
  int spddr = 0;
  int mobdr = 0;

  mvprintw(1, 51, "Acu |% 3d |% 3d |% 3d |% 3d (%d)", acuba, acubo, acusk, acu, acudr);
  mvprintw(2, 51, "Atk |% 3d |% 3d |% 3d |% 3d (%d)", atkba, atkbo, atksk, atk, atkdr);
  mvprintw(3, 51, "Avo |% 3d |% 3d |% 3d |% 3d (%d)", avoba, avobo, avosk, avo, avodr);
  mvprintw(4, 51, "Def |% 3d |% 3d |% 3d |% 3d (%d)", defba, defbo, defsk, def, defdr);
  mvprintw(5, 51, "Dur |% 3d |% 3d |% 3d |% 3d (%d)", durba, durbo, dursk, dur, durdr);
  mvprintw(6, 51, "Spd |% 3d |% 3d |% 3d |% 3d (%d)", spdba, spdbo, spdsk, spd, spddr);
  mvprintw(7, 51, "Mob |% 3d |% 3d |% 3d |% 3d (%d)", mobba, mobbo, mobsk, mob, mobdr);

  attron(COLOR_PAIR(2));
  for(i = 0; i < 7; ++i) mvaddch(1 + i, 79, '|');
  attroff(COLOR_PAIR(2));

  return;
}

void draw_skill(char* dirname)
{
  params_skill = get_skill(dirname);

  int i;

  attron(COLOR_PAIR(1));
  for(i = 0; i < COLS; ++i) mvprintw(8, i, " ");
  mvprintw(8, 0, "Skills:");
  attroff(COLOR_PAIR(1));

  attron(COLOR_PAIR(2));
  for(i = 0; i < LINES - 11; ++i) mvaddch(9 + i, 0, '|');
  attroff(COLOR_PAIR(2));

  for(i = 0; i < params_skill.index; ++i)
    {
      mvprintw(9 + i, 2, "%s", params_skill.array[i].name);
      mvprintw(9 + i, 18, "|% 02d | %s | %s | %s |% 3d | % 3d |% 2d | %s",
               params_skill.array[i].level,  params_skill.array[i].type,  params_skill.array[i].judge,
               params_skill.array[i].target, params_skill.array[i].range, params_skill.array[i].cost,
               params_skill.array[i].max,    params_skill.array[i].text);
    }

  attron(COLOR_PAIR(2));
  for(i = 0; i < LINES - 11; ++i) mvaddch(9 + i, COLS - 1, '|');
  attroff(COLOR_PAIR(2));
}

int prompt_minibuffer(char* prompt)
{
  if(prompt == NULL) prompt = "Minibuffer: ";

  int c = 0;
  int y = LINES - 1;
  int i;

  mvprintw(y, 0, "%s", prompt);

  c = getch();

  for(i = 0; i < COLS; ++i) mvaddch(y, i, ' ');

  return c;
}

char* open_minibuffer(char* prompt)
{
  if(prompt == NULL) prompt = "Minibuffer: ";

  char* buffer = NULL;
  int   buflen = 0;
  int   c      = 0;
  int   x      = strlen(prompt);
  int   y      = LINES - 1;
  int   i;

  curs_set(1);

  mvprintw(y, 0, "%s", prompt);
  move(y, x);

  buffer = malloc(sizeof(char));

  for(;;)
    {
      c = getch();
      if(c == '\n' || c == '\r')
        {
          break;
        }
      else if(c == 127 || c == 8) /* Handle backspace */
        {
          if(buflen > 0)
            {
              mvaddch(y, x + buflen - 1, ' ');
              buffer[buflen - 1] = '\0';
              buffer = realloc(buffer, (buflen - 1) * sizeof(char));
              buflen--;
            }
        }
      else
        {
          buffer = realloc(buffer, (buflen + 1) * sizeof(char));
          buffer[buflen] = c;
          buflen++;
        }
      for(i = 0; i < COLS; ++i) mvaddch(y, i, ' ');
      mvprintw(y, 0, "%s%s", prompt, buffer);
      move(y, x + buflen);
    }

  curs_set(0);

  for(i = 0; i < COLS; ++i) mvaddch(y, i, ' ');

  return buffer;
}

void ndice()
{
  char* buffer;

  int a[6];
  int i = 0;
  int m = 0;
  int n = 0;
  int t = 0;

  buffer = open_minibuffer("Number of dice: ");

  m = atoi(buffer);

  for(i = 0; i < 6; ++i) a[i] = 0;

  init_genrand((unsigned)time(NULL));

  for(i = 0; i < m; ++i)
    {
      t = (int)(genrand_real1() * 6);
      a[t]++;
      n += t + 1;
    }

  for(i = 0; i < COLS; ++i) mvaddch(LINES - 1, i, ' ');
  for(i = 0; i < 6; ++i) mvprintw(LINES - 1, i * 6, "%d:% 3d", i + 1, a[i]);
  mvprintw(LINES - 1, 0, "%d: %d    %d: %d    %d: %d    %d: %d    %d: %d    %d: %d    Total: %d",
           1, a[0], 2, a[1], 3, a[2], 4, a[3], 5, a[4], 6, a[5], n);
}

void change_hp()
{
  int c = 0;

  while(c != '+' && c != '-')
    {
      c = prompt_minibuffer("Increase or decrease? (+/-)");
    }

  if(c == '+') add_hp();
  if(c == '-') red_hp();
}

void change_mp()
{
  int c = 0;

  while(c != '+' && c != '-')
    {
      c = prompt_minibuffer("Increase or decrease? (+/-)");
    }

  if(c == '+') add_mp();
  if(c == '-') red_mp();
}

void change_fate()
{
  int c = 0;

  while(c != '+' && c != '-')
    {
      c = prompt_minibuffer("Increase or decrease? (+/-)");
    }

  if(c == '+') add_fate();
  if(c == '-') red_fate();
}

void add_hp()
{
  char* value = NULL;
  int n;
  int i;

  value = open_minibuffer("Amount HP to increase: ");
  n = atoi(value);

  for(i = 0; i < n; ++i) inc_hp();
}

void red_hp()
{
  char* value = NULL;
  int n;
  int i;

  value = open_minibuffer("Amount HP to decrease: ");
  n = atoi(value);

  for(i = 0; i < n; ++i) dec_hp();
}

void add_mp()
{
  char* value = NULL;
  value = open_minibuffer("Amount MP to increase: ");
  int n = atoi(value);
  int i;

  for(i = 0; i < n; ++i) inc_mp();
}

void red_mp()
{
  char* value = NULL;
  value = open_minibuffer("Amount MP to decrease: ");
  int n = atoi(value);
  int i;

  for(i = 0; i < n; ++i) dec_mp();
}

void add_fate()
{
  char* value = NULL;
  value = open_minibuffer("Amount Fate to increase: ");
  int n = atoi(value);
  int i;

  for(i = 0; i < n; ++i) inc_fate();
}

void red_fate()
{
  char* value = NULL;
  value = open_minibuffer("Amount Fate to decrease: ");
  int n = atoi(value);
  int i;

  for(i = 0; i < n; ++i) dec_fate();
}

void inc_hp()
{
  hp = (hp < mhp) ? hp + 1 : hp;
  mvprintw(5, 7, "% 4d", hp);
}

void dec_hp()
{
  hp = (hp > 0) ? hp - 1 : hp;
  mvprintw(5, 7, "% 4d", hp);
}

void inc_mp()
{
  mp = (mp < mmp) ? mp + 1 : mp;
  mvprintw(6, 7, "% 4d", mp);
}

void dec_mp()
{
  mp = (mp > 0) ? mp - 1 : mp;
  mvprintw(6, 7, "% 4d", mp);
}

void inc_fate()
{
  fate = (fate < mfate) ? fate + 1 : fate;
  mvprintw(7, 7, "% 4d", fate);
}

void dec_fate()
{
  fate = (fate > 0) ? fate - 1 : fate;
  mvprintw(7, 7, "% 4d", fate);
}

int move_cursor(int y)
{
  init_pair(3, COLOR_BLACK, COLOR_WHITE);
  if(y >= params_skill.index || y < 0) return 0;

  int i, j;

  for(i = 0; i < params_skill.index; ++i)
    {
      for(j = 1; j < COLS - 1; ++j) mvaddch(9 + i, j, ' ');
      mvprintw(9 + i, 2, "%s", params_skill.array[i].name);
      mvprintw(9 + i, 18, "|% 02d | %s | %s | %s |% 3d | % 3d |% 2d | %s",
               params_skill.array[i].level,  params_skill.array[i].type,  params_skill.array[i].judge,
               params_skill.array[i].target, params_skill.array[i].range, params_skill.array[i].cost,
               params_skill.array[i].max,    params_skill.array[i].text);
    }

  attron(COLOR_PAIR(3));
  for(i = 1; i < COLS - 1; ++i) mvaddch(9 + y, i, ' ');
  mvprintw(9 + y, 2, "%s", params_skill.array[y].name);
  mvprintw(9 + y, 18, "|% 02d | %s | %s | %s |% 3d | % 3d |% 2d | %s",
           params_skill.array[y].level,  params_skill.array[y].type,  params_skill.array[y].judge,
           params_skill.array[y].target, params_skill.array[y].range, params_skill.array[y].cost,
           params_skill.array[y].max,    params_skill.array[y].text);
  attroff(COLOR_PAIR(3));

  return 1;
}

