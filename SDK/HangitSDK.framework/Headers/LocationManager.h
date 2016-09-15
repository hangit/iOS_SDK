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
#import "LocationMsgController.h"

@interface LocationManager : NSObject <CLLocationManagerDelegate> {

    UILocalNotification * localNotification;
    
    NSUserDefaults * prefs;
    
    int locationCount;
    
    BOOL updatingLocationFlag;
    
    BOOL locationServiceRunning;
    
    LocationMsgController * locationMsgController;
    
}

@property (nonatomic, strong) OfferFullViewController * offerFullViewController;

@property (strong, nonatomic) CLLocationManager * locationManager;

@property (strong, nonatomic) NSMutableArray * targets;

@property (strong, nonatomic) NSMutableArray * offers;

@property (nonatomic) BOOL accuracyError;

@property (nonatomic, retain) NSMutableArray * logHistoryArray;

@property (nonatomic, retain) NSMutableArray * logTargetsArray;

@property (nonatomic, retain) NSMutableArray * logLocationsArray;

@property (nonatomic) BOOL presentNotifications;

@property (nonatomic) BOOL presentOfferView;

@property (nonatomic) BOOL withLocation;

@property (nonatomic) BOOL deviceHasExited;

@property (nonatomic) BOOL eventBeingChecked;

@property (strong, nonatomic) NSTimer * queueMessageTimer;

@property (strong, nonatomic) NSTimer * checkTimer;

@property (strong, nonatomic) NSTimer * updateTimer;

@property (strong, nonatomic) NSTimer * logTimer;

@property (strong, nonatomic) NSMutableArray * placesInTimer;

- (void)initLocation;

- (void)startMonitoringLocation;

- (void)stopMonitoringLocation;


@end
