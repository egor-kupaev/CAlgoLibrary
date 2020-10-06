// Copyright (c) 2020 Egor Kupaev
// This work is distributed under the Apache-2.0 License
// See the accompanying LICENSE file or http://www.apache.org/licenses/

#ifndef DEFINES_H
#define DEFINES_H

#include <assert.h>

#define CALGO_CHECK_NULL(p) if (!p) return CAlgoStatusNullPtr
#define CALGO_CHECK_STATUS(status) if (CAlgoStatusOK != status) return status
#define CALGO_CHECK_ALLOCATION(p) if (p == NULL) return CAlgoStatusBadAlloc

#define CALGO_INTERNAL_CHECK_NULL(p) if (!p) return CAlgoStatusError

#endif //DEFINES_H
