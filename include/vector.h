// Copyright (c) 2020 Egor Kupaev
// This work is distributed under the MIT License
// See the accompanying LICENSE file or https://mit-license.org/

#ifndef VECTOR_H
#define VECTOR_H

#include <types.h>
#include <stddef.h>

struct CAlgoVectorImpl;

typedef struct
{
    struct CAlgoVectorImpl *pImpl;
} CAlgoVector;

CAlgoStatus CAlgoMakeVector(size_t typeSize, CAlgoVector *pVector);

CAlgoStatus CAlgoReserve(CAlgoVector *pVector, size_t newSize);

CAlgoStatus CAlgoPushBackVector(CAlgoVector *pVector, const void *pValue);

CAlgoStatus CAlgoGetElemVector(CAlgoVector *pVector, size_t index, void **ppValue);

CAlgoStatus CAlgoDestroyVector(CAlgoVector *pVector);

#endif //VECTOR_H
