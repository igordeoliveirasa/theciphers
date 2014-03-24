//
//  CipherFactory.cpp
//  theciphers
//
//  Created by Igor de Oliveira Sa on 23/03/14.
//  Copyright (c) 2014 Igor de Oliveira Sa. All rights reserved.
//

#include "../commons.h"
#include "cipher_factory.h"
#include "../interfaces/icipher.h"
#include "../implementations/aes_cipher.h"
#include "../factories/cipher_factory.h"

CipherFactory::CipherFactory() {}

std::shared_ptr<ICipher> CipherFactory::Build(Ciphers cipher_type, const unsigned char * key, const unsigned char* iv) {
    return std::shared_ptr<ICipher>(new AESCipher(key, iv));
}

#ifdef _SYSTEM_TEST

TEST(CipherFactory, CipherFactoryShouldInstance) {
    std::shared_ptr<ICipher> cipher = CipherFactory::Build(AES, (unsigned char*)"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", (unsigned char*)"AAAAAAAAAAAAAAAA");
    
    unsigned char* message = (unsigned char*)"Hello World";
    size_t message_size = strlen((const char*)message) + 1; // let's embbed the \0
    
    unsigned char ciphered_message[message_size * 2];
    size_t ciphered_message_size = cipher->Cipher(message, message_size, ciphered_message);
    
    unsigned char deciphered_message[message_size];
    size_t deciphered_message_size = cipher->Decipher(ciphered_message, ciphered_message_size, deciphered_message);
    
    ASSERT_TRUE(ciphered_message_size==16);
    ASSERT_STREQ((const char*)message, (const char*)deciphered_message);
}

#endif