//
// Copyright © 2017 Arm Ltd. All rights reserved.
// See LICENSE file in the project root for full license information.
//
#include "backends/ClWorkloadFactory.hpp"
#include "backends/RefWorkloadFactory.hpp"
#include "backends/MemCopyWorkload.hpp"
#include "backends/ClWorkloadUtils.hpp"
#include "backends/ClWorkloads.hpp"
#include "backends/ClTensorHandle.hpp"

#include "test/CreateWorkloadClNeon.hpp"

boost::test_tools::predicate_result CompareIClTensorHandleShape(IClTensorHandle*                    tensorHandle,
                                                                std::initializer_list<unsigned int> expectedDimensions)
{
    return CompareTensorHandleShape<IClTensorHandle>(tensorHandle, expectedDimensions);
}

BOOST_AUTO_TEST_SUITE(CreateWorkloadCl)

BOOST_AUTO_TEST_CASE(CreateActivationWorkload)
{
    Graph graph;
    ClWorkloadFactory factory;

    auto workload = CreateActivationWorkloadTest<ClActivationFloat32Workload>(factory, graph);

    // check that inputs/outputs are as we expect them (see definition of CreateActivationWorkloadTest)
    ActivationQueueDescriptor queueDescriptor = workload->GetData();
    auto inputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Inputs[0]);
    auto outputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Outputs[0]);

    BOOST_TEST(CompareIClTensorHandleShape(inputHandle, {1}));
    BOOST_TEST(CompareIClTensorHandleShape(outputHandle, {1}));
}

BOOST_AUTO_TEST_CASE(CreateAdditionWorkload)
{
    Graph graph;
    ClWorkloadFactory factory;

    auto workload = CreateAdditionWorkloadTest<ClAdditionFloat32Workload>(factory, graph);

    // check that inputs/outputs are as we expect them (see definition of CreateAdditionWorkloadTest)
    AdditionQueueDescriptor queueDescriptor = workload->GetData();
    auto inputHandle1 = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Inputs[0]);
    auto inputHandle2 = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Inputs[1]);
    auto outputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Outputs[0]);
    BOOST_TEST(CompareIClTensorHandleShape(inputHandle1, {2, 3}));
    BOOST_TEST(CompareIClTensorHandleShape(inputHandle2, {2, 3}));
    BOOST_TEST(CompareIClTensorHandleShape(outputHandle, {2, 3}));
}

BOOST_AUTO_TEST_CASE(CreateBatchNormalizationWorkload)
{
    Graph             graph;
    ClWorkloadFactory factory;

    auto workload = CreateBatchNormalizationWorkloadTest<ClBatchNormalizationFloat32Workload>(factory, graph);

    // check that inputs/outputs are as we expect them (see definition of CreateBatchNormalizationWorkloadTest)
    BatchNormalizationQueueDescriptor queueDescriptor = workload->GetData();
    auto inputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Inputs[0]);
    auto outputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Outputs[0]);

    BOOST_TEST(CompareIClTensorHandleShape(inputHandle, {2, 3, 1, 1}));
    BOOST_TEST(CompareIClTensorHandleShape(outputHandle, {2, 3, 1, 1}));
}

template <typename Convolution2dWorkloadType>
static void Convolution2dWorkloadTest()
{
    Graph               graph;
    ClWorkloadFactory   factory;
    auto                workload = CreateConvolution2dWorkloadTest<Convolution2dWorkloadType>(factory, graph);

    // check that outputs and inputs are as we expect them (see definition of CreateConvolution2dWorkloadTest)
    Convolution2dQueueDescriptor queueDescriptor = workload->GetData();
    auto inputHandle  = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Inputs[0]);
    auto outputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Outputs[0]);
    BOOST_TEST(CompareIClTensorHandleShape(inputHandle, {2, 3, 8, 16}));
    BOOST_TEST(CompareIClTensorHandleShape(outputHandle, {2, 2, 2, 10}));
}

BOOST_AUTO_TEST_CASE(CreateConvolution2dFloat32Workload)
{
    Convolution2dWorkloadTest<ClConvolution2dFloat32Workload>();
}


