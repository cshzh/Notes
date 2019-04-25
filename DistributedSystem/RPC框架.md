# 集群

> **VS:** Virtual Server, Director Server(DS), Dispather(调度器), Load Balancer
>
> **RS:** Real Server(LVS), upstream server(nginx), backend server(haproxy)
>
> **CIP:** Client IP
>
> **VIP:** Virtual Server IP
>
> **DIP:** Director IP
>
> **RIP:** Real Server IP

# RPC框架

### **实现RPC需要用到的技术**

一个成熟的RPC框架需要考虑的问题有很多，这里只介绍实现一个远程调用需要用到的基本技术，感兴趣的朋友可以找一些开源的RPC框架代码来看下。

**动态代理**

生成 client stub和server stub需要用到Java 动态代理技术，我们可以使用JDK原生的动态代理机制，可以使用一些开源字节码工具框架 如：CgLib、Javassist等。

**序列化** 

为了能在网络上传输和接收 Java对象，我们需要对它进行序列化和反序列化操作。

可以使用Java原生的序列化机制，但是效率非常低，推荐使用一些开源的、成熟的序列化技术，例如：protobuf、Thrift、hessian、Kryo、Msgpack

**NIO**

当前很多RPC框架都直接基于netty这一IO通信框架，比如阿里巴巴的HSF、dubbo，Hadoop Avro，推荐使用Netty 作为底层通信框架。

**服务注册中心** 

可选技术： Redis、Zookeeper、Consul、Etcd

参考资料 ：https://www.jianshu.com/p/dbfac2b876b1

### **开源RPC框架**

**Dubbo**

Dubbo 是阿里巴巴公司开源的一个Java高性能优秀的服务框架，使得应用可通过高性能的 RPC 实现服务的输出和输入功能，可以和 Spring框架无缝集成。目前已经进入Apache孵化器。

**Motan**

Motan是新浪微博开源的一个Java RPC框架。2016年5月开源。Motan 在微博平台中已经广泛应用，每天为数百个服务完成近千亿次的调用。

**gRPC**

gRPC是Google开发的高性能、通用的开源RPC框架，其由Google主要面向移动应用开发并基于HTTP/2协议标准而设计，基于ProtoBuf(Protocol Buffers)序列化协议开发，且支持众多开发语言。本身它不是分布式的，所以要实现上面的框架的功能需要进一步的开发。

**Thrift**

Thrift是Apache的一个跨语言的高性能的服务框架，也得到了广泛的应用。