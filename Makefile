CFLAGS = -fPIC -g -c
TARGET = *.so *.o *.class tester
JAVA_HOME = $(shell readlink -f /usr/bin/javac | sed "s:bin/javac::")
JAVA_INCLUDE = $(JAVA_HOME)/include
JAVA_INCLUDE_LINUX = $(JAVA_INCLUDE)/linux
 
all: libJRAPL
install: libJRAPL
	sudo mkdir -p /usr/lib/jni
	sudo cp libJRAPL.so /usr/lib/jni/

ryzen.o: ryzen.c ryzen.h
	gcc $(CFLAGS) ryzen.c -lm

JRAPL.o: JRAPL.c JRAPL.h
	gcc $(CFLAGS) -I $(JAVA_INCLUDE) -I$(JAVA_INCLUDE_LINUX) JRAPL.c -lm

libJRAPL: ryzen.o JRAPL.o
	gcc -I $(JAVA_INCLUDE) -I $(JAVA_INCLUDE_LINUX) -shared -Wl,-soname,libJRAPL.so -o libJRAPL.so ryzen.o JRAPL.o -lc -lm

test: tester.c ryzen.o
	gcc $(CFLAGS) tester.c -lm
	gcc -o tester tester.o ryzen.o -lm
	sudo ./tester
clean:
	rm -f $(TARGET)