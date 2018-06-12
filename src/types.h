/**
 * @file types.h
 *
 * @author Simon Petit
 */

#ifndef TYPES_H
#define TYPES_H

/**
 * @enum lsdp_network_type_t
 *
 * @typedef lsdp_network_type_t
 *
 * @brief Type of the network used for the session. Currently only internet (IN)
 * is supported.
 */
typedef enum lsdp_network_type_t {
    IN /**< Internet. */
} lsdp_network_type_t;

/**
 * @enum lsdp_network_type_t
 *
 * @typedef lsdp_network_type_t
 *
 * @brief Version of the IP used. Currently choice between IPv4 (IP4) and IPv6
 * (IP6)
 */
typedef enum lsdp_address_type_t {
    IP4, /**< IPv4. */
    IP6 /**< IPv6. */
} lsdp_address_type_t;

/**
 * @enum lsdp_bandwidth_type_t
 *
 * @typedef lsdp_bandwidth_type_t
 */
typedef enum lsdp_bandwidth_type_t {
    CT, /**< Conference Total. */
    AS /**< Application specific. */
} lsdp_bandwidth_type_t;

/**
 * @enum lsdp_encryption_method_t
 *
 * @typedef lsdp_encryption_method_t
 */
typedef enum lsdp_encryption_method_t {
    CLEAR,
    BASE64,
    URI,
    PROMPT
} lsdp_encryption_method_t;


/**
 * @enum lsdp_media_type_t
 *
 */
typedef enum lsdp_media_type_t {
    AUDIO,
    VIDEO,
    TEXT,
    APPLICATION,
    MESSAGE
} lsdp_media_type_t;


/**
 * @enum lsdp_attribute_type_t
 *
 * @typedef lsdp_attribute_type_t
 */
typedef enum lsdp_attribute_type_t {
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
} lsdp_attribute_type_t;


/**
 * @enum lsdp_protocol_type_t
 *
 * @typedef lsdp_protocol_type_t
 *
 * @brief Protocol of the media. Currently udp (UDP), real-time protocol
 * (RTP_AVP) and secure real time protocol (RTP_SAVP) supported.
 */
typedef enum lsdp_protocol_type_t {
    UDP,
    RTP_AVP,
    RTP_SAVP
} lsdp_protocol_type_t;

#endif
