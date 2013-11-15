#ifndef __ARIANRHOD_CLASS_C__
#define __ARIANRHOD_CLASS_C__

#include "class.h"

stats class_stats(char* name)
{
  stats class;

  int i;

  for(i = 0; name[i]; ++i) name[i] = 0x5b > name[i] && name[i] > 0x40 ? name[i] | 0x60 : name[i];

  if(strcmp(name, "mage"))     class = mage;
  if(strcmp(name, "summoner")) class = summoner;

  return class;
}

#endif
