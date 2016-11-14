#include "ctr/console.h"
#include "ctr/draw.h"
#include "ctr/printf.h"

static console_s console;

void console_putc(void* p, char c)
{
	if(c == '\n' || (console.x + 8) > SUB_WIDTH)
	{
		console.x = 0;
		console.y += 8;
	}

	if(console.y >= SUB_HEIGHT)
	{
		draw_shift_up(SCREEN_SUB);
		console.y -= 8;

		draw_rect(SCREEN_SUB, 0, console.y, SUB_WIDTH, 8, console.bg);
	}

	if(c == '\r' || c == '\n') return;

	draw_rect(SCREEN_SUB, console.x, console.y, 8, 8, console.bg);
	draw_char(SCREEN_SUB, console.x, console.y, console.fg, c);
	console.x += 8;
}

void console_adjust_cursor(size_t x, size_t y)
{
	console.x = x;
	console.y = y;
}

void console_clear(void)
{
	draw_clear_screen(SCREEN_SUB, console.bg);
}

void console_init(u32 fg, u32 bg)
{
	console.x = 0;
	console.y = 0;
	console.fg = fg;
	console.bg = bg;

	draw_clear_screen(SCREEN_SUB, bg);
	init_printf(NULL, console_putc);
}

void console_fg_color(uint32_t color)
{
	console.fg = color;
}

void console_bg_color(uint32_t color)
{
	console.bg = color;
}

