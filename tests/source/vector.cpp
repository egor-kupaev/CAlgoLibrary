// Copyright (c) 2020 Egor Kupaev
// This work is distributed under the Apache-2.0 License
// See the accompanying LICENSE file or http://www.apache.org/licenses/

#include "gtest/gtest.h"

#include "blob.hpp"

extern "C" {
#include "vector.h"
}

// MakeVector part TODO: Add correct flow test case
TEST(VectorMakeVector, VectorNull)
{
    EXPECT_EQ(CAlgoStatusNullPtr, CAlgoMakeVector(sizeof(int), NULL));
}

TEST(VectorMakeVector, TypeSizeZero)
{
    CAlgoVector vector;
    EXPECT_EQ(CAlgoStatusZeroTypeSize, CAlgoMakeVector(0u, &vector));
}

// PushBack part
template<typename T>
class VectorPushBack: public ::testing::Test
{
};

using VectorPushBackTypes = ::testing::Types<int32_t, uint64_t, double, BLOB>;

TYPED_TEST_SUITE(VectorPushBack, VectorPushBackTypes);

TYPED_TEST(VectorPushBack, Sample)
{
    // Construct a vector
    CAlgoVector vector;
    EXPECT_EQ(CAlgoStatusOK, CAlgoMakeVector(sizeof(TypeParam), &vector));

    // Push back five values
    TypeParam value{1};
    for (size_t i = 0u; i < 5u; ++i) {
        EXPECT_EQ(CAlgoStatusOK, CAlgoPushBackVector(&vector, &value));
    }

    // Check whether the five pushed values are equal to the reference value
    for (size_t i = 0u; i < 5u; ++i) {
        TypeParam *pElem = NULL;
        EXPECT_EQ(CAlgoStatusOK, CAlgoGetElemVector(&vector, i, (void **) &pElem));

        EXPECT_EQ(value, *pElem);
    }

    // Destruct the vector
    EXPECT_EQ(CAlgoStatusOK, CAlgoDestroyVector(&vector));
}

TEST(VectorPushBack, PushBack_VectorNull)
{
    int value{1};
    EXPECT_EQ(CAlgoStatusNullPtr, CAlgoPushBackVector(NULL, &value));
}

TEST(VectorPushBack, PushBack_ValueNull)
{
    CAlgoVector vector;
    EXPECT_EQ(CAlgoStatusOK, CAlgoMakeVector(sizeof(int), &vector));
    EXPECT_EQ(CAlgoStatusNullPtr, CAlgoPushBackVector(&vector, NULL));
    EXPECT_EQ(CAlgoStatusOK, CAlgoDestroyVector(&vector));
}

// TODO: Add tests for Reserve, Destroy, GetElem APIs