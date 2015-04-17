//
//  SessionManager.h
//  HangitSDK
//
//  Created by John Dutchak on 4/9/15.
//  Copyright (c) 2015 Hangit LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AdSupport/ASIdentifierManager.h>
#import <SystemConfiguration/SystemConfiguration.h>

@protocol SessionManagerDelegate <NSObject>

/* Methods */
@required

@optional

- (NSString *)deviceId;

@end

@interface SessionManager : NSObject <SessionManagerDelegate> {
    
    NSString * adid;
    
    NSUserDefaults * prefs;
    
}

+ (SessionManager *)sharedInstance;

@property (nonatomic, weak) id <SessionManagerDelegate>delegate;

@property (nonatomic, assign) BOOL isReachable;

- (NSString *)deviceId;

- (NSString *)startSession:(NSString *)apiKey;

- (NSString *)startSessionUsingLocation:(NSString *)apiKey;

- (BOOL)checkNetworkStatus:(NSNotification *)notif;

@property (nonatomic) BOOL presentNotifications;

@property (nonatomic) BOOL presentOfferView;

@end
