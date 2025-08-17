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
  for (int i = 0; i < updateFunctions_.size(); ++i)
  {
    if (updateFunctions_[i]->timePoint_ >= currentTimePoint_)
    {
      updateFunctions_[i]->callCallback();
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
  return TimeUtil::timeToTM(currentTimePoint_);
}
