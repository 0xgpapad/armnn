//
// Copyright © 2017 Arm Ltd. All rights reserved.
// See LICENSE file in the project root for full license information.
//

#pragma once

#include "NeonConvolution2dBaseWorkload.hpp"
#include <backends/NeonWorkloadUtils.hpp>

#include "arm_compute/runtime/MemoryManagerOnDemand.h"

#include <memory>

namespace armnn
{

class NeonConvolution2dFloat32Workload : public NeonConvolution2dBaseWorkload<DataType::Float32>
{
public:
    NeonConvolution2dFloat32Workload(const Convolution2dQueueDescriptor& descriptor, const WorkloadInfo& info,
                                     std::shared_ptr<arm_compute::MemoryManagerOnDemand>& memoryManager);

    void Execute() const override;
    void ValidateData() const override;
};

} //namespace armnn

