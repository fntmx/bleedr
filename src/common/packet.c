#include <stdio.h>
#include <pcap.h>
#include "../../include/types.h"
#include "../../include/ethernet.h"
#include "../../include/wifi.h"

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    Bleedr_t *bleedr = (Bleedr_t *) param;

    pcap_dump((u_char *) bleedr->pcap_dump_h, header, pkt_data);

    int pcap_link_type = pcap_datalink(bleedr->pcap_h);
    if (pcap_link_type == PCAP_ERROR_NOT_ACTIVATED) {
        fprintf(stderr, "Attempting to get link type from handle that has not been activated");
    }

    bleedr->packet_len = header->len;
    bleedr->packet_data = pkt_data;

    // For link types see: https://www.tcpdump.org/linktypes.html
    switch (pcap_link_type) {
        case 1:
            handle_ethernet(bleedr);
            break;
        case 105:
            handle_wifi(bleedr);
            break;
        default:
            //TODO: return pcap_error here, link-type encapsulating packet is not supported
            break;
    }
}