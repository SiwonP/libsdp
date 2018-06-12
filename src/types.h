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
 * @enum lsdp_address_type_t
 *
 * @typedef lsdp_address_type_t
 *
 * @brief Version of the IP used. 
 */
typedef enum lsdp_address_type_t {
    IP4, /**< IPv4. */
    IP6 /**< IPv6. */
} lsdp_address_type_t;

/**
 * @enum lsdp_bandwidth_type_t
 *
 * @typedef lsdp_bandwidth_type_t
 *
 * @brief Type of the bandwith.
 */
typedef enum lsdp_bandwidth_type_t {
    CT, /**< Conference Total. */
    AS /**< Application specific. */
} lsdp_bandwidth_type_t;

/**
 * @enum lsdp_encryption_method_t
 *
 * @typedef lsdp_encryption_method_t
 *
 * @brief Encryption method of the key
 */
typedef enum lsdp_encryption_method_t {
    CLEAR, /**< The key is not given as is. */
    BASE64, /**< The key has been base64 encoded. */
    URI, /**< The uri refering to the key. */
    PROMPT /**< No key included. */
} lsdp_encryption_method_t;


/**
 * @enum lsdp_media_type_t
 *
 * @typedef lsdp_media_type_t
 *
 * @brief Support of the media.
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
 *
 * @brief Type for attributes.
 */
typedef enum lsdp_attribute_type_t {
    CAT, /**< */
    KEYWDS, /**< To assist identifying wanted sessions at the receiver.
              The receiver can chose interesting sessions based on keywords
              describing the session's purpose. */
    TOOL, /**< Gives the name and version of the tool used to create the 
            session description.*/
    PTIME, /**< Gives the length of time represented by the media in a packet. */
    MAXPTIME, /**< Gives the maximum amount of media that can be encapsulated 
                in each packet. */
    RTPMAP,
    RECVONLY, /**< Specifies that the tools should be started in receive-only
                mode. */
    SENDRECV, /**< Specifies that the tools should be started in send and reveive
                mode. */
    SENDONLY, /**< Specifies that the tools should be started in send-only 
                mode. */
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
 * @brief Protocol of the media. 
 */
typedef enum lsdp_protocol_type_t {
    UDP, /**< Unspecified protocol over udp. */
    RTP_AVP, /**< Real Time Protcol  with minimal control. */
    RTP_SAVP /**< Secure Real Time Protocol. */
} lsdp_protocol_type_t;

#endif
