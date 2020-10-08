// Copyright (c) 2020 Egor Kupaev
// This work is distributed under the MIT License
// See the accompanying LICENSE file or https://mit-license.org/

#ifndef VECTOR_H
#define VECTOR_H

#include <container.h>
#include <types.h>
#include <stddef.h>

static CAlgoStatus VectorMakeFunction(size_t typeSize, void **ppVector);

//CAlgoStatus CAlgoReserve(CAlgoContainer *pVector, size_t newSize);
//
//CAlgoStatus CAlgoPushBackVector(CAlgoContainer *pVector, const void *pValue);
//
//CAlgoStatus CAlgoGetElemVector(CAlgoContainer *pVector, size_t index, void **ppValue);

static void VectorDestroyFunction(void **ppVector);

#endif //VECTOR_H