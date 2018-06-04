/**
 * @file description.h
 *
 * @author Simon Petit
 */
#ifndef LSDP_DESCRIPTION_H
#define LSDP_DESCRIPTION_H

#include "types.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/**
 * @typedef lsdp_origin_t
 *
 */
typedef struct lsdp_origin_t lsdp_origin_t;

/**
 * @struct lsdp_origin_t
 *
 * @brief Gathering of basic info about the session and the user.
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
 * @brief Timing information of the session.
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
 * @brief Time zone adjustment.
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
 * @brief Encryption key method and value.
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
 * @brief Relative information about the session's connection.
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
 * @brief Attribute described by its name and optionnal value.
 */
struct lsdp_attribute_t {
    lsdp_attribute_type_t name; /**< Name of the attribute. */
    char *value; /**< If needed, value of the attribute. */
};

/**
 * @typedef lsdp_media_t
 *
 */
typedef struct lsdp_media_t lsdp_media_t;

/**
 * @struct lsdp_media_t
 *
 * @brief Describe a media which will be use during the session.
 */
struct lsdp_media_t {
    lsdp_media_type_t media_type; /**< Type of media. */
    int port; /**< Port on which to receive data. */
    char *proto; /**< Transport protocol. */
    char *fmt; /**< Format description. */
    lsdp_attribute_t **attributes; /**< Attributes on the media level. */
    int count_attributes; /**< Number of attributes of the media level. */
};

/**
 * @typedef lsdp_session_t
 *
 */
typedef struct lsdp_session_t lsdp_session_t;

/**
 * @struct lsdp_session_t
 * 
 * @brief Whole description of a session.
 */
struct lsdp_session_t {
    int version; /**< Version number, currently 0. */
    lsdp_origin_t *origin; /**< Basic info about the user and the session. */ 
    char *session_name; /**< Session name, MUST at least be one character (whitespace if not provided). */
    char *information; /**< Session title or short information. */
    char *uri; /**< URI of the description. */
    char *email; /**< Email with optional contact name. */
    char *phone; /**< Phone number with optional contact name. */
    lsdp_connection_t *connection; /**< Connection information. */
    char *bandwidth; /**< Bandwidth information. */
    lsdp_time_t **times; /**< Stop, start and repeat timing information
                           of the session. */
    lsdp_time_zone_t **time_zones; /**< Adujusting time zones parameter. */
    lsdp_encryption_key_t *encryption_key; /**< Encryption key. */
    lsdp_attribute_t **attributes; /**< Session-level attributes that apply to the whole seesion. */
    int count_attributes; /**< Number of attributes on session level. */
    lsdp_media_t **media_descriptions; /**< Medias used by the session. */
    int count_media; /**< Number of medias. */
};

/**
 * @brief Allocate the memory of a new lsdp_seesion_t.
 *
 * @return A pointer to a neutral session.
 */
lsdp_session_t* lsdp_session_new(lsdp_origin_t *origin, char *session_name,
        char *info, char *uri, char *email, char *phone,
        lsdp_connection_t *connection);

/**
 * @brief Free the allocated memory of every struct involved in the description.
 *
 * @param[in] sess A pointer to the description to free.
 */
void lsdp_session_free(lsdp_session_t *sess);


/**
 * @brief Check the given session name, and replace it to " " in the case it is
 * a NULL pointer or an empty string. This follow the recomendations of the RFC.
 *
 * @param[in] session_name A session name string to check
 *
 * @return A valid name for the session : The given session name if it was
 * already correctly formatted, " " in any other case.
 */
char *check_session_name(char *session_name);

/**
 * @brief Allocate the memore of a new origin and add the given parameters.
 *
 * @return A pointer to the said lsdp_origin_t filled structure.
 */
lsdp_origin_t *lsdp_origin_new(void *username, lsdp_network_type_t nettype, 
        lsdp_address_type_t addrtype, char *address);

/**
 * @brief Free the memory of an origin structure.
 *
 * @param[in] origin A lsdp_origin_t pointer.
 *
 */
void lsdp_origin_free(lsdp_origin_t *origin);

/**
 * @brief Allocate mamory for a connection specification structure.
 *
 * @return A pointer to a lsdp_connection_t structure.
 */
lsdp_connection_t *lsdp_connection_new(lsdp_network_type_t nettype,
        lsdp_address_type_t addrtype, char *connection_address);

/**
 * @brief Free the memory of the connection structure.
 *
 * @param[in] connection A lsdp_connection_t pointer.
 */
void lsdp_connection_free(lsdp_connection_t *connection);

/**
 * @brief Allocate memory for a attribute structure.
 *
 * @return A pointer to a lsdp_attribute_structure.
 */
lsdp_attribute_t *lsdp_attribute_new(lsdp_attribute_type_t name,
        char *value);

/**
 * @brief Allocate memory for a new media structure.
 *
 * @return A pointer to a lsdp_media_t strcuture.
 */
lsdp_media_t *lsdp_media_new(lsdp_media_type_t media_type, int port, char *proto,
        char *fmt);


#endif
