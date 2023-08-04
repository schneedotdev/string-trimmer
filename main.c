#include <stdio.h>
#define MAXLINE 1000
#define IN_WORD 1
#define NOT_IN_WORD 0

int findStartIndex(char line[], int length);
int findEndIndex(char line[], int length);
void printFormattedString(char line[], int startIndex, int endIndex);

/*  remove trailing blanks and tabs from each line of 
    input, and delete blank lines */
int main() {
  int c, length = 0;
  char line[MAXLINE];

  printf("Please enter a string to be formatted. Leading and trailing whitespaces\nwill be removed, along with tabs within the middle of the string.\n");

  while ((c = getchar()) != EOF && length < MAXLINE) {
    if (c == '\n') {
      int startIndex = findStartIndex(line, length);
      int endIndex = findEndIndex(line, length);

      printFormattedString(line, startIndex, endIndex);

      length = 0;
    } else {
      line[length] = c;
      ++length;
    }
  }
}

// findStartIndex - find the index where the first word begins
int findStartIndex(char line[], int length) {
  int startIndex = 0;
  int state = NOT_IN_WORD;

  for (int i = 0; state == NOT_IN_WORD && i < length; ++i) {
    if (line[i] != ' ' && line[i] != '\t') {
      state = IN_WORD;
      startIndex = i;
    }
  }

  return startIndex;
}

// findEndIndex - find the index where the last word ends
int findEndIndex(char line[], int length) {
  int endIndex = length;
  int state = NOT_IN_WORD;

  for (int i = length - 1; state == NOT_IN_WORD && i >= 0; --i) {
    if (line[i] != ' ' && line[i] != '\t') {
        state = IN_WORD;
        endIndex = i + 1;
    }
  }

  return endIndex;
}

void printFormattedString(char line[], int startIndex, int endIndex) {
  char formatted[MAXLINE];
  int j = 0;
  
  // copy over new string
  for (int i = startIndex; i < endIndex; ++i) {
    if (line[i] != '\t') {
      formatted[j] = line[i];
      ++j;
    }
  }

  formatted[j] = '\0';

  printf("the line: \"%s\"\n", line);
  printf("was formatted to: \"%s\"\n", formatted);
}