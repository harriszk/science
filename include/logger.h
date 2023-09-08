// @file logger.h
// Created on 07/16/2023
// 
// Logging utility for the application using spdlog library. This class
// provides initialization and shutdown methods for setting up logging. It also
// defines log macros for various log levels, such as TRACE, INFO, WARN, ERROR,
// and CRITICAL.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <memory>

#include "spdlog/spdlog.h"

class Logger {
  public:
    // Initialize the logger.
    static void Initialize();

    // Shutdown the logger.
    static void Shutdown();

    // Get the logger instance.
    // 
    // @return std::shared_ptr<spdlog::logger>& A shared pointer to the logger instance.
    inline static std::shared_ptr<spdlog::logger>& get_logger() { return logger_; }
  
  private:
    // The logger instance.
    static std::shared_ptr<spdlog::logger> logger_;
};

// Log macros
#define LOG_TRACE(...) ::Logger::get_logger()->trace(__VA_ARGS__)
#define LOG_INFO(...) ::Logger::get_logger()->info(__VA_ARGS__)
#define LOG_WARN(...) ::Logger::get_logger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::Logger::get_logger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...) ::Logger::get_logger()->critical(__VA_ARGS__)

#endif