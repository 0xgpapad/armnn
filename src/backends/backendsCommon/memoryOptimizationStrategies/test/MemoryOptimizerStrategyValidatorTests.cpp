//
// Copyright © 2021 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include <backendsCommon/memoryOptimizationStrategies/MemoryOptimizerStrategyValidator.hpp>

#include <doctest/doctest.h>
#include <vector>

using namespace armnn;

TEST_SUITE("MemoryOptimizerStrategyValidatorTestSuite")
{

// TestMemoryOptimizerStrategy: Create a MemBin and put all blocks in it so the can overlap.
class TestMemoryOptimizerStrategy : public IMemoryOptimizerStrategy
{
public:
    TestMemoryOptimizerStrategy(MemBlockStrategyType type)
            : m_Name(std::string("testMemoryOptimizerStrategy"))
            , m_MemBlockStrategyType(type) {}

    std::string GetName() const override
    {
        return m_Name;
    }

    MemBlockStrategyType GetMemBlockStrategyType() const override
    {
        return m_MemBlockStrategyType;
    }

    std::vector<MemBin> Optimize(std::vector<MemBlock>& memBlocks) override
    {
        std::vector<MemBin> memBins;
        memBins.reserve(memBlocks.size());

        MemBin memBin;
        memBin.m_MemBlocks.reserve(memBlocks.size());
        memBin.m_MemSize = 0;
        for (auto& memBlock : memBlocks)
        {

            memBin.m_MemSize = memBin.m_MemSize + memBlock.m_MemSize;
            memBin.m_MemBlocks.push_back(memBlock);
        }
        memBins.push_back(memBin);

        return memBins;
    }

private:
    std::string m_Name;
    MemBlockStrategyType m_MemBlockStrategyType;
};

TEST_CASE("MemoryOptimizerStrategyValidatorTestOverlapX")
{
    // create a few memory blocks
    MemBlock memBlock0(0, 5, 20, 0, 0);
    MemBlock memBlock1(5, 10, 10, 0, 1);
    MemBlock memBlock2(10, 15, 15, 0, 2);
    MemBlock memBlock3(15, 20, 20, 0, 3);
    MemBlock memBlock4(20, 25, 5, 0, 4);

    std::vector<MemBlock> memBlocks;
    memBlocks.reserve(5);
    memBlocks.push_back(memBlock0);
    memBlocks.push_back(memBlock1);
    memBlocks.push_back(memBlock2);
    memBlocks.push_back(memBlock3);
    memBlocks.push_back(memBlock4);

    // Optimize the memory blocks with TestMemoryOptimizerStrategySingle
    TestMemoryOptimizerStrategy testMemoryOptimizerStrategySingle(MemBlockStrategyType::SingleAxisPacking);
    auto ptr = std::make_shared<TestMemoryOptimizerStrategy>(testMemoryOptimizerStrategySingle);
    MemoryOptimizerValidator validator(std::move(ptr));
    // SingleAxisPacking can overlap on X axis.
    CHECK(validator.Validate(memBlocks));

    // Optimize the memory blocks with TestMemoryOptimizerStrategyMulti
    TestMemoryOptimizerStrategy testMemoryOptimizerStrategyMulti(MemBlockStrategyType::MultiAxisPacking);
    auto ptrMulti = std::make_shared<TestMemoryOptimizerStrategy>(testMemoryOptimizerStrategyMulti);
    MemoryOptimizerValidator validatorMulti(std::move(ptrMulti));
    // MultiAxisPacking can overlap on X axis.
    CHECK(validatorMulti.Validate(memBlocks));
}

TEST_CASE("MemoryOptimizerStrategyValidatorTestOverlapXAndY")
{
    // create a few memory blocks
    MemBlock memBlock0(0, 5, 20, 0, 0);
    MemBlock memBlock1(0, 10, 10, 0, 1);
    MemBlock memBlock2(0, 15, 15, 0, 2);
    MemBlock memBlock3(0, 20, 20, 0, 3);
    MemBlock memBlock4(0, 25, 5, 0, 4);

    std::vector<MemBlock> memBlocks;
    memBlocks.reserve(5);
    memBlocks.push_back(memBlock0);
    memBlocks.push_back(memBlock1);
    memBlocks.push_back(memBlock2);
    memBlocks.push_back(memBlock3);
    memBlocks.push_back(memBlock4);

    // Optimize the memory blocks with TestMemoryOptimizerStrategySingle
    TestMemoryOptimizerStrategy testMemoryOptimizerStrategySingle(MemBlockStrategyType::SingleAxisPacking);
    auto ptr = std::make_shared<TestMemoryOptimizerStrategy>(testMemoryOptimizerStrategySingle);
    MemoryOptimizerValidator validator(std::move(ptr));
    // SingleAxisPacking cannot overlap on both X and Y axis.
    CHECK(!validator.Validate(memBlocks));

    // Optimize the memory blocks with TestMemoryOptimizerStrategyMulti
    TestMemoryOptimizerStrategy testMemoryOptimizerStrategyMulti(MemBlockStrategyType::MultiAxisPacking);
    auto ptrMulti = std::make_shared<TestMemoryOptimizerStrategy>(testMemoryOptimizerStrategyMulti);
    MemoryOptimizerValidator validatorMulti(std::move(ptrMulti));
    // MultiAxisPacking cannot overlap on both X and Y axis.
    CHECK(!validatorMulti.Validate(memBlocks));
}

TEST_CASE("MemoryOptimizerStrategyValidatorTestOverlapY")
{
    // create a few memory blocks
    MemBlock memBlock0(0, 2, 20, 0, 0);
    MemBlock memBlock1(0, 3, 10, 20, 1);
    MemBlock memBlock2(0, 5, 15, 30, 2);
    MemBlock memBlock3(0, 6, 20, 50, 3);
    MemBlock memBlock4(0, 8, 5, 70, 4);

    std::vector<MemBlock> memBlocks;
    memBlocks.reserve(5);
    memBlocks.push_back(memBlock0);
    memBlocks.push_back(memBlock1);
    memBlocks.push_back(memBlock2);
    memBlocks.push_back(memBlock3);
    memBlocks.push_back(memBlock4);

    // Optimize the memory blocks with TestMemoryOptimizerStrategySingle
    TestMemoryOptimizerStrategy testMemoryOptimizerStrategySingle(MemBlockStrategyType::SingleAxisPacking);
    auto ptr = std::make_shared<TestMemoryOptimizerStrategy>(testMemoryOptimizerStrategySingle);
    MemoryOptimizerValidator validator(std::move(ptr));
    // SingleAxisPacking cannot overlap on Y axis
    CHECK(!validator.Validate(memBlocks));

    // Optimize the memory blocks with TestMemoryOptimizerStrategyMulti
    TestMemoryOptimizerStrategy testMemoryOptimizerStrategyMulti(MemBlockStrategyType::MultiAxisPacking);
    auto ptrMulti = std::make_shared<TestMemoryOptimizerStrategy>(testMemoryOptimizerStrategyMulti);
    MemoryOptimizerValidator validatorMulti(std::move(ptrMulti));
    // MultiAxisPacking can overlap on Y axis
    CHECK(validatorMulti.Validate(memBlocks));
}

// TestMemoryOptimizerStrategyDuplicate: Create a MemBin and put all blocks in it duplicating each so validator
// can check
class TestMemoryOptimizerStrategyDuplicate : public TestMemoryOptimizerStrategy
{
public:
    TestMemoryOptimizerStrategyDuplicate(MemBlockStrategyType type)
            : TestMemoryOptimizerStrategy(type)
    {}

    std::vector<MemBin> Optimize(std::vector<MemBlock>& memBlocks) override
    {
        std::vector<MemBin> memBins;
        memBins.reserve(memBlocks.size());

        MemBin memBin;
        memBin.m_MemBlocks.reserve(memBlocks.size());
        for (auto& memBlock : memBlocks)
        {
            memBin.m_MemSize = memBin.m_MemSize + memBlock.m_MemSize;
            memBin.m_MemBlocks.push_back(memBlock);
            // Put block in twice so it gets found twice
            memBin.m_MemBlocks.push_back(memBlock);
        }
        memBins.push_back(memBin);

        return memBins;
    }
};

TEST_CASE("MemoryOptimizerStrategyValidatorTestDuplicateBlocks")
{
    // create a few memory blocks
    MemBlock memBlock0(0, 2, 20, 0, 0);
    MemBlock memBlock1(2, 3, 10, 20, 1);
    MemBlock memBlock2(3, 5, 15, 30, 2);
    MemBlock memBlock3(5, 6, 20, 50, 3);
    MemBlock memBlock4(7, 8, 5, 70, 4);

    std::vector<MemBlock> memBlocks;
    memBlocks.reserve(5);
    memBlocks.push_back(memBlock0);
    memBlocks.push_back(memBlock1);
    memBlocks.push_back(memBlock2);
    memBlocks.push_back(memBlock3);
    memBlocks.push_back(memBlock4);

    // Optimize the memory blocks with TestMemoryOptimizerStrategySingle
    // Duplicate strategy is invalid as same block is found twice
    TestMemoryOptimizerStrategyDuplicate testMemoryOptimizerStrategySingle(MemBlockStrategyType::SingleAxisPacking);
    auto ptr = std::make_shared<TestMemoryOptimizerStrategyDuplicate>(testMemoryOptimizerStrategySingle);
    MemoryOptimizerValidator validator(std::move(ptr));
    CHECK(!validator.Validate(memBlocks));

    // Optimize the memory blocks with TestMemoryOptimizerStrategyMulti
    TestMemoryOptimizerStrategyDuplicate testMemoryOptimizerStrategyMulti(MemBlockStrategyType::MultiAxisPacking);
    auto ptrMulti = std::make_shared<TestMemoryOptimizerStrategyDuplicate>(testMemoryOptimizerStrategyMulti);
    MemoryOptimizerValidator validatorMulti(std::move(ptrMulti));
    CHECK(!validatorMulti.Validate(memBlocks));
}

// TestMemoryOptimizerStrategySkip: Create a MemBin and put all blocks in it skipping every other block so validator
// can check
class TestMemoryOptimizerStrategySkip : public TestMemoryOptimizerStrategy
{
public:
    TestMemoryOptimizerStrategySkip(MemBlockStrategyType type)
            : TestMemoryOptimizerStrategy(type)
    {}

    std::vector<MemBin> Optimize(std::vector<MemBlock>& memBlocks) override
    {
        std::vector<MemBin> memBins;
        memBins.reserve(memBlocks.size());

        MemBin memBin;
        memBin.m_MemBlocks.reserve(memBlocks.size());
        for (unsigned int i = 0; i < memBlocks.size()-1; i+=2)
        {
            auto memBlock = memBlocks[i];
            memBin.m_MemSize = memBin.m_MemSize + memBlock.m_MemSize;
            memBin.m_MemBlocks.push_back(memBlock);
        }
        memBins.push_back(memBin);

        return memBins;
    }
};

TEST_CASE("MemoryOptimizerStrategyValidatorTestSkipBlocks")
{
    // create a few memory blocks
    MemBlock memBlock0(0, 2, 20, 0, 0);
    MemBlock memBlock1(2, 3, 10, 20, 1);
    MemBlock memBlock2(3, 5, 15, 30, 2);
    MemBlock memBlock3(5, 6, 20, 50, 3);
    MemBlock memBlock4(7, 8, 5, 70, 4);

    std::vector<MemBlock> memBlocks;
    memBlocks.reserve(5);
    memBlocks.push_back(memBlock0);
    memBlocks.push_back(memBlock1);
    memBlocks.push_back(memBlock2);
    memBlocks.push_back(memBlock3);
    memBlocks.push_back(memBlock4);

    // Optimize the memory blocks with TestMemoryOptimizerStrategySingle
    // Skip strategy is invalid as every second block is not found
    TestMemoryOptimizerStrategySkip testMemoryOptimizerStrategySingle(MemBlockStrategyType::SingleAxisPacking);
    auto ptr = std::make_shared<TestMemoryOptimizerStrategySkip>(testMemoryOptimizerStrategySingle);
    MemoryOptimizerValidator validator(std::move(ptr));
    CHECK(!validator.Validate(memBlocks));

    // Optimize the memory blocks with TestMemoryOptimizerStrategyMulti
    TestMemoryOptimizerStrategySkip testMemoryOptimizerStrategyMulti(MemBlockStrategyType::MultiAxisPacking);
    auto ptrMulti = std::make_shared<TestMemoryOptimizerStrategySkip>(testMemoryOptimizerStrategyMulti);
    MemoryOptimizerValidator validatorMulti(std::move(ptrMulti));
    CHECK(!validatorMulti.Validate(memBlocks));
}

}
