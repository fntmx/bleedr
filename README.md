# Installation
Dependencies will differ based on your platform, but the core library used in bleedr is libpcap (pcap). Unix based systems (including MacOS) will only need to install lex and bison, however Windows systems will need the windows version of lex and bison, as well as npcap - which serves as a wrapper around libpcap.

## Binaries 
> :warning: **This will be available when bleedr is released**


## Source

### Windows
#### Dependencies
* npcap needs to be downloaded and installed: https://nmap.org/npcap/
* Win flex-bison needs to be downloaded and installed: https://github.com/lexxmark/winflexbison

### Unix/Mac
#### Dependencies

* Unix lex-bison needs to be downloaded and installed. For example, for apt ```sudo apt-get install bison flex```

# Building (TODO)

To build and ultimately execute bleedr, simply navigate to the root of the bleedr directory and run the following. These commands will be the same, regardless of the system you are on. Dependencies must be installed (platform dependent) before these commands are run.

* ```git submodule update --init``` (clone libraries)


### Windows

### Unix/Mac
* ```cmake -B ./build -S .```

# Writers
## JSON Writer
You can pass an argument to bleedr that turns on JSON output. You must also pass in a parameter that specifies where to save the .json output. The JSON looks like so:

```json
{
  "data": [
    {
      "link_layer": {
        "meta": {
          "destination_mac": "94:db:56:86:c7:44",
          "ether_type": "0x0800",
          "source_mac": "10:bf:48:80:68:2d"
        },
        "protocol": "Ethernet"
      },
      "network_layer": {
        "meta": {
          "destination_ip": "94.149.169.160",
          "source_ip": "92.65.112.172"
        },
        "protocol": "IPv4"
      },
      "transport_layer": {
        "meta": {
          "ack_flag": true,
          "destination_port": "369",
          "fin_flag": true,
          "sequence_number": "841649509",
          "source_port": "23882",
          "syn_flag": false
        },
        "protocol": "TCP"
      }
    },
    {
      "link_layer": {
        "meta": {
          "destination_mac": "10:bf:48:80:68:2d",
          "ether_type": "0x0800",
          "source_mac": "ec:ad:e0:94:f6:50"
        },
        "protocol": "Ethernet"
      },
      "network_layer": {
        "meta": {
          "destination_ip": "78.168.76.154",
          "source_ip": "246.126.85.30"
        },
        "protocol": "IPv4"
      },
      "transport_layer": {
        "meta": {
          "ack_flag": false,
          "destination_port": "64730",
          "fin_flag": false,
          "sequence_number": "3275329088",
          "source_port": "41448",
          "syn_flag": false
        },
        "protocol": "TCP"
      }
    }
  ]
}
```

## Sockets
You can pass an argument to bleedr that turns on socket streaming. For example, if you were running bleedr on a remote computer and wanted to stream the packet capture to another computer on another network - you would be able to use the socket writer to achieve this. (TODO: Add TLS/SSL support)
