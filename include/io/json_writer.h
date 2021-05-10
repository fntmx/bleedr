#ifndef BLEEDR_JSON_WRITER_H
#define BLEEDR_JSON_WRITER_H

#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include "../types.h"
#include "../link_layer/ethernet.h"
#include "../network_layer/ip.h"
#include "../transport_layer/tcp.h"

using namespace nlohmann;

namespace Bleedr {
    namespace IO {
        class JsonWriter {
        private:
            Bleedr_t *bleedr;
            std::ofstream write_file;
            bool with_raw;
        public:
            std::string filename;

            JsonWriter(std::string, Bleedr_t *, bool with_raw = false);

            json Read() const;

            void Write();

            unsigned long long Filesize() const;
        };
    }
}

extern Bleedr::IO::JsonWriter *jsonWriter;

#endif //BLEEDR_JSON_WRITER_H
