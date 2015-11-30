#include "header.h"

int get_count_room_links(char *line, bool *miss_room, t_rooms *rooms, t_links *links)
{
	char	**datas;
	int		verbose;

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
			ft_lstinsert(rooms, create_node(datas,"t_rooms"), "t_rooms");
			*miss_room = false;
		}
		ft_freetab(datas);
		datas = ft_strsplit(line, '-');
		if (!datas[0] || !datas[1] || datas[2])
			verbose++;
		else
			ft_lstinsert(links, create_node(datas, "t_links"), "t_links");
		ft_freetab(datas);
		if (verbose == 2)
			return (-1);
	}
	return (0);
}
