#include "proc4j_common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void proc4j_process_list_free(proc4j_process_list_t *list) {
    int i;
    for (i = 0; i < list->len; i++) {
        //free(list->processes[i].name);
    }
    PROC4J_DEBUG(printf("Freeing process list\n"));
    free(list->processes);
    PROC4J_DEBUG(printf("Freeing container object\n"));
    free(list);
}

proc4j_process_list_t* proc4j_new_process_list() {
    proc4j_process_list_t* l = (proc4j_process_list_t *)malloc(sizeof(proc4j_process_list_t));
    l->processes = (proc4j_process_t *)malloc(sizeof(proc4j_process_t)*PROC4J_PROC_LIST_BLOCK_SIZE);
    l->len = 0;
    l->reserved = PROC4J_PROC_LIST_BLOCK_SIZE;
    return l;
}

void proc4j_process_list_put(proc4j_process_list_t* l, proc4j_process_t p) {
    if (l->len == l->reserved) {
        l->processes = realloc(l->processes, l->reserved + PROC4J_PROC_LIST_BLOCK_SIZE);
    }
    proc4j_process_t processCopy;
    memcpy(&processCopy, &p, sizeof(proc4j_process_t));
    l->processes[l->len] = p;
    l->len++;
}

