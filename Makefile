main: cliente servidor

protocolo: protocolo.c protocolo.h
	gcc -c protocolo.c protocolo.h

lista: lista.c lista.h
	gcc -c lista.c lista.h

servidor: servidor.c servidor.h protocolo lista
	gcc -o servidor servidor.c servidor.h protocolo.o lista.o

tserv: servidor
	./servidor 1234

cliente: cliente.c
	gcc -o cliente cliente.c

tclient: cliente
	./cliente 127.0.0.1 1234

clean:
	rm -rf cliente servidor *.o *.h.gch
