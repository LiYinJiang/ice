// **********************************************************************
//
// Copyright (c) 2003-2018 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

#ifdef ICE_USE_SYSTEMD

#include <Ice/SystemdJournalI.h>
#include <Ice/LocalException.h>
#include <syslog.h>
#include <systemd/sd-journal.h>

using namespace std;
using namespace Ice;
using namespace IceInternal;

Ice::SystemdJournalI::SystemdJournalI(const string& prefix) :
    _prefix(prefix)
{
}

void
Ice::SystemdJournalI::print(const string& message)
{
    write(LOG_INFO, message);
}

void
Ice::SystemdJournalI::trace(const string& category, const string& message)
{
    write(LOG_INFO, category + ": " + message);
}

void
Ice::SystemdJournalI::warning(const string& message)
{
    write(LOG_WARNING, message);
}

void
Ice::SystemdJournalI::error(const string& message)
{
    write(LOG_ERR, message);
}

string
Ice::SystemdJournalI::getPrefix()
{
    return _prefix;
}

Ice::LoggerPtr
Ice::SystemdJournalI::cloneWithPrefix(const string& prefix)
{
    return ICE_MAKE_SHARED(SystemdJournalI, prefix);
}

void
Ice::SystemdJournalI::write(int priority, const string& message) const
{
    sd_journal_send("MESSAGE=%s", message.c_str(),
                    "PRIORITY=%i", priority,
                    "SYSLOG_IDENTIFIER=%s", _prefix.c_str(),
                    0);
}

#endif
