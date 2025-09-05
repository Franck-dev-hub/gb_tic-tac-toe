#include <gb/console.h>
#include <gb/gb.h>
#include <stdio.h>

void title_screen(void)
{
	clear_screen();
	gotoxy(4, 5);
	printf("Tic Tac Toe");

	gotoxy(3, 15);
	printf("- Press START -");
	waitpad(J_START);
	waitpadup();
}

void main(void)
{
	while (1)
		title_screen();
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
