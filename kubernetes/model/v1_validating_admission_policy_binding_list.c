#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_validating_admission_policy_binding_list.h"



v1_validating_admission_policy_binding_list_t *v1_validating_admission_policy_binding_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
    v1_validating_admission_policy_binding_list_t *v1_validating_admission_policy_binding_list_local_var = malloc(sizeof(v1_validating_admission_policy_binding_list_t));
    if (!v1_validating_admission_policy_binding_list_local_var) {
        return NULL;
    }
    v1_validating_admission_policy_binding_list_local_var->api_version = api_version;
    v1_validating_admission_policy_binding_list_local_var->items = items;
    v1_validating_admission_policy_binding_list_local_var->kind = kind;
    v1_validating_admission_policy_binding_list_local_var->metadata = metadata;

    return v1_validating_admission_policy_binding_list_local_var;
}


void v1_validating_admission_policy_binding_list_free(v1_validating_admission_policy_binding_list_t *v1_validating_admission_policy_binding_list) {
    if(NULL == v1_validating_admission_policy_binding_list){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_validating_admission_policy_binding_list->api_version) {
        free(v1_validating_admission_policy_binding_list->api_version);
        v1_validating_admission_policy_binding_list->api_version = NULL;
    }
    if (v1_validating_admission_policy_binding_list->items) {
        list_ForEach(listEntry, v1_validating_admission_policy_binding_list->items) {
            v1_validating_admission_policy_binding_free(listEntry->data);
        }
        list_freeList(v1_validating_admission_policy_binding_list->items);
        v1_validating_admission_policy_binding_list->items = NULL;
    }
    if (v1_validating_admission_policy_binding_list->kind) {
        free(v1_validating_admission_policy_binding_list->kind);
        v1_validating_admission_policy_binding_list->kind = NULL;
    }
    if (v1_validating_admission_policy_binding_list->metadata) {
        v1_list_meta_free(v1_validating_admission_policy_binding_list->metadata);
        v1_validating_admission_policy_binding_list->metadata = NULL;
    }
    free(v1_validating_admission_policy_binding_list);
}

cJSON *v1_validating_admission_policy_binding_list_convertToJSON(v1_validating_admission_policy_binding_list_t *v1_validating_admission_policy_binding_list) {
    cJSON *item = cJSON_CreateObject();

    // v1_validating_admission_policy_binding_list->api_version
    if(v1_validating_admission_policy_binding_list->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_validating_admission_policy_binding_list->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_validating_admission_policy_binding_list->items
    if (!v1_validating_admission_policy_binding_list->items) {
        goto fail;
    }
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (v1_validating_admission_policy_binding_list->items) {
    list_ForEach(itemsListEntry, v1_validating_admission_policy_binding_list->items) {
    cJSON *itemLocal = v1_validating_admission_policy_binding_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // v1_validating_admission_policy_binding_list->kind
    if(v1_validating_admission_policy_binding_list->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_validating_admission_policy_binding_list->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_validating_admission_policy_binding_list->metadata
    if(v1_validating_admission_policy_binding_list->metadata) {
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(v1_validating_admission_policy_binding_list->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_validating_admission_policy_binding_list_t *v1_validating_admission_policy_binding_list_parseFromJSON(cJSON *v1_validating_admission_policy_binding_listJSON){

    v1_validating_admission_policy_binding_list_t *v1_validating_admission_policy_binding_list_local_var = NULL;

    // define the local list for v1_validating_admission_policy_binding_list->items
    list_t *itemsList = NULL;

    // define the local variable for v1_validating_admission_policy_binding_list->metadata
    v1_list_meta_t *metadata_local_nonprim = NULL;

    // v1_validating_admission_policy_binding_list->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_validating_admission_policy_binding_listJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_validating_admission_policy_binding_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v1_validating_admission_policy_binding_listJSON, "items");
    if (!items) {
        goto end;
    }

    
    cJSON *items_local_nonprimitive = NULL;
    if(!cJSON_IsArray(items)){
        goto end; //nonprimitive container
    }

    itemsList = list_createList();

    cJSON_ArrayForEach(items_local_nonprimitive,items )
    {
        if(!cJSON_IsObject(items_local_nonprimitive)){
            goto end;
        }
        v1_validating_admission_policy_binding_t *itemsItem = v1_validating_admission_policy_binding_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // v1_validating_admission_policy_binding_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_validating_admission_policy_binding_listJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_validating_admission_policy_binding_list->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_validating_admission_policy_binding_listJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }


    v1_validating_admission_policy_binding_list_local_var = v1_validating_admission_policy_binding_list_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        itemsList,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v1_validating_admission_policy_binding_list_local_var;
end:
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            v1_validating_admission_policy_binding_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    if (metadata_local_nonprim) {
        v1_list_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
