//
//  ContentController.h
//  Hangit
//
//  Created by John Dutchak on 1/25/15.
//  Copyright (c) 2015 Hangit LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ContentController : UIViewController <UIWebViewDelegate>

@property (nonatomic, strong) IBOutlet UINavigationBar * navbar;

@property (nonatomic, retain) NSString * navTitle;

@property (nonatomic, retain) NSString * urlString;

@property (nonatomic, strong) IBOutlet UIWebView * webView;

@end
