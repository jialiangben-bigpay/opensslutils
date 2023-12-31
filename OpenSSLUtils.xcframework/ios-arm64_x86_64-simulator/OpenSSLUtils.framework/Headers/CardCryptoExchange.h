//
//  CardCryptoExchange.h
//  BigPay
//
//  Created by Iurii Mozharovskyi on 6/20/19.
//  Copyright © 2019 Lohika. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** Public and private keys for Diffie Hellman key agreement */
@interface KeysGenerationResult : NSObject

/** Private key. Should be stored locally to generate AES key with server's public key. */
@property (nonatomic, strong) NSString *privateKey;

/** Public key. Should be sent to backend for key agreement. */
@property (nonatomic, strong) NSString *publicKey;

- (instancetype)initWithPrivateKey:(NSString *)privateKey
                         publicKey:(NSString *)publicKey;

@end


/**
 Handles Diffie Hellman key generation and card data decryption.
 https://wiki.openssl.org/index.php/Elliptic_Curve_Diffie_Hellman,
 https://wiki.openssl.org/index.php/EVP_Key_Agreement
 */
@protocol CardCryptoExchange <NSObject>

/**
 Generates public and private keys for Diffie Hellman key agreement
 @return key pair or nil for failure.
 */
- (nullable KeysGenerationResult *)generateExchangePair
NS_SWIFT_NAME(generateExchangePair());

/**
 Decrypts server response.
 @param encryptedResponse Encrypted server response
 @param transactionReference Transaction reference generated by backend
 @param encryptedSessionKey Encrypted session key, which is used for `response` encoding
 @param serverPublicKey Server public key. Used with client private key to generate AES key for `encryptedSessionKey`
 decryption
 @param clientPrivateKey Client private key. Used with server public key key to generate AES key for
 `encryptedSessionKey` decryption
 @return decrypted response or nil for failure.
 */
- (nullable NSString *)decryptResponse:(NSString *)encryptedResponse
                  transactionReference:(NSString *)transactionReference
                   encryptedSessionKey:(NSString *)encryptedSessionKey
                       serverPublicKey:(NSString *)serverPublicKey
                            privateKey:(NSString *)clientPrivateKey;

- (NSData *)deriveSharedSecretFromPublicKey:(NSString *)serverPublicKey
                           clientPrivateKey:(NSString *)clientPrivateKey
                                    context:(nullable NSString *) context;

@end

NS_ASSUME_NONNULL_END
