#include <mlx.h>
#include <string.h>
#include <stdlib.h>

#define TILES 60
#define COL 15
#define ROW 15
#define WIDTH TILES * COL
#define HEIGHT TILES * ROW
#define X_EVENT_KEYPRESS 2
#define X_EVENT_EXIT 17
#define KEYCODE_EXIT 53

typedef struct s_img
{
    void *img_1;
    void *img_2;
    void *img_3;
    void *img_4;
    void *img_5;
    void *img_6;
    void *img_7;
    void *img_8;
}   t_img;



typedef struct s_img
{
    void *img_ptr;
    int *data;
    int bpp;
    int size_line;
    int endian;
} t_img;

typedef struct s_game
{
    void *mlx_ptr;
    void *win_ptr;
    t_img img;
    int map[ROW][COL];
} t_game;

/*

윗 부분은
프로그램 구현에 필요한 헤더파일, define 매크로, 구조체 선언이다.

아래 부분은
프로그램을 동작시킬 함수들이다.
맨 아래에 위치한 main 함수부터 순서대로 읽으면 된다.

// 0 for an empty space,
// 1 for a wall,
// C for a collectible,
// E for a map exit,
// P for the player’s starting position.
*/

void minilibx_init(t_game *game)
{
    game->mlx_ptr = mlx_init();
    game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "Create 2D Map!");
}

void img_init(t_game *game)
{
    game->img.img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
    game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game->img.size_line, &game->img.endian);
}

void draw_pixels_of_tile(t_game *game, int row, int col)
{
    int tile_row, tile_col;

    row *= TILES;
    col *= TILES;
    tile_row = 0;
    while (tile_row < TILES)
    {
        tile_col = 0;
        while (tile_col < TILES)
        {
            if (tile_row == TILES - 1 || tile_col == TILES - 1)
                game->img.data[(tile_row + row) * WIDTH + (tile_col + col)] = 0xb3b3b3;
            else
                game->img.data[(tile_row + row) * WIDTH + (tile_col + col)] = 0xFFFFFF;
            tile_col++;
        }
        tile_row++;
    }
}

void draw_tiles(t_game *game)
{
    int row, col;

    row = 0;
    while (row < ROW)
    {
        col = 0;
        while (col < COL)
        {
            if (game->map[row][col] == 1)
                draw_pixels_of_tile(game, row, col);
            col++;
        }
        row++;
    }
}

void map_init(t_game *game)
{
    int src[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
    {1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    memcpy(game->map, src, sizeof(int) * ROW * COL);
    draw_tiles(game);
}

int    press_key(int keycode, t_game game)
{
    if (keycode == KEYCODE_EXIT)
        exit(0);
    return (0);
}

int main(void)
{
    t_game game;

    minilibx_init(&game);
    img_init(&game);
    map_init(&game);
    mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img.img_ptr, 0, 0);
    mlx_hook(game.win_ptr, X_EVENT_KEYPRESS, 0, &press_key, &game);
    mlx_loop(game.mlx_ptr);
    return (0);
}