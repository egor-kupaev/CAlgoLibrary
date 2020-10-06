// Copyright (c) 2020 Egor Kupaev
// This work is distributed under the Apache-2.0 License
// See the accompanying LICENSE file or http://www.apache.org/licenses/

#ifndef BLOB_HPP
#define BLOB_HPP

#include <cstdint>
#include <numeric>
#include <type_traits>
#include <algorithm>

struct BLOB
{
    explicit BLOB(const std::uint64_t value)
    {
        std::iota(std::begin(data), std::end(data), value);
    }

    std::uint64_t data[1000];
};

static_assert(std::is_standard_layout_v<BLOB>);

bool operator==(const BLOB &lhs, const BLOB &rhs)
{
    return std::equal(std::begin(lhs.data), std::end(lhs.data), std::begin(rhs.data));
}

#endif //BLOB_HPP
