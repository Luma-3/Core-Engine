/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:46:44 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/30 15:45:49 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGING_H
# define LOGGING_H

# include "libft.h"

# define LOGFILE "./logs/logfile_coreEngine.log"
# define LOGFLAGS O_TRUNC
# define LOGFILE_MODE 0644
# define LOGLEVEL DEBUG

typedef enum e_loglevel
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
}	t_loglevel;

void	logdebug(const char *file, int line, const char *message);
void	loginfo(const char *file, int line, const char *message);
void	logwarning(const char *file, int line, const char *message);
void	logerror(const char *file, int line, const char *message);

int		*get_logger_fd(void);
int		init_logger(void);
void	close_logfile(void);

#endif