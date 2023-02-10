#include "./../include/so_long.h"

static void	ft_run_solong(const char *map_path)
{
	t_data		g_data;
	t_map		g_element;
	char		**map;
	char		**map_check;
	int			*xy;

	// 맵을 읽어 드리고, 맵의 2차원 배열의 값을 반환한다.
	map = ft_read_map(map_path);
	// 맵이 게임에 이용가능한 형태인지 확인한다.
	ft_map_validator((const char **)map, &g_element);
	map_check = ft_copymap((const char **)map);
	xy = ft_player_pos((const char **)map_check);
	g_element.character_x = xy[0];
	g_element.character_y = xy[1];
	ft_flood_fill(map_check, xy[0], xy[1]);
	ft_check_can_clear((const char **)map_check);
	g_data.map = map;
	ft_struct_init(&g_data, &g_element);
}

void ft_check_av(int ac, char **av)
{
	if (ac != 2 || ft_strnstr(av[1], ".ber", ft_strlen(av[1]) == 0))
	{
		if (ac != 2)
			ft_printf("ac must be two, your ac isn't two");
		else
			ft_printf("your map format must be \".ber\"");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	ft_check_av(ac, av);	
	ft_run_solong(av[1]);
}

