#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#ifdef BAZEL_BUILD
#include "examples/protos/grpc_scheduler.grpc.pb.h"
#else
#include "grpc_scheduler.grpc.pb.h"
#endif

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc_scheduler::SchedulerService ;

using grpc_scheduler::RegisterRequest;
using grpc_scheduler::RegisterResponse;


class SchedulerServiceImpl final : public SchedulerService::Service {
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
  std::string server_address = "0.0.0.0:50051";
  SchedulerServiceImpl service;

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
  RunServer(50051);
  return 0;
}
