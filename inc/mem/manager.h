#pragma once

#include <inc/types.h>
#include <inc/io.h>

#define S2_MEMFLAG_DEFAULT 0b00000000
#define S2_MEMFLAG_ISALLOC 0b00000001

// TODO: DEFINE MEMORY CAP AUTOMATICALLY 
#define S2_MEMCAP (134217728)

/**
 * Memory Entry
 * Linked list-like memory entry for s2 memory allocator
 */

typedef struct s2_MemoryEntry_T {
    s2_UInt32 magic;
    struct s2_MemoryEntry_T *prev;
    struct s2_MemoryEntry_T *next;
    s2_Size size;
    s2_Byte flags;
} s2_MemoryEntry;

extern s2_MemoryEntry *memUpper;


/**
 * Root entry of the linked list
 */

s2_MemoryEntry *rootEntry;

/** 
 * Memory allocator initializer
 */

extern unsigned int heap_start;

void s2_InitMemoryAllocator();

/**
 *  @param entry the entry to bootstrap from
 *  @param desiredSize size desired to get after allocation
 *  @returns false if operation failed, true if operation succeeded. The memory chunk is passed via param hence can be used if operation succeeded 
 */
bool s2_MemoryMergeIfPossible(s2_MemoryEntry *entry, s2_Size desiredSize);
/**
 * @param size Desired size
 * @returns pointer
 */
void* s2_MemoryAlloc(s2_Size size);

extern unsigned int memleaks;


void s2_MemoryFree(void *ptr);

void s2_MemoryPurge(void *ptr);


extern inline void* s2_MemoryCopy(void *dest, void *src, s2_Size size);