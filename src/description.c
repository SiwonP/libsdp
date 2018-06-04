/**
 * @file description.c
 *
 * @author Simon Petit
 */

#include "description.h"

lsdp_session_t* lsdp_session_new(lsdp_origin_t *origin, char *session_name,
        char *info, char *uri, char *email, char *phone,
        lsdp_connection_t *connection)
{
    lsdp_session_t *session;
    session = (lsdp_session_t *)malloc(sizeof(lsdp_session_t));

    session->version = 0;
    session->origin = origin;
    session->session_name = check_session_name(session_name);
    session->information = info;
    session->uri = uri;
    session->email = email;
    session->phone = phone;
    session->connection = connection;
    session->bandwidth = NULL;

    session->encryption_key = NULL;
    session->attributes = NULL;
    session->count_attributes = 0;
    session->media_descriptions = NULL;
    session->count_media = 0;

    return session;
}

void lsdp_session_free(lsdp_session_t *sess)
{
    free(sess->origin);
    free(sess->times);
    free(sess->time_zones);
    free(sess->encryption_key);
    free(sess->attributes);
    free(sess->media_descriptions);

    free(sess);
}

char *check_session_name(char *session_name)
{
    char *name;
    strcpy(name, session_name);

    if (strcmp(name, "") || name == NULL) {
        strcpy(name, " ");
    }
    return name;
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

void lsdp_origin_free(lsdp_origin_t *origin)
{
    free(origin);
}

lsdp_connection_t *lsdp_connection_new(lsdp_network_type_t nettype, 
        lsdp_address_type_t addrtype, char *connection_address)
{
    lsdp_connection_t *connection;
    connection = (lsdp_connection_t *)malloc(sizeof(lsdp_connection_t));

    connection->nettype = nettype;
    connection->addrtype = addrtype;
    //TODO: Check standard dot format of the IP address + TTL
    connection->connection_address = connection_address;

    return connection;
}

void lsdp_connection_free(lsdp_connection_t *connection)
{
    free(connection);
}

lsdp_attribute_t *lsdp_attribute_new(lsdp_attribute_type_t name,
        char *value)
{
    lsdp_attribute_t *attribute;
    attribute = (lsdp_attribute_t *)malloc(sizeof(lsdp_attribute_t));

    attribute->name = name;

    return attribute;
}

lsdp_media_t *lsdp_media_new(lsdp_media_type_t media_type, int port, char *proto,
        char *fmt)
{
    lsdp_media_t *media;
    media = (lsdp_media_t *)malloc(sizeof(lsdp_media_t));

    media->media_type = media_type;
    media->port = port;
    media->proto = proto;
    media->fmt = fmt;

    return media;
}
