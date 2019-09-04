#include "JemPCH.h"
#include "Component.h"

namespace Jem {
	unsigned int* Component::GetCount() {
		static unsigned int count = 0;
		return &count;
	}
}