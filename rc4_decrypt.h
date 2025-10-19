#pragma once
#pragma once
#include <vector>
#include <cstdint>
#include "rc4_ksa.h"
#include "rc4_prga.h"

std::vector<uint8_t> rc4_decrypt(const std::vector<uint8_t>& data, const std::vector<uint8_t>& key) {
    // RC4 giải mã cũng giống mã hóa (chỉ cần dùng lại thuật toán với cùng key)
    uint8_t S[256];
    rc4_ksa(key, S);
    uint8_t i = 0, j = 0;
    std::vector<uint8_t> output;
    output.reserve(data.size());
    for (size_t idx = 0; idx < data.size(); ++idx) {
        uint8_t k = rc4_prga(S, i, j);
        output.push_back(data[idx] ^ k);
    }
    return output;
}
