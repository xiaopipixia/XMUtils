//
//  WJYAlertView
//  MobileProject 自定义UIAlertView样式（由JCAlertView修改）
//
//  Created by wujunyang on 16/8/3.
//  Copyright © 2016年 wujunyang. All rights reserved.
//


#import <UIKit/UIKit.h>

UIKIT_EXTERN NSString *const WJYAlertViewWillShowNotification;
UIKIT_EXTERN NSString *const WJYAlertViewDidShowNotification;
UIKIT_EXTERN NSString *const WJYAlertViewWillDismissNotification;
UIKIT_EXTERN NSString *const WJYAlertViewDidDismissNotification;

typedef void(^clickHandle)(void);

typedef void(^clickHandleWithIndex)(NSInteger index);

typedef NS_ENUM(NSInteger, WJYAlertViewButtonType) {
    WJYAlertViewButtonTypeDefault = 0,
    WJYAlertViewButtonTypeCancel,
    WJYAlertViewButtonTypeWarn,
    WJYAlertViewButtonTypeNone,
    WJYAlertViewButtonTypeHeight
};

@interface WJYAlertView : UIView

// ------------------------Show AlertView with title and message----------------------

// show alertView with 1 button
+ (void)showOneButtonWithTitle:(NSString *)title Message:(NSString *)message ButtonType:(WJYAlertViewButtonType)buttonType ButtonTitle:(NSString *)buttonTitle Click:(clickHandle)click;

// show alertView with 2 buttons
+ (void)showTwoButtonsWithTitle:(NSString *)title Message:(NSString *)message ButtonType:(WJYAlertViewButtonType)buttonType ButtonTitle:(NSString *)buttonTitle Click:(clickHandle)click ButtonType:(WJYAlertViewButtonType)buttonType ButtonTitle:(NSString *)buttonType Click:(clickHandle)click;

// show alertView with greater than or equal to 3 buttons
// parameter of 'buttons' , pass by NSDictionary like @{JCAlertViewButtonTypeDefault : @"ok"}
+ (void)showMultipleButtonsWithTitle:(NSString *)title Message:(NSString *)message Click:(clickHandleWithIndex)click Buttons:(NSDictionary *)buttons,... NS_REQUIRES_NIL_TERMINATION;

// ------------------------Show AlertView with customView-----------------------------

// create a alertView with customView.
// 'dismissWhenTouchBackground' : If you don't want to add a button on customView to call 'dismiss' method manually, set this property to 'YES'.
- (instancetype)initWithCustomView:(UIView *)customView dismissWhenTouchedBackground:(BOOL)dismissWhenTouchBackground;

- (void)configAlertViewPropertyWithTitle:(NSString *)title Message:(NSString *)message Buttons:(NSArray *)buttons Clicks:(NSArray *)clicks ClickWithIndex:(clickHandleWithIndex)clickWithIndex;

- (void)show;

// alert will resign keywindow in the completion.
- (void)dismissWithCompletion:(void(^)(void))completion;

@end




/**
 *  使用示例
 */

//    1.只有一个Button
//   [WJYAlertView showOneButtonWithTitle:@"我爱你"
//                                Message:@"这只是一个测试"
//                             ButtonType:WJYAlertViewButtonTypeHeight
//                            ButtonTitle:@"确定"
//                             Click:^{
//                                 NSLog(@"点击了确定");
//                             }];
//     2.两个button
//    [WJYAlertView showTwoButtonsWithTitle:@"我爱你"
//                                  Message:@"这也是一个测试"
//                               ButtonType:WJYAlertViewButtonTypeNone
//                              ButtonTitle:@"确定"
//                                    Click:^{
//                                        NSLog(@"点击了确定");
//                                    } ButtonType:WJYAlertViewButtonTypeWarn
//                              ButtonTitle:@"警告"
//                                    Click:^{
//                                        NSLog(@"点击了警告");
//                                    }];
//     3.多上button
//    [WJYAlertView showMultipleButtonsWithTitle:@"我爱你"
//                                       Message:@"这还是一个测试"
//                                         Click:^(NSInteger index) {
//                                             NSLog(@"%ld",index);
//                                         } Buttons:@{@(WJYAlertViewButtonTypeHeight):@"高亮"},
//                                                   @{@(WJYAlertViewButtonTypeWarn):@"第三个"},
//                                                   @{@(WJYAlertViewButtonTypeHeight):@"什么都不是"},nil];
//    4.自定义视图

