#include "header.h"

int get_count_room_links(char *line)
{
	char	*line;
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
			(*room_count)++;
		ft_freetab(datas);
		datas = ft_strsplit(line, '-');
		if (!datas[0] || !datas[1] || datas[2])
			verbose++;
		else
			(*link_count)++;
		if (verbose == 2)
		{
			perror("Map invalid");
			return (-1);
		}
	}
	return (0);
}
