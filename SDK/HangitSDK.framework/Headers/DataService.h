//
//  DataService.h
//  HangitSDK
//
//  Created by John Dutchak on 4/9/15.
//  Copyright (c) 2015 Hangit LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface DataService : NSObject {
    
    NSUserDefaults * prefs;
    
}
/**
 *  @author John Dutchak, 15-04-14 21:04:32
 *
 *  DataService Layer
 *
 *  @return an Instance class
 */
+ (DataService *)instance;

- (void)getLocationsWithLocation:(CLLocation *)location
                      sessionKey:(NSString *)sessionKey
                      completion:(void (^)(NSMutableArray * targetsArray,
                                           NSError * error))completion;

- (void)sendDeviceLinkWithEventId:(NSString *)eventId
                          placeId:(NSString *)placeId
                       sessionKey:(NSString *)sessionKey
                    completion:(void (^)(NSMutableArray * places,
                                         NSString * response,
                                         NSError * error))completion;

- (void)sendDeviceUpdateWithDeviceEventId:(NSString *)deviceEventId
                         statusCode:(NSString *)statusCode
                       sessionKey:(NSString *)sessionKey
                       completion:(void (^)(NSString * response,
                                            NSError * error))completion;

- (void)sendDeviceClearWithSessionKey:(NSString *)sessionKey
                           completion:(void (^)(NSString * response,
                                                NSError * error))completion;

- (void)addDeviceTagWithSessionKey:(NSString *)sessionKey
                         DeviceTag:(NSString *)deviceTag
                    DeviceTagValue:(NSString *)deviceTagValue
                          GroupTag:(NSString *)groupTag
                        completion:(void (^)(NSString * response,
                                             NSError * error))completion;

- (void)deleteDeviceTagWithSessionKey:(NSString *)sessionKey
                         DeviceTag:(NSString *)deviceTag
                          GroupTag:(NSString *)groupTag
                        completion:(void (^)(NSString * response,
                                             NSError * error))completion;

- (void)getEvent:(NSString *)eventId
       DeviceId:(NSString *)deviceId
      completion:(void (^)(NSDictionary * response,
                           NSError * error))completion;

@end
