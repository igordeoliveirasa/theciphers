//
//  CipherFactory.h
//  theciphers
//
//  Created by Igor de Oliveira Sa on 23/03/14.
//  Copyright (c) 2014 Igor de Oliveira Sa. All rights reserved.
//

#ifndef __theciphers__CipherFactory__
#define __theciphers__CipherFactory__


#include "the_ciphers.h"

enum Ciphers {
    AES,
    BLOWFISH
};

class CipherFactory {
public:
    CipherFactory();
    
    static std::shared_ptr<ICipher> Build(Ciphers cipher_type, const unsigned char * key, const unsigned char* iv);
};

#endif /* defined(__theciphers__CipherFactory__) */
