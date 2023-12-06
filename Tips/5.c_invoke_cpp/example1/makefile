all:
	g++ test_class.cpp -shared -o libtestclass.so -I./ -fPIC
	g++ TestWrapper.c -shared -o libmyclass.so -L./ -ltestclass -fPIC  -Xlinker -rpath=./
	gcc main.c -o main -lmyclass -L./ -I . -Xlinker -rpath=./ 

clean:
	rm -rf libmyclass.so
	rm -rf libtestclass.so
	rm -rf main
