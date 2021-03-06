#include <cstdio>
#include <pcap.h>
#include "include/io/json_writer.h"

extern "C" {
#include "include/types.h"
#include "include/common/interface.h"
#include "include/common/packet.h"
#include "include/link_layer/wifi.h"
}

Bleedr::IO::JsonWriter *jsonWriter;

int main() {
    char err_buff[PCAP_ERRBUF_SIZE];
    auto *pcap_iface = (pcap_if_t *) malloc(sizeof(pcap_if_t));
    auto *bleedr = (Bleedr_t *) malloc(sizeof(Bleedr_t));

    /*
    if (pcap_init(0x00000000U, err_buff) == -1) {
        fprintf(stderr, "Initialise Error: %s\n", err_buff);
    }*/

    get_interface(err_buff, pcap_iface);

    pcap_t *pcap_h = pcap_create(pcap_iface->name, err_buff);
    if (pcap_h == nullptr) {
        fprintf(stderr, "Create Error: %s\n", err_buff);
    }

    activate_interface(pcap_h);

    pcap_dumper_t *pcap_dump_handle = pcap_dump_open(pcap_h, "mydump.pcap");
    if (pcap_dump_handle == nullptr) {
        fprintf(stderr, "Error Opening Dump\n");
        return -1;
    }

    bleedr->pcap_h = pcap_h;
    bleedr->pcap_dump_h = pcap_dump_handle;

    // TODO: JsonWriter filename comes from somewhere else
    jsonWriter = new Bleedr::IO::JsonWriter("dump.json", bleedr);

    pcap_loop(pcap_h, 0, packet_handler, (unsigned char *) bleedr);

    delete jsonWriter;

    return 0;
}