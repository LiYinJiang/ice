// **********************************************************************
//
// Copyright (c) 2003-2015 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in
// the ICE_LICENSE file included in this distribution.
//
// **********************************************************************

#import <objc/Ice/Config.h>

#import <objc/Ice/Object.h>

@protocol ICESlicedData<NSObject>
@end

@interface ICEUnknownSlicedObject : ICEObject
{
@private
    NSString* unknownTypeId_;
    id<ICESlicedData> slicedData_;
}
-(NSString*) getUnknownTypeId;
-(id<ICESlicedData>) getSlicedData;
@end
