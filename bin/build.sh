gcc -c -Wall ../src/string.c

gcc -c -Wall ../src/data.c

gcc -c -Wall ../src/list.c

gcc -c -Wall ../src/node.c

gcc -c -Wall ../src/linked_list.c

gcc -Wall ./string.o ./data.o ./list.o ./node.o ./linked_list.o ../src/test.c