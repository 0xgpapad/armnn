//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include <neon/workloads/NeonWorkloadUtils.hpp>

namespace armnn
{
arm_compute::Status NeonMultiplicationWorkloadValidate(const TensorInfo& input0,
                                                       const TensorInfo& input1,
                                                       const TensorInfo& output);

class NeonMultiplicationFloatWorkload : public FloatWorkload<MultiplicationQueueDescriptor>
{
public:
    NeonMultiplicationFloatWorkload(const MultiplicationQueueDescriptor& descriptor, const WorkloadInfo& info);
    virtual void Execute() const override;

private:
    mutable arm_compute::NEPixelWiseMultiplication m_PixelWiseMultiplication;
};

} //namespace armnn




