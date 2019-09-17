//
// Copyright © 2019 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include "BaseIterator.hpp"

#include <armnn/ArmNN.hpp>

namespace armnn
{

void Slice(const TensorInfo& inputInfo,
           const SliceDescriptor& descriptor,
           const void* inputData,
           void* outputData,
           unsigned int dataTypeSize);

} // namespace armnn
