#include <stdio.h>

// function declaration
int func();

int main() {
    printf("01- Inside Function Main before calling func(). \n");

    // function call
    int i = func();
    
    printf("02- Inside Function Main after calling func().\n");
    return 0;
}

// function definition
int func() {
    printf("Inside func.\n");

   return 0;
}