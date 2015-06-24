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
#import "OfferFullViewController.h"

@interface MapManager : UIViewController <MKMapViewDelegate> {

    NSUserDefaults * prefs;
    
}

@property (nonatomic, strong) OfferFullViewController * offerFullViewController;

@property (nonatomic, assign) BOOL trackUser;

@property (weak, nonatomic) IBOutlet MKMapView * mapView;

@property (weak, nonatomic) IBOutlet UIButton * currentLocationButton;

@property (weak, nonatomic) IBOutlet UIButton * refreshMapButton;

- (IBAction)gotoCurrentLocation:(id)sender;

- (IBAction)refreshMap:(id)sender;

- (void)plotLocations;

@end
