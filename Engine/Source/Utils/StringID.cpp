#include "Utils/StringID.h"
#include <functional>

namespace Jem {

	/*constexpr*/ std::size_t HashString(const char* str) {          
		return std::hash<const char*>{}(str);                        
	}

	StringID& StringID::operator=(const StringID& s) {
		StringID mID = SID((char*)s.mStringPtr);
		mStringPtr = s.mStringPtr;

		return *this;
	}
}

/*constexpr*/ std::size_t operator "" _sid(const char* str, size_t) { 
	return Jem::HashString(str);
}