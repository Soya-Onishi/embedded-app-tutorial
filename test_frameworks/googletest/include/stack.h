#ifndef __STACK_H__
#define __STACK_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct my_stack_t;
typedef struct my_stack_t my_stack_t;

extern my_stack_t *new_stack(uint32_t size);
extern uint8_t free_stack(my_stack_t *const stack);

extern uint32_t stack_size(const my_stack_t *const stack);
extern uint32_t stack_len(const my_stack_t *const stack);

extern uint8_t stack_push(my_stack_t *const stack, const uint32_t elem);
extern uint8_t stack_pop(my_stack_t *const stack, uint32_t *const elem);

#ifdef __cplusplus
}
#endif

#endif