//
//  SmartlingSDK.h
//  SmartlingSDK
//
//  Created by Emilien Huet on 3/9/16.
//  Copyright © 2016 Smartling. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SLLogging   @"logging"

typedef NS_ENUM(NSUInteger, SLLoggingLevel){
    SLLoggingNone,
    SLLoggingInfo,
    SLLoggingDebug
};


@interface Smartling : NSObject

+ (void)startWithProjectId:(NSString *)projectId andOptions:(NSDictionary *)options;
+ (NSLocale *)locale;

@end
