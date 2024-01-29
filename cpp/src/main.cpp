#include <iostream>
#include <memory>
#include <grpcpp/grpcpp.h>

#include "../build/helloworld.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::CallbackServerContext;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerUnaryReactor;
using grpc::Status;


class GreeterClient {
public:
    GreeterClient(std::shared_ptr<Channel> channel) : stub_(demo::Greeter::NewStub(channel)) {}

    std::string SayHello(const std::string& user) {
        demo::HelloRequest request;
        request.set_name(user);

        demo::HelloReply reply;
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
private:
    std::unique_ptr<demo::Greeter::Stub> stub_;
};


int main() {
    std::cout << "客户端启动成功" << std::endl;
    GreeterClient greeter(grpc::CreateChannel("localhost:9098", grpc::InsecureChannelCredentials()));
    std::string user("world");
    std::string reply = greeter.SayHello(user);
    std::cout << "Greeter received: " << reply << std::endl;
    return 0;
}