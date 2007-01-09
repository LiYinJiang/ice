# **********************************************************************
#
# Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
#
# This copy of Ice is licensed to you under the terms described in the
# ICE_LICENSE file included in this distribution.
#
# **********************************************************************

top_srcdir	= ..\..\..

CLIENT		= client.exe
SERVER		= server.exe
VERIFIER        = verifier.exe

TARGETS		= $(CLIENT) $(SERVER) $(VERIFIER)

COBJS		= Client.obj \
		  AllTests.obj

SOBJS		= Server.obj

VOBJS		= PermissionsVerifier.obj

SRCS		= $(COBJS:.obj=.cpp) \
		  $(SOBJS:.obj=.cpp) \
		  $(VOBJS:.obj=.cpp)

!include $(top_srcdir)/config/Make.rules.mak

CPPFLAGS	= -I. -I../../include $(CPPFLAGS) -DWIN32_LEAN_AND_MEAN
LINKWITH	= $(LIBS) glacier2$(LIBSUFFIX).lib

!if "$(CPP_COMPILER)" != "BCC2006" & "$(OPTIMIZE)" != "yes"
CPDBFLAGS        = /pdb:$(CLIENT:.exe=.pdb)
SPDBFLAGS        = /pdb:$(SERVER:.exe=.pdb)
VPDBFLAGS        = /pdb:$(VERIFIER:.exe=.pdb)
!endif

$(CLIENT): $(COBJS)
	$(LINK) $(LD_EXEFLAGS) $(CPDBFLAGS) $(COBJS) $(PREOUT)$@ $(PRELIBS)$(LINKWITH) icegrid$(LIBSUFFIX).lib

$(VERIFIER): $(VOBJS)
	$(LINK) $(LD_EXEFLAGS) $(VPDBFLAGS) $(VOBJS) $(PREOUT)$@ $(PRELIBS)$(LINKWITH)

$(SERVER): $(SOBJS)
	$(LINK) $(LD_EXEFLAGS) $(SPDBFLAGS) $(SOBJS) $(PREOUT)$@ $(PRELIBS)$(LINKWITH) icessl$(LIBSUFFIX).lib

!include .depend
