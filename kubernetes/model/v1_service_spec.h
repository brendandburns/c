/*
 * v1_service_spec.h
 *
 * ServiceSpec describes the attributes that a user creates on a service.
 */

#ifndef _v1_service_spec_H_
#define _v1_service_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_service_spec_t v1_service_spec_t;

#include "v1_service_port.h"
#include "v1_session_affinity_config.h"



typedef struct v1_service_spec_t {
    int allocate_load_balancer_node_ports; //boolean
    char *cluster_ip; // string
    list_t *cluster_ips; //primitive container
    list_t *external_ips; //primitive container
    char *external_name; // string
    char *external_traffic_policy; // string
    int health_check_node_port; //numeric
    char *internal_traffic_policy; // string
    list_t *ip_families; //primitive container
    char *ip_family_policy; // string
    char *load_balancer_class; // string
    char *load_balancer_ip; // string
    list_t *load_balancer_source_ranges; //primitive container
    list_t *ports; //nonprimitive container
    int publish_not_ready_addresses; //boolean
    list_t* selector; //map
    char *session_affinity; // string
    struct v1_session_affinity_config_t *session_affinity_config; //model
    char *type; // string

} v1_service_spec_t;

v1_service_spec_t *v1_service_spec_create(
    int allocate_load_balancer_node_ports,
    char *cluster_ip,
    list_t *cluster_ips,
    list_t *external_ips,
    char *external_name,
    char *external_traffic_policy,
    int health_check_node_port,
    char *internal_traffic_policy,
    list_t *ip_families,
    char *ip_family_policy,
    char *load_balancer_class,
    char *load_balancer_ip,
    list_t *load_balancer_source_ranges,
    list_t *ports,
    int publish_not_ready_addresses,
    list_t* selector,
    char *session_affinity,
    v1_session_affinity_config_t *session_affinity_config,
    char *type
);

void v1_service_spec_free(v1_service_spec_t *v1_service_spec);

v1_service_spec_t *v1_service_spec_parseFromJSON(cJSON *v1_service_specJSON);

cJSON *v1_service_spec_convertToJSON(v1_service_spec_t *v1_service_spec);

#endif /* _v1_service_spec_H_ */

