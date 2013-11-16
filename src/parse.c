#ifndef __ARIANRHOD_PARSE_C__
#define __ARIANRHOD_PARSE_C__

pair parse_pair(FILE* fp)
{
  pair ret = { 0, "", "" };

  int c = 0;

  int buflen = 0;
  int bufnum = 0;
  char* buffer = NULL;

  buffer = (char*)malloc(sizeof(char));

  while(c != EOF)
    {
      c = fgetc(fp);

      if(c == '\n' || c == '\r')
        {
          ret.val = buffer;
          bufnum++;

          return ret;
        }
      else if(c == ' ' || c == '\t')
        {
          ret.key = buffer;
          bufnum++;

          buffer = (char*)malloc(sizeof(char));
          buflen = 0;

          while(c == ' ' || c == '\t')
            {
              c = fgetc(fp);
            }
        }

      buffer = (char*)realloc(buffer, (buflen + 1) * sizeof(char));
      buffer[buflen] = c;
      buflen++;
    }

  ret.isEOF = 1;

  return ret;
}

triplet parse_triplet(FILE* fp)
{
  triplet ret = { 0, "", "", "" };

  int c = 0;

  int   buflen = 0;
  char* buffer = NULL;
  char** tmp;

  buffer = (char*)malloc(sizeof(char));

  while(c != EOF)
    {
      c = fgetc(fp);

      if(c == '\n' || c == '\r')
        {
          tmp = parse_line(buffer);

          ret.key  = tmp[0];
          ret.val1 = tmp[1];
          ret.val2 = tmp[2];

          buffer = malloc(sizeof(char));
          buflen = 0;

          return ret;
        }

      buffer = (char*)realloc(buffer, (buflen + 1) * sizeof(char));
      buffer[buflen] = c;
      buflen++;
    }

  ret.isEOF = 1;

  return ret;
}

char** parse_line(char* line)
{
  int   i;
  char* token;
  char** ret;

  ret = (char**)malloc(sizeof(char*));

  token = strtok(line, " ");

  if(token == NULL)
    {
      return NULL;
    }

  ret[i] = token;
  i = 1;

  while((token = strtok(NULL, " ")) != NULL)
    {
      ret = (char**)realloc(ret, (i + 1) * sizeof(char*));
      ret[i] = token;
      i++;
    }

  return ret;
}

_skill parse_skill(FILE* fp)
{
  int   c = 0;
  int   n = 0;
  int   buflen = 0;
  int   bufnum = 0;
  char* buffer;
  char* token;
  char** tmp;
  _skill ret = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  buffer = (char*)malloc(sizeof(char));

  while(c != EOF)
    {
      c = fgetc(fp);

      if(c == '\n' || c == '\r')
        {
          buffer = (char*)realloc(buffer, (buflen + 1) * sizeof(char));
          buffer[buflen] = '\0';

          if((tmp = parse_line(buffer)) != NULL)
            {
              ret.name   =      tmp[0];
              ret.level  = atoi(tmp[1]);
              ret.type   =      tmp[2];
              ret.judge  =      tmp[3];
              ret.target =      tmp[4];
              ret.range  = atoi(tmp[5]);
              ret.cost   = atoi(tmp[6]);
              ret.max    = atoi(tmp[7]);
              ret.text   =      tmp[8];
            }

          fprintf(stderr, "%s %s %s %s %s %s %s %s %s\n",
                  tmp[0], tmp[1], tmp[2], tmp[3],
                  tmp[4], tmp[5], tmp[6], tmp[7],
                  tmp[8]
                  );

          return ret;
        }

      if(c != EOF)
        {
          buffer = (char*)realloc(buffer, (buflen + 1) * sizeof(char));
          buffer[buflen] = c;
          buflen++;
        }
    }

  if(strlen(buffer) != 0)
    {
      if((tmp = parse_line(buffer)) != NULL)
        {
          while(tmp[n] != NULL) ++n;

          if(n == 9)
            {
              ret.name   =      tmp[0];
              ret.level  = atoi(tmp[1]);
              ret.type   =      tmp[2];
              ret.judge  =      tmp[3];
              ret.target =      tmp[4];
              ret.range  = atoi(tmp[5]);
              ret.cost   = atoi(tmp[6]);
              ret.max    = atoi(tmp[7]);
              ret.text   =      tmp[8];
            }
        }
    }
  
  ret.isEOF = 1;

  return ret;
}

#endif