template <typename Convolution2dWorkloadType>
static void DirectConvolution2dWorkloadTest()
{
    Graph               graph;
    ClWorkloadFactory   factory;
    auto                workload = CreateDirectConvolution2dWorkloadTest<Convolution2dWorkloadType>(factory, graph);

    // check that outputs and inputs are as we expect them (see definition of CreateDirectConvolution2dWorkloadTest)
    Convolution2dQueueDescriptor queueDescriptor = workload->GetData();
    auto inputHandle  = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Inputs[0]);
    auto outputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Outputs[0]);
    BOOST_TEST(CompareIClTensorHandleShape(inputHandle, {2, 3, 6, 6}));
    BOOST_TEST(CompareIClTensorHandleShape(outputHandle, {2, 2, 6, 6}));
}

BOOST_AUTO_TEST_CASE(CreateDirectConvolution2dFloat32Workload)
{
    DirectConvolution2dWorkloadTest<ClConvolution2dFloat32Workload>();
}

BOOST_AUTO_TEST_CASE(CreateDirectConvolution2dUint8Workload)
{
    DirectConvolution2dWorkloadTest<ClConvolution2dUint8Workload>();
}

BOOST_AUTO_TEST_CASE(CreateFullyConnectedWorkload)
{
    Graph             graph;
    ClWorkloadFactory factory;
    auto              workload =
        CreateFullyConnectedWorkloadTest<ClFullyConnectedFloat32Workload>(factory, graph);

    // check that outputs and inputs are as we expect them (see definition of CreateFullyConnectedWorkloadTest)
    FullyConnectedQueueDescriptor queueDescriptor = workload->GetData();
    auto inputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Inputs[0]);
    auto outputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Outputs[0]);
    BOOST_TEST(CompareIClTensorHandleShape(inputHandle, {3, 1, 4, 5}));
    BOOST_TEST(CompareIClTensorHandleShape(outputHandle, {3, 7}));
}

BOOST_AUTO_TEST_CASE(CreateMultiplicationWorkload)
{
    Graph             graph;
    ClWorkloadFactory factory;

    auto workload =
        CreateMultiplicationWorkloadTest<ClMultiplicationFloat32Workload>(factory, graph);

    // check that inputs/outputs are as we expect them (see definition of CreateMultiplicationWorkloadTest)
    MultiplicationQueueDescriptor queueDescriptor = workload->GetData();
    auto inputHandle1 = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Inputs[0]);
    auto inputHandle2 = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Inputs[1]);
    auto outputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Outputs[0]);
    BOOST_TEST(CompareIClTensorHandleShape(inputHandle1, {2, 3}));
    BOOST_TEST(CompareIClTensorHandleShape(inputHandle2, {2, 3}));
    BOOST_TEST(CompareIClTensorHandleShape(outputHandle, {2, 3}));
}

BOOST_AUTO_TEST_CASE(CreateNormalizationWorkload)
{
    Graph             graph;
    ClWorkloadFactory factory;

    auto workload = CreateNormalizationWorkloadTest<ClNormalizationFloat32Workload>(factory, graph);

    // check that inputs/outputs are as we expect them (see definition of CreateNormalizationWorkloadTest)
    NormalizationQueueDescriptor queueDescriptor = workload->GetData();
    auto inputHandle  = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Inputs[0]);
    auto outputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Outputs[0]);

    BOOST_TEST(CompareIClTensorHandleShape(inputHandle, {3, 5, 5, 1}));
    BOOST_TEST(CompareIClTensorHandleShape(outputHandle, {3, 5, 5, 1}));
}

BOOST_AUTO_TEST_CASE(CreatePooling2dWorkload)
{
    Graph             graph;
    ClWorkloadFactory factory;

    auto workload = CreatePooling2dWorkloadTest<ClPooling2dFloat32Workload>(factory, graph);

    // check that inputs/outputs are as we expect them (see definition of CreatePooling2dWorkloadTest)
    Pooling2dQueueDescriptor queueDescriptor = workload->GetData();
    auto inputHandle  = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Inputs[0]);
    auto outputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Outputs[0]);

    BOOST_TEST(CompareIClTensorHandleShape(inputHandle, {3, 2, 5, 5}));
    BOOST_TEST(CompareIClTensorHandleShape(outputHandle, {3, 2, 2, 4}));
}

