//0ms (100%), 8.6MB (98.54%)
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeOuterParentheses(char* s) {
    int tracker = 0;
    int len = 0;
    char * removal = malloc(sizeof(char) * (strlen(s) + 1));
    for (int i = 0; s[i] != '\0'; i++){
        switch (s[i]){
            case '(':
                tracker++;

                if (tracker <= 1) break;

                removal[len] = '(';
                len += 1;

                break;
            case ')':
                tracker--;

                if (tracker <= 0) break;

                removal[len] = ')';
                len += 1;

                break;
            default:
                break;
        }
    }

    removal[len] = '\0';
    removal = realloc(removal, sizeof(char) * (len + 1));

    return removal;
}
