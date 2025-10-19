#pragma once
#pragma once
#include <cstdint>

uint8_t rc4_prga(uint8_t S[256], uint8_t& i, uint8_t& j) {
    i = (i + 1) & 0xFF;
    j = (j + S[i]) & 0xFF;
    std::swap(S[i], S[j]);
    return S[(S[i] + S[j]) & 0xFF];
}