#pragma once
#include "Arduino.h"
#ifndef byte
#define byte unsigned char
#endif

byte letter2code(char letter)
{
  switch (letter)
  {
	case ' ': return 0; break;
	case 'a': case '1': return 1; break;
    case 'c': case '3': return 3; break;
    case ',': return 4; break;
    case 'b': case '2': return 5; break;
    case 'i': case '9': return 6; break;
    case 'f': case '6': return 7; break;
    case 'e': case '5': return 9; break;
    case 'd': case '4': return 11; break;
    case ':': return 12; break;
    case 'h': case '8': return 13; break;
    case 'j': case '0': return 14; break;
    case 'g': case '7': return 15; break;
    case '\'': return 16; break;
    case 'k': return 17; break;
    case 'm': return 19; break;
    case ';': return 20; break;
    case 'l': return 21; break;
    case 's': return 22; break;
    case 'p': return 23; break;
    case '*': return 24; break;
    case 'o': return 25; break;
    case 'n': return 27; break;
    case '!': return 28; break;
    case 'r': return 29; break;
    case 't': return 30; break;
    case 'q': return 31; break;
    case '.': return 44; break;
    case 'w': return 46; break;
    case '-': return 48; break;
    case 'u': return 49; break;
    case 'x': return 51; break;
    case 'v': return 53; break;
    case 'z': return 57; break;
    case 'y': return 59; break;
    case '(': case ')': return 60; break;
  }

  return 0;
}
