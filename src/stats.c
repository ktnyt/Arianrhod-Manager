#ifndef __ARIANRHOD_STATS_C__
#define __ARIANRHOD_STATS_C__

#include "stats.h"

stats get_stats(char* dirname)
{
  static stats params_s = { 0, 0, 0, 0, 0, 0, 0 };

  FILE* fp = NULL;
  char* filename = NULL;
  pair   tmp = { 0, "", "" };

  asprintf(&filename, "%s/stats.txt", dirname);

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
      if(strcmp(tmp.key, "STR") == 0) params_s.str = atoi(tmp.val);
      if(strcmp(tmp.key, "DEX") == 0) params_s.dex = atoi(tmp.val);
      if(strcmp(tmp.key, "AGI") == 0) params_s.agi = atoi(tmp.val);
      if(strcmp(tmp.key, "INT") == 0) params_s.inl = atoi(tmp.val);
      if(strcmp(tmp.key, "SEN") == 0) params_s.sen = atoi(tmp.val);
      if(strcmp(tmp.key, "SPI") == 0) params_s.spi = atoi(tmp.val);
      if(strcmp(tmp.key, "LUK") == 0) params_s.luk = atoi(tmp.val);
    }

  free(filename);

  fclose(fp);

  return params_s;
}

#endif
