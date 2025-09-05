#include <stdio.h>
#include <gb/gb.h>
#include <gbdk/console.h>

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

void game_draw_board(void)
{
	clear_screen();
	gotoxy(4, 1);
	printf("Tic Tac Toe");

	gotoxy(1, 17);
	printf("X You - O Computer");

	gotoxy(0, 4);
	printf("       |   |   \n");
	printf("       |   |   \n");
	printf("       |   |   \n");
	printf("    ---+---+---\n");
	printf("       |   |   \n");
	printf("       |   |   \n");
	printf("       |   |   \n");
	printf("    ---+---+---\n");
	printf("       |   |   \n");
	printf("       |   |   \n");
	printf("       |   |   \n");
}

void main(void)
{
	while (1)
	{
		title_screen();
		game_draw_board();

		waitpad(J_START);
		waitpadup();
	}
}
