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

boost::shared_ptr<ICipher> CipherFactory::Build(Ciphers cipher_type, byte * key, size_t key_size) {
    boost::shared_ptr<ICipher> cipher(new AESCipher());
    return cipher;
}

#ifdef _SYSTEM_TEST
#include "gtest/gtest.h"

TEST(CipherFactory, CipherFactoryShouldInstance) {
    byte * key = (byte*)"1234567812345678";
    size_t key_size = strlen((const char*)key);
    
    boost::shared_ptr<ICipher> aes_cipher = CipherFactory::Build(AES, key, key_size);
    byte * message = (byte *)"Hello World";
    size_t message_size = strlen((const char*)message);
    boost::shared_ptr<byte> ciphered = aes_cipher->Cipher(message, message_size);
    size_t ciphered_message_size = 9;
    boost::shared_ptr<byte> plain_text = aes_cipher->Decipher(ciphered.get(), ciphered_message_size);
}

#endif

