CC = gcc
AR = ar
FLAGS = -g -Wall
LIB_LOOPS = advancedClassificationLoop.o basicClassification.o
LIB_REC = advancedClassificationRecursion.o basicClassification.o

all : maindloop maindrec loops loopd recursived recursives mains

.PHONY : clean all

loops : libclassloops.a
libclassloops.a : $(LIB_LOOPS)
	$(AR) rcs libclassloops.a $(LIB_LOOPS)

loopd : libclassloops.so
libclassloops.so : $(LIB_LOOPS)
	$(CC) -shared -o libclassloops.so $(LIB_LOOPS)

recursived : libclassrec.so
libclassrec.so : $(LIB_REC)
	$(CC) -shared -o libclassrec.so $(LIB_REC)

maindloop : main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so

maindrec : main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so

mains : main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a

main.o : main.c NumClass.h
	$(CC) $(FLAGS) -c main.c

recursives : libclassrec.a
libclassrec.a : $(LIB_REC)
	$(AR) rcs libclassrec.a $(LIB_REC)

advancedClassificationRecursion.o : advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -fPIC -c advancedClassificationRecursion.c
advancedClassificationLoop.o : advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -fPIC -c advancedClassificationLoop.c
basicClassification.o : basicClassification.c NumClass.h
	$(CC) $(FLAGS) -fPIC -c basicClassification.c

clean :
	rm *.o *.a *.so maindloop maindrec mains
