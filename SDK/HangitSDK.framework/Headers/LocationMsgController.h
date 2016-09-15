//
//  LocationMsgController.h
//  HangitSDK
//
//  Created by John Dutchak on 7/18/16.
//  Copyright © 2016 Hangit LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LocationMsgController : UIViewController {
    
    NSUserDefaults * prefs;
    
}

@property (nonatomic, copy) void (^didDismiss)(NSString *data);

@property (nonatomic, strong) IBOutlet UIButton * okButton;
@property (nonatomic, strong) IBOutlet UIButton * blockButton;
@property (nonatomic, strong) IBOutlet UITextView * locMessage;
@property (nonatomic, strong) IBOutlet UIView * locView;

- (IBAction)closeMe:(id)sender;
- (IBAction)blockMe:(id)sender;

@end
