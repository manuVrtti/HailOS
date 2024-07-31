#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>

void keyboard_init(void);
void keyboard_handler(void);
char get_char_from_scancode(uint8_t scancode);

#endif // KEYBOARD_H
