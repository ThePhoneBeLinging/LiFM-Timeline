//
// Created by eal on 29/07-2025.
//

#ifndef TIMEBASEDCALLBACK_H
#define TIMEBASEDCALLBACK_H
#include <chrono>
#include <functional>

class TimebasedCallback
{
public:
  TimebasedCallback(const std::chrono::system_clock::time_point& timePoint, const std::function<void()>& callback) :
  timePoint_(timePoint), callback_(callback)
  {
  }

  std::chrono::system_clock::time_point timePoint_;
  void callCallback()
  {
    callback_();
    called_ = true;
  }

  bool called_ = false;
private:
  std::function<void()> callback_;
};

#endif //TIMEBASEDCALLBACK_H
