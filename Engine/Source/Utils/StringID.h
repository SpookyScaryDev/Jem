#pragma once

#include "Core/Core.h"
#include <stdint.h>

// Returns a StringID object.
#define SID(str) StringID( Jem::HashFNV1a(str), str )

namespace Jem {
	// Allows for string iteration at compile time.
	constexpr const uint64_t HashFNV1aConcat(uint64_t base, const char *str) {
		return (*str) ? (HashFNV1aConcat((base ^ *str) * 0x100000001b3, str + 1)) : base;
	}

	// A compile time implimentation of the FNV-1a string hashing algerithm.
	// This is loosely based on the implimentation by TheAllenChou at https://github.com/TheAllenChou/string-id.
	constexpr const uint64_t HashFNV1a(const char* str) {
		return HashFNV1aConcat(0xcbf29ce484222325, str);
	}

	// A struct containing a hashed string id and a pointer to its cstring.
	class JEM_API StringID {
	public:
		                   StringID( uint64_t id, const char * string );
						   ~StringID();

		uint64_t           GetID()       const;
		const char*        GetString()   const;

		bool               operator==(const StringID& right)  const;
		bool               operator!=(const StringID& right)  const;

	private:
		uint64_t           mID;
		const char*        mStringPtr;
	};
}

// Returns an intiger string id at compile time for switch statements.
constexpr const uint64_t operator"" _sid(const char* str, size_t) {
	return Jem::HashFNV1a(str);
}
