main: cliente servidor

protocolo: protocolo.cpp protocolo.h
	g++ -c protocolo.cpp protocolo.h

lista: lista.cpp lista.h
	g++ -c lista.cpp lista.h

servidor: servidor.cpp servidor.h protocolo lista
	g++ -o servidor servidor.cpp servidor.h protocolo.o lista.o

tserv: servidor
	./servidor 1234

cliente: cliente.cpp
	g++ -o cliente cliente.cpp

tclient: cliente
	./cliente 127.0.0.1 1234

clean:
	rm -rf cliente servidor *.o *.h.gch
