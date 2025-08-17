//
// Created by eal on 29/07-2025.
//

#ifndef LIFMTIMELINE_H
#define LIFMTIMELINE_H
#include <chrono>

#include "TimebasedCallback.hpp"


class LiFMTimeline
{
public:
  explicit LiFMTimeline(const std::chrono::system_clock::time_point& startTime);
  void advance();
  void callUpdates();
  void registerUpdate(const std::chrono::system_clock::time_point& timePoint, const std::function<void()>& update);
  [[nodiscard]] tm getTimeObject() const;
  [[nodiscard]] std::string getDateString() const;
  [[nodiscard]] std::string getClockString() const;
private:
  std::chrono::time_point<std::chrono::system_clock> currentTimePoint_;
  std::vector<std::unique_ptr<TimebasedCallback>> updateFunctions_;
};



#endif //LIFMTIMELINE_H
