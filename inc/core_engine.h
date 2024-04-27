/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:31:24 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/28 01:10:57 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ENGINE_H
# define CORE_ENGINE_H

# include "logging.h"
# include <errno.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define FAILURE -1
# define SUCCESS 0

# define CONFIG_FILE "./../config.cfg"

typedef struct s_engine
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	*title;
}			t_engine;

t_engine	*get_engine(void);

int			init_core(void);

void		loop(void);

int			parse_config(t_engine *engine, t_list **config);

int			read_config(t_engine *engine);

#endif