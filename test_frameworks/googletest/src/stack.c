#include "stack.h"

#include <stdint.h>
#include <stdlib.h>

struct my_stack_t {
  uint32_t *buf;
  uint32_t size;
  uint32_t len;
};

my_stack_t *new_stack(const uint32_t size) {
  if (size == 0) {
    return NULL;
  }

  uint32_t *buf = (uint32_t *)malloc(sizeof(uint32_t) * size);
  my_stack_t *stack = (my_stack_t *)malloc(sizeof(my_stack_t));
  stack->buf = buf;
  stack->size = size;
  stack->len = 0;

  return stack;
}

uint32_t stack_size(const my_stack_t *const stack) { return stack->size; }

uint32_t stack_len(const my_stack_t *const stack) { return stack->len; }

uint8_t free_stack(my_stack_t *const stack) {
  if (stack->size == 0) {
    return 0;
  }

  free(stack->buf);
  stack->len = 0;
  stack->size = 0;

  return 1;
}

uint8_t stack_push(my_stack_t *const stack, const uint32_t elem) {
  if (stack->len >= stack->size) {
    return 0;
  }

  stack->buf[stack->len] = elem;
  stack->len++;

  return 1;
}

uint8_t stack_pop(my_stack_t *const stack, uint32_t *const elem) {
  if (stack->len == 0) {
    return 0;
  }

  *elem = stack->buf[stack->len - 1];
  stack->len--;

  return 1;
}