//
//  XMUtil.h
//  Test
//
//  Created by dczd on 2018/8/2.
//  Copyright © 2018年 dczd. All rights reserved.
//

#ifndef XMUtil_h
#define XMUtil_h

/*这里用来切换测试服和发布服地址*/
#if DEBUG
#define XMServerLocal  @"www.baidu.com"
#else
#define XMServerLocal  @"www.baidu.com"
#endif

/*系统一些的屏幕尺寸*/
#define XM_SWIDTH  [[UIScreen mainScreen] bounds].size.width//屏宽
#define XM_SHEIGHT [[UIScreen mainScreen] bounds].size.height//屏高

/*手机号码格式正则表达式*/
#define XMPhoneRegular @"^((13[0-9])|(15[^4,\\D])|(17[0-9])|(18[0-9]))\\d{8}$"

/*判断字符串不为空和null*/
#define XMSTR_Not_Null(str) (![str isKindOfClass:[NSNull class]]&&![str isEqualToString:@""])

/*系统的一些版本对比*/
#define SYSTEM_VERSION_EQUAL_TO(v)([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch]==NSOrderedSame)

#define SYSTEM_VERSION_GREATER_THAN(v)([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch]==NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch]!=NSOrderedAscending)

#define SYSTEM_VERSION_LESS_THAN(v)([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch]==NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch]!=NSOrderedDescending)

/*输出打印*/
#ifdef DEBUG
#define XMLog(FORMAT, ...) fprintf(stderr,"[%s]---Line:%d\t%s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define XMLog(...)
#endif

/*设置圆角*/
#define XMViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

// 判断是否是iPhone X
#define iPhoneX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)
// 状态栏高度
#define STATUS_BAR_HEIGHT (iPhoneX ? 44.f : 20.f)
// 导航栏高度
#define NAVIGATION_BAR_HEIGHT (iPhoneX ? 88.f : 64.f)
// tabBar高度
#define TAB_BAR_HEIGHT (iPhoneX ? (49.f+34.f) : 49.f)
// home indicator高度
#define HOME_INDICATOR_HEIGHT (iPhoneX ? 34.f : 0.f)
//字符串转url
#define XMURLWithString(string) [NSURL URLWithString:[NSString stringWithFormat:@"%@",string]]
#endif /* XMUtil_h */

