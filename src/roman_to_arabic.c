#include <regex.h>
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 16

int toArabic(char roman[MAX_LENGTH]);
int getArabicDigit(char roman);

int main() {
    char inputString[MAX_LENGTH];
    scanf("%s", inputString);

    int result = toArabic(inputString);
    result < 0 ? fprintf(stderr, "Puck you, Verter!") : printf("%d", result);
    result >= 0 ? result = 0 : -1;
    return result;
}

int toArabic(char roman[MAX_LENGTH]) {
    int result = 0;
    regex_t reg;
    regcomp(&reg, "^(M{0,3})(D?C{0,3}|C[DM])(L?X{0,3}|X[LC])(V?I{0,3}|I[VX])$", REG_EXTENDED);

    if (!regexec(&reg, roman, 0, NULL, 0)) {
        int i = 0;
        while (getArabicDigit(roman[i])) {
            int curr = getArabicDigit(roman[i]);
            int next = getArabicDigit(roman[i + 1]);

            if (next && curr < next) {
                result += next;
                result -= curr;
                i++;
            } else {
                result += curr;
            }
            i++;
        }
    } else if (!strcmp(roman, "N") || !strcmp(roman, "nulla") || !strcmp(roman, "nihil"))
        result = 0;
    else
        result = -1;

    regfree(&reg);
    return result;
}
int getArabicDigit(char roman) {
    int result;
    switch (roman) {
        case 'M':
            result = 1000;
            break;
        case 'D':
            result = 500;
            break;
        case 'C':
            result = 100;
            break;
        case 'L':
            result = 50;
            break;
        case 'X':
            result = 10;
            break;
        case 'V':
            result = 5;
            break;
        case 'I':
            result = 1;
            break;
        default:
            result = 0;
            break;
    }
    return result;
}