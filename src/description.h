/**
 * @file description.h
 *
 * @author Simon Petit
 */
#ifndef LSDP_DESCRIPTION_H
#define LSDP_DESCRIPTION_H

#include "types.h"
#include <stdlib.h>

/**
 * @typedef lsdp_origin_t
 *
 */
typedef struct lsdp_origin_t lsdp_origin_t;

/**
 * @struct lsdp_origin_t
 *
 */
struct lsdp_origin_t {
    char *username; /**< The user's name. Must not contain space. It is '-' if
                      no username specified.*/
    char *sess_id; /**< Numeric string that forms a unique identifier of the 
                     session. */
    char *sess_version; /**< Verison number of this session. Should be increased
                          when a modificiation is made to the session data. */
    lsdp_network_type_t nettype; /**< Network type of the session. */
    lsdp_address_type_t addrtype; /**< IP address type of the session. */
    char *unicast_address; /**< IP address formatted with point notation. */
};


/**
 * @typedef lsdp_time_t
 *
 */
typedef struct lsdp_time_t lsdp_time_t;

/**
 * @struct lsdp_time_t
 *
 */
struct lsdp_time_t {
    char *start; /**< Start time of the session. */
    char *stop; /**< Stop time of the session. */
    char *repeat_interval; /**< .*/
    char *active_duration;
    char *offset;
};

/**
 * @typedef lsdp_time_zone_t
 *
 */
typedef struct lsdp_time_zone_t lsdp_time_zone_t;

/**
 * @struct lsdp_time_zone_t
 *
 */
struct lsdp_time_zone_t {
    char *adjustment_time;
    char *offset;
};

/**
 * @typedef lsdp_encryption_key_t
 *
 */
typedef struct lsdp_encryption_key_t lsdp_encryption_key_t;

/**
 * @struct lsdp_encryption_key_t
 *
 */
struct lsdp_encryption_key_t {
    lsdp_encryption_method_t method; /**< Method of encryption for the key. */
    char *encryption_key; /**< The key used for the encryption. */
};

/**
 * @typedef lsdp_connection_t
 *
 */
typedef struct lsdp_connection_t lsdp_connection_t;

/**
 * @struct lsdp_connection_t
 *
 */
struct lsdp_connection_t {
    lsdp_network_type_t nettype; /**< Type of the network.*/
    lsdp_address_type_t addrtype; /**< IP address type. */
    char *connection_address; /**< IP connection address, in dot standard 
                                format. */
};

/**
 * @typedef lsdp_attribute_t
 *
 */
typedef struct lsdp_attribute_t lsdp_attribute_t;

/**
 * @struct lsdp_attribute_t
 *
 */
struct lsdp_attribute_t {
    char *attribute;
    char *value;
};

/**
 * @typedef lsdp_media_t
 *
 */
typedef struct lsdp_media_t lsdp_media_t;

/**
 * @struct lsdp_media_t
 *
 */
struct lsdp_media_t {
    lsdp_media_type_t media;
    int port;
    char *proto;
    char *fmt;
};

/**
 * @typedef lsdp_session_description_t
 *
 */
typedef struct lsdp_session_t lsdp_session_t;

/**
 * @struct lsdp_session_description_t
 * 
 */
struct lsdp_session_t {
    int v; /**< Version number, currently 0. */
    lsdp_origin_t *o;
    char *s; /**< Session name, MUST at least be one character (whitespace
               if not provided). */
    char *i; /**< Session title or short information. */
    char *u; /**< URI of the description. */
    char **e; /**< Emails with optional contact names. */
    char **p; /**< Phone numbers with optional contact names. */
    lsdp_connection_t *c; /**< Connection information. */
    char *b; /**< Bandwidth information. */
    lsdp_time_t **times;
    lsdp_time_zone_t **z;
    lsdp_encryption_key_t *k;
    lsdp_attribute_t **a;
    lsdp_media_t **m;

};

/**
 * @brief Allocate the memory of a new description.
 *
 * @return A pointer to a neutral description.
 */
lsdp_session_t* lsdp_session_new(void);

/**
 * @brief Free the allocated memory of every struct involved in the description.
 *
 * @param[in] desc A pointer to the description to free.
 */
void lsdp_session_free(lsdp_session_t *sess);

#endif
