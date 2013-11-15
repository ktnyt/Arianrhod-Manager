#ifndef __ARIANRHOD_CHARA_C__
#define __ARIANRHOD_CHARA_C__

#include "chara.h"

chara get_chara(char* dirname)
{
  static chara params_s = { "", "", "", "", 0, 0, 0, 0, 0 };

  FILE* fp = NULL;
  char* filename = NULL;
  pair   tmp = { 0, "", "" };

  asprintf(&filename, "%s/chara.txt", dirname);

  if((fp = fopen(filename, "r")) == NULL)
    {
      endwin();
      fprintf(stderr, "Failed to open: %s\n", filename);
      exit(EXIT_FAILURE);
    }

  int i = 0;

  while(!tmp.isEOF)
    {
      tmp = parse_pair(fp);
      if(strcmp(tmp.key, "NAME")  == 0) params_s.name  = tmp.val;
      if(strcmp(tmp.key, "MAIN")  == 0) params_s.main  = tmp.val;
      if(strcmp(tmp.key, "SUB")   == 0) params_s.sub   = tmp.val;
      if(strcmp(tmp.key, "SPEC")  == 0) params_s.spec  = tmp.val;
      if(strcmp(tmp.key, "LEVEL") == 0) params_s.level = atoi(tmp.val);
      if(strcmp(tmp.key, "EXP")   == 0) params_s.exp   = atoi(tmp.val);
      if(strcmp(tmp.key, "HP")    == 0) params_s.hp    = atoi(tmp.val);
      if(strcmp(tmp.key, "MP")    == 0) params_s.mp    = atoi(tmp.val);
      if(strcmp(tmp.key, "FATE")  == 0) params_s.fate  = atoi(tmp.val);
    }

  free(filename);

  fclose(fp);

  return params_s;
}

#endif
