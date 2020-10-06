// Copyright (c) 2020 Egor Kupaev
// This work is distributed under the MIT License
// See the accompanying LICENSE file or https://mit-license.org/

#ifndef DEFINES_H
#define DEFINES_H

#include <assert.h>

#define CALGO_CHECK_NULL(p) if (!p) return CAlgoStatusNullPtr
#define CALGO_CHECK_STATUS(status) if (CAlgoStatusOK != status) return status
#define CALGO_CHECK_ALLOCATION(p) if (p == NULL) return CAlgoStatusBadAlloc

#define CALGO_INTERNAL_CHECK_NULL(p) if (!p) return CAlgoStatusError

#endif //DEFINES_H