template <typename ReshapeWorkloadType>
static void ClCreateReshapeWorkloadTest()
{
    Graph             graph;
    ClWorkloadFactory factory;

    auto workload = CreateReshapeWorkloadTest<ReshapeWorkloadType>(factory, graph);

    // check that outputs and inputs are as we expect them (see definition of CreateReshapeWorkloadTest)
    ReshapeQueueDescriptor queueDescriptor = workload->GetData();
    auto                   inputHandle     = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Inputs[0]);
    auto                   outputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Outputs[0]);

    BOOST_TEST(CompareIClTensorHandleShape(inputHandle, {4, 1}));
    BOOST_TEST(CompareIClTensorHandleShape(outputHandle, {4})); // Leading size 1 dimensions are collapsed by ACL.
}

BOOST_AUTO_TEST_CASE(CreateReshapeFloat32Workload)
{
    ClCreateReshapeWorkloadTest<ClReshapeFloat32Workload>();
}

BOOST_AUTO_TEST_CASE(CreateReshapeUint8Workload)
{
    ClCreateReshapeWorkloadTest<ClReshapeUint8Workload>();
}

BOOST_AUTO_TEST_CASE(CreateSoftmaxWorkload)
{
    Graph             graph;
    ClWorkloadFactory factory;

    auto workload = CreateSoftmaxWorkloadTest<ClSoftmaxFloat32Workload>(factory, graph);

    // check that inputs/outputs are as we expect them (see definition of ClSoftmaxFloat32Workload)
    SoftmaxQueueDescriptor queueDescriptor = workload->GetData();
    auto                   inputHandle     = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Inputs[0]);
    auto                   outputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Outputs[0]);

    BOOST_TEST(CompareIClTensorHandleShape(inputHandle, {4, 1}));
    BOOST_TEST(CompareIClTensorHandleShape(outputHandle, {4, 1}));
}

BOOST_AUTO_TEST_CASE(CreateSplitterWorkload)
{
    Graph graph;
    ClWorkloadFactory factory;

    auto workload = CreateSplitterWorkloadTest<ClSplitterFloat32Workload>(factory, graph);

    // check that outputs are as we expect them (see definition of CreateSplitterWorkloadTest)
    SplitterQueueDescriptor queueDescriptor = workload->GetData();
    auto inputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Inputs[0]);
    BOOST_TEST(CompareIClTensorHandleShape(inputHandle, {5, 7, 7}));

    auto outputHandle1 = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Outputs[1]);
    BOOST_TEST(CompareIClTensorHandleShape(outputHandle1, {2, 7, 7}));

    auto outputHandle2 = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Outputs[2]);
    BOOST_TEST(CompareIClTensorHandleShape(outputHandle2, {2, 7, 7}));

    auto outputHandle0 = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Outputs[0]);
    // NOTE: At the moment the CL collapses the tensor to a 2 dim when dimension zero = 1
    //       we are raising this difference between the NEON and CL libs as an issue with the compute library team
    BOOST_TEST(CompareIClTensorHandleShape(outputHandle0, {7, 7}));
}

BOOST_AUTO_TEST_CASE(CreateSplitterMerger)
{
    // Test that it is possible to decide which output of the splitter layer
    // should be lined to which input of the merger layer
    // We test that is is possible to specify 0th output
    // of the splitter to be the 1st input to the merger and the 1st output of the splitter  to be 0th input
    // of the merger.

    Graph graph;
    ClWorkloadFactory factory;

    auto workloads =
        CreateSplitterMergerWorkloadTest<ClSplitterFloat32Workload, ClMergerFloat32Workload>(factory, graph);

    auto wlSplitter = std::move(workloads.first);
    auto wlMerger = std::move(workloads.second);

    //check that the index of inputs/outputs matches what we declared on InputDescriptor construction.
    armnn::ClSubTensorHandle* sOut0 = dynamic_cast<armnn::ClSubTensorHandle*>(wlSplitter->GetData().m_Outputs[0]);
    armnn::ClSubTensorHandle* sOut1 = dynamic_cast<armnn::ClSubTensorHandle*>(wlSplitter->GetData().m_Outputs[1]);
    armnn::ClSubTensorHandle* mIn0 = dynamic_cast<armnn::ClSubTensorHandle*>(wlMerger->GetData().m_Inputs[0]);
    armnn::ClSubTensorHandle* mIn1 = dynamic_cast<armnn::ClSubTensorHandle*>(wlMerger->GetData().m_Inputs[1]);

    BOOST_TEST(sOut0);
    BOOST_TEST(sOut1);
    BOOST_TEST(mIn0);
    BOOST_TEST(mIn1);

    //fliped order of inputs/outputs
    bool validDataPointers = (sOut0 == mIn1) && (sOut1 == mIn0);
    BOOST_TEST(validDataPointers);


    //also make sure that the inputs are subtensors of one tensor and outputs are sub tensors of another tensor
    bool validSubTensorParents = (mIn0->GetTensor().parent() == mIn1->GetTensor().parent())
                                    && (sOut0->GetTensor().parent() == sOut1->GetTensor().parent());

    BOOST_TEST(validSubTensorParents);
}

