#include <stdbool.h>
#include "my.h"

int		my_char_isprintable(const char letter)
{
  if (!((letter >= 32 && letter <= 126) || letter == '\0'
	|| (letter >= 7 && letter <= 13)))
    return (false);
  return (true);
}
