/**
 * @file description.c
 *
 * @author Simon Petit
 */

#include "description.h"

lsdp_description_t* lsdp_description_new(void)
{
    lsdp_description_t *description;
    description = (lsdp_description_t *)malloc(sizeof(lsdp_description_t));

    description->v = 0;

    return description;
}

void lsdp_description_free(lsdp_description_t *desc)
{
    free(desc->o);
    free(desc->times);
    free(desc->z);
    free(desc->k);
    free(desc->a);
    free(desc->m);

    free(desc);
}
