//
//  MapManager.h
//  Hangit
//
//  Created by John Dutchak on 12/27/14.
//  Copyright (c) 2014 Hangit LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import <CoreLocation/CoreLocation.h>
#import <AdSupport/ASIdentifierManager.h>
#import "OfferController.h"

@interface MapManager : UIViewController <MKMapViewDelegate> {

    NSUserDefaults * prefs;
    
    OfferController * offerController;
    
}

@property (nonatomic, strong) NSTimer * updateTimer;

@property (nonatomic, assign) BOOL trackUser;

@property (weak, nonatomic) IBOutlet MKMapView * mapView;

@property (weak, nonatomic) IBOutlet UIButton * currentLocationButton;

@property (weak, nonatomic) IBOutlet UIButton * refreshMapButton;

@property (nonatomic, strong) NSMutableArray * trackPointArray;

- (IBAction)gotoCurrentLocation:(id)sender;

- (IBAction)refreshMap:(id)sender;

- (void)plotLocations;

@end
