/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:46:17 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/27 17:57:42 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logging.h"

static void	logmessage(t_loglevel level, const char *file, int line,
	const char *message)
{
	const char	*level_str[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			*fd;

	fd = __get_logger_fd();
	if (*fd == -1)
		return ;
	ft_putstr_fd("[", *fd);
	ft_putstr_fd((char *)level_str[level], *fd);
	ft_putstr_fd("] ", *fd);
	ft_putstr_fd((char *)file, *fd);
	ft_putstr_fd(":", *fd);
	ft_putnbr_fd(line, *fd);
	ft_putstr_fd(" - ", *fd);
	ft_putendl_fd((char *)message, *fd);
}

void	loginfo(const char *file, int line, const char *message)
{
	if (LOGLEVEL <= INFO)
		logmessage(INFO, file, line, message);
}

void	logdebug(const char *file, int line, const char *message)
{
	if (LOGLEVEL <= DEBUG)
		logmessage(DEBUG, file, line, message);
}

void	logwarning(const char *file, int line, const char *message)
{
	if (LOGLEVEL <= WARNING)
		logmessage(WARNING, file, line, message);
}

void	logerror(const char *file, int line, const char *message)
{
	if (LOGLEVEL <= ERROR)
		logmessage(ERROR, file, line, message);
}
