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
#define SLOTAKey                @"otaKey"
#define SLAPIUserId             @"apiUserId"
#define SLAPIUserSecret         @"apiUserSecret"

typedef NS_ENUM(NSInteger, SLModeOptions) {
    SLDisabled,
    SLOTAServing,
    SLInAppReview,
    SLContextCapture
};

typedef NS_ENUM(NSUInteger, SLLoggingLevel){
    SLLoggingNone,
    SLLoggingInfo,
    SLLoggingDebug
};

@interface Smartling : NSObject

+ (void)startWithProjectId:(NSString *)projectId andOptions:(NSDictionary *)options;
+ (NSLocale *)locale;
+ (NSString *)pluralizedStringWithKey:(NSString *)key value:(NSNumber *)value NS_FORMAT_ARGUMENT(1);

@end
