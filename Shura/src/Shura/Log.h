#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Shura {
	class SHURA_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define SH_CORE_ERROR(...)	::Shura::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SH_CORE_WARN(...)	::Shura::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SH_CORE_INFO(...)	::Shura::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SH_CORE_TRACE(...)	::Shura::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SH_CORE_FATAL(...)	::Shura::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define SH_ERROR(...)	::Shura::Log::getClientLogger()->error(__VA_ARGS__)
#define SH_WARN(...)	::Shura::Log::getClientLogger()->warn(__VA_ARGS__)
#define SH_INFO(...)	::Shura::Log::getClientLogger()->info(__VA_ARGS__)
#define SH_TRACE(...)	::Shura::Log::getClientLogger()->trace(__VA_ARGS__)
#define SH_FATAL(...)	::Shura::Log::getClientLogger()->fatal(__VA_ARGS__)


#define SH_CORE_INFO