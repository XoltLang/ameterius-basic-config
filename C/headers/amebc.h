// amebc.h
#ifndef AMEBC_H
#define AMEBC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256 //
#define MAX_BLOCKS 10 // IF YOU CHAGNE, ANY THINKS CAN BE CREATED, LIKE A BLACK HOLE!
#define MAX_KEYS 10 //

typedef struct {
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
} KeyValuePair;

typedef struct {
    char name[MAX_LINE_LENGTH];
    KeyValuePair keys[MAX_KEYS];
    int key_count;
} ConfigBlock;

typedef struct {
    ConfigBlock blocks[MAX_BLOCKS];
    int block_count;
} Config;

void parse_config(const char *filename, Config *config);
const char *get_value(const Config *config, const char *block_name, const char *key);

#endif // AMEBC_H
