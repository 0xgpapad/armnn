//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include "LayerTestResult.hpp"

#include <backendsCommon/IBackendInternal.hpp>
#include <backendsCommon/WorkloadFactory.hpp>

//
// Sigmoid
//

LayerTestResult<float, 4> SimpleSigmoidTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<uint8_t, 4> SimpleSigmoidUint8Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<int16_t, 4> SimpleSigmoidInt16Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

//
// TanH
//

LayerTestResult<float, 4> TanhTest(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<uint8_t, 4> TanhUint8Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<int16_t, 4> TanhInt16Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

//
// Linear
//

LayerTestResult<float, 4> ConstantLinearActivationTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<uint8_t, 4> ConstantLinearActivationUint8Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<int16_t, 4> ConstantLinearActivationInt16Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

//
// ReLu
//

LayerTestResult<float, 4> ReLuTest(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<uint8_t, 4> ReLuUint8Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<int16_t, 4> ReLuInt16Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

//
// BoundedReLu
//

LayerTestResult<uint8_t, 4> BoundedReLuUint8Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    float upperBound);

LayerTestResult<uint8_t, 4> BoundedReLuUint8Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    float upperBound,
    float lowerBound);

LayerTestResult<int16_t, 4> BoundedReLuInt16Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<float, 4> BoundedReLuUpperAndLowerBoundTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<uint8_t, 4> BoundedReLuUint8UpperAndLowerBoundTest(
    armnn::IWorkloadFactory& workloadFactor,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManagery);

LayerTestResult<float, 4> BoundedReLuUpperBoundOnlyTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<uint8_t, 4> BoundedReLuUint8UpperBoundOnlyTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<float, 4> CompareBoundedReLuTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    armnn::IWorkloadFactory& refWorkloadFactory,
    float upperBound,
    float lowerBound);

//
// SoftReLu
//

LayerTestResult<float, 4> SoftReLuTest(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<uint8_t, 4> SoftReLuUint8Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<int16_t, 4> SoftReLuInt16Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

//
// LeakyReLu
//

LayerTestResult<float, 4> LeakyReLuTest(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<uint8_t, 4> LeakyReLuUint8Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<int16_t, 4> LeakyReLuInt16Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

//
// Abs
//

LayerTestResult<float, 4> AbsTest(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<uint8_t, 4> AbsUint8Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<int16_t, 4> AbsInt16Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

//
// Sqrt
//

LayerTestResult<float, 4> SqrtTest(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<uint8_t, 4> SqrtUint8Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<int16_t, 4> SqrtInt16Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

//
// Square
//

LayerTestResult<float, 4> SquareTest(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<uint8_t, 4> SquareUint8Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

LayerTestResult<int16_t, 4> SquareInt16Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager);

//
// Other
//

LayerTestResult<float, 4> CompareActivationTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    armnn::IWorkloadFactory& refWorkloadFactory,
    armnn::ActivationFunction f,
    unsigned int batchSize);

LayerTestResult<uint8_t, 4> CompareActivationUint8Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    armnn::IWorkloadFactory& refWorkloadFactory,
    armnn::ActivationFunction f);

LayerTestResult<int16_t, 4> CompareActivationInt16Test(
        armnn::IWorkloadFactory& workloadFactory,
        const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
        armnn::IWorkloadFactory& refWorkloadFactory,
        armnn::ActivationFunction f);
