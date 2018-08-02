//
//  UtilFun.m
//  MJ
//
//  Created by harry on 14/12/4.
//  Copyright (c) 2014年 Simtoon. All rights reserved.
//

#import "UtilFun.h"
#import "MBProgressHUD.h"
#import "sys/utsname.h"
#import "WCAlertView.h"

static NSString*UDIDSTRING=nil;

@implementation UtilFun



+ (UIColor *)colorWithHex:(UInt32)hex andAlpha:(CGFloat)alpha{
    return  [UIColor colorWithRed:((hex >> 16) & 0xFF)/255.0
                                  green:((hex >> 8) & 0xFF)/255.0
                                   blue:(hex & 0xFF)/255.0
                                  alpha:alpha];
}


+(void)presentPopViewControllerWithTitle:(NSString*)title
                                 Message:(NSString*)msg
                            SimpleAction:(NSString*)actionTitle
                                 Handler:(void (^)(void))handle
                            CancelAction:(NSString*)cancelTitle
                           CancelHandler:(void (^)(void))cancelHandle
                                  Sender:(UIViewController*)sender
{
    if (actionTitle == nil || actionTitle.length == 0) {
        actionTitle = @"OK";
    }
    [WCAlertView showAlertWithTitle:title message:msg customizationBlock:nil completionBlock:^(NSUInteger buttonIndex, WCAlertView *alertView) {
        switch (buttonIndex)
        {
            case 0:
            {
                if (handle)
                {
                    handle();
                }
            }
                break;
            case 1:
            default:
            {
                if (cancelHandle)
                {
                    cancelHandle();
                }
            }
                break;
        }
    } cancelButtonTitle:actionTitle otherButtonTitles:cancelTitle, nil];

}


+(void)showWindowHUD:(NSString *)tip
{
    UIView *v = [UIApplication sharedApplication].keyWindow;
    MBProgressHUD *hud = [[MBProgressHUD alloc] initWithView:v];
    hud.label.text = tip;
    [v addSubview:hud];
    [hud showAnimated:YES];
    
}

+(void)hideAllWindowHUD
{

    [MBProgressHUD hideHUDForView:[UIApplication sharedApplication].keyWindow animated:YES];
}

+(void)showHUD:(UIView*)view
{
   MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:view animated:YES];
    hud.bezelView.color = [UIColor blackColor];
    hud.contentColor = [UIColor whiteColor];
    
}

+(void)hideHUD:(UIView*)view
{
    [MBProgressHUD hideHUDForView:view animated:YES];
}

+(void)hideAllHUD:(UIView*)view
{
    [MBProgressHUD hideHUDForView:view animated:YES];
}

+(NSString*)validMobile:(NSString*)mobile{
   
    if (mobile.length < 11){
        return @"手机号长度只能是11位";
    }else{
        /**
         * 移动号段正则表达式
         */
        NSString *CM_NUM = @"^((13[4-9])|(147)|(15[0-2,7-9])|(178)|(18[2-4,7-8]))\\d{8}|(1705)\\d{7}$";
        /**
         * 联通号段正则表达式
         */
        NSString *CU_NUM = @"^((13[0-2])|(145)|(15[5-6])|(176)|(18[5,6]))\\d{8}|(1709)\\d{7}$";
        /**
         * 电信号段正则表达式
         */
        NSString *CT_NUM = @"^((133)|(153)|(177)|(18[0,1,9]))\\d{8}$";
        NSPredicate *pred1 = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", CM_NUM];
        BOOL isMatch1 = [pred1 evaluateWithObject:mobile];
        NSPredicate *pred2 = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", CU_NUM];
        BOOL isMatch2 = [pred2 evaluateWithObject:mobile];
        NSPredicate *pred3 = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", CT_NUM];
        BOOL isMatch3 = [pred3 evaluateWithObject:mobile];
        
        if (isMatch1 || isMatch2 || isMatch3) {
            return nil;
        }else{
            return @"请输入正确的手机号码";
        }
    }
    return nil;
}


+(NSString*)getAppName{
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    // app名称
    return  [infoDictionary objectForKey:@"CFBundleDisplayName"];
}

+(UIImage *)imageFromColor:(UIColor *)color Size:(CGSize)sz{
    
    CGRect rect = CGRectMake(0, 0, sz.width, sz.height);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, [color CGColor]);
    CGContextFillRect(context, rect);
    UIImage *img = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext(); return img;
}

+(NSString*)firstUrlSchemes{
    NSDictionary *infoDic = [[NSBundle mainBundle] infoDictionary];
    
    NSArray *UrlTypes = [infoDic objectForKey:@"CFBundleURLTypes"];
    NSDictionary*urlType = [UrlTypes objectAtIndex:0];
    
    NSString *urlSchemes = [NSString stringWithFormat:@"%@",[[urlType objectForKey:@"CFBundleURLSchemes"] objectAtIndex:0]];
    return urlSchemes;
}
@end
