//
//  AESCipher.cpp
//  theciphers
//
//  Created by Igor de Oliveira Sa on 23/03/14.
//  Copyright (c) 2014 Igor de Oliveira Sa. All rights reserved.
//

#include "the_ciphers.h"

#define AES_KEYLEN 128

AESCipher::AESCipher( unsigned char * key, size_t key_size) : key_(key), key_size_(key_size) {
}

std::shared_ptr<unsigned char> AESCipher::Cipher(unsigned char *message, size_t message_size, size_t * ciphered_message_size) {
    return std::shared_ptr<unsigned char>();
}

std::shared_ptr<unsigned char> AESCipher::Decipher(unsigned char *ciphered_message, size_t ciphered_message_size, size_t * deciphered_message_size) {
    return std::shared_ptr<unsigned char>();
}


#ifdef _UNIT_TEST

TEST(AESCipher, TestCipher) {

    unsigned char * key = (unsigned char*)"1234567812345678";
    size_t key_size = strlen((const char*)key);

    AESCipher cipher(key, key_size);
    
    unsigned char * message = (unsigned char *)"Hello World";
    size_t message_size = strlen((const char*)message);
    
    size_t ciphered_message_size;
    std::shared_ptr<unsigned char> ciphered_message = cipher.Cipher(message, message_size, &ciphered_message_size);

    std::shared_ptr<unsigned char> deciphered_message = cipher.Decipher(ciphered_message.get(), message_size, &ciphered_message_size);
    printf("%s", (const char*)deciphered_message.get());
    
    ASSERT_TRUE(ciphered_message_size == 10);
}

#endif