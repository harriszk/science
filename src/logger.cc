// @file logger.cc
// Created on 07/16/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "logger.h"

#include "spdlog/sinks/stdout_color_sinks.h"

std::shared_ptr<spdlog::logger> Logger::logger_;

void Logger::Initialize() {
  spdlog::set_pattern("%^[%T] %n: %v%$");
  logger_ = spdlog::stdout_color_mt("APP");
  logger_->set_level(spdlog::level::trace);

  LOG_INFO("Initialized logger!");
}

