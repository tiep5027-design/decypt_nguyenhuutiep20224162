#pragma once
#pragma once
#include <vector>
#include <cstdint>

void rc4_ksa(const std::vector<uint8_t>& key, uint8_t S[256]) {
    for (int i = 0; i < 256; ++i) S[i] = i;
    uint8_t j = 0;
    for (int i = 0; i < 256; ++i) {
        j = (j + S[i] + key[i % key.size()]) & 0xFF;
        std::swap(S[i], S[j]);
    }
}