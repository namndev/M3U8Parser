# M3U8Kit

[![Build Status](https://travis-ci.org/namndev/M3U8Parser.svg?branch=master)](https://travis-ci.org/namndev/M3U8Parser)
[![CocoaPods Compatible](https://img.shields.io/cocoapods/v/UZM3U8Kit.svg)](https://img.shields.io/cocoapods/v/UZM3U8Kit.svg)
![Platform](https://img.shields.io/cocoapods/p/UZM3U8Kit.svg?style=flat)
[![MIT license](https://img.shields.io/cocoapods/l/UZM3U8Kit.svg?style=flat)](https://raw.githubusercontent.com/namndev/M3U8Parser/master/LICENSE)

## TODO
- [ ] Rewrite with Swift

## New Features
- Add X-Key parser support that is now for each ts resource.
- Add support for AVERAGE-BANDWIDTH property

## Installation

### [Cocoapods](https://cocoapods.org/pods/UZM3U8Kit)

#### Podfile

Specify it in your Podfile:

```ruby
pod 'UZM3U8Kit'
```

Then, run the following command:

```bash
$ pod install
```

### Manually

If you prefer not to use either of the above mentioned dependency managers, you can integrate `M3U8Kit` into your project manually by adding the files contained in the [Source](https://github.com/namndev/M3U8Parser/tree/master/Source) folder to your project.

## Usage

- Asynchronous

```objc
#import "NSURL+m3u8.h"

[<#URL#> loadM3U8AsyncCompletion:^(M3U8PlaylistModel *model, NSError *error) {
                                      }];
```

- Synchronous

```objective-c
NSError *error = nil;
M3U8PlaylistModel *model = [[M3U8PlaylistModel alloc] 
            initWithURL:@"https://xxx.xxx.com/live.m3u8"
              error:&error];
```

## License

UZM3U8Kit is available under the MIT license. See the LICENSE file for more info.
