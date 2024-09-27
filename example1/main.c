#include <netdb.h>
#include <stdio.h>

int main() {
    struct hostent *host;
    unsigned char *ip;
    host = gethostbyname("www.pdc.kth.se");
    ip = host->h_addr_list[0];
    printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    return 0;
}
