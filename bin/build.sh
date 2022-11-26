gcc -c -Wall ../src/string.c

gcc -c -Wall ../src/data.c

gcc -c -Wall ../src/list.c

gcc -c -Wall ../src/node.c

gcc -Wall ./string.o ./data.o ./list.o ./node.o ../src/test.c