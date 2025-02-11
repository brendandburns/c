#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_resource_slice_spec.h"



static v1beta1_resource_slice_spec_t *v1beta1_resource_slice_spec_create_internal(
    int all_nodes,
    list_t *devices,
    char *driver,
    char *node_name,
    v1_node_selector_t *node_selector,
    v1beta1_resource_pool_t *pool
    ) {
    v1beta1_resource_slice_spec_t *v1beta1_resource_slice_spec_local_var = malloc(sizeof(v1beta1_resource_slice_spec_t));
    if (!v1beta1_resource_slice_spec_local_var) {
        return NULL;
    }
    v1beta1_resource_slice_spec_local_var->all_nodes = all_nodes;
    v1beta1_resource_slice_spec_local_var->devices = devices;
    v1beta1_resource_slice_spec_local_var->driver = driver;
    v1beta1_resource_slice_spec_local_var->node_name = node_name;
    v1beta1_resource_slice_spec_local_var->node_selector = node_selector;
    v1beta1_resource_slice_spec_local_var->pool = pool;

    v1beta1_resource_slice_spec_local_var->_library_owned = 1;
    return v1beta1_resource_slice_spec_local_var;
}

__attribute__((deprecated)) v1beta1_resource_slice_spec_t *v1beta1_resource_slice_spec_create(
    int all_nodes,
    list_t *devices,
    char *driver,
    char *node_name,
    v1_node_selector_t *node_selector,
    v1beta1_resource_pool_t *pool
    ) {
    return v1beta1_resource_slice_spec_create_internal (
        all_nodes,
        devices,
        driver,
        node_name,
        node_selector,
        pool
        );
}

void v1beta1_resource_slice_spec_free(v1beta1_resource_slice_spec_t *v1beta1_resource_slice_spec) {
    if(NULL == v1beta1_resource_slice_spec){
        return ;
    }
    if(v1beta1_resource_slice_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_resource_slice_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_resource_slice_spec->devices) {
        list_ForEach(listEntry, v1beta1_resource_slice_spec->devices) {
            v1beta1_device_free(listEntry->data);
        }
        list_freeList(v1beta1_resource_slice_spec->devices);
        v1beta1_resource_slice_spec->devices = NULL;
    }
    if (v1beta1_resource_slice_spec->driver) {
        free(v1beta1_resource_slice_spec->driver);
        v1beta1_resource_slice_spec->driver = NULL;
    }
    if (v1beta1_resource_slice_spec->node_name) {
        free(v1beta1_resource_slice_spec->node_name);
        v1beta1_resource_slice_spec->node_name = NULL;
    }
    if (v1beta1_resource_slice_spec->node_selector) {
        v1_node_selector_free(v1beta1_resource_slice_spec->node_selector);
        v1beta1_resource_slice_spec->node_selector = NULL;
    }
    if (v1beta1_resource_slice_spec->pool) {
        v1beta1_resource_pool_free(v1beta1_resource_slice_spec->pool);
        v1beta1_resource_slice_spec->pool = NULL;
    }
    free(v1beta1_resource_slice_spec);
}

