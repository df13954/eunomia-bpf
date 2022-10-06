#ifndef EWASM_APP_INIT_H
#define EWASM_APP_INIT_H

#include "native-ewasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "cJSON/cJSON.h"

/// @brief start the eBPF program with JSON and wait for it to exit
/// @param program_data the json data of eBPF program
/// @return 0 on success, -1 on failure, the eBPF program will be terminated in failure case
int start_bpf_program(char *program_data)
{
    int res = create_bpf(program_data, strlen(program_data));
    if (res < 0)
    {
        printf("create_bpf failed %d", res);
        return -1;
    }
    res = run_bpf(res);
    if (res < 0)
    {
        printf("run_bpf failed %d\n", res);
        return -1;
    }
    res = wait_and_poll_bpf(res);
    if (res < 0)
    {
        printf("wait_and_poll_bpf failed %d\n", res);
        return -1;
    }
    return 0;
}

cJSON *
add_runtime_arg_to_bpf_program(cJSON *program, char *key, cJSON *value)
{

    cJSON *args = cJSON_GetObjectItem(program, "runtime_args");
    if (args == NULL)
    {
        args = cJSON_CreateObject();
        cJSON_AddItemToObject(program, "runtime_args", args);
    }
    cJSON_AddItemToObject(args, key, value);
    return program;
}

#endif // EWASM_APP_INIT_H
