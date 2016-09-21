main: clean cliente servidor

token: token.cpp token.h
	g++ -c token.cpp token.h

protocolo: protocolo.cpp protocolo.h
	g++ -c protocolo.cpp protocolo.h

lista: lista.cpp lista.h
	g++ -c lista.cpp lista.h

tempo: tempo.cpp tempo.h
	g++ -c tempo.cpp tempo.h

servidor: servidor.cpp servidor.h protocolo lista tempo token
	g++ -o servidor servidor.cpp servidor.h protocolo.o lista.o tempo.o token.o

tserv: servidor
	./servidor 1234

cliente: cliente.cpp
	g++ -o cliente cliente.cpp

tclient: cliente
	./cliente 127.0.0.1 1234

clean:
	rm -rf cliente servidor *.o *.h.gch
