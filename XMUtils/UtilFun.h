//
//  UtilFun.h
//  MJ
//
//  Created by harry on 14/12/4.
//  Copyright (c) 2014年 Simtoon. All rights reserved.
//
/*[UtilFun presentPopViewControllerWithTitle:title Message:msg SimpleAction:action Sender:tmpSender];*/

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "XMUtil.h"

#define SHOWWINDOWHUD(tip) ([UtilFun showWindowHUD:(tip)]);
#define HIDEALLWINDOWHUD ([UtilFun hideAllWindowHUD]);

#define SHOWHUD_WINDOW ([UtilFun showHUD:[UIApplication sharedApplication].keyWindow]);
#define HIDEHUD_WINDOW ([UtilFun hideHUD:[UIApplication sharedApplication].keyWindow]);

#define SHOWHUD(v) ([UtilFun showHUD:v]);
#define HIDEHUD(v) ([UtilFun hideHUD:v]);
#define HIDEALLHUD(v) ([UtilFun hideAllHUD:v]);



#define MJAlert(title,msg,action,hander,sender)\
{\
    id tmpSender = sender;\
    if(sender == nil) tmpSender = self;\
    [UtilFun presentPopViewControllerWithTitle:title Message:msg SimpleAction:action Handler:hander CancelAction:nil  CancelHandler:nil Sender:tmpSender];\
}\


#define MJAlertWithOkAndCancelAction(title,msg,ok,hander,cancel,cancelHander,sender)\
{\
id tmpSender = sender;\
if(sender == nil) tmpSender = self;\
[UtilFun presentPopViewControllerWithTitle:title Message:msg SimpleAction:ok Handler:hander CancelAction:cancel  CancelHandler:cancelHander Sender:tmpSender];\
}\

#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]



@interface UtilFun : NSObject
+ (UIColor *)colorWithHex:(UInt32)hex andAlpha:(CGFloat)alpha;
+(void)presentPopViewControllerWithTitle:(NSString*)title Message:(NSString*)msg SimpleAction:(NSString*)action Handler:(void (^)(void))handle CancelAction:(NSString*)cancelTitle CancelHandler:(void (^)(void))cancelHandle Sender:(UIViewController*)sender;



+(void)showHUD:(UIView*)view;
+(void)hideHUD:(UIView*)view;
+(void)hideAllHUD:(UIView*)view;
+(void)showWindowHUD:(NSString *)tip;
+(void)hideAllWindowHUD;

//获取app名字
+(NSString*)getAppName;
+(NSString*)firstUrlSchemes;
+(UIImage *)imageFromColor:(UIColor *)color Size:(CGSize)sz;
@end
