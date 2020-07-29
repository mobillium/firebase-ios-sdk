/*
 * Copyright 2020 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

#import "FirebaseInstallations/Source/Library/InstallationsIDController/FIRCurrentDateProvider.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, FIRInstallationsBackoffEvent) {
  FIRInstallationsBackoffEventSuccess,
  FIRInstallationsBackoffEventRecoverableFailure,
  FIRInstallationsBackoffEventUnrecoverableFailure
};

@protocol FIRInstallationsBackoffControllerProtocol <NSObject>

- (void)registerEvent:(FIRInstallationsBackoffEvent)event;
- (BOOL)isNextRequestAllowed;

@end

@interface FIRInstallationsBackoffController : NSObject <FIRInstallationsBackoffControllerProtocol>

- (instancetype)initWithCurrentDateProvider:(FIRCurrentDateProvider)currentDateProvider;

@end

NS_ASSUME_NONNULL_END
