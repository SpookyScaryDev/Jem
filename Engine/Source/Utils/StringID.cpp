#include "JemPCH.h"

#include "StringID.h"
#include <stdint.h>

namespace Jem {
	StringID::StringID( uint64_t id, const char* string) :
		mID(id), mStringPtr(string) {}

	StringID::~StringID() {}

	uint64_t StringID::GetID() const {
		return mID;
	}

	const char* StringID::GetString() const {
		return mStringPtr;
	}

	bool StringID::operator==(const StringID& right) const {
		return this->mID == right.mID;
	}

	bool StringID::operator!=(const StringID& right) const {
		return this->mID != right.mID;
	}
}
