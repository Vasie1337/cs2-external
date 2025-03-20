#include "logger.hpp"

Logger::Logger(const std::string& logFilePath, LogLevel minLevel)
    : logLevel(minLevel)
{
    logFile.open(logFilePath, std::ios::app);
    if (!logFile.is_open()) {
		throw std::runtime_error("Failed to open log file: " + logFilePath);
    }
}

Logger::~Logger()
{
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::Log(const std::string& msg, LogLevel level)
{
    if (level < logLevel) {
        return;
    }

    std::string timestamp = GetCurrentTimestamp();
    std::string levelStr = LogLevelToString(level);

    std::string formattedMsg = timestamp + " [" + levelStr + "] " + msg;

    if (logFile.is_open()) {
        logFile << formattedMsg << std::endl;
        logFile.flush();
    }

    if (level >= LogLevel::LOG_ERROR) {
        std::cerr << formattedMsg << std::endl;
    }
    else if (level >= LogLevel::LOG_INFO) {
        std::cout << formattedMsg << std::endl;
    }
}

void Logger::Error(const std::string& msg)
{
    Log(msg, LogLevel::LOG_ERROR);
}

void Logger::Warning(const std::string& msg)
{
    Log(msg, LogLevel::LOG_WARNING);
}

void Logger::Info(const std::string& msg)
{
    Log(msg, LogLevel::LOG_INFO);
}

void Logger::Debug(const std::string& msg)
{
    Log(msg, LogLevel::LOG_DEBUG);
}

void Logger::SetLogLevel(LogLevel level)
{
    logLevel = level;
}

LogLevel Logger::GetLogLevel() const
{
    return logLevel;
}

void Logger::StopFileLogging()
{
	if (logFile.is_open()) {
		logFile.close();
	}
}

std::string Logger::GetCurrentTimestamp()
{
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);

    std::tm tm = *std::localtime(&time);

    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()) % 1000;

    std::stringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    ss << '.' << std::setfill('0') << std::setw(3) << ms.count();

    return ss.str();
}

std::string Logger::LogLevelToString(LogLevel level)
{
    switch (level) {
    case LogLevel::LOG_DEBUG:   return "DEBUG";
    case LogLevel::LOG_INFO:    return "INFO";
    case LogLevel::LOG_WARNING: return "WARNING";
    case LogLevel::LOG_ERROR:   return "ERROR";
    case LogLevel::LOG_FATAL:   return "FATAL";
    default:                return "UNKNOWN";
    }
}