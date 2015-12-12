#pragma once
#ifndef byte
#define byte unsigned char
#endif
byte letter2code(char letter)
{
  switch (letter)
  {
    case ' ': return 0; break;
    case '!': return 11; break;
    case '"': return 19; break;
    case '$': return 24; break;
    case '%': return 26; break;
    case '&': return 23; break;
    case '(': return 2; break;
    case ')': return 14; break;
    case '*': return 10; break;
    case '+': return 11; break;
    case ',': return 1; break;
    case '-': return 18; break;
    case '.': return 2; break;
    case '/': return 1; break;
    case '0': return 13; break;
    case '1': return 0; break;
    case '2': return 1; break;
    case '3': return 4; break;
    case '4': return 12; break;
    case '5': return 8; break;
    case '6': return 13; break;
    case '7': return 5; break;
    case '8': return 9; break;
    case '9': return 5; break;
    case ':': return 9; break;
    case ';': return 3; break;
    case '=': return 27; break;
    case '?': return 17; break;
    case '@': return 14; break;
    case 'A': return 0; break;
    case 'B': return 1; break;
    case 'C': return 4; break;
    case 'D': return 12; break;
    case 'E': return 8; break;
    case 'F': return 5; break;
    case 'G': return 13; break;
    case 'H': return 9; break;
    case 'I': return 5; break;
    case 'J': return 13; break;
    case 'K': return 2; break;
    case 'L': return 3; break;
    case 'M': return 6; break;
    case 'N': return 14; break;
    case 'O': return 10; break;
    case 'P': return 7; break;
    case 'Q': return 15; break;
    case 'R': return 11; break;
    case 'S': return 7; break;
    case 'T': return 15; break;
    case 'U': return 18; break;
    case 'V': return 19; break;
    case 'W': return 29; break;
    case 'X': return 22; break;
    case 'Y': return 30; break;
    case 'Z': return 26; break;
    case '[': return 2; break;
    case ']': return 31; break;
    case 'a': return 0; break;
    case 'b': return 1; break;
    case 'c': return 4; break;
    case 'd': return 12; break;
    case 'e': return 8; break;
    case 'f': return 5; break;
    case 'g': return 13; break;
    case 'h': return 9; break;
    case 'i': return 5; break;
    case 'j': return 13; break;
    case 'k': return 2; break;
    case 'l': return 3; break;
    case 'm': return 6; break;
    case 'n': return 14; break;
    case 'o': return 10; break;
    case 'p': return 7; break;
    case 'q': return 15; break;
    case 'r': return 11; break;
    case 's': return 7; break;
    case 't': return 15; break;
    case 'u': return 18; break;
    case 'v': return 19; break;
    case 'w': return 29; break;
    case 'x': return 19; break;
    case 'y': return 30; break;
    case 'z': return 26; break;
    case '|': return 28; break;
    case '�': return 7; break;
    case '<<': return 19; break;
    case '>>': return 19; break;

    default: return '?';
  }
}
