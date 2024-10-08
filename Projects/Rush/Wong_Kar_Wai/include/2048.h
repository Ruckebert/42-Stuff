#ifndef FT_2048
# define FT_2048

# include <ncurses.h>
# include <signal.h>
# include <stdbool.h>
# include "libft.h"

# ifndef SUCCESS
  define SUCCESS 0
# endif
# ifndef FAILURE
  define  FAILURE !SUCCESS
# endif

# define SQUARE_HEIGHT 3
# define SQUARE_WIDTH 5

extern size_t sigResize;

typedef enum e_custom_colors
{
	WHITE,
	BLACK,
	GREY,
	LIGHT_GREY,
	DARK_GREY,
	CUSTOM_1,
	CUSTOM_2,
	CUSTOM_3,
	CUSTOM_4,
	CUSTOM_5,
	CUSTOM_6,
	CUSTOM_7,
	CUSTOM_8,
	CUSTOM_9
}		t_custom_colors;

typedef enum e_game_status
{
	PLAYING,
	PAUSED,
	ABORTED,
	OVER
}		t_game_status;

enum e_direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

enum e_const
{
	WIN_VALUE = 2048
};

typedef struct s_position
{
	int	row;
	int	col;
}				t_position;

typedef struct s_square
{
	int		value;
	WINDOW	*win;
	bool	merged;
}			t_square;

typedef struct s_grid
{
	t_square	squares[5][5];
	bool		grid_changed_after_move;
}			t_grid;

typedef struct s_game
{
	t_game_status	status;
	t_grid			grid;
	t_grid			check_grid;
	int				size;
	int				last_key;
}			t_game;

// game.c
void	game_init(t_game *game, int size);
void	game_destroy(t_game *game);
void	game_draw(t_game *game);
void	game_wait_for_input_and_update(t_game *game);

// grid.c
void	grid_create_windows(t_game *game, t_grid *grid);
void	grid_destroy_windows(t_game *game, t_grid *grid);
void	grid_spawn_random_nr(t_grid *grid, int size);
void	grid_slide_left(t_game *game, t_grid *grid);
void	grid_slide_right(t_game *game, t_grid *grid);
void	grid_slide_up(t_game *game, t_grid *grid);
void	grid_slide_down(t_game *game, t_grid *grid);
void 	check_neighbor_and_merge(t_game *game, t_grid *grid, t_position src, t_position dst);
void	grid_copy(t_game *game, t_square src[5][5], t_square dst[5][5]);
void	grid_reset_merged(t_game *game, t_grid *grid);
void	grid_reset_values(t_game *game, t_grid *grid);
bool	moves_are_possible(t_game *game);

// position.c
bool	position_is_equal(t_position pos1, t_position pos2);
void	position_shift_by_one_reverse(t_position *pos, int direction);
void	position_shift_by_one(t_position *pos, int direction);

// ascii_art.c
void	ascii_art_init(t_game *game);

#endif
