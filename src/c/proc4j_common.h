#include <stdio.h>
#include <stdlib.h>

#define PROC4J_PROC_LIST_BLOCK_SIZE 100

#ifndef PROC4J_H
#define PROC4J_H

#ifdef PROC4J_MODE_DEBUG
    #define PROC4J_DEBUG(statement) statement;
#else
    #define PROC4J_DEBUG(statement)
#endif

typedef struct {
    int id;
    char* name;
} proc4j_process_t;

typedef struct {
    proc4j_process_t *processes;
    int len;
    int reserved;
} proc4j_process_list_t;


void proc4j_process_list_free(proc4j_process_list_t *list);

proc4j_process_list_t* proc4j_get_process_list();

proc4j_process_list_t* proc4j_new_process_list();

void proc4j_process_list_put(proc4j_process_list_t* l, proc4j_process_t p);

#endif /* PROC4J_H */