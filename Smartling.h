//
//  SmartlingSDK.h
//  SmartlingSDK
//
//  Created by Emilien Huet on 3/9/16.
//  Copyright © 2016 Smartling. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SLLogging               @"logging"
#define SLMode                  @"mode"

typedef NS_ENUM(NSInteger, SLModeOptions) {
    SLDisabled,
    SLOTAServing,
    SLInAppReview
};

typedef NS_ENUM(NSUInteger, SLLoggingLevel){
    SLLoggingNone,
    SLLoggingInfo,
    SLLoggingDebug
};

@interface Smartling : NSObject

+ (void)startWithProjectId:(NSString *)projectId key:(NSString *)key andOptions:(NSDictionary *)options;
+ (NSLocale *)locale;
+ (NSString *)pluralizedStringWithKey:(NSString *)key value:(NSNumber *)value NS_FORMAT_ARGUMENT(1);

@end
