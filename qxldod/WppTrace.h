/*
* Copyright 2013-2016 Red Hat, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
*
* You may obtain a copy of the License at
* http://www.apache.org/licenses/LICENSE-2.0
*/

#pragma once

//
// Define the tracing flags.
//
// Tracing GUID - {756ABE50-54E3-4A05-B5BB-F0112C75B18A}
//

#define WPP_CONTROL_GUIDS                                              \
    WPP_DEFINE_CONTROL_GUID(                                           \
        QxlDodTraceGuid, (756ABE50,54E3,4A05,B5BB,F0112C75B18A),       \
                                                                       \
        WPP_DEFINE_BIT(TRACE_DRIVER)                                   \
        WPP_DEFINE_BIT(TRACE_DEVICE)                                   \
        WPP_DEFINE_BIT(TRACE_MEMORY)                                   \
        WPP_DEFINE_BIT(TRACE_TIMING)                                   \
        WPP_DEFINE_BIT(TRACE_HARDWARE)                                 \
        )

#define WPP_FLAG_LEVEL_LOGGER(flag, level)     WPP_LEVEL_LOGGER(flag)

#define WPP_FLAG_LEVEL_ENABLED(flag, level)                            \
    (WPP_LEVEL_ENABLED(flag) &&                                        \
     WPP_CONTROL(WPP_BIT_ ## flag).Level >= level)

#define WPP_LEVEL_FLAGS_LOGGER(lvl,flags)      WPP_LEVEL_LOGGER(flags)

#define WPP_LEVEL_FLAGS_ENABLED(lvl, flags)                            \
    (WPP_LEVEL_ENABLED(flags) && WPP_CONTROL(WPP_BIT_ ## flags).Level >= lvl)

#if DBG
#define WPP_INIT_TRACING(driver, regpath)
#define WPP_CLEANUP(driver)
#endif

//
// This comment block is scanned by the trace preprocessor to define our
// Trace function.
//
// begin_wpp config
// FUNC Trace{FLAG=TRACE_DRIVER}(LEVEL,MSG, ...);
// FUNC TraceEvents(LEVEL, FLAGS, MSG, ...);
// FUNC DbgPrint{FLAG=TRACE_DRIVER}(LEVEL, (MSG, ...));
// CUSTOM_TYPE(devprop, ItemEnum(DEVICE_REGISTRY_PROPERTY));
// end_wpp
//
