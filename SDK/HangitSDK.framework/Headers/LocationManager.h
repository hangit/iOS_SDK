//
//  LocationManager.h
//  HangitSDK
//
//  Created by John Dutchak on 4/9/15.
//  Copyright (c) 2015 Hangit LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "OfferFullViewController.h"
#import <CoreMotion/CoreMotion.h>

@interface LocationManager : NSObject <CLLocationManagerDelegate>
{
    
    UILocalNotification * localNotification;
    
    NSUserDefaults * prefs;
        
    OfferFullViewController * offerFullViewController;
    
}

@property (retain, nonatomic) CMMotionActivityManager * motionActivityManager;

@property (strong, nonatomic) NSTimer * updateTimer;

@property (strong, nonatomic) NSTimer * logTimer;

@property (strong, nonatomic) CLLocationManager * locationManager;

@property (strong, nonatomic) NSMutableArray * targets;

@property (strong, nonatomic) NSMutableArray * offers;

@property (nonatomic) BOOL accuracyError;

@property (nonatomic, retain) NSMutableArray * logHistoryArray;

@property (nonatomic, retain) NSMutableArray * logMotionArray;

@property (nonatomic, retain) NSMutableArray * logTargetsArray;

@property (nonatomic) BOOL presentNotifications;

@property (nonatomic) BOOL presentOfferView;

- (void)initLocation;

- (void)startMonitoringLocation;

- (void)stopMonitoringLocation;

@end
