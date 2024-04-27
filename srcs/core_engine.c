/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:42:36 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/27 21:48:18 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"

t_engine	*get_engine(void)
{
	static t_engine	engine;

	return (&engine);
}