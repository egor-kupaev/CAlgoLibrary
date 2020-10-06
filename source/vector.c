// Copyright (c) 2020 Egor Kupaev
// This work is distributed under the Apache-2.0 License
// See the accompanying LICENSE file or http://www.apache.org/licenses/

#include <vector.h>

#include <stdlib.h>
#include <memory.h>
#include <stddef.h>

#include "defines.h"

struct CAlgoVectorImpl
{
    void *pData;
    size_t size;
    size_t capacity;
    size_t typeSize;
};

typedef struct CAlgoVectorImpl VectorImpl;

CAlgoStatus CAlgoMakeVector(const size_t typeSize, CAlgoVector *const pVector)
{
    CALGO_CHECK_NULL(pVector);

    if (typeSize == 0u) {
        return CAlgoStatusZeroTypeSize;
    }

    pVector->pImpl = (VectorImpl *) malloc(sizeof(VectorImpl));
    CALGO_CHECK_ALLOCATION(pVector->pImpl);

    pVector->pImpl->size = 0u;
    pVector->pImpl->pData = NULL;
    pVector->pImpl->capacity = 0u;
    pVector->pImpl->typeSize = typeSize;

    return CAlgoStatusOK;
}

CAlgoStatus CAlgoReserve(CAlgoVector *const pVector, const size_t newSize)
{
    CALGO_CHECK_NULL(pVector);
    CALGO_INTERNAL_CHECK_NULL(pVector->pImpl);

    const size_t size_ = pVector->pImpl->size;
    const size_t capacity_ = pVector->pImpl->capacity;
    const size_t typeSize_ = pVector->pImpl->typeSize;

    if (capacity_ != newSize) {
        if (newSize < size_) {
            return CAlgoStatusBadSize;
        }
        else {
            void *pNewData = malloc(typeSize_ * newSize);
            CALGO_CHECK_ALLOCATION(pNewData);

            void *pOldData = pVector->pImpl->pData;
            if (pOldData != NULL) {
                memcpy(pNewData, pOldData, typeSize_ * size_);
                free(pOldData);
            }

            pVector->pImpl->pData = pNewData;
            pVector->pImpl->capacity = newSize;
        }
    }

    return CAlgoStatusOK;
}

CAlgoStatus CAlgoPushBackVector(CAlgoVector *pVector, const void *pValue)
{
    CALGO_CHECK_NULL(pVector);
    CALGO_CHECK_NULL(pValue);
    CALGO_INTERNAL_CHECK_NULL(pVector->pImpl);

    const size_t size_ = pVector->pImpl->size;
    const size_t capacity_ = pVector->pImpl->capacity;
    const size_t typeSize_ = pVector->pImpl->typeSize;

    if (size_ + 1u > capacity_) {
        const size_t newCapacity = (capacity_ == 0u) ? 2u : capacity_ * 2u;
        const CAlgoStatus status = CAlgoReserve(pVector, newCapacity);
        CALGO_CHECK_STATUS(status);
    }
    const size_t offset = typeSize_ * size_;
    memcpy((char *) pVector->pImpl->pData + offset, pValue, typeSize_);
    pVector->pImpl->size++;

    return CAlgoStatusOK;
}

CAlgoStatus CAlgoGetElemVector(CAlgoVector *const pVector, size_t index, void **ppValue)
{
    CALGO_CHECK_NULL(pVector);
    CALGO_CHECK_NULL(ppValue);
    CALGO_INTERNAL_CHECK_NULL(pVector->pImpl);

    const size_t size_ = pVector->pImpl->size;
    const size_t typeSize_ = pVector->pImpl->typeSize;
    if (index >= size_) {
        return CAlgoStatusOutOfBounds;
    }

    const size_t offset = typeSize_ * index;
    (*ppValue) = (char *) pVector->pImpl->pData + offset;

    return CAlgoStatusOK;
}

CAlgoStatus CAlgoDestroyVector(CAlgoVector *pVector)
{
    CALGO_CHECK_NULL(pVector);
    CALGO_INTERNAL_CHECK_NULL(pVector->pImpl);

    if (pVector->pImpl->pData != NULL) {
        free(pVector->pImpl->pData);
    }
    free(pVector->pImpl);

    return CAlgoStatusOK;
}
