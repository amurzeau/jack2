/*
  Copyright (C) 2000 Paul Davis
  Copyright (C) 2003 Rohan Drape
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.
  
  You should have received a copy of the GNU Lesser General Public License
  along with this program; if not, write to the Free Software 
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

*/

#ifndef __RINGBUFFER__
#define __RINGBUFFER__

#ifdef __cplusplus
extern "C"
{
#endif

#include <sys/types.h>

typedef struct {
    char *buf;
    size_t len;
}
jack_ringbuffer_data_t ;

typedef struct {
    char	*buf;
    volatile size_t write_ptr;
    volatile size_t read_ptr;
    size_t	size;
    size_t	size_mask;
    int	mlocked;
}
jack_ringbuffer_t ;

LIB_EXPORT jack_ringbuffer_t *jack_ringbuffer_create(size_t sz);
LIB_EXPORT void jack_ringbuffer_free(jack_ringbuffer_t *rb);
LIB_EXPORT void jack_ringbuffer_get_read_vector(const jack_ringbuffer_t *rb,
                                         jack_ringbuffer_data_t *vec);
LIB_EXPORT void jack_ringbuffer_get_write_vector(const jack_ringbuffer_t *rb,
                                          jack_ringbuffer_data_t *vec);
LIB_EXPORT size_t jack_ringbuffer_read(jack_ringbuffer_t *rb, char *dest, size_t cnt);
LIB_EXPORT size_t jack_ringbuffer_peek(jack_ringbuffer_t *rb, char *dest, size_t cnt);
LIB_EXPORT void jack_ringbuffer_read_advance(jack_ringbuffer_t *rb, size_t cnt);
LIB_EXPORT size_t jack_ringbuffer_read_space(const jack_ringbuffer_t *rb);
LIB_EXPORT int jack_ringbuffer_mlock(jack_ringbuffer_t *rb);
LIB_EXPORT void jack_ringbuffer_reset(jack_ringbuffer_t *rb);
LIB_EXPORT void jack_ringbuffer_reset_size (jack_ringbuffer_t * rb, size_t sz);
LIB_EXPORT size_t jack_ringbuffer_write(jack_ringbuffer_t *rb, const char *src,
                                 size_t cnt);
void jack_ringbuffer_write_advance(jack_ringbuffer_t *rb, size_t cnt);
size_t jack_ringbuffer_write_space(const jack_ringbuffer_t *rb);

#ifdef __cplusplus
}
#endif

#endif
