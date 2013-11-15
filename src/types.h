#ifndef __ARIANRHOD_TYPES_H__
#define __ARIANRHOD_TYPES_H__

typedef struct {
  int   isEOF;
  char* key;
  char* val;
} pair;

typedef struct {
  char* name;
  char* main;
  char* sub;
  char* spec;
  int   level;
  int   exp;
  int   hp;
  int   mp;
  int   fate;
} chara;

typedef struct {
  char* name;
  int   level;
  char* type;
  char* judge;
  char* target;
  int   range;
  int   cost;
  int   max;
  char* text;
  int   isEOF;
} skill;

typedef struct {
  skill* array;
  int    index;
} Pskill;

typedef struct {
  int str;
  int dex;
  int agi;
  int inl;
  int sen;
  int spi;
  int luk;
} stats;

#endif
