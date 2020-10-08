// Copyright (c) 2020 Egor Kupaev
// This work is distributed under the MIT License
// See the accompanying LICENSE file or https://mit-license.org/

#ifndef CONTAINER_H
#define CONTAINER_H

#include <types.h>
#include <stddef.h>

struct CAlgoContainerImpl;

typedef struct CAlgoContainerImpl CAlgoContainer;

CAlgoStatus CAlgoMake(CAlgoContainerType_e containerType, size_t typeSize, CAlgoContainer **ppContainer);

CAlgoStatus CAlgoReserve(CAlgoContainer *pContainer, size_t newSize);

CAlgoStatus CAlgoPushBack(CAlgoContainer *pContainer, const void *pValue);

CAlgoStatus CAlgoGetElem(CAlgoContainer *pContainer, size_t index, void **ppValue);

CAlgoStatus CAlgoDestroy(CAlgoContainer **ppContainer);

#endif //CONTAINER_H
