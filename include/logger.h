// @file logger.h
// Created on 07/16/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <memory>

#include "spdlog/spdlog.h"

class Logger {
  public:
    // 
    // 
    static void Initialize();

    // 
    // 
    static void Shutdown();

    // Get the logger
    // 
    // @return std::shared_ptr<spdlog::logger>& 
    inline static std::shared_ptr<spdlog::logger>& get_logger() { return logger_; }
  
  private:
    // 
    static std::shared_ptr<spdlog::logger> logger_;
};

// Log macros
#define LOG_TRACE(...) ::Logger::get_logger()->trace(__VA_ARGS__)
#define LOG_INFO(...) ::Logger::get_logger()->info(__VA_ARGS__)
#define LOG_WARN(...) ::Logger::get_logger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::Logger::get_logger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...) ::Logger::get_logger()->critical(__VA_ARGS__)

#endif