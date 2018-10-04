#include <stdio.h>

int Index(int c) {
  return c - 'A' + 1;
}

int BMMatch(char Text[], int TextLen, char Pat[], int PatLen) {
  int Skip[26], PText, PPat, PLast, I;
  for (I = 1; I <= 26; I += 1) {
    Skip[I - 1] = PatLen;
  }
  for (I = 1; I <= PatLen - 1; I += 1) {
    Skip[Index(Pat[I - 1]) - 1] = PatLen - I;
  }
  PLast = PatLen;
  while (PLast <= TextLen) {
    PText = PLast; /* Alpha */
    fputs("Alpha\n", stderr);
    PPat = PatLen;
    while (Text[PText - 1] == Pat[PPat - 1]) {
      fputs("Beta\n", stderr);
      if (PPat == 1) { /* Beta */
	return PText;
      }
      PText = PText - 1;
      PPat = PPat - 1;
    }
    PLast = PLast + Skip[Index(Text[PLast - 1]) - 1];
  }
  return -1;
}

int main(void) {
  char Text[] = "ABCXBBACABACADEC";
  char Pat[] = "ABAC";
  int TextLen = 16;
  int PatLen = 4;
  int r;
  r = BMMatch(Text, TextLen, Pat, PatLen);
  printf("BMMatch = %d\n", r);
  return 0;
}
