#include "JemPCH.h"

#include "Utils/StringID.h"
#include "stdint.h"

namespace Jem {
	StringID& StringID::operator=(const StringID& s) {
		StringID mID = SID((char*)s.mStringPtr);
		mStringPtr = s.mStringPtr;

		return *this;
	}

	bool operator==(const StringID& left, const StringID& right) {
		return left.mID == right.mID;
	}

	bool operator!=(const StringID& left, const StringID& right) {
		return left.mID != right.mID;
	}
}
