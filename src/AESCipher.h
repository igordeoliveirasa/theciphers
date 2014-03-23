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

class AESCipher : public ICipher {
    boost::shared_ptr<byte> Cipher(byte*message, size_t message_size);
    boost::shared_ptr<byte> Decipher(byte*ciphered_message, size_t ciphered_message_size);
};


#endif /* defined(__theciphers__AESCipher__) */
