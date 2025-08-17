//
// Created by eal on 29/07-2025.
//
#include "gtest/gtest.h"
#include "LiFM-Timeline/LiFMTimeline.hpp"

class TestTemplate : public testing::Test
{

};

TEST_F(TestTemplate, Constructor)
{
 auto thing = std::make_shared<LiFMTimeline>(std::chrono::system_clock::now());
 EXPECT_TRUE(true);
}