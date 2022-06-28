CFLAGS = -fPIC -g -c
TARGET = *.so *.o *.class tester
JAVA_HOME = $(shell readlink -f /usr/bin/javac | sed "s:bin/javac::")
JAVA_INCLUDE = $(JAVA_HOME)/include
JAVA_INCLUDE_LINUX = $(JAVA_INCLUDE)/linux
 
all: test
install: lib_shared_CPUScaler

ryzen.o: ryzen.c ryzen.h
	gcc $(CFLAGS) ryzen.c -lm

lib_shared_CPUScaler:
	gcc $(CFLAGS) -I $(JAVA_INCLUDE) -I$(JAVA_INCLUDE_LINUX) CPUScaler.c arch_spec.c msr.c dvfs.c -lc -lm
	gcc -I $(JAVA_INCLUDE) -I $(JAVA_INCLUDE_LINUX) -shared -Wl,-soname,libCPUScaler.so -o libCPUScaler.so CPUScaler.o arch_spec.o msr.o dvfs.o -lc -lm

test: tester.c ryzen.o
	gcc $(CFLAGS) tester.c -lm
	gcc -o tester tester.o ryzen.o -lm
	sudo ./tester
clean:
	rm -f $(TARGET)