/**
 * @file description.h
 *
 */
#ifndef LSDP_DESCRIPTION_H
#define LSDP_DESCRIPTION_H

#include <stdlib.h>

typedef enum lsdp_network_type_t lsdp_network_type_t;

enum lsdp_network_type_t {
    IN /**< Internet. */
};

typedef enum lsdp_address_type_t lsdp_address_type_t;

enum lsdp_address_type_t {
    IP4, /**< IPv4. */
    IP6 /**< IPv6. */
};

typedef enum lsdp_bandwidth_type_t lsdp_bandwidth_type_t;

enum lsdp_bandwidth_type_t {
    CT, /**< Conference Total. */
    AS /**< Application specific. */
};

typedef enum lsdp_encryption_method_t lsdp_encryption_method_t;

enum lsdp_encryption_method_t {
    CLEAR,
    BASE64,
    URI,
    PROMPT
};

typedef enum lsdp_media_type_t lsdp_media_type_t;

enum lsdp_media_type_t {
    AUDIO,
    VIDEO,
    TEXT,
    APPLICATION,
    MESSAGE
};

typedef enum lsdp_attribute_type_t lsdp_attribute_type_t;

enum lsdp_attribute_type_t {
    CAT,
    KEYWDS,
    TOOL,
    PTIME,
    MAXPTIME,
    RTPMAP,
    RECVONLY,
    SENDRECV,
    SENDONLY,
    INACTIVE,
    ORIENT,
    TYPE,
    CHARSET,
    SDPLANG,
    LANG,
    FRAMERATE,
    QUALITY,
    FMTP
};

typedef struct lsdp_origin_t lsdp_origin_t;

struct lsdp_origin_t {
    char *username; /**< Must not contain space. */
    char *o_sess_id;
    char *o_sess_version;
    lsdp_network_type_t o_nettype; /**< Network type of the session. */
    lsdp_address_type_t o_addrtype; /**< IP address type of the session. */
    char *o_unicast_address; /**< IP address formatted with point notation. */
};


typedef struct lsdp_time_description_t lsdp_time_description_t;

struct lsdp_time_description_t {
    char *t;
    char *r;
};

typedef struct lsdp_time_zone_t lsdp_time_zone_t;

struct lsdp_time_zone_t {
    char *adjustment_time;
    char *offset;
};

typedef struct lsdp_encryption_key_t lsdp_encryption_key_t;

struct lsdp_encryption_key_t {
    lsdp_encryption_method_t method;
    char *encryption_key;
};

typedef struct lsdp_connection_description_t lsdp_connection_description_t;

struct lsdp_connection_description_t {
    lsdp_network_type_t nettype;
    lsdp_address_type_t addrtype;
    char *connection_address;
};

typedef struct lsdp_attribute_t lsdp_attribute_t;

struct lsdp_attribute_t {
    char *attribute;
    char *value;
};

typedef struct lsdp_media_description_t lsdp_media_description_t;

struct lsdp_media_description_t {
    lsdp_media_type_t media;
    int port;
    char *proto;
    char *fmt;
};

typedef struct lsdp_description_t lsdp_description_t;

/**
 * @struct 
 */
struct lsdp_description_t {
    int v;
    lsdp_origin_t *o;
    char *s; /**< Session name, MUST at least be one character. */
    char *i; /**< Session title or short information. */
    char *u; /**< URI of the description. */
    char **e; /**< Emails with optional contact names. */
    char **p; /**< Phone numbers with optional contact names. */
    char *c; /**< Connection information. */
    char *b; /**< Bandwidth information. */
    lsdp_time_description_t **times;
    lsdp_time_zone_t **z;
    lsdp_encryption_key_t *k;
    lsdp_attribute_t **a;
    lsdp_media_description_t **m;

};

lsdp_description_t* lsdp_description_new(void);

void lsdp_description_free(lsdp_description_t *desc);

#endif
