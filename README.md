# grpc小demo
## 服务端
使用go+grpc作为服务端
### 运行方法
- 使用make protoc根据proto文件生成代码
- 使用go run src/main/main.go运行服务端
## 客户端
使用Cpp+grpc作为客户端
### 运行方法
- 运行下面指令生成可执行文件
```shell
cd cpp
mkdir build
cd build
cmake ..
make -j4
```
- 运行可执行文件
./client
