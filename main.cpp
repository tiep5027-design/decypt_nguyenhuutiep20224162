#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "rc4_decrypt.h"

// Hàm chuyển chuỗi hex (cách nhau dấu cách) thành vector<uint8_t>
std::vector<uint8_t> hexStringToBytes(const std::string& hexStr) {
    std::vector<uint8_t> bytes;
    std::istringstream iss(hexStr);
    std::string hexByte;
    while (iss >> hexByte) {
        uint8_t byte = static_cast<uint8_t>(std::stoul(hexByte, nullptr, 16));
        bytes.push_back(byte);
    }
    return bytes;
}

int main() {
    std::string hexInput, key;

    std::cout << "Nhap ciphertext (hex, moi byte cach nhau boi dau cach): ";
    std::getline(std::cin, hexInput);

    std::cout << "Nhap key: ";
    std::getline(std::cin, key);

    std::vector<uint8_t> ciphertext = hexStringToBytes(hexInput);
    std::vector<uint8_t> decrypted = rc4_decrypt(
        ciphertext, std::vector<uint8_t>(key.begin(), key.end())
    );

    std::cout << "Decrypted text: ";
    for (uint8_t c : decrypted)
        std::cout << static_cast<char>(c);
    std::cout << std::endl;
    return 0;
}