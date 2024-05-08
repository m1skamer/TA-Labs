#include <iostream>
#include <string>

std::string decrypt(const std::string& input) {
    std::string message = input;

    for (int i = 0; i < message.length(); ++i) {
        message[i] ^= 0b1001001;
        message[i] -= 0x1A - i;
        message[i] ^= 0b1100100;
        message[i] += 2 + i;
        message[i] = message[i] << (2 >> 1);
        i ? --message[i] : message[i];
    }

    return message;
}

int main() {
    std::string encrypted = "%9$$/";
    std::string decrypted = decrypt(encrypted);
    std::cout << "Decrypted message: " << decrypted << std::endl;

    return 0;
}