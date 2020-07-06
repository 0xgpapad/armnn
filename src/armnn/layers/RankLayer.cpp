//
// Copyright © 2020 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "RankLayer.hpp"

#include "LayerCloneBase.hpp"

#include <backendsCommon/WorkloadData.hpp>
#include <backendsCommon/WorkloadFactory.hpp>

namespace armnn
{

RankLayer::RankLayer(const char* name)
        : Layer(1, 1, LayerType::Rank, name)
{}

std::unique_ptr<IWorkload> RankLayer::CreateWorkload(const IWorkloadFactory& factory) const
{
    RankQueueDescriptor descriptor;
    return factory.CreateRank(descriptor, PrepInfoAndDesc(descriptor));
}

Layer* RankLayer::Clone(Graph& graph) const
{
    RankLayer* clone = CloneBase<RankLayer>(graph, GetName());
    return clone;
}

void RankLayer::ValidateTensorShapesFromInputs(ShapeInferenceMethod shapeInferenceMethod)
{
    IgnoreUnused(shapeInferenceMethod);
    VerifyLayerConnections(1, CHECK_LOCATION());

    ConditionalThrowIfNotEqual<LayerValidationException>(
            "Rank: TensorShape set on OutputSlot[0] does not match the inferred shape.",
            GetOutputSlot(0).GetTensorInfo().GetShape(), {TensorShape{Dimensionality::Scalar}});
}

void RankLayer::Accept(ILayerVisitor& visitor) const
{
    visitor.VisitRankLayer(this, GetName());
}

} //namespace armnn