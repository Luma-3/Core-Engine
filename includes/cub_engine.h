/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_engine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:09:38 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/27 17:44:02 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_ENGINE_H
# define CUB_ENGINE_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <vectorft.h>

//////////////////////////
//		  Logger		//
//////////////////////////

/**
 * @brief Log a message with the INFO level
 * 
 * @param file the file where the log is called
 * @param line the line where the log is called
 * @param message the message to log
*/
void		loginfo(const char *file, int line, const char *message);

/**
 * @brief Log a message with the DEBUG level
 * 
 * @param file the file where the log is called
 * @param line the line where the log is called
 * @param message the message to log
*/
void		logdebug(const char *file, int line, const char *message);

/**
 * @brief Log a message with the WARNING level
 * 
 * @param file the file where the log is called
 * @param line the line where the log is called
 * @param message the message to log
*/
void		logwarning(const char *file, int line, const char *message);

/**
 * @brief Log a message with the ERROR level
 * 
 * @param file the file where the log is called
 * @param line the line where the log is called
 * @param message the message to log
*/
void		logerror(const char *file, int line, const char *message);

//////////////////////////
//		  Engine		//
//////////////////////////

typedef struct s_texture	t_texture;

typedef struct s_engine		t_engine;

/**
 * @brief Initialize the engine
 * 
 * @return -1 if an error occured, 0 otherwise
 * @warning This function must be called before any other 
 * 	engine function and Call it only once
*/
int			init_engine(void);

/**
 * @brief initialize a texture from a `file_name`
 * 
 * @param path the path to the texture file
 * @return a pointer to the texture, NULL if an error occured
 * 
 * @warning The texture must be destroyed with 
 * 	`destroy_texture` when it is no longer needed
 * @note The texture need .xpm format
*/
t_texture	*init_texture(const char *path);

/**
 * @brief Destroy a texture
 * 
 * @param texture the texture to destroy
 * 
 * @warning The texture must be initialized with 
 * 	`init_texture` before being destroyed ! 
 * 	This function does not check if the texture is initialized
*/
void		destroy_texture(t_texture *texture);

/**
 * @brief Create a new window with the given `win_size` and `title`
 * 
 * @param win_size the size of the window
 * @param title the title of the window
 * 
 * @return -1 if an error occured, 0 otherwise
 * 
 * @warning This function must be called after `init_engine`
 * @note The window must be destroyed with `destroy_window`
 * 	when it is no longer needed
*/
int			init_window(t_vector2 win_size, const char *title);

//////////////////////////
//		  Event			//
//////////////////////////

/**
 * @brief Hook a function to the key event
 * 
 * @param f the function to call when a key event is triggered
 * @param param the parameter to pass to the function
 * 
 * @note The function Callback has hide parameter, 
 * the first parameter is the key code (`int`)
*/
int			key_hook(int (*f)(), void *param);

/**
 * @brief Hook a function to the mouse event
 * 
 * @param f the function to call when a mouse event is triggered
 * @param param the parameter to pass to the function
 * 
 * @note The function Callback has hide parameter,
 * `keycode` - the key code (`int`),
 * `x` - the x position of the mouse (`int`)
 * `y` - the y position of the mouse (`int`)
*/
int			mouse_hook(int (*f)(), void *param);

/**
 * @brief Hook a function to the expose event
 * 
 * @param f the function to call when an expose event is triggered
 * @param param the parameter to pass to the function
*/
int			expose_hook(int (*f)(), void *param);

/**
 * @brief Hook a function to an event on a window
 * 
 * @param f the function to call when an event is triggered
 * @param envent the event to hook
 * @param mask the mask to apply to the event
 * @param param the parameter to pass to 
*/
int			event_hook(int (*f)(), int envent, int mask,
				void *param, int id_win);

#endif