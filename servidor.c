#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSZ 1024

void logexit(const char *str) {
	perror(str);
	exit(EXIT_FAILURE);
}

void fill(const struct sockaddr *addr, char *line)
{

	// Inteiro que guardará a versão. Caso AF_INET, versão = 4.
	int version;

	/* String que guarda o resultado da conversão do struct de endereço de rede
	para um string.
	*/
	char str[INET6_ADDRSTRLEN];

	// Short que guardará o número da porta utilizada.
	unsigned short port;


	/* Caso a família do endereço seja AF_INET. A maior parte das aplicações
	baseadas no uso da internet utilizam esta família */
	if(addr->sa_family == AF_INET) {

		// IPv4, protocolo versão 4.
		version = 4;

		/* Neste caso, podemos utilizar o struct do tipo sockaddr_in
		para fazer uma cópia do primeiro parâmetro, addr. Por exemplo,
		o struct in_addr, que guarda um endereço de IPv4, é um unsigned long,
		enquanto o struct in6_addr, que guarda um endereço de IPv6, é
		um unsigned char[16].
		*/
		struct sockaddr_in *addr4 = (struct sockaddr_in *)addr;

		/* A função inet_ntop converte endereços IPv4 e IPv6 da forma
		binária (rede) para a forma de texto. (Lembrar: Network TO
		Presentation)

		O primeiro parâmetro é a família do endereço;
		O segundo paràmetro é o endereço de rede;
		O terceiro parâmetro é o buffer que vamos utilizar para guardar
		o resultado da conversão;
		O quarto parâmetro é o tamanho do buffer, que foi padronizado
		para INET6 para contemplar o IPv6.

		É utilizada a função logexit para retornar o tipo de erro
		relacionado à ntop.
		*/
		if(!inet_ntop(addr4->sin_family, &(addr4->sin_addr),
				str, INET6_ADDRSTRLEN)) {
			logexit("ntop");
		}

		/* O número da porta é o resultado da conversão
		de sin_port, contida no struct addr4, utilizando a função
		ntohs (Network TO Host Short */
		port = ntohs(addr4->sin_port);
	} else {

		// IPv6, protocolo versão 6.
		version = 6;
		/* Neste caso, podemos utilizar o struct do tipo sockaddr_in6
		para fazer uma cópia do primeiro parâmetro, addr. Por exemplo,
		o struct in_addr, que guarda um endereço de IPv4, é um unsigned long,
		enquanto o struct in6_addr, que guarda um endereço de IPv6, é
		um unsigned char[16].
		*/
		struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *)addr;

		/* A função inet_ntop converte endereços IPv4 e IPv6 da forma
		binária (rede) para a forma de texto. (Lembrar: Network TO
		Presentation)

		O primeiro parâmetro é a família do endereço;
		O segundo paràmetro é o endereço de rede;
		O terceiro parâmetro é o buffer que vamos utilizar para guardar
		o resultado da conversão;
		O quarto parâmetro é o tamanho do buffer, que foi padronizado
		para INET6 para contemplar o IPv6.

		É utilizada a função logexit para retornar o tipo de erro
		relacionado à ntop.
		*/
		if(!inet_ntop(addr6->sin6_family, &(addr6->sin6_addr),
				str, INET6_ADDRSTRLEN))
		{
			logexit("ntop");
		}

		/* O número da porta é o resultado da conversão
		de sin_port, contida no struct addr6, utilizando a função
		ntohs (Network TO Host Short */

		port = ntohs(addr6->sin6_port);
	}

	/* Ao final, o buffer 'line' recebe a versão do protocolo de internet
	(4 ou 6),o endereço de rede e o número da porta,
	que serão posteriormente impressas na função clientfunc, que é chamada
	por uma thread no main.
	*/
	sprintf(line, "IPv%d %s %hu\n", version, str, port);
}

int main(int argc, char const *argv[]) {
  int porta = atoi(argv[1]);

  int s;
  s = socket(AF_INET, SOCK_STREAM, 0);
  if(s == -1) logexit("socket");

  setsockopt(s, SOL_SOCKET, SO_REUSEADDR, "eth1", 4);

  struct in_addr addr;
  if(inet_pton(AF_INET, "127.0.0.1", &addr) < 1) logexit("pton");
  struct sockaddr_in dst;

  dst.sin_family = AF_INET;
  dst.sin_port = htons(porta);
  dst.sin_addr = addr;

  struct sockaddr *sa_dst = (struct sockaddr *)&dst;

  if(bind(s, sa_dst, sizeof(*sa_dst))) logexit("bind");
  if(listen(s, 0)) logexit("listen");
  printf("Aguardando...\n");

  while (1) {
		struct sockaddr raddr;
		socklen_t rlen = sizeof(struct sockaddr);

    int r = accept(s, &raddr, &rlen);

    struct sockaddr_in *raddrptr = (struct sockaddr_in *) &raddr;

    char line[BUFSZ];

    fill((struct sockaddr *)raddrptr, line);
    printf("connection from %s", line);
  }

  return 0;
}
