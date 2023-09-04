/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   sha256.c                                                                 */
/*                                                                            */
/*   Updated By: chuhei <cyanopsitta@duck.com>                                */
/*                                                                            */
/*   Created: 2018/08  by anesteru <marvin@42.fr>                             */
/*   Updated: 2023/09/04 by chuhei (chuhei1987)                               */
/*                                                                            */
/* ************************************************************************** */

#include "ssl_hash.h"

char		*sha256(char *input, uint64_t size)
{
	t_md5			s;
	unsigned char	result[32];

	s.a = 0x6a09e667;
	s.b = 0xbb67ae85;
	s.c = 0x3c6ef372;
	s.d = 0xa54ff53a;
	s.e = 0x510e527f;
	s.f = 0x9b05688c;
	s.g = 0x1f83d9ab;
	s.h = 0x5be0cd19;
	s.low = 0;
	s.high = 0;
	sha256_update(&s, input, size);
	sha256_final(result, &s);
	return (get_result_string(result, 32));
}


