/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:38:35 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/27 23:40:44 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef enum {
    DEBUG,
    INFO,
    WARNING,
    ERROR
} LogLevel;

void logdebug(LogLevel level, const char* file, int line, const char* message)
{
    printf("[DEBUG] %s:%d - %s\n", file, line, message);
}

int main() {
	logdebug(DEBUG, __FILE__, __LINE__, "Hello, World!");
    return 0;
}
