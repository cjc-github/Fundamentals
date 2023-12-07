#include "grpc_cpp.h"
#include <stdlib.h>
#include <string.h>

int main()
{
    // Register_Request rr;
    Fuzzer myFuzzer;
    myFuzzer.id = 123;
    myFuzzer.fuzzer_type = 1;
    myFuzzer.exec = 0;
    myFuzzer.bitmap_size = 1024;
    myFuzzer.timestamp = 1638768000;
    myFuzzer.compute_node_id = 456;

    // 声明并初始化 ComputeNode 结构体变量
    ComputeNode myComputeNode;
    myComputeNode.id = 456;
    strcpy(myComputeNode.ipaddr, "192.168.0.1");
    myComputeNode.cores = 4;
    myComputeNode.mem_size = 8192;

    // 声明并初始化 Register_Request 结构体变量
    Register_Request myRequest;
    myRequest.fuzzer = myFuzzer;
    myRequest.computernode = myComputeNode;
    register_c(myRequest);
}
