/*
 * v1beta1_ip_address_list.h
 *
 * IPAddressList contains a list of IPAddress.
 */

#ifndef _v1beta1_ip_address_list_H_
#define _v1beta1_ip_address_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_ip_address_list_t v1beta1_ip_address_list_t;

#include "v1_list_meta.h"
#include "v1beta1_ip_address.h"



typedef struct v1beta1_ip_address_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_ip_address_list_t;

__attribute__((deprecated)) v1beta1_ip_address_list_t *v1beta1_ip_address_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1beta1_ip_address_list_free(v1beta1_ip_address_list_t *v1beta1_ip_address_list);

v1beta1_ip_address_list_t *v1beta1_ip_address_list_parseFromJSON(cJSON *v1beta1_ip_address_listJSON);

cJSON *v1beta1_ip_address_list_convertToJSON(v1beta1_ip_address_list_t *v1beta1_ip_address_list);

#endif /* _v1beta1_ip_address_list_H_ */

