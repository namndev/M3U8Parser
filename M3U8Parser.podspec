#
# Be sure to run `pod lib lint M3U8Kit.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |spec|
  spec.name = "M3U8Parser"
  spec.version = "1.0.0"
  spec.summary = "A light weight m3u8 parser."


# This description is used to generate ƒtags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!
  # spec.description      = <<-DESC
  #                      DESC

  spec.homepage = "https://github.com/uizaio/M3U8Parser.git"
  spec.author = { 'NamND' => 'namnd.bka@gmail.com' }
  spec.license = { :type => "BSD", :file => "LICENSE" }
  spec.source = { :git => "https://github.com/namndev/M3U8Parser.git", :tag => spec.version }

  spec.ios.deployment_target = '9.0'
  spec.requires_arc = true

  spec.source_files = 'Source/*.{h,m}', 'Source/**/*.{h,m}'
  spec.public_header_files = 'Source/*.h', 'Source/**/*.h'

end
