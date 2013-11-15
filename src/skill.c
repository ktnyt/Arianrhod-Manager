#ifndef __ARIANRHOD_SKILL_C__
#define __ARIANRHOD_SKILL_C__

#include "skill.h"

Pskill get_skill(char* dirname)
{
  skill* params_s = malloc(sizeof(skill));

  FILE* fp = NULL;
  char* filename = NULL;
  skill tmp = {"", 0, 0, 0, 0, 0, 0, 0, "", 0};
  Pskill ret;

  int   i = 0;

  asprintf(&filename, "%s/skill.txt", dirname);

  if((fp = fopen(filename, "r")) == NULL)
    {
      endwin();
      fprintf(stderr, "Failed to open: %s\n", filename);
      exit(EXIT_FAILURE);
    }

  while(!tmp.isEOF)
    {
      tmp = parse_skill(fp);
      if(tmp.name != NULL)
        params_s = realloc(params_s, (i + 1) * sizeof(skill));
        params_s[i] = tmp;
        i++;
    }

  ret.array = params_s;
  ret.index = i - 1;

  return ret;
}

#endif
