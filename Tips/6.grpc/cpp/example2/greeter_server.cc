#include <iostream>
#include <memory>
#include <string>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#ifdef BAZEL_BUILD
#include "examples/protos/helloworld.grpc.pb.h"
#else
#include "helloworld.grpc.pb.h"
#endif

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using helloworld::Greeter;
using helloworld::HelloReply;
using helloworld::HelloRequest;
using helloworld::RegisterRequest;
using helloworld::RegisterResponse;

ABSL_FLAG(uint16_t, port, 50051, "Server port for the service");

class GreeterServiceImpl final : public Greeter::Service {
  Status SayHello(ServerContext* context, const HelloRequest* request,
                  HelloReply* reply) override {
    std::string prefix("您好，尊敬的用户:");
    reply->set_message(prefix + request->name());
    return Status::OK;
  }

  Status Register(ServerContext* context, const RegisterRequest* request,
                  RegisterResponse* reply) override {
    std::cout << "fuzzer().id(): " << request->fuzzer().id() << std::endl;
    std::cout << "fuzzer().fuzzer_type(): " << request->fuzzer().fuzzer_type() << std::endl;
    std::cout << "fuzzer().exec(): " << request->fuzzer().exec() << std::endl;
    std::cout << "fuzzer().bitmap_size(): " << request->fuzzer().bitmap_size() << std::endl;
    std::cout << "fuzzer().timestamp(): " << request->fuzzer().timestamp() << std::endl;
    std::cout << "fuzzer().compute_node_id(): " << request->fuzzer().compute_node_id() << std::endl;
    std::cout << "compute_node().id(): " << request->compute_node().id() << std::endl;
    std::cout << "compute_node().ipaddr(): " << request->compute_node().ipaddr() << std::endl;
    std::cout << "compute_node().cores(): " << request->compute_node().cores() << std::endl;
    std::cout << "compute_node().mem_size(): " << request->compute_node().mem_size() << std::endl;

    reply->set_success(true);
    reply->set_fuzzer_id(2);
    reply->set_compute_node_id(4);
    return Status::OK;
  }
};

void RunServer(uint16_t port) {
  std::string server_address = absl::StrFormat("0.0.0.0:%d", port);
  GreeterServiceImpl service;

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  server->Wait();
}

int main(int argc, char** argv) {
  // absl
  absl::ParseCommandLine(argc, argv);
  RunServer(absl::GetFlag(FLAGS_port));
  return 0;
}
