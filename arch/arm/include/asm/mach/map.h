/*
 *  arch/arm/include/asm/map.h
 *
 *  Copyright (C) 1999-2000 Russell King
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 *  Page table mapping constructs and function prototypes
 */
#ifndef __ASM_ARM_MACH_MAP_H
#define __ASM_ARM_MACH_MAP_H

#include <asm/io.h>

struct map_desc {
	unsigned long virtual;
	unsigned long pfn;
	unsigned long length;
	unsigned int type;
};

#define MT_UNCACHED		4
#define MT_CACHECLEAN		5
#define MT_MINICLEAN		6
#define MT_LOW_VECTORS		7
#define MT_HIGH_VECTORS		8
#define MT_MEMORY		9
#define MT_ROM			10
#define MT_MEMORY_NONCACHED	11
#define MT_MEMORY_DTCM		12
#define MT_MEMORY_ITCM		13
#define MT_MEMORY_SO		14
#define MT_MEMORY_R		15
#define MT_MEMORY_RW		16
#define MT_MEMORY_RX		17
#define MT_MEMORY_DMA_READY	18
#define MT_DEVICE_USER_ACCESSIBLE	19

#ifdef CONFIG_MMU
extern void iotable_init(struct map_desc *, int);

struct mem_type;
extern const struct mem_type *get_mem_type(unsigned int type);
extern int ioremap_page(unsigned long virt, unsigned long phys,
			const struct mem_type *mtype);

extern int ioremap_pages(unsigned long virt, unsigned long phys,
			unsigned long size, const struct mem_type *mtype);
#else
#define iotable_init(map,num)	do { } while (0)
#endif

#endif
