// Copyright (c) 2020 Egor Kupaev
// This work is distributed under the MIT License
// See the accompanying LICENSE file or https://mit-license.org/

#include <stdlib.h>
#include <stdbool.h>
#include <container.h>
#include "vector.h"
#include "defines.h"

struct CAlgoContainerImpl
{
    CAlgoContainerType_e type;
    void *pImpl;
};

// Add check for bad_alloc
#define CALGO_CREATE_VTABLE(type) \
     vTables[CAlgo ## type].makeFunction = type ## MakeFunction; \
     vTables[CAlgo ## type].destroyFunction = type ## DestroyFunction;

typedef CAlgoStatus (*MakeFunction)(size_t, void **);

typedef void (*DestroyFunction)(void **);

typedef struct
{
    MakeFunction makeFunction;
    DestroyFunction destroyFunction;
} VTable;

inline static VTable *InternalGetVTable()
{
    static VTable vTables[CAlgoContainerLast - 1u];
    static bool initialized = false;

    if (!initialized) {
        CALGO_CREATE_VTABLE(Vector);
        initialized = true;
    }

    return vTables;
}

CAlgoStatus CAlgoMake(CAlgoContainerType_e containerType, size_t typeSize, CAlgoContainer **ppContainer)
{
    CALGO_CHECK_TYPE(containerType);
    CALGO_CHECK_TYPE_SIZE(typeSize);
    CALGO_CHECK_NULL(ppContainer);

    (*ppContainer) = (CAlgoContainer *) malloc(sizeof(CAlgoContainer));
    CALGO_CHECK_ALLOCATION((*ppContainer));

    (*ppContainer)->pImpl = NULL;
    (*ppContainer)->type = containerType;

    return InternalGetVTable()[containerType].makeFunction(typeSize, (void **) (&((*ppContainer)->pImpl)));
}

//CAlgoStatus CAlgoReserve(CAlgoContainer *pContainer, size_t newSize);
//
//CAlgoStatus CAlgoPushBack(CAlgoContainer *pContainer, const void *pValue);
//
//CAlgoStatus CAlgoGetElem(CAlgoContainer *pContainer, size_t index, void **ppValue);

CAlgoStatus CAlgoDestroy(CAlgoContainer **ppContainer)
{
    CALGO_CHECK_NULL(ppContainer);

    InternalGetVTable()[(*ppContainer)->type].destroyFunction((void **) (&((*ppContainer)->pImpl)));
    free(*ppContainer);
    ppContainer = NULL;

    return CAlgoStatusOK;
}

#include "vector.cxx"