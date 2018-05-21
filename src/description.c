/**
 * @file description.c
 *
 * @author Simon Petit
 */

#include "description.h"

lsdp_session_t* lsdp_session_new(void)
{
    lsdp_session_t *session;
    session = (lsdp_session_t *)malloc(sizeof(lsdp_session_t));

    session->v = 0;

    return session;
}

void lsdp_session_free(lsdp_session_t *sess)
{
    free(sess->o);
    free(sess->times);
    free(sess->z);
    free(sess->k);
    free(sess->a);
    free(sess->m);

    free(sess);
}

lsdp_origin_t *lsdp_origin_new(void *username, lsdp_network_type_t nettype, 
        lsdp_address_type_t addrtype, char *address)
{
    lsdp_origin_t *origin = (lsdp_origin_t *)malloc(sizeof(lsdp_origin_t));

    if (username != NULL) {
        origin->username = (char *)username;
    } else {
        origin->username = "-";
    }

    origin->nettype = nettype;
    origin->addrtype = addrtype;
    origin->unicast_address = address;

    return origin;
}
