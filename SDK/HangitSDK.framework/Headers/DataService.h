//
//  DataService.h
//  HangitSDK
//
//  Created by John Dutchak on 4/9/15.
//  Copyright (c) 2015 Hangit LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class DataModel;

@interface DataService : NSObject {
    
    NSUserDefaults * prefs;
    
}

+ (DataService *)instance;


/* Data Service Methods */

- (void)getLocationsWithLocation:(CLLocation *)location
                      sessionKey:(NSString *)sessionKey
                      completion:(void (^)(NSMutableArray * parametersArray,
                                           NSMutableArray * targetsArray,
                                           NSMutableArray * offersArray,
                                           NSMutableArray * redemptionsArray,
                                           NSError * error))completion;

- (void)getOffersWithLocation:(CLLocation *)location
                   sessionKey:(NSString *)sessionKey
                   completion:(void (^)(NSMutableArray * offersArray,
                                        NSError * error))completion;

- (void)getMOffersWithLocation:(CLLocation *)location
                    sessionKey:(NSString *)sessionKey
                        idType:(NSString *)idType
                      targetId:(NSString *)targetId
                         theid:(NSString *)theid
                         refId:(NSString *)refId
                    completion:(void (^)(NSMutableArray * offersArray,
                                         NSError * error))completion;

- (void)getRegionsWithSessionKey:(NSString *)sessionKey
                      completion:(void (^)(NSMutableArray * regionsArray,
                                           NSError * error))completion;

- (void)acknowledgeWithAlertID:(NSString *)alertId
                    sessionKey:(NSString *)sessionKey
                    completion:(void (^)(NSString * response,
                                         NSError * error))completion;

- (void)offerStatusWithOfferID:(NSString *)offerId
                    sessionKey:(NSString *)sessionKey
                    statusCode:(NSString *)statusCode
                    completion:(void (^)(NSString * response,
                                         NSError * error))completion;

- (void)setMaxNumberOfNotifications:(NSString *)maxNotifications
                         sessionKey:(NSString *)sessionKey
                         completion:(void (^)(NSString * response,
                                              NSError * error))completion;

- (void)setRatingWithCampaignId:(NSString *)campaignid
                       ratingid:(NSString *)ratingid
                     sessionKey:(NSString *)sessionKey
                     completion:(void (^)(NSString * response,
                                          NSError * error))completion;

- (void)deleteDeviceWithSesionKey:(NSString *)sessionKey
                       completion:(void(^)(NSString * response,
                                           NSError * error)) completion;



@end
