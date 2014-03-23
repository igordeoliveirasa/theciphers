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
    virtual boost::shared_ptr<byte> Cipher(byte*message, size_t message_size) = 0;
    virtual boost::shared_ptr<byte> Decipher(byte*ciphered_message, size_t ciphered_message_size) = 0;
};

#endif
