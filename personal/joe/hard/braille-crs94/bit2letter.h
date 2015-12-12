#pragma once
#ifndef byte
#define byte unsigned char
#endif

byte letter2code(char letter)
{
  switch (letter)
  {
    case ' ': return 0; break;
    case '!': return 22; break;
    case '"': return 38; break;
    case '$': return 48; break;
    case '%': return 52; break;
    case '&': return 47; break;
    case '(': return 4; break;
    case ')': return 28; break;
    case '*': return 20; break;
    case '+': return 22; break;
    case ',': return 2; break;
    case '-': return 36; break;
    case '.': return 4; break;
    case '/': return 2; break;
    case '0': return 26; break;
    case '1': return 1; break;
    case '2': return 3; break;
    case '3': return 9; break;
    case '4': return 25; break;
    case '5': return 17; break;
    case '6': return 27; break;
    case '7': return 11; break;
    case '8': return 19; break;
    case '9': return 10; break;
    case ':': return 18; break;
    case ';': return 6; break;
    case '=': return 54; break;
    case '?': return 34; break;
    case '@': return 28; break;
    case 'A': return 1; break;
    case 'B': return 3; break;
    case 'C': return 9; break;
    case 'D': return 25; break;
    case 'E': return 17; break;
    case 'F': return 11; break;
    case 'G': return 27; break;
    case 'H': return 19; break;
    case 'I': return 10; break;
    case 'J': return 26; break;
    case 'K': return 5; break;
    case 'L': return 7; break;
    case 'M': return 13; break;
    case 'N': return 29; break;
    case 'O': return 21; break;
    case 'P': return 15; break;
    case 'Q': return 31; break;
    case 'R': return 23; break;
    case 'S': return 14; break;
    case 'T': return 30; break;
    case 'U': return 37; break;
    case 'V': return 39; break;
    case 'W': return 58; break;
    case 'X': return 45; break;
    case 'Y': return 61; break;
    case 'Z': return 53; break;
    case '[': return 4; break;
    case ']': return 62; break;
    case 'a': return 1; break;
    case 'b': return 3; break;
    case 'c': return 9; break;
    case 'd': return 25; break;
    case 'e': return 17; break;
    case 'f': return 11; break;
    case 'g': return 27; break;
    case 'h': return 19; break;
    case 'i': return 10; break;
    case 'j': return 26; break;
    case 'k': return 5; break;
    case 'l': return 7; break;
    case 'm': return 13; break;
    case 'n': return 29; break;
    case 'o': return 21; break;
    case 'p': return 15; break;
    case 'q': return 31; break;
    case 'r': return 23; break;
    case 's': return 14; break;
    case 't': return 30; break;
    case 'u': return 37; break;
    case 'v': return 39; break;
    case 'w': return 58; break;
    case 'x': return 38; break;
    case 'y': return 61; break;
    case 'z': return 53; break;
    case '|': return 56; break;
    case '�': return 14; break;
    case '<<': return 38; break;
    case '>>': return 38; break;

    default: return '?';
  }
}

byte get_precedence(char letter)
{
  switch (letter)
  {
    case '%': return 56; break;
    case '(': return 35; break;
    case ')': return 32; break;
    case '/': return 32; break;
    case '0': return 60; break;
    case '1': return 60; break;
    case '2': return 60; break;
    case '3': return 60; break;
    case '4': return 60; break;
    case '5': return 60; break;
    case '6': return 60; break;
    case '7': return 60; break;
    case '8': return 60; break;
    case '9': return 60; break;
    case 'A': return 40; break;
    case 'B': return 40; break;
    case 'C': return 40; break;
    case 'D': return 40; break;
    case 'E': return 40; break;
    case 'F': return 40; break;
    case 'G': return 40; break;
    case 'H': return 40; break;
    case 'I': return 40; break;
    case 'J': return 40; break;
    case 'K': return 40; break;
    case 'L': return 40; break;
    case 'M': return 40; break;
    case 'N': return 40; break;
    case 'O': return 40; break;
    case 'P': return 40; break;
    case 'Q': return 40; break;
    case 'R': return 40; break;
    case 'S': return 40; break;
    case 'T': return 40; break;
    case 'U': return 40; break;
    case 'V': return 40; break;
    case 'W': return 40; break;
    case 'X': return 40; break;
    case 'Y': return 40; break;
    case 'Z': return 40; break;
    case '[': return 55; break;
    case ']': return 32; break;
    case '�': return 14; break;
    case '<<': return 32; break;
    case '>>': return 32; break;
    default: return 0;
  }
}
