
Pod::Spec.new do |s|

  s.name         = "XMUtils"
  s.version      = "1.0.0"
  s.summary      = "A short description of XMUtils."

  s.homepage     = "https://github.com/xiaopipixia/XMUtils"

s.license      = { :type => 'MIT', :text => <<-LICENSE
                                                                Copyright 2016
                                                                Permission is granted to daoxuehao.com
                                                                LICENSE
                                                    }

  s.author             = { "XM" => "1159936662@qq.com" }

 s.platform     = :ios, "8.0"

  s.source       = { :git => "https://github.com/xiaopipixia/XMUtils" }

  s.source_files  = "XMUtils/**/*.{h,m}"

  s.framework  = "UIKit"

    s.requires_arc = true
    s.dependency  'MBProgressHUD'
    s.dependency  'MJRefresh'
end
