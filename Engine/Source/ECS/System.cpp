#include "JemPCH.h"

#include "System.h"
#include <ECS/EntityAdmin.h>

namespace Jem {
	System::System(EntityAdmin* admin) :
		mAdmin(admin) {}

	unsigned int* System::GetCount() {
		static unsigned int count = 0;
		return &count;
	}
}
