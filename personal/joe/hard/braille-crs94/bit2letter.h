#pragma once
#ifndef byte
#define byte unsigned char
#endif
byte letter2code(char letter)
{
  switch (letter)
  {
      case ' ': return 0; break;

    default: return '?';
  }
}
