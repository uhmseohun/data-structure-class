//
//  main.cpp
//  ds-stack
//
//  Created by 엄서훈 on 2020/05/20.
//  Copyright © 2020 seohun. All rights reserved.
//

#include <stdio.h>
#define STACK_SIZE 10

char COMMANDS[][10] = {
    "quit",
    "print",
    "push",
    "pop",
    "peek",
    "del",
    "isEmpty",
    "getSize"
};
char stack[STACK_SIZE];
int top;

int getCommand () {
    for (int i=0; i<8; ++i) {
        printf("%d - %s\n", i, COMMANDS[i]);
    }
    printf("선택: ");
    int uCommand;
    scanf("%d", &uCommand);
    
    return uCommand;
}

void print () {
    for (int i=0; i<top; ++i) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

void push (char value) {
		if (top >= STACK_SIZE) {
			printf("스택에 공간이 더 이상 없습니다.");
			return;
		}
    stack[top++] = value;
}

int isEmpty () {
    return top == 0;
}

char pop () {
    return stack[--top];
}

char peek () {
    return stack[top-1];
}

void del () {
    top = 0;
}

int getSize () {
    return top;
}

int main () {
    while (1) {
        int uCommand = getCommand();
        char value;
        switch (uCommand) {
            case 0:
                return 0;
            case 1:
                print();
                break;
            case 2:
                printf("스택에 저장할 문자: ");
                scanf(" %c", &value);
                push(value);
                break;
            case 3:
                if(isEmpty())
                    puts("Pop할 문자가 없습니다.");
                else
                    printf("Pop한 문자: %c\n", pop());
                break;
            case 4:
                if(isEmpty())
                    puts("Peek할 문자가 없습니다.");
                else
                    printf("Peek한 문자: %c\n", peek());
                break;
            case 5:
                del();
                break;
            case 6:
                puts(isEmpty() ? "스택이 비어 있습니다.": "스택이 비어 있지 않습니다.");
                break;
            case 7:
                printf("스택의 크기는 %d입니다.\n", getSize());
                break;
        }
    }
    return 0;
}
