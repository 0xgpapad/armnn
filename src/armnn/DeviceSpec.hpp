//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//
#pragma once

#include "armnn/Types.hpp"
#include <set>

namespace armnn
{

class DeviceSpec : public IDeviceSpec
{
public:
    DeviceSpec() {}
    virtual ~DeviceSpec() {}

    std::set<Compute> m_SupportedComputeDevices;
};

}
