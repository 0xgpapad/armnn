//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "RefBackend.hpp"
#include "RefWorkloadFactory.hpp"

#include <backends/BackendRegistry.hpp>

#include <boost/cast.hpp>

namespace armnn
{

namespace
{

static BackendRegistry::Helper s_RegisterHelper{
    RefBackend::GetIdStatic(),
    []()
    {
        return IBackendUniquePtr(new RefBackend, &RefBackend::Destroy);
    }
};

}

const BackendId& RefBackend::GetIdStatic()
{
    static const BackendId s_Id{"CpuRef"};
    return s_Id;
}

const ILayerSupport& RefBackend::GetLayerSupport() const
{
    return m_LayerSupport;
}

std::unique_ptr<IWorkloadFactory> RefBackend::CreateWorkloadFactory() const
{
    return std::make_unique<RefWorkloadFactory>();
}

void RefBackend::Destroy(IBackend* backend)
{
    delete boost::polymorphic_downcast<RefBackend*>(backend);
}

} // namespace armnn