/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   md5_whirlpool.c                                                          */
/*                                                                            */
/*   By: anesteru <cyanopsitta@duck.com>                                      */
/*                                                                            */
/*   Created: 2018/08 by anesteru  <marvin@42.fr>                             */
/*   Updated: 2023/09/04 by chuhei (chuhei1987)                               */
/*                                                                            */
/* ************************************************************************** */

#include "ssl_hash.h"

char		*whirlpool(char *input, uint64_t size)
{
	t_md5			s;
	unsigned char	result[64];

	s.low = 0;
	s.high = 0;
	memset(s.hash, 0, sizeof(s.hash));
	whirlpool_update(&s, input, size);
	whirlpool_final(result, &s);
	return (get_result_string(result, 64));
}