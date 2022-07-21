#include "strlen.h"

size_t std_strlen(const char *str)
{
  int comp;

  comp = 0;
  while(str[comp] != '\0')
    comp++;
  return comp;
}
