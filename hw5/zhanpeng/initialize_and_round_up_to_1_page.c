#include "mem.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FAIL -1
#define NUM_ALLOC 512
#define MINIMUM_BLOCK_SIZE 8
#define MAXIMUM_HEADER_SIZE 32

long rounding(long val, long base)
{
  return ((val - 1) / base) * base + base;
}

void initialize_and_round_up_to_1_page()
{
    printf("Test: Initialize and Round up to 1 page\n");
    int pagesize = getpagesize();

    if (Mem_Init(NUM_ALLOC) == FAIL)
        exit(EXIT_FAILURE);
    printf("----Mem_Init(512)----\n");
    printf("The page size is %ld.\n", pagesize);
    long rounding_memory_size = rounding(NUM_ALLOC, MINIMUM_BLOCK_SIZE)/ MINIMUM_BLOCK_SIZE * MAXIMUM_HEADER_SIZE + NUM_ALLOC;
    long desired_memory_size = rounding(rounding_memory_size, pagesize);
    printf("The desired memory size is %ld.\n", desired_memory_size);
    printf("The page size is %d.\n", pagesize);
    Mem_Dump();
    printf("You should see that the size of the free block is a little off compared with the desired memory size. \n");
    exit(EXIT_SUCCESS);
}

void main(void)
{
    initialize_and_round_up_to_1_page();
    exit(EXIT_SUCCESS);
}