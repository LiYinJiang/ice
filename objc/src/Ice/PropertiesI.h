// **********************************************************************
//
// Copyright (c) 2003-2015 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

#import <objc/Ice/Properties.h>

#import <Wrapper.h>

#include <Ice/Properties.h>
#include <Ice/NativePropertiesAdmin.h>

@interface ICEProperties : ICEInternalWrapper<ICEProperties>
{
    Ice::Properties* properties_;
}
-(Ice::Properties*)properties;
@end

@interface ICEPropertiesAdminUpdateCallback ()
-(void) setPropertiesAdminUpdateCallback:(Ice::PropertiesAdminUpdateCallback*)callback;
-(Ice::PropertiesAdminUpdateCallback*) propertiesAdminUpdateCallback;
@end

@interface ICENativePropertiesAdmin : ICEInternalWrapper<ICENativePropertiesAdmin>
@end
