# Usage:
```
mkdir -p cmake/build
pushd cmake/build
cmake -DCMAKE_PREFIX_PATH=$MY_INSTALL_DIR ../..
make -j 4
```

Then, it will generate the target executable file in `cmake/build`

```
./greeter_server
./greeter_client
```

note：This is the cmake compilation