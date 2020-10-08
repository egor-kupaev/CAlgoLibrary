// Copyright (c) 2020 Egor Kupaev
// This work is distributed under the MIT License
// See the accompanying LICENSE file or https://mit-license.org/

#ifndef TYPES_H
#define TYPES_H

typedef enum
{
    CAlgoStatusOK = 0u,
    CAlgoStatusError = -1,
    CAlgoStatusNullPtr = -2,
    CAlgoStatusBadAlloc = -4,
    CAlgoStatusBadSize = -5,
    CAlgoStatusOutOfBounds = -6,
    CAlgoStatusBadContainerType = -7
} CAlgoStatus;

typedef enum
{
    CAlgoVector = 0u,
    CAlgoContainerLast
} CAlgoContainerType_e;

#endif //TYPES_H
