#pragma once

#include <Core/Core.h>

#ifdef JEM_ENABLE_ASSERTIONS
    // Tests expression and breaks with a message on false.
    #define JEM_ASSERT(expression, /*message*/...)        \
        if (expression) {}                                \
        else {                                            \
            JEM_ERROR("Assertion Failed: ", __VA_ARGS__); \
        }
    
    // Tests expression and breaks with a message on false.
    // For use by Core systems.
    #define JEM_CORE_ASSERT(expression, /*message*/...)        \
        if (expression) {}                                     \
        else {                                                 \
            JEM_CORE_ERROR("Assertion Failed: ", __VA_ARGS__); \
        }

#else
    #define JEM_ASSERT(expression, ...)       // Strip out assertions for optimization.
    #define JEM_CORE_ASSERT(expression, ...)

#endif // JEM_ENABLE_ASSERTIONS