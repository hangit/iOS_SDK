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
#import "LocationManager.h"
#import "WalletController.h"

@protocol SessionManagerDelegate <NSObject>

/* Methods */
@required

@optional

- (NSString *)deviceId;

@end

@interface SessionManager : NSObject <SessionManagerDelegate> {
    
    NSString * adid;
    
    NSUserDefaults * prefs;

    WalletController * walletController;
    
}

+ (SessionManager *)sharedInstance;

@property (nonatomic, weak) id <SessionManagerDelegate>delegate;

@property (nonatomic, strong) LocationManager * lm;

@property (nonatomic, assign) BOOL isReachable;

@property (nonatomic) NSInteger sessionCount;

- (NSString *)deviceId;

- (NSString *)startSession:(NSString *)apiKey;

//@DEPRECATED
//- (NSString *)startSessionUsingLocation:(NSString *)apiKey;

//@DEPRECATED
//- (void)stopSession;

- (void)startLocation;

- (void)stopLocation;

- (void)clearDevice;

- (void)openWallet;

- (void)presentNotification:(BOOL)present;

- (BOOL)isLocationEnabled;

- (BOOL)checkNetworkStatus:(NSNotification *)notif;

@property (nonatomic) BOOL presentNotifications;

@property (nonatomic) BOOL presentOfferView;

@end
