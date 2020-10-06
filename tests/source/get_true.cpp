#include "gtest/gtest.h"

extern "C" {
#include "calgo.h"
}

TEST(GetTrueSuite, Sample)
{
    ASSERT_TRUE(CAlgoGetTrue());
}