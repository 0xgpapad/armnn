//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "BackendRegistry.hpp"
#include <armnn/Exceptions.hpp>

namespace armnn
{

BackendRegistry& BackendRegistry::Instance()
{
    static BackendRegistry instance;
    return instance;
}

void BackendRegistry::Register(const BackendId& id, FactoryFunction factory)
{
    if (m_BackendFactories.count(id) > 0)
    {
        throw InvalidArgumentException(std::string(id) + " already registered as backend",
                                       CHECK_LOCATION());
    }

    m_BackendFactories[id] = factory;
}

BackendRegistry::FactoryFunction BackendRegistry::GetFactory(const BackendId& id) const
{
    auto it = m_BackendFactories.find(id);
    if (it == m_BackendFactories.end())
    {
        throw InvalidArgumentException(std::string(id) + " has no backend factory registered",
                                       CHECK_LOCATION());
    }

    return it->second;
}

void BackendRegistry::Swap(BackendRegistry::FactoryStorage& other)
{
    BackendRegistry& instance = Instance();
    std::swap(instance.m_BackendFactories, other);
}

BackendIdSet BackendRegistry::GetBackendIds() const
{
    BackendIdSet result;
    for (const auto& it : m_BackendFactories)
    {
        result.insert(it.first);
    }
    return result;
}

} // namespace armnn
