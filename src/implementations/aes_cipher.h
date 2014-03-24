//
//  AESCipher.h
//  theciphers
//
//  Created by Igor de Oliveira Sa on 23/03/14.
//  Copyright (c) 2014 Igor de Oliveira Sa. All rights reserved.
//

#ifndef __theciphers__AESCipher__
#define __theciphers__AESCipher__

#include "../commons.h"
#include "../interfaces/icipher.h"

class AESCipher : public ICipher {
    
private:
    unsigned char * key_;
    unsigned char *iv_;
    
public:
    AESCipher(const unsigned char * key, const unsigned char * iv);
    int Cipher(unsigned char * message, size_t message_size, unsigned char * ciphered_message);
    int Decipher(unsigned char * ciphered_message, size_t ciphered_message_size, unsigned char * deciphered_message);
};


#endif /* defined(__theciphers__AESCipher__) */