BOOST_AUTO_TEST_CASE(CreateSingleOutputMultipleInputs)
{
    // Test that it is possible to assign multiple (two) different layers to each of the outputs of a splitter layer.
    // We create a splitter with two outputs. That each of those outputs is used by two different activation layers

    Graph graph;
    ClWorkloadFactory factory;
    std::unique_ptr<ClSplitterFloat32Workload> wlSplitter;
    std::unique_ptr<ClActivationFloat32Workload> wlActiv0_0;
    std::unique_ptr<ClActivationFloat32Workload> wlActiv0_1;
    std::unique_ptr<ClActivationFloat32Workload> wlActiv1_0;
    std::unique_ptr<ClActivationFloat32Workload> wlActiv1_1;

    CreateSplitterMultipleInputsOneOutputWorkloadTest<ClSplitterFloat32Workload,
        ClActivationFloat32Workload>(factory, graph, wlSplitter, wlActiv0_0, wlActiv0_1, wlActiv1_0, wlActiv1_1);

    //check that the index of inputs/outputs matches what we declared on InputDescriptor construction.
    armnn::ClSubTensorHandle* sOut0 = dynamic_cast<armnn::ClSubTensorHandle*>(wlSplitter->GetData().m_Outputs[0]);
    armnn::ClSubTensorHandle* sOut1 = dynamic_cast<armnn::ClSubTensorHandle*>(wlSplitter->GetData().m_Outputs[1]);
    armnn::ClSubTensorHandle* activ0_0Im = dynamic_cast<armnn::ClSubTensorHandle*>(wlActiv0_0->GetData().m_Inputs[0]);
    armnn::ClSubTensorHandle* activ0_1Im = dynamic_cast<armnn::ClSubTensorHandle*>(wlActiv0_1->GetData().m_Inputs[0]);
    armnn::ClSubTensorHandle* activ1_0Im = dynamic_cast<armnn::ClSubTensorHandle*>(wlActiv1_0->GetData().m_Inputs[0]);
    armnn::ClSubTensorHandle* activ1_1Im = dynamic_cast<armnn::ClSubTensorHandle*>(wlActiv1_1->GetData().m_Inputs[0]);


    BOOST_TEST(sOut0);
    BOOST_TEST(sOut1);
    BOOST_TEST(activ0_0Im);
    BOOST_TEST(activ0_1Im);
    BOOST_TEST(activ1_0Im);
    BOOST_TEST(activ1_1Im);

    bool validDataPointers = (sOut0 == activ0_0Im) && (sOut0 == activ0_1Im) &&
                             (sOut1 == activ1_0Im) && (sOut1 == activ1_1Im);

    BOOST_TEST(validDataPointers);
}

BOOST_AUTO_TEST_CASE(CreateMemCopyWorkloadsCl)
{
    ClWorkloadFactory    factory;
    CreateMemCopyWorkloads<CopyFromCpuToClWorkload,CopyFromClToCpuWorkload,IClTensorHandle>(factory);
}

BOOST_AUTO_TEST_CASE(CreateL2NormalizationWorkload)
{
    Graph             graph;
    ClWorkloadFactory factory;

    auto workload = CreateL2NormalizationWorkloadTest<ClL2NormalizationFloat32Workload>(factory, graph);

    // check that inputs/outputs are as we expect them (see definition of CreateNormalizationWorkloadTest)
    L2NormalizationQueueDescriptor queueDescriptor = workload->GetData();
    auto inputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Inputs[0]);
    auto outputHandle = boost::polymorphic_downcast<IClTensorHandle*>(queueDescriptor.m_Outputs[0]);

    BOOST_TEST(CompareIClTensorHandleShape(inputHandle, { 5, 20, 50, 67 }));
    BOOST_TEST(CompareIClTensorHandleShape(outputHandle, { 5, 20, 50, 67 }));
}

BOOST_AUTO_TEST_SUITE_END()
