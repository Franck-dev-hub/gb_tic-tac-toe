#include <gb/gb.h>
#include <gbdk/console.h>
#include <stdio.h>

UINT8 GAME_BOARD[9];
UINT8 GAME_CURSOR_X;
UINT8 GAME_CURSOR_Y;

#define GAME_BOARD_CELL_EMPTY ' '
#define GAME_BOARD_CELL_PLAYER 'x'
#define GAME_BOARD_CELL_COMPUTER 'o'

#define GAME_STATUS_PLAYING 0
#define GAME_STATUS_WON 1
#define GAME_STATUS_LOST 2
#define GAME_STATUS_DRAW 3

UINT8 coord_2d_to_1d(UINT8 x, UINT8 y)
{
	return (y * 3 + x);
}

UINT8 game_check_status(void)
{
	UINT8 x, y, i, player_score, computer_score;
	UINT8 empty_cell = 0;

	/* Check line score */
	for (y = 0; y < 3; y += 1)
	{
		player_score   = 0;
		computer_score = 0;
		for (x = 0; x < 3; x += 1)
		{
			i = coord_2d_to_1d(x, y);
			switch (GAME_BOARD[i])
			{
				case GAME_BOARD_CELL_EMPTY:
					empty_cell = 1;
					break;
				case GAME_BOARD_CELL_PLAYER:
					player_score += 1;
					break;
				case GAME_BOARD_CELL_COMPUTER:
					computer_score += 1;
					break;
			}
		}
		if (player_score == 3)
			return (GAME_STATUS_WON);
		if (computer_score == 3)
			return (GAME_STATUS_LOST);
	}

	/* Check row score */
	for (x = 0; x < 3; x += 1)
	{
		player_score   = 0;
		computer_score = 0;
		for (y = 0; y < 3; y += 1)
		{
			i = coord_2d_to_1d(x, y);
			switch (GAME_BOARD[i])
			{
				case GAME_BOARD_CELL_PLAYER:
					player_score += 1;
					break;
				case GAME_BOARD_CELL_COMPUTER:
					computer_score += 1;
					break;
			}
		}
		if (player_score == 3)
		{
			return (GAME_STATUS_WON);
		}
		if (computer_score == 3)
		{
			return (GAME_STATUS_LOST);
		}
	}

	/* Check first diagonal score */
	player_score   = 0;
	computer_score = 0;
	for (x = 0; x < 3; x += 1)
	{
		y = x;
		i = coord_2d_to_1d(x, y);
		switch (GAME_BOARD[i])
		{
			case GAME_BOARD_CELL_PLAYER:
				player_score += 1;
				break;
			case GAME_BOARD_CELL_COMPUTER:
				computer_score += 1;
				break;
		}
	}
	if (player_score == 3)
		return (GAME_STATUS_WON);
	if (computer_score == 3)
		return (GAME_STATUS_LOST);

	/* Check second diagonal score */
	player_score   = 0;
	computer_score = 0;
	for (x = 0; x < 3; x += 1)
	{
		y = 2 - x;
		i = coord_2d_to_1d(x, y);
		switch (GAME_BOARD[i])
		{
			case GAME_BOARD_CELL_PLAYER:
				player_score += 1;
				break;
			case GAME_BOARD_CELL_COMPUTER:
				computer_score += 1;
				break;
		}
	}
	if (player_score == 3)
		return (GAME_STATUS_WON);
	if (computer_score == 3)
		return (GAME_STATUS_LOST);

	/* Check if it's a draw or if the game continue */
	if (empty_cell)
		return (GAME_STATUS_PLAYING);
	else
		return (GAME_STATUS_DRAW);

	return (GAME_STATUS_PLAYING);
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

void game_computer_play(void)
{
	UINT8 i;

	for (i = 0; i < 9; i += 1)
	{
		if (GAME_BOARD[i] == GAME_BOARD_CELL_EMPTY)
		{
			GAME_BOARD[i] = GAME_BOARD_CELL_COMPUTER;
			break;
		}
	}
}

void game_player_play(void)
{
	UINT8 key, i;

	while (1)
	{
		game_draw_cursor('/');
		key = waitpad(J_UP | J_DOWN | J_LEFT | J_RIGHT | J_A);
		game_draw_cursor(' ');

		if (key & J_UP && GAME_CURSOR_Y != 0)
			GAME_CURSOR_Y -= 1;
		if (key & J_DOWN && GAME_CURSOR_Y != 2)
			GAME_CURSOR_Y += 1;
		if (key & J_LEFT && GAME_CURSOR_X != 0)
			GAME_CURSOR_X -= 1;
		if (key & J_RIGHT && GAME_CURSOR_X != 2)
			GAME_CURSOR_X += 1;
		if (key & J_A)
		{
			i = coord_2d_to_1d(GAME_CURSOR_X, GAME_CURSOR_Y);
			if (GAME_BOARD[i] == GAME_BOARD_CELL_EMPTY)
			{
				GAME_BOARD[i] = GAME_BOARD_CELL_PLAYER;
				break;
			}
		}
		waitpadup();
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

void game_draw_game_over(UINT8 status)
{
	clear_line(1);
	switch (status)
	{
		case GAME_STATUS_WON:
			gotoxy(4, 1);
			printf("YOU WON !");
			break;
		case GAME_STATUS_LOST:
			gotoxy(4, 1);
			printf("YOU LOST ...");
			break;
		case GAME_STATUS_DRAW:
			gotoxy(5, 1);
			printf(" -DRAW-");
			break;
	}
	clear_line(17);
	gotoxy(2, 17);
	printf("- Press START -");
	waitpad(J_START);
	waitpadup();
}

void game(void)
{
	UINT8 status;

	game_init();
	game_draw_board();

	while (1)
	{
		/* Player turn */
		game_player_play();
		game_draw_state();
		status = game_check_status();
		if (status != GAME_STATUS_PLAYING)
			break;

		/* Computer turn */
		game_computer_play();
		game_draw_state();
		status = game_check_status();
		if (status != GAME_STATUS_PLAYING)
			break;
	}
	game_draw_game_over(status);
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
