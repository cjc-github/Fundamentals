#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#ifdef BAZEL_BUILD
#include "examples/protos/grpc_scheduler.grpc.pb.h"
#else
#include "grpc_scheduler.grpc.pb.h"
#endif
#include "grpc_cpp.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using grpc_scheduler::SchedulerService;

using grpc_scheduler::FUZZER_AFL;
using grpc_scheduler::RegisterRequest;
using grpc_scheduler::RegisterResponse;

class SchedulerClient {
 public:
  SchedulerClient(std::shared_ptr<Channel> channel)
      : stub_(SchedulerService::NewStub(channel)) {}
  std::string Register(Register_Request rr) {
    RegisterRequest request;
    
    request.mutable_fuzzer()->set_id(rr.fuzzer.id);
    if(rr.fuzzer.fuzzer_type==1){
        request.mutable_fuzzer()->set_fuzzer_type(FUZZER_AFL);
    }
    request.mutable_fuzzer()->set_exec(rr.fuzzer.exec);
    request.mutable_fuzzer()->set_bitmap_size(rr.fuzzer.bitmap_size);
    request.mutable_fuzzer()->set_timestamp(rr.fuzzer.timestamp);
    request.mutable_fuzzer()->set_compute_node_id(rr.fuzzer.compute_node_id);

    request.mutable_compute_node()->set_id(rr.computernode.id);
    request.mutable_compute_node()->set_ipaddr(rr.computernode.ipaddr);
    request.mutable_compute_node()->set_cores(rr.computernode.cores);
    request.mutable_compute_node()->set_mem_size(rr.computernode.mem_size);

    RegisterResponse reply;
    ClientContext context;
    Status status = stub_->Register(&context, request, &reply);

    std::string msg ="ok";
    if (status.ok()) {
      msg += "succsess:" + std::to_string(reply.success()) + "\n";
      msg += "fuzzer_id:" + std::to_string(reply.fuzzer_id()) + "\n";
      msg += "compute_node _id:" + std::to_string(reply.compute_node_id());
      return msg;
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

 private:
  std::unique_ptr<SchedulerService::Stub> stub_;
};

void register_c(Register_Request rr){
  std::string target_str = "127.0.0.1:50051";
  // target_str ip:port
  SchedulerClient greeter(grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
  std::string reply = greeter.Register(rr);
  std::cout << "服务端返回: " << reply << std::endl;
}