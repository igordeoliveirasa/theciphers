//
//  the_ciphers.h
//  theciphers
//
//  Created by Igor de Oliveira Sa on 23/03/14.
//  Copyright (c) 2014 Igor de Oliveira Sa. All rights reserved.
//

#ifndef theciphers_the_ciphers_h
#define theciphers_the_ciphers_h

#include <stdio.h>
#include <iostream>
#include <string.h>

#include <openssl/ssl.h>
#include <openssl/aes.h>
#include <openssl/opensslconf.h>
#include <openssl/err.h>
#include <openssl/conf.h>

#if defined(_SYSTEM_TEST) || defined(_UNIT_TEST)
#include "gtest/gtest.h"
#endif


#endif
