//
//  WalletController.h
//  HangitSDK
//
//  Created by John Dutchak on 4/22/16.
//  Copyright © 2016 Hangit LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@interface WalletController : UIViewController <WKNavigationDelegate, UIWebViewDelegate>

@property (nonatomic, strong) IBOutlet UINavigationBar * navbar;

@property (nonatomic, retain) NSString * navTitle;

@property (nonatomic, retain) NSString * urlString;

@property (nonatomic, strong) WKWebView * wkv;

@property (nonatomic, strong) IBOutlet UIWebView * webView;

@property (nonatomic, strong) IBOutlet UIButton * closeButton;

@property (nonatomic, strong) IBOutlet UIButton * backButton;

- (IBAction)closeMe:(id)sender;

- (IBAction)goBack:(id)sender;

@end
