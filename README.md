# Fundamentals
Fundamentals knowledge about program. Here are some of the bugs、problems、tips and so on encountered during development.

[中文](./README_zh.md) | [English](./README.md)



------
- [Fundamentals](#fundamentals)
- [Tips](#tips)
  - [1. Command-line argument parsing](#1-command-line-argument-parsing)
  - [2. signal](#2-signal)
  - [3. thread](#3-thread)
  - [4. compiler optimization](#4-compiler-optimization)
  - [5. C code invoke C++ code](#5-c-code-invoke-c-code)
  - [6. Grpc](#6-grpc)
    - [1）grpc for rust](#1grpc-for-rust)
    - [2）grpc for c++](#2grpc-for-c)




# Tips

## 1. Command-line argument parsing

+ Tag: `C/C++`

`getopt()`、`getopt_long()`、package `argp` 、`docopt`、 `popt`、`argtable`、`argv`and so on

[Case getopt](/Tips/1.argparse/getopt_c/getopt_usage.md)


##  2. signal

`sigaction`、`signal` and so on



## 3. thread

`pthread`、`thread` and so on



## 4. compiler optimization

`likely`、`unlikely` and so on



## 5. C code invoke C++ code

+ Wraps c++ code and call it as a library
+ 
+ 

[Case demo1](/Tips/5.c_invoke_cpp/example1/readme.md)



## 6. Grpc

### 1）grpc for rust

[Case demo1](/Tips/6.grpc/rust/example1/Readme.md)

### 2）grpc for c++

[Case demo2](/Tips/6.grpc/cpp/example1/)

