# iOS_SDK
Hangit iOS SDK and Test Project. This SDK supports iOS7 and up. Background location is supported under iOS 8 and higher apps.

Latest version

The latest version of the Hangit iOS SDK Framework is 1.2.0 and was released May, 7th 2015.

Overview

This document shows you a quick way to start using the Hangit iOS SDK Framework for location-aware apps. You will find code examples for core features, and best practices that developers should follow.

Installing the iOS SDK Framework

In this section we’ll run through the steps to add our Framework to your Xcode project.

You will not be able to monitor changes for CoreMotion using the Simulator, you will need to test and run your project on a real device.
If this is your first time out with Xcode and iOS App development, then we recommend you read Apple’s introductory guide.

Download the SDK Framework files

Clone the git repo - git clone https://github.com/hangit/iOS_SDK.git

Change to Example folder - cd iOS_SDK

Open the test.xcodeproj and run

To use in your own app. Add the SDK Framework files to your project found under the SDK folder.

Create a new project in Xcode and give it a name.
Create an empty folder in your project directory.
Copy the resource bundle HangitResources.bundle to your new folder.
Choose File > Add Files to Your ProjectName.
Select your new folder containing the SDK files
Drag the Hangit.framework file to your Embedded Binaries section under General for your projects target.
Add file to embedded binaries

Link the SDK files to your project

In XCode 6, the SDK will be linked automatically to your project.

If you need to manually link the files, or just check that they are there:

In the project navigator, select your project.
Click Build Phases -> Link Binary With Libraries.
Check that Hangit.framework is already added, if it isn’t:
Click the Add button (+).
Select Hangit.framework and click Add.
Your project now references the Hangit SDK Framework and your installation is complete.

Adding objects and methods

Now we can start using objects and methods from the SDK. First we need to establish a session with your app and the SDK.

Go to your ViewController.h and can add the following. The process is simple and all our objects are modular and configurable to fit your apps design pattern.

Make this View Controller a SessionManagerDelegate

And implement its methods:

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

Add to viewDidLoad()

    self.sessionManager = [SessionManager sharedInstance];

    self.sessionManager.delegate = self;

    //Push Notification To Users
    self.sessionManager.presentNotifications = YES;

    //Present Offers To Users
    self.sessionManager.presentOfferView = YES;

    self.sessionKey = [self.sessionManager startSessionUsingLocation:@"YOURAPIKEY"];
    
The _sessionKey property will contain the unique key for this app's session providing continued communication with the Hangit network allowing this user to receive offers specific to them and their location.
Add iOS 8 Compatibility

For your app to work correctly with iOS 8 you have to add a new key to your project’s plist file.

In the project navigator, select your project.
Select your projects Info.plist file
Add the following key string pair to the file.
    <key>NSLocationAlwaysUsageDescription</key>
    <string>Uses background location</string>
The string can be empty, or defined by you the developer, the content is not important.

In the project navigator, select your project.
Select your projects Target and choose Capabilities
Turn on Background Modes.
Select "Location updates" and "Background fetch"
iOS 8 compatability is now complete.

Receiving SDK Location Updates

In the following example we’ll show you how the Hangit SDK can provide your app with the device's location updates. This will save time from implementing your own location manager.

Add an Observer to your class

In our example, we have used the ViewController.m class for simplicity, you can create the Observer on any class in your project.

First we’ll include the Hangit SDK Framework.

    #import <HangitSDK/HangitSDK.h>

And Implement the NSNotificationCenter Observer and callback method

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(locationNotification:)  name:@"hangitLocationNotification" object:nil];

    - (void) locationNotification:(NSNotification *)notification{

        if ([notification object]) {
          CLLocation * location = [[notification object] objectForKey:@"Location"];
          NSLog(@"location callback: %@", location);
        }
    }

This code has created an Observer that will monitor for location updates received in the Hangit SDK. You can consume these location updates in any ViewController in your app for your development location requirements and to send to our DataService to comsume Hangit JSON Campaigns & Offers.

Requirement: Implement the didReceiveNotification callback to your AppDelegate.m

    /* Hangit AppDelegate NotificaitonManager Requirement */
    - (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification {

    //OPTIONAL ** use a timer delay for notificaiton if you have slow loading startup view controller(s)
    dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, 5.0 * NSEC_PER_SEC);
    
    dispatch_after(popTime, dispatch_get_main_queue(), ^(void){
        
        [[NSNotificationCenter defaultCenter] postNotificationName:@"hangitNotificationReceived" object:notification];
        
    });


    }

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notificationReceived:)
    name:@"hangitNotificationReceived" object:nil];

    - (void) notificationReceived:(NSNotification *)notification {
        if ([notification object]) {
         NSLog(@"notification callback: %@", [notification object]);
        }
    }

Consuming Hangit Campaigns

In the following example we’ll show you how the Hangit SDK can provide your app with raw JSON Campaign data allowing you to use it in any way that meets your requirements.

Add a Hangit DataService object to your class

In our example, we have used the ViewController.m class for simplicity; you can create the Observer on any class in your project.

And Implement the DataService object and callback method

    CLLocation * myLocation = [[CLLocation alloc] initWithLatitude:28.550 longitude:-81.400];

    [[DataService instance] getLocationsWithLocation:myLocation sessionKey:@"1234567890"
        completion:^(NSMutableArray *targetsArray, NSError *error) {

       NSLog(@"%@", targetsArray);

    }];

This code has created a Hangit DataService object that will retrieve Campaign, Offer and Redemption data in raw JSON format within X meters from your users reported location. Each response is converted to a NSMutable Array.

Adding the Hangit Offers Map. Class Type: Apple MapKit

In the following example we’ll show you how to can create a Hangit Offers Map to visually monitor Offers based on the users current location.

Add the MapModule to your class

    @property (nonatomic, strong) MapManager * mapManager;

In our example, we have used the ViewController.m class for simplicity; you can create the MapModule on any class in your project.

And Implement the Hanigt MapManager

    self.mapManager = [[MapManager alloc] initWithNibName:@"MapManager" bundle:[NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"HangitSDKResources" ofType:@"bundle"]]];

    /* 1. Add the map to the current view and define the frame parameters */

    self.mapManager.view.frame = CGRectMake(0,0,320,200);

    self.mapManager.view.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;

    [self.view addSubview:self.mapManager.view];

This code has placed the Offers Map on your view controller. You can decide what size you would like the map frame rect to be in order to fit with the design of your app.

In the following example we’ll show you how to can create a Hangit Settings UITableView to display the SDK settings.

    @property (nonatomic, strong) SettingsController * settingsController;

And Implement the Hangit Settings View

    self.settingsController = [[SettingsController alloc] initWithNibName:@"SettingsController"
        bundle:[NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"HangitSDKResources" ofType:@"bundle"]]];

    /* 1. Add the UITableView to the current view and define the frame parameters */

    self.settingsController.view.frame = CGRectMake(0,0,320,200);

    self.settingsController.view.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;

    [self.view addSubview:self.settingsController.view];

This code has placed the Settings Controller on your view controller. You can decide what size you would like the table view frame rect to be in order to fit with the design of your app.
