#include "keyboard.h"
#include "io.h"
#include "terminal.h"

#define KEYBOARD_DATA_PORT 0x60

static const char scancode_to_char[] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', /* 9 */
    '9', '0', '-', '=', '\b', '\t', /* Backspace */
    'q', 'w', 'e', 'r', /* 19 */
    't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', /* Enter key */
    0, /* 29 - Control */
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', /* 39 */
    '\'', '`', 0, /* Left shift */
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', /* 49 */
    'm', ',', '.', '/', 0, /* Right shift */
    '*',
    0,  /* Alt */
    ' ',  /* Space bar */
    0,  /* Caps lock */
    0,  /* 59 - F1 key ... > */
    0, 0, 0, 0, 0, 0, 0, 0,
    0,  /* < ... F10 */
    0,  /* 69 - Num lock*/
    0,  /* Scroll Lock */
    0,  /* Home key */
    0,  /* Up Arrow */
    0,  /* Page Up */
    '-',
    0,  /* Left Arrow */
    0,
    0,  /* Right Arrow */
    '+',
    0,  /* 79 - End key*/
    0,  /* Down Arrow */
    0,  /* Page Down */
    0,  /* Insert Key */
    0,  /* Delete Key */
    0, 0, 0, 0,  /* F11 Key */
    0,  /*
    0,  /* F12 Key */
    0,  /* All other keys are undefined */
};

char get_char_from_scancode(uint8_t scancode) {
    if (scancode >= sizeof(scancode_to_char)) {
        return 0;
    }
    return scancode_to_char[scancode];
}

void keyboard_handler(void) {
    uint8_t scancode = inb(KEYBOARD_DATA_PORT);
    char c = get_char_from_scancode(scancode);

    if (c != 0) {
        terminal_putchar(c);
    }
}

void keyboard_init(void) {
    // Enable keyboard interrupts here (if needed)
}
