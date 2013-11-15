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

skill parse_line(char* line)
{
  int   i;
  char* token;
  skill ret = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  i = 0;

  token = strtok(line, " ");

  ret.name = token;

  while((token = strtok(NULL, " ")) != NULL)
    {
      switch(i)
        {
        case 0: ret.level  = atoi(token); break;
        case 1: ret.type   = token;       break;
        case 2: ret.judge  = token;       break;
        case 3: ret.target = token;       break;
        case 4: ret.range  = atoi(token); break;
        case 5: ret.cost   = atoi(token); break;
        case 6: ret.max    = atoi(token); break;
        case 7: ret.text   = token;       break;
        }

      i++;
    }

  return ret;
}

skill parse_skill(FILE* fp)
{
  int   c = 0;
  int   buflen = 0;
  int   bufnum = 0;
  char* buffer;
  char* token;
  skill ret = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  buffer = (char*)malloc(sizeof(char));

  while(c != EOF)
    {
      c = fgetc(fp);

      if(c == '\n' || c == '\r')
        {
          buffer = (char*)realloc(buffer, (buflen + 1) * sizeof(char));
          buffer[buflen] = '\0';

          ret = parse_line(buffer);

          return ret;
        }

      buffer = (char*)realloc(buffer, (buflen + 1) * sizeof(char));
      buffer[buflen] = c;
      buflen++;
    }

  ret = parse_line(buffer);
  ret.isEOF = 1;

  return ret;
}

#endif
