
Pod::Spec.new do |s|
  s.name              = "Smartling"
  s.version           = "1.1.5"
  s.summary           = "Smartling in-context translation editor "
  s.description       = <<-DESC
                        Smartling offers an advanced interface for translating and performing QA on a mobile app, in-context, directly within the app and on the actual device.
                        DESC
  s.homepage          = "https://www.smartling.com"
  s.license           = { :type => "Commercial", :text => "            All text and design is copyright © 2016 Smartling, Inc.\n\n                            All rights reserved.\n\n                             www.smartling.com\n" }
  s.author            = { "EmilienHuet" => "ehuet@smartling.com" }
  s.source            = { :git => "https://github.com/Smartling/ios-lqa-sdk.git", :tag => s.version.to_s }
  s.social_media_url  = 'https://twitter.com/smartling'
  s.documentation_url = 'https://resources.smartling.com/h/'

  s.platform          = :ios, '8.0'
  s.requires_arc      = true
                      
  s.preserve_paths    = ['SmartlingSDK.framework']
  s.libraries         = ["icucore"]
  s.frameworks        = "UIKit", "Foundation", "SystemConfiguration", "SmartlingSDK"
  s.xcconfig          = { "FRAMEWORK_SEARCH_PATHS" => "\"$(PODS_ROOT)/Smartling\"" }
end
