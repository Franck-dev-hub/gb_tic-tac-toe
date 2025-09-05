#include <gb/gb.h>
#include <gbdk/console.h>
#include <stdio.h>

UINT8 GAME_BOARD[9];
UINT8 GAME_CURSOR_X;
UINT8 GAME_CURSOR_Y;

#define GAME_BOARD_CELL_EMPTY ' '
#define GAME_BOARD_CELL_PLAYER 'x'
#define GAME_BOARD_CELL_COMPUTER 'o'

UINT8 coord_2d_to_1d(UINT8 x, UINT8 y)
{
	return (y * 3 + x);
}

void game_draw_cursor(UINT8 cursor_char)
{
	UINT8 graph_x = 4 + GAME_CURSOR_X * 4 + 1;
	UINT8 graph_y = 4 + GAME_CURSOR_Y * 4 + 1;
	UINT8 cx, cy;

	for (cy = graph_y - 1; cy <= graph_y + 1; cy += 1)
	{
		for (cx = graph_x - 1; cx <= graph_x + 1; cx += 1)
		{
			if (cx == graph_x && cy == graph_y)
				continue;

			gotoxy(cx, cy);
			setchar(cursor_char);
		}
	}
}

void game_init(void)
{
	UINT8 i;

	for (i = 0; i < 9; i += 1)
		GAME_BOARD[i] = GAME_BOARD_CELL_EMPTY;

	GAME_CURSOR_X = 1;
	GAME_CURSOR_Y = 1;
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

void game_draw_state(void)
{
	UINT8 i, x, y, graph_x, graph_y;

	for (y = 0; y < 3; y += 1)
	{
		for (x = 0; x < 3; x += 1)
		{
			i	= coord_2d_to_1d(x, y);
			graph_x = 4 + x * 4 + 1;
			graph_y = 4 + y * 4 + 1;
			gotoxy(graph_x, graph_y);
			setchar(GAME_BOARD[i]);
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

void game(void)
{
	game_init();
	game_draw_board();

	game_draw_cursor('/');
}

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
