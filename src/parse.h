#ifndef __ARIANRHOD_PARSE_H__
#define __ARIANRHOD_PARSE_H__

#include "types.h"

pair parse_pair(FILE* fp);
triplet parse_triplet(FILE* fp);
char** parse_line(char* line);
_skill parse_skill(FILE* fp);

#endif
