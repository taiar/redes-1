main: cliente servidor

servidor: servidor.c
	gcc -o servidor servidor.c

tserv: servidor
	./servidor 1234

cliente: cliente.c
	gcc -o cliente cliente.c

tclient: cliente
	./cliente 127.0.0.1 1234

clean:
	rm -rf cliente servidor
