#include <stdio.h>
#include "stack.h"

int main(int argc, char** argv) {
    const my_stack_t* stack = new_stack(16);
    printf("%d\n", stack_len(stack));
    return 0;
}