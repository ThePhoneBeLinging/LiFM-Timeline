//
// Created by eal on 29/07-2025.
//

#include "LiFM-Timeline/LiFMTimeline.hpp"
#include "Utility/ConfigController.h"
#include "Utility/TimeUtil.h"

LiFMTimeline::LiFMTimeline(const std::chrono::system_clock::time_point& startTime) : currentTimePoint_(startTime)
{
}

void LiFMTimeline::advance()
{
  int minutesToIncrement = ConfigController::getConfigInt("minutesToIncrement");
  currentTimePoint_ += std::chrono::minutes(minutesToIncrement);
}

void LiFMTimeline::callUpdates()
{
  for (const auto & updateFunction : updateFunctions_)
  {
    if (updateFunction->timePoint_ >= currentTimePoint_)
    {
      updateFunction->callCallback();
    }
  }
  std::erase_if(updateFunctions_,[](const std::unique_ptr<TimebasedCallback>& a)
  {
    return a->called_;
  });
}

void LiFMTimeline::registerUpdate(const std::chrono::system_clock::time_point& timePoint,
                                const std::function<void()>& update)
{
  updateFunctions_.emplace_back(std::make_unique<TimebasedCallback>(timePoint,update));
}

tm LiFMTimeline::getTimeObject() const
{
  auto timeObject = TimeUtil::timeToTM(currentTimePoint_);
  return timeObject;
}

std::string LiFMTimeline::getDateString() const
{
  auto time = getTimeObject();
  time.tm_year -= 1900;
  std::stringstream ss;
  ss << std::put_time(&time, "%d/%m-%Y");
  return ss.str();
}

std::string LiFMTimeline::getClockString() const
{
  auto time = getTimeObject();
  std::stringstream ss;
  ss << std::put_time(&time, "%H:%M:%S");
  return ss.str();
}
