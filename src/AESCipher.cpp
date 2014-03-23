//
//  AESCipher.cpp
//  theciphers
//
//  Created by Igor de Oliveira Sa on 23/03/14.
//  Copyright (c) 2014 Igor de Oliveira Sa. All rights reserved.
//

#include "the_ciphers.h"

std::shared_ptr<byte> AESCipher::Cipher(byte *message, size_t message_size, size_t * ciphered_message_size) {
    return std::shared_ptr<byte>(new byte());
}

std::shared_ptr<byte> AESCipher::Decipher(byte *ciphered_message, size_t ciphered_message_size, size_t * deciphered_message_size) {
    return std::shared_ptr<byte>(new byte());
}

