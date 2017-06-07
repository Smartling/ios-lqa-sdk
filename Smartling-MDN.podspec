
Pod::Spec.new do |s|
  s.name              = "Smartling-MDN"
  s.version           = "1.4.0"
  s.summary           = "Smartling in-context translation editor "
  s.description       = <<-DESC
                        Smartling MDN serves your Smartling translations to you end users over the air.
                        DESC
  s.homepage          = "https://www.smartling.com"
  s.license           = { :type => "Commercial", :text => "            All text and design is copyright © 2016 Smartling, Inc.\n\n                            All rights reserved.\n\n                             www.smartling.com\n" }
  s.author            = { "EmilienHuet" => "ehuet@smartling.com" }
  s.source            = { :git => "https://github.com/Smartling/ios-lqa-sdk.git", :tag => "mdn-#{s.version.to_s}" }
  s.social_media_url  = 'https://twitter.com/smartling'
  s.documentation_url = 'https://resources.smartling.com/h/'

  s.platform          = :ios, '7.0'
  s.requires_arc      = true
                      
  s.source_files      = '*.h'
  s.preserve_paths    = ['libSmartlingMDN.a']
  s.libraries         = ["SmartlingMDN"]
  s.frameworks        = 'UIKit'
                      
  s.xcconfig          = { "LIBRARY_SEARCH_PATHS" => "\"$(PODS_ROOT)/Smartling-MDN\"",
                          "OTHER_LINKER_FLAGS" => ["-lz", "-ObjC"] }
end
