// Copyright (c) 2020 Egor Kupaev
// This work is distributed under the MIT License
// See the accompanying LICENSE file or https://mit-license.org/

#include <stdlib.h>
#include <stdbool.h>
#include <container.h>
#include "vector.h"
#include "defines.h"


typedef void (*DestroyFunction_t)(void **);

typedef struct
{
    DestroyFunction_t DestroyFunction;
} VTable;

struct CAlgoContainerImpl
{
    VTable *vTable;
    void *this;
};

#define CALGO_ADD_VTABLE_ENTRY(type, fname) .fname ## Function = type ## fname ## Function

CAlgoStatus CAlgoMakeVector(size_t typeSize, CAlgoContainer **ppContainer)
{
    static VTable vTable = {
        CALGO_ADD_VTABLE_ENTRY(Vector, Destroy)
    };

    CALGO_CHECK_TYPE_SIZE(typeSize);
    CALGO_CHECK_NULL(ppContainer);

    (*ppContainer) = (CAlgoContainer *) malloc(sizeof(CAlgoContainer));
    CALGO_CHECK_ALLOCATION((*ppContainer));

    (*ppContainer)->this = NULL;
    (*ppContainer)->vTable = &vTable;

    return VectorMakeFunction(typeSize, (void **) (&((*ppContainer)->this)));
}

//CAlgoStatus CAlgoReserve(CAlgoContainer *pContainer, size_t newSize);
//
//CAlgoStatus CAlgoPushBack(CAlgoContainer *pContainer, const void *pValue);
//
//CAlgoStatus CAlgoGetElem(CAlgoContainer *pContainer, size_t index, void **ppValue);

CAlgoStatus CAlgoDestroy(CAlgoContainer **ppContainer)
{
    CALGO_CHECK_NULL(ppContainer);

    (*ppContainer)->vTable->DestroyFunction((void **) (&((*ppContainer)->this)));
    free(*ppContainer);
    ppContainer = NULL;

    return CAlgoStatusOK;
}

#include "defs/vector_defs.c"