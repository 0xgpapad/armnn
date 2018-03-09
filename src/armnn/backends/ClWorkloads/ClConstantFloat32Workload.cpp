//
// Copyright © 2017 Arm Ltd. All rights reserved.
// See LICENSE file in the project root for full license information.
//

#include "ClConstantFloat32Workload.hpp"
namespace armnn
{

void ClConstantFloat32Workload::Execute() const
{
    ARMNN_SCOPED_PROFILING_EVENT(Compute::GpuAcc, "ClConstantFloat32Workload_Execute");
    ClBaseConstantWorkload::Execute();
}

} //namespace armnn