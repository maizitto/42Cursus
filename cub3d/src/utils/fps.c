/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:19:16 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/02 17:03:06 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

unsigned long	get_time_in_mms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static void	reverse_str(char *str)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = 0;
	while (str[end] != '\0')
		end++;
	end--;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

static	void	int_to_str(int num, char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = num;
	if (sign < 0)
		num = -num;
	while (num > 0)
	{
		str[i++] = num % 10 + '0';
		num = num / 10;
	}
	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';
	reverse_str(str);
}

static void	build_fps_text(int fps, char *fps_text)
{
	char	fps_str[64];
	int		i;
	int		j;

	i = 0;
	j = 0;
	int_to_str(fps, fps_str);
	fps_text[i++] = 'F';
	fps_text[i++] = 'P';
	fps_text[i++] = 'S';
	fps_text[i++] = ':';
	fps_text[i++] = ' ';
	while (fps_str[j] != '\0')
		fps_text[i++] = fps_str[j++];
	fps_text[i] = '\0';
}

void	draw_fps_counter(t_game *g)
{
	char	fps_text[64];
	int		fps;

	fps = (int)(1 / g->frametime_sec);
	build_fps_text(fps, fps_text);
	mlx_string_put(g->data.mlx, g->data.win, 10, 10, 0x00FF00, fps_text);
}
