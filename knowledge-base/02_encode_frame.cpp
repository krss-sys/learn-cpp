#include <arpa/inet.h>

#include <cstdint>
#include <iostream>
#include <span>
#include <vector>

std::vector<uint8_t> encode_frame(std::span<const uint8_t> payload) {
    uint32_t len = payload.size();
    uint32_t lenNetwork = htonl(len);

    std::vector<uint8_t> frame;

    const uint8_t* lenBytes = reinterpret_cast<const uint8_t*>(&lenNetwork);
    for (int i = 0; i < 4; i++) {
        frame.push_back(lenBytes[i]);
    }

    for (uint8_t b : payload) {
        frame.push_back(b);
    }

    return frame;
}

void inFrame(const std::vector<uint8_t>& frame) {
    for (uint8_t b : frame) {
        printf("%02X ", b);
    }
    std::cout << "\n";
}

int main() {
    std::string msg = "hello";
    std::span<const uint8_t> payload(reinterpret_cast<const uint8_t*>(msg.data()), msg.size());
    std::vector<uint8_t> frame = encode_frame(payload);

    std::cout << "payload: " << msg << " (size = " << msg.size() << ")\n";
    std::cout << "frame: ";
    inFrame(frame);

    return 0;
}