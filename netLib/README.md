#网络库的概要说明
> 1. Echo借鉴了大量muduo的代码，并对其进行了简化.
> 2. Echo体现了现代c++的两大风格,一是事件回调机制，使用function/bind实现回调机制。二是采用智能指针进行资源管理。

## 安装方法
> 执行make,生成echo头文件和静态库libecho.a
将echo安装到/usr/include/下,将libecho.a放置/usr/lib下
编译时的时候加上-std=c++0x -lecho
