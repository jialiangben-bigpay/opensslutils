//
//  OpenSSLUtilsAssembly.h
//  OpenSSLUtils
//
//  Created by Iurii Mozharovskyi on 6/20/19.
//  Copyright © 2019 Lohika. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <OpenSSLUtils/CardCryptoExchange.h>


NS_ASSUME_NONNULL_BEGIN

/** Assembly for OpenSSLUtils framework. */
@interface OpenSSLUtilsAssembly : NSObject

+ (instancetype)sharedInstance;

- (id<CardCryptoExchange>)cardCryptoExchange;

@end

NS_ASSUME_NONNULL_END
