//
//  ICipher.h
//  theciphers
//
//  Created by Igor de Oliveira Sa on 23/03/14.
//  Copyright (c) 2014 Igor de Oliveira Sa. All rights reserved.
//

#ifndef theciphers_ICipher_h
#define theciphers_ICipher_h

#include "the_ciphers.h"

class ICipher {
public:
    virtual std::shared_ptr<unsigned char> Cipher(unsigned char * message, size_t message_size, size_t * ciphered_message_size) = 0;
    virtual std::shared_ptr<unsigned char> Decipher(unsigned char * ciphered_message, size_t ciphered_message_size, size_t * deciphered_message_size) = 0;
};

#endif
