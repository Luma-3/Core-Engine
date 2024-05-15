/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:42:36 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/15 10:41:48 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "renderer.h"

t_engine	*get_engine(void)
{
	static t_engine	engine;

	return (&engine);
}
