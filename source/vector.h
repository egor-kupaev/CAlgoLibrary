// Copyright (c) 2020 Egor Kupaev
// This work is distributed under the MIT License
// See the accompanying LICENSE file or https://mit-license.org/

#ifndef VECTOR_H
#define VECTOR_H

#include <container.h>
#include <types.h>
#include <stddef.h>

static CAlgoStatus VectorMakeFunction(void **const pThis, const size_t typeSize);

//CAlgoStatus CAlgoReserve(CAlgoContainer *pVector, size_t newSize);
//
//CAlgoStatus CAlgoPushBackVector(CAlgoContainer *pVector, const void *pValue);
//
//CAlgoStatus CAlgoGetElemVector(CAlgoContainer *pVector, size_t index, void **ppValue);

static void VectorDestroyFunction(void **pThis);

#endif //VECTOR_H
