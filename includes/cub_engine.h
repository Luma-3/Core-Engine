/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_engine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:09:38 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 16:37:43 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_ENGINE_H
# define CUB_ENGINE_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <vectorft.h>

# include "data.h"

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

/**
 * @brief Initialize the engine
 * 
 * @return -1 if an error occured, 0 otherwise
 * @warning This function must be called before any other 
 * 	engine function and Call it only once
*/
int			init_engine(void);

/**
 * @brief Stop the engine
*/
int			stop_engine(void);

/**
 * @brief destroy a window
 * 
 * @param win the id of window to destroy
*/
void		destroy_win(int id_win);

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
 * @param maskage the maskage of the event (0 index for event, 1 index for mask)
 * @param param the parameter to pass to function callback
 * @param id_win the id of the window where the event is hooked
*/
int			event_hook(int (*f)(), int maskage[2], void *param, int id_win);

//////////////////////////
//		  Render		//
//////////////////////////

/**
 * @brief Create a TRGB color
 * 
 * @param t the transparency of the color
 * @param r the red value of the color
 * @param g the green value of the color
 * @param b the blue value of the color
 * 
 * @return the TRGB color in an integer
*/
int			create_trgb(unsigned char t, unsigned char r,
				unsigned char g, unsigned char b);

/**
 * @brief Put a pixel on the renderer of the window
 * 
 * @param win the window where the pixel will be put
 * @param coord the coordinate of the pixel
 * @param color the color of the pixel
 * 
 * @note The pixel will be put on the back buffer of the window
 */
void		pixel_put(t_win *win, t_vector2 coord, int color);

/**
 * @brief Apply a shade to a color
 * 
 * @param color the color to shade
 * @param shade a modifier to apply to the color
*/
int			apply_shade(int color, float shade);

/**
 * @brief Take a pixel from a texture
 * 
 * @param texture the texture where the pixel will be taken
 * @param coord the coordinate of the pixel
 * 
 * @return the color of the pixel
*/
int			take_pixel(t_texture *texture, t_vector2 coord);

/**
 * @brief Draw a 2D object on the window
 * 
 * @param self the render2d of the object to draw
 * 
 * @note this function must be put in variable `draw` of the render2d
*/
void		basic_draw2d(void *self);

/**
 * @brief Draw a ray on the window
 * 
 * @param obj the debug object to draw
 * 
 * @note this function must be put in variable `draw` of the debug object
*/
void		draw_ray(void *obj);

//////////////////////////
//		  Object		//
//////////////////////////

/**
 * @brief Create a new debug object
 * 
 * @param start the start position of the ray
 * @param end the end position of the ray
 * @param id the id of the debug object
 * 
 * @return a pointer to the debug object, NULL if an error occured
*/
t_debug		*new_debug(t_vector2 start, t_vector2 end, int id);

/**
 * @brief Create a new object
 * 
 * @param id the id of the object
 * @param texture the texture of the object
 * @param win_id the id of the window where the object will be drawn
 * 
 * @return a pointer to the object, NULL if an error occured
*/
t_gobject	*new_object(unsigned int id, t_texture *texture,
				unsigned int win_id);

/**
 * @brief Destroy a game object
 * 
 * @param object the object to destroy
 * 
 * @param do_destroy_texture if 1, the texture of the object will be destroyed
*/
void		destroy_object(t_gobject *object, int do_destroy_texture);

//////////////////////////
//		  Utils 		//
//////////////////////////

/**
 * @brief Convert a world position to a screen position
 * 
 * @param world the world position to convert
 * @param id_win the id of the window where the position will be converted
 * 
 * @return the screen position
*/
t_vector2	world_to_screen(t_vector2 world, int id_win);

/**
 * @brief add a function to the loop update
 * 
 * @param f the function to add
 * @param param the parameter to pass to the callback function
 * 
 * @note The function callback call before the rendering loop
 * 
*/
void		add_loop_update(int (*f)(void *), void *param);

/**
 * @brief add a function to the loop render
 * 
 * @param f the function to add
 * @param param the parameter to pass to the callback function
 * 
 * @note The function callback call after reset the back buffer to void
*/
void		add_loop_render(int (*f)(void *), void *param);

/**
 * @brief Start the rendering loop
*/
void		loop(void);

/**
 * @brief Get the engine 
 * 
 * @return a pointer to the engine
 * 
 * @warning This function is internal, critical functions
 * take care to use it properly
*/
t_engine	*__get_engine(void);

#endif