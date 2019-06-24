#include "JemPCH.h"

#include "Log.h"
#include "../Vendor/Logger/Include/LittleLogger.h"

namespace Jem {
	std::shared_ptr<lilo::Logger> Log::CoreLogger;
	std::shared_ptr<lilo::Logger> Log::ClientLogger;

	void Log::Init() {
		CoreLogger = lilo::CreateColourLogger(lilo::LOG_MESSAGE);
		ClientLogger = lilo::CreateColourLogger(lilo::LOG_MESSAGE);
	}
}