cJSON *v1beta1_resource_slice_spec_convertToJSON(v1beta1_resource_slice_spec_t *v1beta1_resource_slice_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_resource_slice_spec->all_nodes
    if(v1beta1_resource_slice_spec->all_nodes) {
    if(cJSON_AddBoolToObject(item, "allNodes", v1beta1_resource_slice_spec->all_nodes) == NULL) {
    goto fail; //Bool
    }
    }


    // v1beta1_resource_slice_spec->devices
    if(v1beta1_resource_slice_spec->devices) {
    cJSON *devices = cJSON_AddArrayToObject(item, "devices");
    if(devices == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *devicesListEntry;
    if (v1beta1_resource_slice_spec->devices) {
    list_ForEach(devicesListEntry, v1beta1_resource_slice_spec->devices) {
    cJSON *itemLocal = v1beta1_device_convertToJSON(devicesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(devices, itemLocal);
    }
    }
    }


    // v1beta1_resource_slice_spec->driver
    if (!v1beta1_resource_slice_spec->driver) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driver", v1beta1_resource_slice_spec->driver) == NULL) {
    goto fail; //String
    }


    // v1beta1_resource_slice_spec->node_name
    if(v1beta1_resource_slice_spec->node_name) {
    if(cJSON_AddStringToObject(item, "nodeName", v1beta1_resource_slice_spec->node_name) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_resource_slice_spec->node_selector
    if(v1beta1_resource_slice_spec->node_selector) {
    cJSON *node_selector_local_JSON = v1_node_selector_convertToJSON(v1beta1_resource_slice_spec->node_selector);
    if(node_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeSelector", node_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_resource_slice_spec->pool
    if (!v1beta1_resource_slice_spec->pool) {
        goto fail;
    }
    cJSON *pool_local_JSON = v1beta1_resource_pool_convertToJSON(v1beta1_resource_slice_spec->pool);
    if(pool_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "pool", pool_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_resource_slice_spec_t *v1beta1_resource_slice_spec_parseFromJSON(cJSON *v1beta1_resource_slice_specJSON){

    v1beta1_resource_slice_spec_t *v1beta1_resource_slice_spec_local_var = NULL;

    // define the local list for v1beta1_resource_slice_spec->devices
    list_t *devicesList = NULL;

    // define the local variable for v1beta1_resource_slice_spec->node_selector
    v1_node_selector_t *node_selector_local_nonprim = NULL;

    // define the local variable for v1beta1_resource_slice_spec->pool
    v1beta1_resource_pool_t *pool_local_nonprim = NULL;

    // v1beta1_resource_slice_spec->all_nodes
    cJSON *all_nodes = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_slice_specJSON, "allNodes");
    if (cJSON_IsNull(all_nodes)) {
        all_nodes = NULL;
    }
    if (all_nodes) { 
    if(!cJSON_IsBool(all_nodes))
    {
    goto end; //Bool
    }
    }

    // v1beta1_resource_slice_spec->devices
    cJSON *devices = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_slice_specJSON, "devices");
    if (cJSON_IsNull(devices)) {
        devices = NULL;
    }
    if (devices) { 
    cJSON *devices_local_nonprimitive = NULL;
    if(!cJSON_IsArray(devices)){
        goto end; //nonprimitive container
    }

    devicesList = list_createList();

    cJSON_ArrayForEach(devices_local_nonprimitive,devices )
    {
        if(!cJSON_IsObject(devices_local_nonprimitive)){
            goto end;
        }
        v1beta1_device_t *devicesItem = v1beta1_device_parseFromJSON(devices_local_nonprimitive);

        list_addElement(devicesList, devicesItem);
    }
    }

    // v1beta1_resource_slice_spec->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_slice_specJSON, "driver");
    if (cJSON_IsNull(driver)) {
        driver = NULL;
    }
    if (!driver) {
        goto end;
    }

    
    if(!cJSON_IsString(driver))
    {
    goto end; //String
    }

    // v1beta1_resource_slice_spec->node_name
    cJSON *node_name = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_slice_specJSON, "nodeName");
    if (cJSON_IsNull(node_name)) {
        node_name = NULL;
    }
    if (node_name) { 
    if(!cJSON_IsString(node_name) && !cJSON_IsNull(node_name))
    {
    goto end; //String
    }
    }

    // v1beta1_resource_slice_spec->node_selector
    cJSON *node_selector = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_slice_specJSON, "nodeSelector");
    if (cJSON_IsNull(node_selector)) {
        node_selector = NULL;
    }
    if (node_selector) { 
    node_selector_local_nonprim = v1_node_selector_parseFromJSON(node_selector); //nonprimitive
    }

    // v1beta1_resource_slice_spec->pool
    cJSON *pool = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_slice_specJSON, "pool");
    if (cJSON_IsNull(pool)) {
        pool = NULL;
    }
    if (!pool) {
        goto end;
    }

    
    pool_local_nonprim = v1beta1_resource_pool_parseFromJSON(pool); //nonprimitive


    v1beta1_resource_slice_spec_local_var = v1beta1_resource_slice_spec_create_internal (
        all_nodes ? all_nodes->valueint : 0,
        devices ? devicesList : NULL,
        strdup(driver->valuestring),
        node_name && !cJSON_IsNull(node_name) ? strdup(node_name->valuestring) : NULL,
        node_selector ? node_selector_local_nonprim : NULL,
        pool_local_nonprim
        );

    return v1beta1_resource_slice_spec_local_var;
end:
    if (devicesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, devicesList) {
            v1beta1_device_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(devicesList);
        devicesList = NULL;
    }
    if (node_selector_local_nonprim) {
        v1_node_selector_free(node_selector_local_nonprim);
        node_selector_local_nonprim = NULL;
    }
    if (pool_local_nonprim) {
        v1beta1_resource_pool_free(pool_local_nonprim);
        pool_local_nonprim = NULL;
    }
    return NULL;

}
