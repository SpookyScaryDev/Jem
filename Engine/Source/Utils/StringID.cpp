#include "JemPCH.h"

#include "Utils/StringID.h"
#include "stdint.h"

namespace Jem {
	bool operator==(const StringID& left, const StringID& right) {
		return left.mID == right.mID;
	}

	bool operator!=(const StringID& left, const StringID& right) {
		return left.mID != right.mID;
	}
}
