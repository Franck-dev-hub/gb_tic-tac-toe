#include <gb/gb.h>
#include <gbdk/console.h>
#include <stdio.h>

UINT8 GAME_BOARD[9];

#define GAME_BOARD_CELL_EMPTY ' '
#define GAME_BOARD_CELL_PLAYER 'x'
#define GAME_BOARD_CELL_COMPUTER 'o'

UINT8 coord_2d_to_1d(UINT8 x, UINT8 y)
{
	return (y * 3 + x);
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

void game_init(void)
{
	UINT8 i;

	for (i = 0; i < 9; i += 1)
		GAME_BOARD[i] = GAME_BOARD_CELL_EMPTY;
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

void game(void)
{
	game_init();
	game_draw_board();

	GAME_BOARD[0] = GAME_BOARD_CELL_COMPUTER;
	GAME_BOARD[4] = GAME_BOARD_CELL_PLAYER;
	game_draw_state();
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
