//
//  M3U8ExtXStreamInf.h
//  ILSLoader
//
//  Created by Jin Sun on 13-4-15.
//  Copyright (c) 2013年 iLegendSoft. All rights reserved.
//

#import <Foundation/Foundation.h>

struct MediaResoulution{
    float width;
    float height;
};
typedef struct MediaResoulution MediaResoulution;

extern MediaResoulution MediaResolutionMake(float width, float height);

extern const MediaResoulution MediaResoulutionZero;
NSString * NSStringFromMediaResolution(MediaResoulution resolution);

@interface M3U8ExtXStreamInf : NSObject

@property (nonatomic, readonly, assign) NSInteger bandwidth;
@property (nonatomic, readonly, assign) NSInteger averageBandwidth;
@property (nonatomic, readonly, assign) NSInteger programId;        // removed by draft 12
@property (nonatomic, readonly, copy) NSArray *codecs;
@property (nonatomic, readonly) MediaResoulution resolution;
@property (nonatomic, readonly, copy) NSString *audio;
@property (nonatomic, readonly, copy) NSString *video;
@property (nonatomic, readonly, copy) NSString *subtitles;
@property (nonatomic, readonly, copy) NSString *closedCaptions;
@property (nonatomic, readonly, copy) NSURL   *URI;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

- (NSURL *)m3u8URL; // the absolute url

- (NSString *)m3u8PlanString;

@end
