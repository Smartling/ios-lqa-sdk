//
//  SmartlingSDK.h
//  SmartlingSDK
//
//  Created by Emilien Huet on 3/9/16.
//  Copyright © 2016 Smartling. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 * Smartling startup option keys
 */
#define SLLogging               @"logging"              // Level of logging to output to the console by the Smartling SDK. See SLLoggingLevel.
#define SLMode                  @"mode"                 // SDK Mode. See SLModeOptions.
#define SLOTAKey                @"otaKey"               // AES key to decrypt strings downloaded in OTA mode. Required option for OTA.
#define SLAPIUserId             @"apiUserId"            // Smartling API v2 user ID. Required option for Context Capture mode and for OTA if the getProjectLocalesWithCompletion: method is used.
#define SLAPIUserSecret         @"apiUserSecret"        // Smartling API v2 user secret. Required option for Context Capture mode and for OTA if the getProjectLocalesWithCompletion: method is used.
#define SLForceLocale           @"forceLocale"          // Set this option to a locale ID in OTA mode to ignore automatic locale detection and force an arbitrary locale.
#define SLAllowLocaleChange     @"allowLocaleChange"    // Set this option to YES in OTA mode if your app allows the user to change the locale from within the app.

/**
 * Options for the SDK mode startup option.
 */
#define SLDisabled                          @"SLDisabled"           // SDK entirely disabled.
#define SLOTAServing                        @"SLOTAServing"         // Mobile Delivery Network enabled, strings are downloaded in the user's phone language and displayed in the UI.
#define SLInAppReview                       @"SLInAppReview"        // In-App Review enabled, users can log in, translate strings and review them.
#define SLContextCapture                    @"SLContextCapture"     // Context Capture enabled, users can take screenshots of the app that will be sent to the dashboard with associated strings.
#define SLInAppReviewAndContextCapture      @"SLInAppReviewAndContextCapture"     // Combines both modes

/**
 * Options for the logging startup option.
 */
#define SLLoggingNone           @"SLLoggingNone"        // Logging disabled.
#define SLLoggingInfo           @"SLLoggingInfo"        // Major errors and important information only.
#define SLLoggingDebug          @"SLLoggingDebug"       // Verbose logging.


@interface Smartling : NSObject

/**
 * Initialize the SDK with a dictionary of options. 
 * Call this method in your app's main before `return UIApplicationMain()` or in your AppDelegate's `application:didFinishLaunchingWithOptions:`.
 */
+ (void)startWithProjectId:(NSString *)projectId andOptions:(NSDictionary *)options;

/**
 * Get the locale currently used by the Smartling SDK.
 */
+ (NSLocale *)locale;

/**
 * Get the app's base locale.
 */
+ (NSLocale *)baseLocale;

/**
 * Change the locale used by the Smartling SDK to supported locale ID. 
 * For your app to support locale switching, enabled the option `SLAllowLocaleChange`.
 * For a list of locales supported by your project, call `getProjectLocalesWithCompletion:`.
 */
+ (void)setLocaleWithId:(NSString *)localeId andCompletion:(void (^)(BOOL success))completion;

/**
 * Get a list of locales supported by your project. Requires the SLAPIUserId and SLAPIUserSecret options to be set.
 */
+ (void)getProjectLocalesWithCompletion:(void (^)(NSArray *locales, NSError *error))completion;

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

/**
 * Manually trigger a screenshot in Context Capture mode.
 */
+ (void)captureWindow:(UIWindow *)window withCompletion:(void (^)(NSError *error))completion;


@end
