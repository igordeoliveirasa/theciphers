//
//  AESCipher.cpp
//  theciphers
//
//  Created by Igor de Oliveira Sa on 23/03/14.
//  Copyright (c) 2014 Igor de Oliveira Sa. All rights reserved.
//

#include "the_ciphers.h"

AESCipher::AESCipher( byte * key, size_t key_size) : key_(key), key_size_(key_size) {
    
}

std::shared_ptr<byte> AESCipher::Cipher(byte *message, size_t message_size, size_t * ciphered_message_size) {
    return std::shared_ptr<byte>(new byte());
}

std::shared_ptr<byte> AESCipher::Decipher(byte *ciphered_message, size_t ciphered_message_size, size_t * deciphered_message_size) {
    return std::shared_ptr<byte>(new byte());
}


#ifdef _UNIT_TEST

TEST(AESCipher, TestCipher) {

    byte * key = (byte*)"1234567812345678";
    size_t key_size = strlen((const char*)key);

    AESCipher cipher(key, key_size);
    
    byte * message = (byte *)"Hello World";
    size_t message_size = strlen((const char*)message);
    
    size_t ciphered_message_size;
    std::shared_ptr<byte> ciphered_message = cipher.Cipher(message, message_size, &ciphered_message_size);
    
    size_t deciphered_message_size;
    
    std::shared_ptr<byte> deciphered_message = cipher.Decipher(ciphered_message.get(), ciphered_message_size, &deciphered_message_size);
}

#endif