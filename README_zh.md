# 基础知识

关于编程的基础知识。这里存放着一些开发过程中时遇见的bug、问题、技巧等。

[中文](./README_zh.md) | [English](./README.md)



------
- [基础知识](#基础知识)
- [技巧](#技巧)
  - [1. 命令行参数解析](#1-命令行参数解析)
  - [2. 信号](#2-信号)
  - [3. 线程](#3-线程)
  - [4. 编译优化](#4-编译优化)
  - [5. C代码调用C++代码](#5-c代码调用c代码)
  - [6. Grpc](#6-grpc)
    - [1）rust语言的grpc](#1rust语言的grpc)
    - [2）c++语言的grpc](#2c语言的grpc)






# 技巧

## 1. 命令行参数解析

`getopt()`函数、`getopt_long()`函数、第三方库`argp` 、`docopt`、 `popt`、`argtable`、`argv`等等。



[getopt()函数文档跳转](/Tips/1.argparse/getopt_c/getopt_usage.md)



## 2. 信号

`sigaction`、`signal`等



## 3. 线程

`pthread`、`thread`等



## 4. 编译优化

`likely`、`unlikely`等



## 5. C代码调用C++代码

+ 将C代码封装起来，作为库来调用\
[案例demo1](./c_invoke_cpp/demo1/readme_zh.md)



## 6. Grpc


### 1）rust语言的grpc

[案例](/Tips/6.grpc/rust/example1/Readme_zh.md)

### 2）c++语言的grpc

[案例](/Tips/6.grpc/cpp/example1/Readme_zh.md)\
[cmake案例](/Tips/6.grpc/cpp/example2/Readme_zh.md)\
[makefile案例](/Tips/6.grpc/cpp/example3/readme_zh.md)
