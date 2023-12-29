//
//  NSString+OpenSSLUtils.h
//  OpenSSLUtils
//
//  Created by Iurii Mozharovskyi on 6/14/19.
//  Copyright © 2019 Lohika. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface  NSString (OpenSSLUtils)

+ (nullable instancetype)opensslutils_stringWithASCIIString:(const char *)cString;

- (nullable const char *)opensslutils_toASCIIString;

- (BOOL)opensslutils_isBase64EncodedData;

@end

NS_ASSUME_NONNULL_END
