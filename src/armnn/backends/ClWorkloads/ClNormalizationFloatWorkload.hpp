//
// Copyright © 2017 Arm Ltd. All rights reserved.
// See LICENSE file in the project root for full license information.
//

#pragma once

#include "backends/ClWorkloadUtils.hpp"

namespace armnn
{

arm_compute::Status ClNormalizationWorkloadValidate(const TensorInfo& input,
    const TensorInfo& output,
    const NormalizationDescriptor& descriptor);

class ClNormalizationFloatWorkload : public FloatWorkload<NormalizationQueueDescriptor>
{
public:
    ClNormalizationFloatWorkload(const NormalizationQueueDescriptor& descriptor, const WorkloadInfo& info);
    void Execute() const override;

private:
    mutable arm_compute::CLNormalizationLayer    m_NormalizationLayer;
};

} //namespace armnn