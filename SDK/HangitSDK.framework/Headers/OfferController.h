//
//  OfferController.h
//  Hangit
//
//  Created by John Dutchak on 2/7/15.
//  Copyright (c) 2015 Hangit LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import <CoreLocation/CoreLocation.h>
#import <MessageUI/MFMessageComposeViewController.h>
#import <MessageUI/MFMailComposeViewController.h>


@interface OfferController : UIViewController <MKMapViewDelegate, MFMailComposeViewControllerDelegate, MFMessageComposeViewControllerDelegate> {
    
    NSUserDefaults * prefs;

}

/* Offer properties */

@property (nonatomic, retain) NSString * offer_id;

@property (nonatomic, retain) NSString * offer_adURI;

@property (nonatomic, retain) NSString * offer_useitURI;

@property (nonatomic) float offer_lat;

@property (nonatomic) float offer_lng;

@property (nonatomic, retain) NSString * offer_miles;

@property (nonatomic, retain) NSString * offer_headerText;

@property (nonatomic, retain) NSString * offer_displayText;

@property (nonatomic, retain) NSString * offer_campaignid;

/* Outlets */

@property (weak, nonatomic) IBOutlet MKMapView * mapView;

@property (nonatomic, strong) IBOutlet UIWebView * adWebView;

@property (nonatomic, strong) IBOutlet UIWebView * useWebView;

@property (nonatomic, strong) IBOutlet UIView * rateView;

@property (nonatomic, strong) IBOutlet UIView * shareView;

@property (nonatomic, strong) IBOutlet UIButton * mapButton;

@property (nonatomic, strong) IBOutlet UIButton * rateButton;

@property (nonatomic, strong) IBOutlet UIButton * shareButton;

@property (nonatomic, strong) IBOutlet UIButton * useButton;

@property (nonatomic, strong) IBOutlet UIButton * backButton;

@property (nonatomic, strong) IBOutlet UIButton * closeButton;

@property (nonatomic, strong) IBOutlet UIButton * shareEmail;

@property (nonatomic, strong) IBOutlet UIButton * shareSMS;

@property (nonatomic, strong) IBOutlet UIButton * rateYes;

@property (nonatomic, strong) IBOutlet UIButton * rateNo;

@property (nonatomic, strong) UIButton * redeemButton;

- (IBAction)goBack:(id)sender;
- (IBAction)showMap:(id)sender;
- (IBAction)showRate:(id)sender;
- (IBAction)showShare:(id)sender;
- (IBAction)showUse:(id)sender;
- (IBAction)shareEmail:(id)sender;
- (IBAction)shareSMS:(id)sender;
- (IBAction)closeMe:(id)sender;
- (IBAction)rateYes:(id)sender;
- (IBAction)rateNo:(id)sender;

@end
