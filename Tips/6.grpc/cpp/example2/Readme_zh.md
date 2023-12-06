# 使用:
```
mkdir -p cmake/build
pushd cmake/build
cmake -DCMAKE_PREFIX_PATH=$MY_INSTALL_DIR ../..
make -j 4
```

然后，可执行目标文件在`cmake/build`目录中出现

```
./greeter_server
./greeter_client
```

注意：这是cmake编译方式