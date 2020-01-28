#include "JemPCH.h"

#include "Log.h"
#include "../Vendor/Logger/Include/LittleLogger.h"

namespace Jem {
	namespace Log {
		std::shared_ptr<lilo::Logger> CoreLogger;
		std::shared_ptr<lilo::Logger> ClientLogger;

		void Init() {
			CoreLogger = lilo::CreateColourLogger(lilo::LOG_MESSAGE);
			ClientLogger = lilo::CreateColourLogger(lilo::LOG_MESSAGE);
		}
	}
}