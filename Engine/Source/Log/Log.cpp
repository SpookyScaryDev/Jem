#include "Log/Log.h"

#include "../Vendor/Logger/include/Logger/Logger.h"

namespace Jem {

	logger::Logger* Log::CoreLogger;
	logger::Logger* Log::ClientLogger;

	void Log::Init() {
		CoreLogger = new logger::Logger(logger::LOG_CONSOLE, logger::LOG_MESSAGE, "CoreLogger", "");
		ClientLogger = new logger::Logger(logger::LOG_CONSOLE, logger::LOG_MESSAGE, "ClientLogger", "");
	}

	void Log::Shutdown() {
		delete CoreLogger;
		delete ClientLogger;
	}

}