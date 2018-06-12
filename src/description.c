/**
 * @file description.c
 *
 * @author Simon Petit
 */

#include "sdp.h"

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
    session->attributes_count = 0;
    session->attributes_capacity = 3;
    session->attributes = calloc(session->attributes_capacity,
            sizeof(lsdp_attribute_t*));
    session->media_count = 0;
    session->media_capacity = 3;
    session->media_descriptions = calloc(session->media_capacity, 
            sizeof(lsdp_media_t*));

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
    media = (lsdp_media_t *)malloc(sizeof(lsdp_media_t*));

    media->media_type = media_type;
    media->port = port;
    media->proto = proto;
    media->fmt = fmt;
    media->attributes = NULL;
    media->attributes_count = 0;
    media->attributes_capacity = 3;

    return media;
}

int lsdp_append_media_to_session(lsdp_session_t *session, lsdp_media_t *media)
{
    int n;
    if (session->media_count >= session->media_capacity) {
        session->media_capacity *=2;
        session->media_descriptions = realloc(session->media_descriptions,
                session->media_capacity * sizeof(lsdp_media_t*));
    }
    session->media_descriptions[session->media_count] = media;
    session->media_count++;
    return n;
}

int lsdp_append_attribute_to_session(lsdp_session_t *session,
        lsdp_attribute_t *attribute)
{
    int n;
    if (session->attributes_count >= session->attributes_capacity) {
        session->attributes_capacity *= 2;
        session->attributes = realloc(session->attributes,
                session->attributes_capacity * sizeof(lsdp_attribute_t*));
    }
    session->attributes[session->attributes_count] = attribute;
    session->attributes_count++;
    return n;
}

int lsdp_append_attribute_to_media(lsdp_media_t *media,
        lsdp_attribute_t *attribute)
{
    int n;
    if (media->attributes_count >= media->attributes_capacity) {
        media->attributes_capacity *= 2;
        media->attributes = realloc(media->attributes,
                media->attributes_capacity * sizeof(lsdp_attribute_t*));
    }
    media->attributes[media->attributes_count] = attribute;
    media->attributes_count++;
    return n;
}
