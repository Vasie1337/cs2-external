#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>

enum class LogLevel 
{
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_FATAL
};

class Logger 
{
public:
    Logger(const std::string& logFilePath = "application.log", LogLevel minLevel = LogLevel::LOG_INFO);
    ~Logger();

    void Log(const std::string& msg, LogLevel level = LogLevel::LOG_INFO);
    void Error(const std::string& msg);
    void Warning(const std::string& msg);
    void Info(const std::string& msg);
    void Debug(const std::string& msg);

    void SetLogLevel(LogLevel level);
    LogLevel GetLogLevel() const;

	void StopFileLogging();

private:
    std::ofstream logFile;
    LogLevel logLevel;

    std::string GetCurrentTimestamp();
    std::string LogLevelToString(LogLevel level);
};