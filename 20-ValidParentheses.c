//this submission returned 0ms runtime (beats 100%) and 8.58mb memory (beats 96.95%)

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    //validity checker
    if (!s)
        return false;

    int i = strlen(s);

    //
    int n = -1;
    char openers[i];

    //goes through the entire array once, ordinally taking note of openers and checking if closers match the most recent non-popped opener
    for (int j = 0; j < i; j++){
        //opener case -- keeps track of where the last opener was and iterates n alongside it
        if (s[j] == '(' || s[j] == '[' || s[j] == '{'){
            openers[++n] = s[j];
        } //closer case -- checks to see if the closer is the same type as the most recent non-popped opener, deiterates n if so
        else if (s[j] == ')' || s[j] == ']' || s[j] == '}'){
            //if there have been more closers than openers, we immediately know that the string is invalid
            if (n < 0) return false;
            char opener = openers[n--];
            if ((s[j] == ')' && opener != '(') || (s[j] == ']' && opener != '[') || (s[j] == '}' && opener != '{'))
                return false;
        } else return false; //the string is obviously invalid if there is an invalid type within the string
    }

    //success if n is pushed back to its original value after making its way through the entire array; will only return true if the #of openers and closers matched
    return (n == -1);
}

//placeholder main so that the file would actually compile
int main(){return 0;}
