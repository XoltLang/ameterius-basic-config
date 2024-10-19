// amebc.c

/*
 * Copyright: Xolt Language Community
 * Author: Ametero
 * Version: 2.5 RLS
 */



#include "amebc.h"

void parse_config(const char *filename, Config *config) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Openning config errored!");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Removing the "\n"
        line[strcspn(line, "\n")] = 0;

        // Skipping comments and spaces (including empty lines)
        if (strlen(line) == 0 || line[0] == '#') {
            continue;
        }

        // Parsing - block:key:value
        char block_name[MAX_LINE_LENGTH], key[MAX_LINE_LENGTH], value[MAX_LINE_LENGTH];
        if (sscanf(line, "%[^:]:%[^:]:%s", block_name, key, value) == 3) {
            // searching block
            int block_index = -1;
            for (int i = 0; i < config->block_count; i++) {
                if (strcmp(config->blocks[i].name, block_name) == 0) {
                    block_index = i;
                    break;
                }
            }

            // If block don't founded, creating him
            if (block_index == -1) {
                block_index = config->block_count;
                strncpy(config->blocks[block_index].name, block_name, sizeof(config->blocks[block_index].name));
                config->blocks[block_index].key_count = 0;
                config->block_count++;
            }

            // Adding the key-value
            ConfigBlock *block = &config->blocks[block_index];
            strncpy(block->keys[block->key_count].key, key, sizeof(block->keys[block->key_count].key));
            strncpy(block->keys[block->key_count].value, value, sizeof(block->keys[block->key_count].value));
            block->key_count++;
        }
    }

    fclose(file);
}

const char *get_value(const Config *config, const char *block_name, const char *key) {
    for (int i = 0; i < config->block_count; i++) {
        if (strcmp(config->blocks[i].name, block_name) == 0) {
            for (int j = 0; j < config->blocks[i].key_count; j++) {
                if (strcmp(config->blocks[i].keys[j].key, key) == 0) {
                    return config->blocks[i].keys[j].value;
                }
            }
        }
    }
    return NULL;
}
