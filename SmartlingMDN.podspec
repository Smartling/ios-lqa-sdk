
Pod::Spec.new do |s|
  s.name              = "SmartlingMDN"
  s.version           = "1.5.0"
  s.summary           = "Smartling Mobile Delivery Network SDK"
  s.description       = <<-DESC
                        Smartling MDN serves your Smartling translations to your end users over the air.
                        DESC
  s.homepage          = "https://www.smartling.com"
  s.license           = { :type => "Commercial", :text => "            All text and design is copyright © 2018 Smartling, Inc.\n\n                            All rights reserved.\n\n                             www.smartling.com\n" }
  s.author            = { "Smartling" => "srossillo@smartling.com" }
  s.source            = { :git => "https://github.com/Smartling/ios-lqa-sdk.git", :tag => "mdn-#{s.version.to_s}" }
  s.social_media_url  = 'https://twitter.com/smartling'
  s.documentation_url = 'https://resources.smartling.com/h/'

  s.platform          = :ios, '7.0'
  s.requires_arc      = true
                      
  s.source_files      = '*.h'
  s.preserve_paths    = ['libSmartlingMDN.a']
  s.ios.frameworks    = 'UIKit'
                      
  s.xcconfig          = { "OTHER_LINKER_FLAGS" => ["-lz", "-ObjC"] }
end
