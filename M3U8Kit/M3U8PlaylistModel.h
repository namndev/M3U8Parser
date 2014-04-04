//
//  M3U8Parser.h
//  M3U8Kit
//
//  Created by Oneday on 13-1-11.
//  Copyright (c) 2013年 0day. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "M3U8MasterPlaylist.h"
#import "M3U8MediaPlaylist.h"

// 用来管理 m3u playlist, 根据 URL 或者 string 生成 master playlist, 从master playlist 生成指定的 media playlist
// 生成 master playlist
// 提取默认的 media playlist，包括 video segments, subtitles playlist, audio playlist
// 取出media playlist 里面的链接等信息

// 把 master playlist 和 media playlist 中的链接替换 合成为本地服务器可用的playlist

/**
 
 需要下载的内容：
 
 --- master playlist 中的内容，如果有的话
 1. master playlist
 2. 默认的 media playlist, 由第一个 #EXT-X-STREAM-INF Tag 指定
 3. 音频 如果有一个 #EXT-X-STREAM-INF Tag 的codecs只有音频部分，则认为它的URI指向一个音频文件，应该下载下来，其它的Tag 暂时都简单的忽略掉
 
 . 下载各 media playlist 对应的分段内容
 
 */

@interface M3U8PlaylistModel : NSObject

// 如果初始化时的字符串是 media playlist, masterPlaylist为nil
// M3U8PlaylistModel 默认会按照《需要下载的内容》规则选取默认的playlist，如果需要手动指定获取特定的media playlist, 需调用方法 -specifyVideoURL:(这个在选取视频源的时候会用到);

@property (readonly, nonatomic, strong) M3U8MasterPlaylist *masterPlaylist;

@property (readonly, nonatomic, strong) M3U8MediaPlaylist *mainMediaPl;
@property (readonly, nonatomic, strong) M3U8MediaPlaylist *audioPl;
//@property (readonly, nonatomic, strong) M3U8MediaPlaylist *subtitlePl;

//
- (id)initWithURL:(NSURL *)URL error:(NSError **)error;
- (id)initWithString:(NSString *)string baseURL:(NSURL *)URL;

// 改变 mainMediaPl
// 这个url必须是master playlist 中多码率url(绝对地址)中的一个; 如果URL内容获取失败,不会引起变化
- (void)specifyVideoURL:(NSString *)url completion:(void (^)(BOOL success))completion;

- (NSString *)indexPlaylistName;

- (NSString *)prefixOfSegmentNameInPlaylist:(M3U8MediaPlaylist *)playlist;


//- (NSArray *)segmentNamesForPlaylist:(M3U8MediaPlaylist *)playlist;

- (void)savePlaylistsToPath:(NSString *)path error:(NSError **)error;

@end