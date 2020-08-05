#ifndef FLECS_SWITCH_LIST_H
#define FLECS_SWITCH_LIST_H

#include "api_defines.h"

typedef struct ecs_switch_header_t {
    int32_t element;
    int32_t count;
} ecs_switch_header_t;

typedef struct ecs_switch_node_t {
    int32_t next;
    int32_t prev;
    int32_t value;
} ecs_switch_node_t;

typedef struct ecs_switch_t {
    int32_t min;
    int32_t max;
    ecs_switch_header_t *headers;
    ecs_vector_t *nodes;
} ecs_switch_t;

FLECS_EXPORT
ecs_switch_t* ecs_switch_new(
    int32_t min, 
    int32_t max,
    int32_t elements);

FLECS_EXPORT
void ecs_switch_free(
    ecs_switch_t *sw);

FLECS_EXPORT
void ecs_switch_add(
    ecs_switch_t *sw);

FLECS_EXPORT
void ecs_switch_set(
    ecs_switch_t *sw,
    int32_t element,
    int32_t value);

FLECS_EXPORT
void ecs_switch_remove(
    ecs_switch_t *sw,
    int32_t element);

FLECS_EXPORT
int32_t ecs_switch_get_case(
    const ecs_switch_t *sw,
    int32_t element);

FLECS_EXPORT
int32_t ecs_switch_first(
    const ecs_switch_t *sw,
    int32_t value);

FLECS_EXPORT
int32_t ecs_switch_next(
    const ecs_switch_t *sw,
    int32_t elem);

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif
