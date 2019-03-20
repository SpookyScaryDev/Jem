#pragma once

#include "Core/Core.h"
#include <functional> // TODO: Maybe include pch?

// Returns a StringID object.
#define SID(str) StringID{ Jem::HashString(str), str } // <- Is there a better way?

namespace Jem {

	/*constexpr*/ std::size_t HashString(const char* str);     // TODO: Replace hash function. Crc32?    
	                                                           // because std::hash isn't constexpr.

	// A struct containing a hashed string id and a pointer to its cstring.
	struct JEM_API StringID
	{
		StringID&           operator=(const StringID& s);

		const std::size_t   mID;
		const char*         mStringPtr;
	};


	typedef StringID GameObjectID;
}

// Returns a raw hash value 
/*constexpr*/ std::size_t operator "" _sid(const char* str, size_t);   // Also could be in Jem?                                                                          