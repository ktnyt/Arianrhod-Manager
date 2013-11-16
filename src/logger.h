#ifndef __ARIANRHOD_LOGGER_H__
#define __ARIANRHOD_LOGGER_H__

#include <stdarg.h>

static FILE* log = NULL;

void init_logger()
{
  if(log == NULL)
    {
      log = fopen("arianrhod.log", "w");
    }
}

void close_logger()
{
  if(log != NULL)
    {
      fclose(log);
    }
}

void lprintf(const char* format, ...)
{
  va_list args;
  va_start(args, format);
  vfprintf(log, format, args);
  va_end(args);
}

#endif
