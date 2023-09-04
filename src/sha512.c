/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   sha512.c                                                                 */
/*                                                                            */
/*   Updated By: chuhei <cyanopsitta@duck.com>                                */
/*                                                                            */
/*   Created: 2018/08 by anesteru  <marvin@42.fr>                             */
/*   Updated: 2023/09/04 by chuhei (chuhei1987)                               */
/*                                                                            */
/* ************************************************************************** */

#include "ssl_hash.h"

char		*sha512(char *input, uint64_t size)
{
	t_md5			s;
	unsigned char	result[64];

	s.a = 0x6a09e667f3bcc908;
	s.b = 0xbb67ae8584caa73b;
	s.c = 0x3c6ef372fe94f82b;
	s.d = 0xa54ff53a5f1d36f1;
	s.e = 0x510e527fade682d1;
	s.f = 0x9b05688c2b3e6c1f;
	s.g = 0x1f83d9abfb41bd6b;
	s.h = 0x5be0cd19137e2179;
	s.low = 0;
	s.high = 0;
	sha512_update(&s, input, size);
	sha512_final(result, &s);
	return (get_result_string(result, 64));
}

char		*sha384(char *input, uint64_t size)
{
	t_md5			s;
	unsigned char	result[48];

	s.a = 0xcbbb9d5dc1059ed8;
	s.b = 0x629a292a367cd507;
	s.c = 0x9159015a3070dd17;
	s.d = 0x152fecd8f70e5939;
	s.e = 0x67332667ffc00b31;
	s.f = 0x8eb44a8768581511;
	s.g = 0xdb0c2e0d64f98fa7;
	s.h = 0x47b5481dbefa4fa4;
	s.low = 0;
	s.high = 0;
	sha512_update(&s, input, size);
	sha384_final(result, &s);
	return (get_result_string(result, 48));
}




