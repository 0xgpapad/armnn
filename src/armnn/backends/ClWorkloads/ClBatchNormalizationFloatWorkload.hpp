//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include "backends/ClWorkloadUtils.hpp"

namespace armnn
{

arm_compute::Status ClBatchNormalizationValidate(const TensorInfo& input,
                                                 const TensorInfo& output,
                                                 const TensorInfo& mean,
                                                 const TensorInfo& var,
                                                 const TensorInfo& beta,
                                                 const TensorInfo& gamma,
                                                 const BatchNormalizationDescriptor& desc);

class ClBatchNormalizationFloatWorkload : public FloatWorkload<BatchNormalizationQueueDescriptor>
{
public:
    ClBatchNormalizationFloatWorkload(const BatchNormalizationQueueDescriptor& descriptor, const WorkloadInfo& info);

    using FloatWorkload<BatchNormalizationQueueDescriptor>::FloatWorkload;
    void Execute() const override;

private:
    mutable arm_compute::CLBatchNormalizationLayer m_Layer;

    std::unique_ptr<arm_compute::CLTensor> m_Mean;
    std::unique_ptr<arm_compute::CLTensor> m_Variance;
    std::unique_ptr<arm_compute::CLTensor> m_Gamma;
    std::unique_ptr<arm_compute::CLTensor> m_Beta;

    void FreeUnusedTensors();
};

} //namespace armnn