//    UIView *customView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 240, 200)];
//    customView.backgroundColor = [UIColor redColor];
//
//    UIButton *btn = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, 100, 40)];
//    [btn setTitle:@"点我关闭" forState:UIControlStateNormal];
//    btn.center = CGPointMake(120, 100);
//    [customView addSubview:btn];
//    [btn addTarget:self action:@selector(closeBtnClick) forControlEvents:UIControlEventTouchUpInside];
//    //aletView 最好设成属性做全局用，否则可能会出错
//    //dismissWhenTouchedBackground:NO表示背景蒙层没有关闭弹出窗效果
//     _alertView = [[WJYAlertView alloc] initWithCustomView:customView dismissWhenTouchedBackground:YES];
//    [_alertView show];

//5.有标题的带输入框的弹框
//    WJYAlertInputTextView *myInputView=[[WJYAlertInputTextView alloc]initPagesViewWithTitle:@"消息内容" leftButtonTitle:@"取消" rightButtonTitle:@"确定" placeholderText:@"请输入正确的订单号"];
//
//    __weak typeof(self)weakSelf = self;
//    myInputView.leftBlock=^(NSString *text)
//    {
//        NSLog(@"当前值：%@",text);
//        [weakSelf.alertView dismissWithCompletion:nil];
//    };
//    myInputView.rightBlock=^(NSString *text)
//    {
//        if (text.length==0) {
//            //ToView:weakSelf.alertView这样才会显示出来 否则会被AlertView盖住
//            [MBProgressHUD showError:@"内容没有输入" ToView:weakSelf.alertView];
//            return;
//        }
//        weakSelf.alertView.window.windowLevel = UIWindowLevelStatusBar +1;
//        [MBProgressHUD showAutoMessage:[NSString stringWithFormat:@"当前内容为:%@",text]];
//        [weakSelf.alertView dismissWithCompletion:nil];
//    };

//    _alertView=[[WJYAlertView alloc]initWithCustomView:myInputView dismissWhenTouchedBackground:NO];
//    [_alertView show];

//    6.无标题的带输入框弹窗
//    WJYAlertInputTextView *myInputView=[[WJYAlertInputTextView alloc]initPagesViewWithTitle:nil leftButtonTitle:@"取消" rightButtonTitle:@"确定" placeholderText:@"请输入正确的订单号"];
//
//    __weak typeof(self)weakSelf = self;
//    myInputView.leftBlock=^(NSString *text)
//    {
//        NSLog(@"当前值：%@",text);
//        [weakSelf.alertView dismissWithCompletion:nil];
//    };
//    myInputView.rightBlock=^(NSString *text)
//    {
//        if (text.length==0) {
//            //ToView:weakSelf.alertView这样才会显示出来 否则会被AlertView盖住
//            [MBProgressHUD showError:@"内容没有输入" ToView:weakSelf.alertView];
//
//            return;
//        }
//        weakSelf.alertView.window.windowLevel = UIWindowLevelStatusBar +1;
//        [MBProgressHUD showAutoMessage:[NSString stringWithFormat:@"当前内容为:%@",text]];
//        [weakSelf.alertView dismissWithCompletion:nil];
//    };
//
//
//    _alertView=[[WJYAlertView alloc]initWithCustomView:myInputView dismissWhenTouchedBackground:NO];
//    [_alertView show];



//-(void)closeBtnClick
//{
//    // 如果没有其它事件要处理可以直接用下面这样关闭
//     [_alertView dismissWithCompletion:nil];
//
////    [_alertView dismissWithCompletion:^{
////        // 处理内容
////        NSLog(@"弹出窗被关闭了");
////    }];
//}


