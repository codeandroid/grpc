#include <exception>
#include <iostream>
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>
#include <grpc++/server_credentials.h>
int main(int argc, char** argv)
{
   try {
      grpc_init();

      {
         grpc::ServerBuilder builder;
         builder.AddPort("0.0.0.0:9009", grpc::InsecureServerCredentials());
         auto server = builder.BuildAndStart();
         server->Shutdown();
         server->Wait();
         server.reset();
      }

      grpc_shutdown();
   }
   catch (std::exception& ex)
   {
      std::cerr << "ERROR: " << ex.what() << std::endl;
   }
   return 0;
}
