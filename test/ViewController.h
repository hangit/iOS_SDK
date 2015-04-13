//
//  ViewController.h
//  test
//
//  Created by John Dutchak on 4/10/15.
//  Copyright (c) 2015 Hangit LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <HangitSDK/HangitSDK.h>

@interface ViewController : UIViewController <SessionManagerDelegate>

/* Hangit SessionManager */
@property (nonatomic, strong) SessionManager *sessionManager;

/* Hangit MapManager */
@property (nonatomic, strong) MapManager *mapManager;

/* Hangit sessionKey Property */
@property (nonatomic, retain) NSString * sessionKey;

@property (nonatomic, strong) UIButton * chevron;

@end

