//
// Copyright © 2017 Arm Ltd. All rights reserved.
// See LICENSE file in the project root for full license information.
//

#pragma once

#include "NeonBaseConstantWorkload.hpp"

namespace armnn
{

class NeonConstantFloatWorkload : public NeonBaseConstantWorkload<DataType::Float16, DataType::Float32>
{
public:
    using NeonBaseConstantWorkload<DataType::Float16, DataType::Float32>::NeonBaseConstantWorkload;
    virtual void Execute() const override;
};

} //namespace armnn
