@echo off
rem.
rem NOTE: Make sure to have compiled grpc and src\csharp\Grpc.sln!
rem.
copy /y vsprojects\vs2013\Debug\grpc_csharp_ext.dll src\csharp\Grpc.IntegrationTesting.Client\bin\Debug
start src\csharp\Grpc.IntegrationTesting.Server\bin\Debug\Grpc.IntegrationTesting.Server.exe --port=9009
src\csharp\Grpc.IntegrationTesting.Client\bin\Debug\Grpc.IntegrationTesting.Client.exe --server_host=localhost --server_port=9009
