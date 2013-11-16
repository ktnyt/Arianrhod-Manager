#ifndef __ARIANRHOD_TYPES_H__
#define __ARIANRHOD_TYPES_H__

typedef struct {
  int   isEOF;
  char* key;
  char* val;
} pair;

typedef struct {
  int   isEOF;
  char* key;
  char* val1;
  char* val2;
} triplet;

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
} _skill;

typedef struct {
  _skill* array;
  int     index;
} skill;

typedef struct {
  int str;
  int dex;
  int agi;
  int inl;
  int sen;
  int spi;
  int luk;
} stats;

typedef struct {
  int acu;
  int atk;
  int avo;
  int def;
  int dur;
  int spd;
  int mob;
} equip;

#endif
