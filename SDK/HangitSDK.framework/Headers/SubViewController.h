//
//  SubViewController.h
//  Hangit
//
//  Created by John Dutchak on 2/14/15.
//  Copyright (c) 2015 Hangit LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SubViewController : UIViewController <UITableViewDelegate, UITableViewDataSource> {

    NSUserDefaults * prefs;
    
}

@property (nonatomic, retain) NSIndexPath * checkedIndexPath;

@property (nonatomic, strong) IBOutlet UITableView * tableView;

@property (nonatomic, retain) NSMutableArray * tableData;

@property (nonatomic, strong) IBOutlet UIButton * backButon;

@end
