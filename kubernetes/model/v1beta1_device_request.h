/*
 * v1beta1_device_request.h
 *
 * DeviceRequest is a request for devices required for a claim. This is typically a request for a single resource like a device, but can also ask for several identical devices.  A DeviceClassName is currently required. Clients must check that it is indeed set. It&#39;s absence indicates that something changed in a way that is not supported by the client yet, in which case it must refuse to handle the request.
 */

#ifndef _v1beta1_device_request_H_
#define _v1beta1_device_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_device_request_t v1beta1_device_request_t;

#include "v1beta1_device_selector.h"



typedef struct v1beta1_device_request_t {
    int admin_access; //boolean
    char *allocation_mode; // string
    long count; //numeric
    char *device_class_name; // string
    char *name; // string
    list_t *selectors; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_device_request_t;

__attribute__((deprecated)) v1beta1_device_request_t *v1beta1_device_request_create(
    int admin_access,
    char *allocation_mode,
    long count,
    char *device_class_name,
    char *name,
    list_t *selectors
);

void v1beta1_device_request_free(v1beta1_device_request_t *v1beta1_device_request);

v1beta1_device_request_t *v1beta1_device_request_parseFromJSON(cJSON *v1beta1_device_requestJSON);

cJSON *v1beta1_device_request_convertToJSON(v1beta1_device_request_t *v1beta1_device_request);

#endif /* _v1beta1_device_request_H_ */

