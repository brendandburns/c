/*
 * v1beta1_replica_set_status.h
 *
 * ReplicaSetStatus represents the current status of a ReplicaSet.
 */

#ifndef _v1beta1_replica_set_status_H_
#define _v1beta1_replica_set_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1beta1_replica_set_condition.h"



typedef struct v1beta1_replica_set_status_t {
    int available_replicas; //numeric
    list_t *conditions; //nonprimitive container
    int fully_labeled_replicas; //numeric
    long observed_generation; //numeric
    int ready_replicas; //numeric
    int replicas; //numeric

} v1beta1_replica_set_status_t;

v1beta1_replica_set_status_t *v1beta1_replica_set_status_create(
    int available_replicas,
    list_t *conditions,
    int fully_labeled_replicas,
    long observed_generation,
    int ready_replicas,
    int replicas
);

void v1beta1_replica_set_status_free(v1beta1_replica_set_status_t *v1beta1_replica_set_status);

v1beta1_replica_set_status_t *v1beta1_replica_set_status_parseFromJSON(cJSON *v1beta1_replica_set_statusJSON);

cJSON *v1beta1_replica_set_status_convertToJSON(v1beta1_replica_set_status_t *v1beta1_replica_set_status);

#endif /* _v1beta1_replica_set_status_H_ */

