#include "header.h"

int get_count_room_links(char *line, bool *miss_room, t_rooms *rooms, t_links *links)
{
	char	**datas;
	int		verbose;

	(void)rooms;
	(void)links;
	verbose = 0;
	if (line[0] != '#')
	{
		datas = ft_strsplit(line, ' ');
		if (!datas[0] || !datas[1] || !datas[2] ||
				ft_isdigit(ft_atoi(datas[1])) || ft_isdigit(ft_atoi(datas[2])))
		{
			verbose++;
		}
		else
		{
			miss_room = false;
		}
		ft_freetab(datas);
		datas = ft_strsplit(line, '-');
		if (!datas[0] || !datas[1] || datas[2])
			verbose++;
		else
		{
			;
		}
		ft_freetab(datas);
		if (verbose == 2)
		{
			//perror("Map invalid");
			return (-1);
		}
	}
	return (0);
}
