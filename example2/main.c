#include "config.h"

#include <netdb.h>
#include <stdio.h>

#ifdef HAVE_GETADDRINFO
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#endif /* HAVE_GETADDRINFO */

#define HOSTNAME "www.pdc.kth.se"

int main() {
    unsigned char *ip;
#ifdef HAVE_GETADDRINFO
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;        // AF_INET for IPv4
    hints.ai_socktype = SOCK_STREAM;  // TCP stream sockets
    getaddrinfo(HOSTNAME, NULL, &hints, &res);
    ip = (unsigned char *) &((struct sockaddr_in *) res->ai_addr)->sin_addr;
#else /* HAVE_GETADDRINFO */
    struct hostent *host;
    host = gethostbyname(HOSTNAME);
    ip = host->h_addr_list[0];
#endif /* HAVE_GETADDRINFO */
    printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    return 0;
}
