#include <iostream>
#include <memory>
#include <string>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

#include <grpcpp/grpcpp.h>

#ifdef BAZEL_BUILD
#include "examples/protos/helloworld.grpc.pb.h"
#else
#include "helloworld.grpc.pb.h"
#endif

ABSL_FLAG(std::string, target, "localhost:50051", "Server address");

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloworld::Greeter;
using helloworld::HelloReply;
using helloworld::HelloRequest;

using helloworld::FUZZER_AFL;
using helloworld::RegisterRequest;
using helloworld::RegisterResponse;

class GreeterClient {
 public:
  GreeterClient(std::shared_ptr<Channel> channel)
      : stub_(Greeter::NewStub(channel)) {}
  std::string SayHello(const std::string& user) {
    HelloRequest request;
    request.set_name(user);
    HelloReply reply;
    ClientContext context;
    Status status = stub_->SayHello(&context, request, &reply);

    if (status.ok()) {
      return reply.message();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

  std::string Register() {
    RegisterRequest request;
    // 赋值,模糊器编号1
    request.mutable_fuzzer()->set_id(100);
    // 赋值，模糊器类型为AFL
    request.mutable_fuzzer()->set_fuzzer_type(FUZZER_AFL);
    // 模糊器已执行数位666次
    request.mutable_fuzzer()->set_exec(666);
    // 模糊器局部覆盖率位图1M
    request.mutable_fuzzer()->set_bitmap_size(1024000);
    // 模糊器心跳30秒
    request.mutable_fuzzer()->set_timestamp(30);
    // 模糊器所属节点5
    request.mutable_fuzzer()->set_compute_node_id(5);

    //计算节点编号0
    request.mutable_compute_node()->set_id(0);
    // ip地址
    request.mutable_compute_node()->set_ipaddr("172.16.1.1:7890");
    // cpu核心数
    request.mutable_compute_node()->set_cores(4);
    // 可用内存数
    request.mutable_compute_node()->set_mem_size(20480);

    RegisterResponse reply;
    ClientContext context;
    Status status = stub_->Register(&context, request, &reply);

    std::string msg ="ok";
    if (status.ok()) {
      msg += "succsess:" + std::to_string(reply.success()) + "\n";
      msg += "fuzzer_id:" + std::to_string(reply.fuzzer_id()) + "\n";
      msg += "compute_node _id:" + std::to_string(reply.compute_node_id());
      return msg;
      // if(reply.success()){
      //   return msg;
      // }
      return msg;
      // return reply.success();
      //return reply.message();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

 private:
  std::unique_ptr<Greeter::Stub> stub_;
};

int main(int argc, char** argv) {
  absl::ParseCommandLine(argc, argv);
  std::string target_str = absl::GetFlag(FLAGS_target);
  GreeterClient greeter(
      grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
  std::string user("曹建超");
  std::string reply = greeter.SayHello(user);
  std::cout << "服务端返回: " << reply << std::endl;

  reply = greeter.Register();
  std::cout << "服务端返回: " << reply << std::endl;
  return 0;
}
