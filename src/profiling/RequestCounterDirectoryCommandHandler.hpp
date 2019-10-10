//
// Copyright © 2019 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include "CommandHandlerFunctor.hpp"
#include "ISendCounterPacket.hpp"
#include "Packet.hpp"
#include "ProfilingStateMachine.hpp"

namespace armnn
{

namespace profiling
{

class RequestCounterDirectoryCommandHandler : public CommandHandlerFunctor
{

public:
    RequestCounterDirectoryCommandHandler(uint32_t packetId,
                                          uint32_t version,
                                          ICounterDirectory& counterDirectory,
                                          ISendCounterPacket& sendCounterPacket,
                                          ProfilingStateMachine& profilingStateMachine)
        : CommandHandlerFunctor(packetId, version)
        , m_CounterDirectory(counterDirectory)
        , m_SendCounterPacket(sendCounterPacket)
        , m_StateMachine(profilingStateMachine)
    {}

    void operator()(const Packet& packet) override;

private:
    const ICounterDirectory& m_CounterDirectory;
    ISendCounterPacket& m_SendCounterPacket;
    const ProfilingStateMachine& m_StateMachine;
};

} // namespace profiling

} // namespace armnn
