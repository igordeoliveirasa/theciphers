//
//  CipherFactory.cpp
//  theciphers
//
//  Created by Igor de Oliveira Sa on 23/03/14.
//  Copyright (c) 2014 Igor de Oliveira Sa. All rights reserved.
//

#include "the_ciphers.h"

CipherFactory::CipherFactory() {
    
}

std::shared_ptr<ICipher> CipherFactory::Build(Ciphers cipher_type, byte * key, size_t key_size) {
    return std::shared_ptr<ICipher>(new AESCipher());
}

#ifdef _SYSTEM_TEST

#include "gtest/gtest.h"

TEST(CipherFactory, CipherFactoryShouldInstance) {
    byte * key = (byte*)"1234567812345678";
    size_t key_size = strlen((const char*)key);
    
    std::shared_ptr<ICipher> aes_cipher = CipherFactory::Build(AES, key, key_size);
    
    byte * message = (byte *)"Hello World";
    size_t message_size = strlen((const char*)message);
    
    size_t ciphered_message_size;
    std::shared_ptr<byte> ciphered_message = aes_cipher->Cipher(message, message_size, &ciphered_message_size);
    
    size_t deciphered_message_size;
    
    std::shared_ptr<byte> deciphered_message = aes_cipher->Decipher(ciphered_message.get(), ciphered_message_size, &deciphered_message_size);
}

#endif