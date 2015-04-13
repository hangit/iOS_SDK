//
//  SettingsController.h
//  Hangit
//
//  Created by John Dutchak on 1/5/15.
//  Copyright (c) 2015 Hangit LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ContentController.h"
#import "SubViewController.h"

@interface SettingsController : UIViewController <UITableViewDelegate, UITableViewDataSource> {
    
    ContentController * contentController;

    SubViewController * subViewController;
    
    NSUserDefaults * prefs;
    
}

@property (nonatomic, strong) IBOutlet UITableView * tableView;

@property (nonatomic, retain) NSMutableArray * tableData;


@end
