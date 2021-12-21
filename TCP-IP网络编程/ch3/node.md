#### 3.1 分配给套接字的IP地址与端口号
IP，为收发网络数据而分配给计算机的值。
端口号，为区分程序中创建的套接字而分配给套接字的序号。

#### 3.2 地址信息的表示
1. 采用哪一种地址族
2. IP地址是多少
3. 端口号是多少

```c
struct sockaddr_in
{
    sa_family_t     sin_family; //地址族
    uint16_t        sin_port;   //16位TCP/UDP端口号
    struct in_addr  sin_addr;   //32位IP地址
    char            sin_zero[8]; 
}
```

字节序和网络字节序
- 大端序：高位字节存放在低位地址
- 小端序：高位字节存放在高位地址

#### 3.4 网络地址的初始化与分配

