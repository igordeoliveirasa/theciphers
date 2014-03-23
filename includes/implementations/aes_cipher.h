//
//  AESCipher.h
//  theciphers
//
//  Created by Igor de Oliveira Sa on 23/03/14.
//  Copyright (c) 2014 Igor de Oliveira Sa. All rights reserved.
//

#ifndef __theciphers__AESCipher__
#define __theciphers__AESCipher__

#include "the_ciphers.h"
#include <openssl/aes.h>
#include <openssl/evp.h>

class AESCipher : public ICipher {
    
private:
    unsigned char * key_;
    size_t key_size_;
    
    EVP_CIPHER_CTX *aes_context;
    unsigned char *aes_key;
    unsigned char *aes_IV;
    
public:
    AESCipher(unsigned char * key, size_t key_size);
    std::shared_ptr<unsigned char> Cipher(unsigned char * message, size_t message_size, size_t * ciphered_message_size);
    std::shared_ptr<unsigned char> Decipher(unsigned char * ciphered_message, size_t ciphered_message_size, size_t * deciphered_message_size);
};


#endif /* defined(__theciphers__AESCipher__) */
