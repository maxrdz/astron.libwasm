/*
 * Copyright (c) 2014, Astron Contributors. All rights reserved.
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file byteorder.hxx
 * @author Astron Contributors
 * @date 2023-04-30
 */

#ifndef ASTRON_LIBWASM_BYTEORDER_HXX
#define ASTRON_LIBWASM_BYTEORDER_HXX

// First, detect endianness. This is fairly compiler-specific, so if this
// doesn't work on some compiler, more cases may need to be added.
#if defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
#define PLATFORM_BIG_ENDIAN
#endif

#ifdef PLATFORM_BIG_ENDIAN

static inline uint16_t swap_le_16(uint16_t x) {
    return (x & 0x00ff) << 8 |
           (x & 0xff00) >> 8;
}

static inline uint32_t swap_le_32(uint32_t x) {
    return (x & 0x000000ff) << 24 |
           (x & 0x0000ff00) <<  8 |
           (x & 0x00ff0000) >>  8 |
           (x & 0xff000000) >> 24;
}

static inline uint64_t swap_le_64(uint64_t x) {
    return (x & 0x00000000000000ff) << 56 |
           (x & 0x000000000000ff00) << 40 |
           (x & 0x0000000000ff0000) << 24 |
           (x & 0x00000000ff000000) <<  8 |
           (x & 0x000000ff00000000) >>  8 |
           (x & 0x0000ff0000000000) >> 24 |
           (x & 0x00ff000000000000) >> 40 |
           (x & 0xff00000000000000) >> 56;
}

#define swap_le(var) \
( \
	(sizeof(var) == 8) ? \
		swap_le_64(var) : \
	(sizeof(var) == 4) ? \
		swap_le_32(var) : \
	(sizeof(var) == 2) ? \
		swap_le_16(var) : \
	var \
)

#else
#define swap_le(var) (var)
#endif

#endif //ASTRON_LIBWASM_BYTEORDER_HXX