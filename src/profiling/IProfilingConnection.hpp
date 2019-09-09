//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include "Packet.hpp"

#include <cstdint>

namespace armnn
{

namespace profiling
{

class IProfilingConnection
{
public:
    virtual ~IProfilingConnection() {}

    virtual bool IsOpen() = 0;

    virtual void Close() =  0;

    virtual bool WritePacket(const char* buffer, uint32_t length) = 0;

    virtual Packet ReadPacket(uint32_t timeout) = 0;
};

} // namespace profiling

} // namespace armnn
