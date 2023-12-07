#ifndef TESTCLASS_H
#define TESTCLASS_H
#include <stdio.h>
#include <stdint.h>

// enum FuzzerType {
//     FUZZER_UNKNOWN = 0,
//     FUZZER_AFL = 1,
//     FUZZER_ANGORA = 2,
//     FUZZER_QSYM = 3,
//     FUZZER_LIBFUZZER = 4,
//     FUZZER_HONGGFUZZ = 5,
//     FUZZER_AFLFAST = 6,
//     FUZZER_FAIRFUZZ = 7,
//     FUZZER_RADAMSA = 8
// };

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

#ifdef __cplusplus
extern "C" {
#endif 

void register_c(Register_Request rr);

#ifdef __cplusplus
}
#endif 

#endif