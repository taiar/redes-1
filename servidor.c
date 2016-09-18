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

void fill(const struct sockaddr *addr, char *line) {
	int version;
	char str[INET6_ADDRSTRLEN];
	unsigned short port;

	if(addr->sa_family == AF_INET) {
		version = 4;
		struct sockaddr_in *addr4 = (struct sockaddr_in *)addr;
		if(!inet_ntop(addr4->sin_family, &(addr4->sin_addr), str, INET6_ADDRSTRLEN)) logexit("ntop");
		port = ntohs(addr4->sin_port);
	} else {
		version = 6;
		struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *)addr;
		if(!inet_ntop(addr6->sin6_family, &(addr6->sin6_addr), str, INET6_ADDRSTRLEN)) logexit("ntop");
		port = ntohs(addr6->sin6_port);
	}

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

		char line2[BUFSZ];
		while(strcmp(line2, "sair\n") != 0) {
			if(recv(r, line2, BUFSZ, 0) <= 0) {
				// Fecha ambas as direções da conexão baseada no socket r
				close(r);
			} else {
				printf("%s\n", line2);
			}
		}
  }

  exit(EXIT_SUCCESS);
}