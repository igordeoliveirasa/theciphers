//
//  AESCipher.cpp
//  theciphers
//
//  Created by Igor de Oliveira Sa on 23/03/14.
//  Copyright (c) 2014 Igor de Oliveira Sa. All rights reserved.
//

#include "the_ciphers.h"

#define AES_KEYLEN 128

AESCipher::AESCipher( const unsigned char * key, const unsigned char * iv) {
    key_ = (unsigned char*)key;
    iv_ = (unsigned char*)iv;
    
    ERR_load_crypto_strings();
    OpenSSL_add_all_algorithms();
    OPENSSL_config(NULL);
}

int AESCipher::Cipher(unsigned char *message, size_t message_size, unsigned char * ciphered_message) {

    EVP_CIPHER_CTX *ctx;
    
    int len;
    
    int ciphertext_len;
    
    /* Create and initialise the context */
    if(!(ctx = EVP_CIPHER_CTX_new()))
        printf("erro");
//        handleErrors();
    
    /* Initialise the encryption operation. IMPORTANT - ensure you use a key
     * and IV size appropriate for your cipher
     * In this example we are using 256 bit AES (i.e. a 256 bit key). The
     * IV size for *most* modes is the same as the block size. For AES this
     * is 128 bits */
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key_, iv_))
        printf("erro");
//        handleErrors();
    
    /* Provide the message to be encrypted, and obtain the encrypted output.
     * EVP_EncryptUpdate can be called multiple times if necessary
     */
    
    if(1 != EVP_EncryptUpdate(ctx, ciphered_message, &len, message, message_size))
        printf("erro");
        //handleErrors();
    
    ciphertext_len = len;
    
    /* Finalise the encryption. Further ciphertext bytes may be written at
     * this stage.
     */
    if(1 != EVP_EncryptFinal_ex(ctx, ciphered_message + len, &len))
        printf("erro");
//        handleErrors();
    ciphertext_len += len;
    
    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);
    
    return ciphertext_len;
}

int AESCipher::Decipher(unsigned char *ciphered_message, size_t ciphered_message_size, unsigned char * deciphered_message) {

    EVP_CIPHER_CTX *ctx;
    
    int len;
    
    int plaintext_len;
    
    /* Create and initialise the context */
    if(!(ctx = EVP_CIPHER_CTX_new()))
        printf("erro");
//        handleErrors();
    
    /* Initialise the decryption operation. IMPORTANT - ensure you use a key
     * and IV size appropriate for your cipher
     * In this example we are using 256 bit AES (i.e. a 256 bit key). The
     * IV size for *most* modes is the same as the block size. For AES this
     * is 128 bits */
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key_, iv_))
        printf("erro");
    //        handleErrors();
    
    /* Provide the message to be decrypted, and obtain the plaintext output.
     * EVP_DecryptUpdate can be called multiple times if necessary
     */
    if(1 != EVP_DecryptUpdate(ctx, deciphered_message, &len, ciphered_message, ciphered_message_size))
        printf("erro");
    //        handleErrors();
    plaintext_len = len;
    
    /* Finalise the decryption. Further plaintext bytes may be written at
     * this stage.
     */
    if(1 != EVP_DecryptFinal_ex(ctx, deciphered_message + len, &len))
        printf("erro");
    //        handleErrors();
    plaintext_len += len;
    
    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}


#ifdef _UNIT_TEST

TEST(AESCipher, TestCipher) {
    AESCipher cipher((const unsigned char*)"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", (const unsigned char*)"AAAAAAAAAAAAAAAA");
    
    unsigned char * message = (unsigned char *)"Hello World";
    size_t message_size = strlen((const char*)message) +1; // let's embbed the \0;
    
    unsigned char ciphered_message[message_size * 2];
    size_t ciphered_message_size = cipher.Cipher(message, message_size, ciphered_message);
    
    unsigned char deciphered_message[message_size];
    cipher.Decipher(ciphered_message, ciphered_message_size, deciphered_message);
    
    ASSERT_TRUE(ciphered_message_size == 16);
    ASSERT_STREQ((const char*)message, (const char*)deciphered_message);
}

#endif