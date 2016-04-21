# Installation instructions

- In your project's `podfile`, add the Smartling source and pod as shown below:
```
source 'https://github.com/Smartling/ios-lqa-sdk.git'
source 'https://github.com/CocoaPods/Specs.git'

target 'MyApp' do
	pod 'Smartling'
end

```

- In your app's AppDelegate, import the library and call the start method as shown below:
```objc
#import "AppDelegate.h"
#import <Smartling/Smartling.h>

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [Smartling startWithProjectId:@"<ProjectID>" andOptions:@{SLLogging : @(SLLoggingDebug)}];
    return YES;
}

@end
```
