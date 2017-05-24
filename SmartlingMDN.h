//
//  MDN_SDK.h
//  MDN-SDK
//
//  Created by Emilien on 5/23/17.
//  Copyright © 2017 Smartling Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Smartling startup option keys
 */
#define SLLogging               @"logging"              // Level of logging to output to the console by the Smartling SDK. See SLLoggingLevel.
#define SLForceLocale           @"forceLocale"          // Set this option to a locale ID in OTA mode to ignore automatic locale detection and force an arbitrary locale.

/**
 * Options for the logging startup option.
 */
#define SLLoggingNone           @"SLLoggingNone"        // Logging disabled.
#define SLLoggingInfo           @"SLLoggingInfo"        // Major errors and important information only.
#define SLLoggingDebug          @"SLLoggingDebug"       // Verbose logging.


@interface SmartlingMDN : NSObject

/**
 * Initialize the SDK with a dictionary of options.
 * Call this method in your app's main before `return UIApplicationMain()` or in your AppDelegate's `application:didFinishLaunchingWithOptions:`.
 */
+ (void)startWithProjectId:(NSString *)projectId OTAKey:(NSString *)otaKey andOptions:(NSDictionary *)options;

/**
 * Get the locale currently used by the Smartling SDK.
 */
+ (NSLocale *)locale;

/**
 * Get the app's base locale.
 */
+ (NSLocale *)baseLocale;

/**
 * Returns a localized version of a string with plurals support.
 */
+ (NSString *)pluralizedStringWithKey:(NSString *)key value:(NSNumber *)value NS_FORMAT_ARGUMENT(1);

/**
 * Returns a dictionary of all of the app's base locale strings.
 */
+ (NSDictionary *)baseLocaleStrings;

/**
 * Returns a dictionary of all of the app's localized strings in the current locale.
 */
+ (NSDictionary *)localizedStrings;

@end
