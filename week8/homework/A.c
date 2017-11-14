// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  A.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/14 16时37分23秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//
//

void put_spaces(int cnt) {
    while (cnt--) putchar(' ');
}

int main() {
    int spaces = 0;
    char c;
    int beg = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') spaces++;
        else if (isalpha(c)) {
            if (beg && spaces) put_spaces(spaces);
            putchar(c);
            spaces = 0;
            if (beg == 0) beg = 1;
        } else if (c == ',' || c == '\n') {
            if (beg)puts("");
            beg = 0; spaces = 0;
        }
    }
    // if (beg) puts("");
    return 0;
}
