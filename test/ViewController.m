//
//  ViewController.m
//  test
//
//  Created by John Dutchak on 4/10/15.
//  Copyright (c) 2015 Hangit LLC. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [self startHangit];
    
    
}

/* Hangit Location Module */


- (void) startHangit
{
    self.sessionManager = [SessionManager sharedInstance];
    self.sessionManager.delegate = self;
    self.sessionManager.presentNotifications = YES;
    self.sessionManager.presentOfferView = YES;
    
    self.sessionKey = [self.sessionManager startSession:@"YOURAPIKEY"];
    
    /**
     *  Starts Location Manager in SDK
     *  Use this method when you want to
     *  offer location enabled deals
     */
    [self.sessionManager startLocation];
    
    /**
     *  Stops Location Manager in SDK
     *
     *  Stops Location Manager in SDK
     *  Use this method when you want to
     *  stop offering location enabled deals
     */
    //    [self.sessionManager stopLocation];
    
    /**
     *  Respond true or false wether location
     *  is enabled or disabled by the user
     *  for your app
     */
    //    [self.sessionManager isLocationEnabled];

    
    //  Hangit: Callback when the notification is viewed
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(messageViewedNotification:)
                                                     name:@"hangitMessageViewed"
                                                   object:nil];
    
    //  Hangit: Callback for recieving location events
    //    [[NSNotificationCenter defaultCenter] addObserver:self
    //                                             selector:@selector(locationNotification:)
    //                                                 name:@"hangitLocationNotification"
    //                                               object:nil];
    
    //  Hangit : Callback for Enter Target Area
    //    [[NSNotificationCenter defaultCenter] addObserver:self
    //                                             selector:@selector(inBounds:)
    //                                                 name:@"hangitInBounds"
    //                                               object:nil];
    
    
    //  Hangit : Show the Map
    [NSTimer scheduledTimerWithTimeInterval:3.0
                                     target:self
                                   selector:@selector(showMap)
                                   userInfo:nil
                                    repeats:NO];
    
}


- (void) locationNotification:(NSNotification *)notification{
    
    if ([notification object]) {
        
        CLLocation * location = [[notification object] objectForKey:@"Location"];
        
        NSLog(@"location callback: %@", location);
        
    }
    
}

- (void) messageViewedNotification:(NSNotification *)notification {
    
    if ([notification object]) {
        
        NSLog(@"message viewed callback: %@", [notification object]);
        
    }
    
}

- (void) inBounds:(NSNotification *)notification {
    
    if ([notification object]) {
        
        NSLog(@"in bounds area callback: %@", [notification object]);
        
    }
    
}

- (void)showMap {
    
    /* Show Hangit Map Module */
    
    self.mapManager = [[MapManager alloc] initWithNibName:@"MapManager"
                                                   bundle:[NSBundle bundleWithPath:[[NSBundle mainBundle]
                                                                                    pathForResource:@"HangitSDKResources"
                                                                                    ofType:@"bundle"]]];
    
    self.mapManager.view.frame = CGRectMake(0,20,[[UIScreen mainScreen] bounds].size.width,150);
    
    self.mapManager.view.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    
    self.chevron = [UIButton buttonWithType:UIButtonTypeCustom];
    
    self.chevron.frame = CGRectMake((self.mapManager.view.bounds.size.width / 2) - 40, -5, 80, 60);
    
    [self.chevron addTarget:self
                 action:@selector(resizeMap:)
       forControlEvents:UIControlEventTouchDown];
    
    [self.chevron setBackgroundImage:[UIImage imageNamed:@"ChevronDown"]
                            forState:UIControlStateNormal];
    
    [self.mapManager.view addSubview:self.chevron];
    
    [self.view addSubview:self.mapManager.view];
    
    /* End Show Hangit Map Module */
    
}

- (void)resizeMap:(id)sender {
    
    /* Animation Sizing Code for Hangit Map Module */
    
    if (self.mapManager.view.bounds.size.height == 150) {
        
        [self.chevron setBackgroundImage:[UIImage imageNamed:@"ChevronUp"]
                            forState:UIControlStateNormal];
        
        [UIView animateWithDuration:0.5
                              delay:0.1
                            options: UIViewAnimationOptionCurveEaseOut
                         animations:^{
                             self.mapManager.view.frame = CGRectMake(0, 20,
                                                                 [[UIScreen mainScreen] bounds].size.width,
                                                                 [[UIScreen mainScreen] bounds].size.height);
                         }
                         completion:^(BOOL finished){}];
    } else {
        
        [self.chevron setBackgroundImage:[UIImage imageNamed:@"ChevronDown"]
                            forState:UIControlStateNormal];
        
        [UIView animateWithDuration:0.5
                              delay:0.1
                            options: UIViewAnimationCurveEaseIn
                         animations:^{
                             self.mapManager.view.frame = CGRectMake(0, 20,
                                                                 [[UIScreen mainScreen] bounds].size.width,
                                                                 150);
                         }
                         completion:^(BOOL finished){ }];
        
    }
    
    /* End Animation Sizing Code for Hangit Map Module */
    
}

- (void)didReceiveMemoryWarning {
    
    [super didReceiveMemoryWarning];

}

@end
