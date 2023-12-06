#ifndef TESTCLASS_H
#define TESTCLASS_H
#include <stdio.h>
#include <stdint.h>

//#include <grpcpp/grpcpp.h>

// #ifdef BAZEL_BUILD
// #include "examples/protos/grpc_scheduler.grpc.pb.h"
// #else
// #include "grpc_scheduler.grpc.pb.h"
// #endif
// #include "test_class.h"

typedef struct fuzzer{
    uint64_t id;
    int fuzzer_type;
    uint64_t exec;
    uint64_t bitmap_size;
    uint64_t timestamp;
    uint64_t compute_node_id;
}Fuzzer;

typedef struct compute_node{
    uint64_t id;
    char ipaddr[50];
    uint32_t cores; 
    uint64_t mem_size;
}ComputeNode;


typedef struct register_request{
    Fuzzer fuzzer;
    ComputeNode computernode;
}Register_Request;

void test(Register_Request rr);

#endif