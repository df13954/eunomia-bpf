
// Code generated by c-struct-bindgen and ecc - DO NOT EDIT
// See https://github.com/eunomia-bpf/c-struct-bindgen for details.
// struct-bindgen versions: 0.1.0
// source file path: sigsnoop.bpf.o
#ifndef __STRUCT_MARSHAL_SIGSNOOP_BPF_O_H__
#define __STRUCT_MARSHAL_SIGSNOOP_BPF_O_H__
    
#include <assert.h>
#include <string.h>
#include <stdint.h>

struct event {
    unsigned int pid;
    unsigned int tpid;
    int sig;
    int ret;
    char comm[16];
} __attribute__((packed));
static_assert(sizeof(struct event) == 32, "Size of event2 is not 32");

#endif

