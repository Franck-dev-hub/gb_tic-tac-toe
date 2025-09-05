/* ===== INCLUDES ===== */
/* Native */
#include <stdio.h>

/* gbdk 2020*/
#include <gb/gb.h>

/* Custom */
#include "game.h"
#include "helpers.h"
#include "screen_title.h"

/* Main loop */
void main(void)
{
	while (1)
	{
		title_screen();
		game();

		waitpad(J_START);
		waitpadup();
	}
}
