#ifndef __CONSOLE_H
#define __CONSOLE_H

#include "ctr/types.h"

void console_init(u32 fg, u32 bg);
void console_putc(void* p, char c);

#endif /*__CONSOLE_H*/
