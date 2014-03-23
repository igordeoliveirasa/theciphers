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
    virtual int Cipher(unsigned char * message, size_t message_size, unsigned char * ciphered_message) = 0;
    virtual int Decipher(unsigned char * ciphered_message, size_t ciphered_message_size, unsigned char * deciphered_message) = 0;
};

#endif
