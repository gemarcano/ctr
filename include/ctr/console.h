#ifndef __CONSOLE_H
#define __CONSOLE_H

#include "ctr/types.h"

typedef struct console_s
{
	u32 fg;
	u32 bg;
	u32 x;
	u32 y;
} console_s;

void console_init(u32 fg, u32 bg);
void console_putc(void* p, char c);
void console_adjust_cursor(size_t x, size_t y);
void console_clear(void);
void console_fg_color(uint32_t color);
void console_bg_color(uint32_t color);

#endif /*__CONSOLE_H*/
