//
//  main.cpp
//  ds-stack
//
//  Created by 엄서훈 on 2020/05/20.
//  Copyright © 2020 seohun. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

char stack[MAX_LENGTH];
int top;

int isEmpty () {
    return top == 0;
}

int iSFull () {
    return MAX_LENGTH <= top;
}

void push (char value) {
    if (iSFull()) {
        puts("FULL!");
        exit(0);
    }
    stack[top++] = value;
}

char pop () {
    if (isEmpty()) {
        puts("EMPTY!");
        exit(0);
    }
    return stack[--top];
}

int main () {
    printf("문자열 입력 ");
    char str[MAX_LENGTH];
    scanf("%s", str);
    int len = strlen(str);

    for (int i=0; i<len; ++i) {
        push(str[i]);
    }

    while (top) {
        printf("%c", pop());
    }
    printf("\n");
    return 0;
}

