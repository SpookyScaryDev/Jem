#include "Log.h"

namespace Jem {

	//std::shared_ptr<logger::Logger> Log::pCoreLogger;
	//std::shared_ptr<logger::Logger> Log::pLogger;
	logger::Logger* Log::pCoreLogger;
	logger::Logger* Log::pLogger;

	void Log::init() {
		pCoreLogger = new logger::Logger(logger::LOG_CONSOLE, logger::LOG_MESSAGE, "CoreLogger", "");
		pLogger = new logger::Logger(logger::LOG_CONSOLE, logger::LOG_MESSAGE, "ClientLogger", "");
	}

	void Log::shutdown() {
		delete pCoreLogger;
		delete pLogger;
	}

}