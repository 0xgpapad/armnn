//
// Copyright © 2017 Arm Ltd. All rights reserved.
// See LICENSE file in the project root for full license information.
//

#pragma once

#include "backends/ClWorkloadUtils.hpp"

namespace armnn
{

arm_compute::Status ClDivisionWorkloadValidate(const TensorInfo& input0,
                                               const TensorInfo& input1,
                                               const TensorInfo& output);

class ClDivisionFloatWorkload : public FloatWorkload<DivisionQueueDescriptor>
{
public:
    ClDivisionFloatWorkload(const DivisionQueueDescriptor& descriptor, const
    WorkloadInfo& info);

    using FloatWorkload<DivisionQueueDescriptor>::FloatWorkload;
    void Execute() const override;

private:
    mutable arm_compute::CLArithmeticDivision m_ArithmeticDivision;
};

} //namespace armnn
