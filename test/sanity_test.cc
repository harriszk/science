// @file sanity_test.cc
// Created on 08/02/2023
// 
// A simple test to ensure that the testing framework is setup
// correctly.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include <gtest/gtest.h>

TEST(SanityTest, SanityTest) {
  EXPECT_EQ(1 + 1, 2);
}