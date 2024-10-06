#include <netdb.h>
#include <stdio.h>

#include "config.h"

#ifdef WITH_LIBXML2
#include <libxml/xmlwriter.h>

#define MY_ENCODING "UTF-8"

void gen_xml(char* ip_address) {
    xmlTextWriterPtr writer;
    xmlBufferPtr buffer;

    buffer = xmlBufferCreate();
    writer = xmlNewTextWriterMemory(buffer, 0);

    xmlTextWriterStartDocument(writer, NULL, MY_ENCODING, NULL);
    xmlTextWriterStartElement(writer, BAD_CAST "IPAddress");
    xmlTextWriterWriteString(writer, BAD_CAST ip_address);
    xmlTextWriterEndElement(writer);
    xmlTextWriterEndDocument(writer);

    printf("%s", (const char *)buffer->content);

    xmlFreeTextWriter(writer);
    xmlBufferFree(buffer);
}
#endif

int main() {
    struct hostent *host;
    unsigned char *ip;
    host = gethostbyname("www.pdc.kth.se");
    ip = host->h_addr_list[0];
#ifdef WITH_LIBXML2
    {
      char buf[16];
      sprintf(buf, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
      gen_xml(buf); /* uses libxml2 to print ip address in xml */
    }
#else
    printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
#endif
    return 0;
}
