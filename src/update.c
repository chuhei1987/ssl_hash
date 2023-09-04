/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   update.c                                                                 */
/*                                                                            */
/*   Updated By: chuhei <cyanopsitta@duck.com>                                */
/*                                                                            */
/*   Created: 2018/08/08 15:31:58 by anesteru <marvin@42.fr>                  */
/*   Updated: 2023/09/04 by chuhei (chuhei1987)                               */
/*                                                                            */
/* ************************************************************************** */

#include "ssl_hash.h"



void			sha256_update(t_md5 *s, const void *data, uint64_t size)
{
	s->low = size & 0x1fffffff;
	s->high += size >> 29;
	if (size >= 64)
	{
		data = sha256_transform(s, data, size & ~(uint64_t)0x3f);
		size &= 0x3f;
	}
	memcpy(s->buffer, data, size);
}

void			sha512_update(t_md5 *s, const void *data, uint64_t size)
{
	s->low = size;
	if (s->low >= 0x2000000000000000)
		s->high = s->low >> 61;
	if (size >= 128)
	{
		data = sha512_transform(s, data, size & ~(uint64_t)0x7f);
		size &= 0x7f;
	}
	memcpy(s->buffer, data, size);
}

void			whirlpool_update(t_md5 *s, const void *data, uint64_t size)
{
	s->low = size;
	if (s->low >= 0x2000000000000000)
		s->high = s->low >> 61;
	if (size >= 64)
	{
		data = whirlpool_transform(s->hash, data, size & ~(uint64_t)0x3f);
		size &= 0x3f;
	}
	memcpy(s->buffer, data, size);
}
