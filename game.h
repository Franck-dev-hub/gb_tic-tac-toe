#ifndef MAIN_H
#define MAIN_H

#define GAME_BOARD_CELL_EMPTY ' '
#define GAME_BOARD_CELL_PLAYER 'x'
#define GAME_BOARD_CELL_COMPUTER 'o'

#define GAME_STATUS_PLAYING 0
#define GAME_STATUS_WON 1
#define GAME_STATUS_LOST 2
#define GAME_STATUS_DRAW 3

/* Draws */
void game_draw_cursor(UINT8 cursor_char);
void game_draw_state(void);
void game_draw_board(void);
void game_draw_game_over(UINT8 status);

/* Gameplay */
UINT8 game_check_status(void);
void  game_computer_play(void);
void  game_player_play(void);
void  game_init(void);
void  game(void);

#endif
