//
//  OfferFullViewController.h
//  Hangit
//
//  Created by John Dutchak on 3/16/15.
//  Copyright (c) 2015 Hangit LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface OfferFullViewController : UIViewController <UIWebViewDelegate> {
    
    NSUserDefaults * prefs;
    
}

/* Offer properties */

@property (nonatomic, retain) NSString * eventId;

@property (nonatomic, retain) NSString * deviceEventId;

@property (nonatomic, retain) NSString * mediaType;

@property (nonatomic, retain) NSString * mediaURL;

@property (nonatomic, retain) NSString * mediaURLWide;

@property (nonatomic, retain) NSString * mediaImgURL;

@property (nonatomic, retain) NSString * mediaTitle;

@property (nonatomic, retain) NSString * mediaDesc;

@property (nonatomic, retain) NSString * alertText;

//@property (nonatomic, retain) UIActivityIndicatorView * activityIndicator;

//@property (nonatomic, retain) NSString * offer_id;
//
//@property (nonatomic, retain) NSString * offer_adURI;
//
//@property (nonatomic, retain) NSString * offer_useitURI;
//
//@property (nonatomic) float offer_lat;
//
//@property (nonatomic) float offer_lng;
//
//@property (nonatomic, retain) NSString * offer_miles;
//
//@property (nonatomic, retain) NSString * offer_headerText;
//
//@property (nonatomic, retain) NSString * offer_displayText;
//
//@property (nonatomic, retain) NSString * offer_campaignid;


@property (nonatomic, strong) IBOutlet UIWebView * adWebView;

@property (nonatomic, strong) IBOutlet UIButton * closeButton;

- (IBAction)closeMe:(id)sender;

@end
