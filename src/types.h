/**
 * @file types.h
 *
 * @author Simon Petit
 */

#ifndef TYPES_H
#define TYPES_H

typedef enum lsdp_network_type_t lsdp_network_type_t;

/**
 * @enum lsdp_network_type_t
 *
 */
enum lsdp_network_type_t {
    IN /**< Internet. */
};

typedef enum lsdp_address_type_t lsdp_address_type_t;

/**
 * @enum lsdp_network_type_t
 *
 */
enum lsdp_address_type_t {
    IP4, /**< IPv4. */
    IP6 /**< IPv6. */
};

typedef enum lsdp_bandwidth_type_t lsdp_bandwidth_type_t;

/**
 * @enum lsdp_bandwidth_type_t
 *
 */
enum lsdp_bandwidth_type_t {
    CT, /**< Conference Total. */
    AS /**< Application specific. */
};

typedef enum lsdp_encryption_method_t lsdp_encryption_method_t;

/**
 * @enum lsdp_encryption_method_t
 *
 */
enum lsdp_encryption_method_t {
    CLEAR,
    BASE64,
    URI,
    PROMPT
};

typedef enum lsdp_media_type_t lsdp_media_type_t;

/**
 * @enum lsdp_media_type_t
 *
 */
enum lsdp_media_type_t {
    AUDIO,
    VIDEO,
    TEXT,
    APPLICATION,
    MESSAGE
};

typedef enum lsdp_attribute_type_t lsdp_attribute_type_t;

/**
 * @enum lsdp_attribute_type_t
 *
 */
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

#endif
