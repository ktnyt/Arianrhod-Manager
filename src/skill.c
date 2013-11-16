#ifndef __ARIANRHOD_SKILL_C__
#define __ARIANRHOD_SKILL_C__

#include "skill.h"

skill get_skill(char* dirname)
{
  _skill* params_s = malloc(sizeof(_skill));

  FILE* fp = NULL;
  char* filename = NULL;
  _skill tmp = {"", 0, 0, 0, 0, 0, 0, 0, "", 0};
  skill ret;

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
        params_s = realloc(params_s, (i + 1) * sizeof(_skill));
        params_s[i] = tmp;
        i++;
    }

  ret.array = params_s;
  ret.index = i - 1;

  return ret;
}

#endif
