/* ===== INCLUDES ===== */
/* gbdk 2020*/
#include <gbdk/console.h>

/* Custom */
#include "helpers.h"

UINT8 coord_2d_to_1d(UINT8 x, UINT8 y)
{
	return (y * 3 + x);
}

void clear_screen(void)
{
	UINT8 x;
	UINT8 y = 18;
	while (y)
	{
		y -= 1;
		x = 20;
		while (x)
		{
			x -= 1;
			gotoxy(x, y);
			setchar(' ');
		}
	}
}

void clear_line(UINT8 y)
{
	UINT8 x = 20;

	while (x)
	{
		x -= 1;
		gotoxy(x, y);
		setchar(' ');
	}
}
