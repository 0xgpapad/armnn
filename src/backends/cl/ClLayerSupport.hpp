//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//
#pragma once

#include <armnn/ILayerSupport.hpp>

namespace armnn
{

class ClLayerSupport : public ILayerSupport
{
public:
    bool IsActivationSupported(const TensorInfo& input,
                               const TensorInfo& output,
                               const ActivationDescriptor& descriptor,
                               Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsAdditionSupported(const TensorInfo& input0,
                             const TensorInfo& input1,
                             const TensorInfo& output,
                             Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsBatchNormalizationSupported(const TensorInfo& input,
                                       const TensorInfo& output,
                                       const TensorInfo& mean,
                                       const TensorInfo& var,
                                       const TensorInfo& beta,
                                       const TensorInfo& gamma,
                                       const BatchNormalizationDescriptor& descriptor,
                                       Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsConstantSupported(const TensorInfo& output,
                             Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsConvertFp16ToFp32Supported(const TensorInfo& input,
                                      const TensorInfo& output,
                                      Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsConvertFp32ToFp16Supported(const TensorInfo& input,
                                      const TensorInfo& output,
                                      Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsConvolution2dSupported(const TensorInfo& input,
                                  const TensorInfo& output,
                                  const Convolution2dDescriptor& descriptor,
                                  const TensorInfo& weights,
                                  const Optional<TensorInfo>& biases,
                                  Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsDepthwiseConvolutionSupported(const TensorInfo& input,
                                         const TensorInfo& output,
                                         const DepthwiseConvolution2dDescriptor& descriptor,
                                         const TensorInfo& weights,
                                         const Optional<TensorInfo>& biases,
                                         Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsDivisionSupported(const TensorInfo& input0,
                             const TensorInfo& input1,
                             const TensorInfo& output,
                             Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsFakeQuantizationSupported(const TensorInfo& input,
                                     const FakeQuantizationDescriptor& descriptor,
                                     Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsFloorSupported(const TensorInfo& input,
                          const TensorInfo& output,
                          Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsFullyConnectedSupported(const TensorInfo& input,
                                   const TensorInfo& output,
                                   const TensorInfo& weights,
                                   const TensorInfo& biases,
                                   const FullyConnectedDescriptor& descriptor,
                                   Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsInputSupported(const TensorInfo& input,
                          Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsL2NormalizationSupported(const TensorInfo& input,
                                    const TensorInfo& output,
                                    const L2NormalizationDescriptor& descriptor,
                                    Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsLstmSupported(const TensorInfo& input,
                         const TensorInfo& outputStateIn,
                         const TensorInfo& cellStateIn,
                         const TensorInfo& scratchBuffer,
                         const TensorInfo& outputStateOut,
                         const TensorInfo& cellStateOut,
                         const TensorInfo& output,
                         const LstmDescriptor& descriptor,
                         const TensorInfo& inputToForgetWeights,
                         const TensorInfo& inputToCellWeights,
                         const TensorInfo& inputToOutputWeights,
                         const TensorInfo& recurrentToForgetWeights,
                         const TensorInfo& recurrentToCellWeights,
                         const TensorInfo& recurrentToOutputWeights,
                         const TensorInfo& forgetGateBias,
                         const TensorInfo& cellBias,
                         const TensorInfo& outputGateBias,
                         const TensorInfo* inputToInputWeights,
                         const TensorInfo* recurrentToInputWeights,
                         const TensorInfo* cellToInputWeights,
                         const TensorInfo* inputGateBias,
                         const TensorInfo* projectionWeights,
                         const TensorInfo* projectionBias,
                         const TensorInfo* cellToForgetWeights,
                         const TensorInfo* cellToOutputWeights,
                         Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsMeanSupported(const TensorInfo& input,
                         const TensorInfo& output,
                         const MeanDescriptor& descriptor,
                         Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsMergerSupported(const std::vector<const TensorInfo*> inputs,
                           const OriginsDescriptor& descriptor,
                           Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsMultiplicationSupported(const TensorInfo& input0,
                                   const TensorInfo& input1,
                                   const TensorInfo& output,
                                   Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsNormalizationSupported(const TensorInfo& input,
                                  const TensorInfo& output,
                                  const NormalizationDescriptor& descriptor,
                                  Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsOutputSupported(const TensorInfo& output,
                           Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsPadSupported(const TensorInfo& input,
                        const TensorInfo& output,
                        const PadDescriptor& descriptor,
                        Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsPermuteSupported(const TensorInfo& input,
                            const TensorInfo& output,
                            const PermuteDescriptor& descriptor,
                            Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsPooling2dSupported(const TensorInfo& input,
                              const TensorInfo& output,
                              const Pooling2dDescriptor& descriptor,
                              Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsReshapeSupported(const TensorInfo& input,
                            Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsResizeBilinearSupported(const TensorInfo& input,
                                   Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsSoftmaxSupported(const TensorInfo& input,
                            const TensorInfo& output,
                            const SoftmaxDescriptor& descriptor,
                            Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsSplitterSupported(const TensorInfo& input,
                             const ViewsDescriptor& descriptor,
                             Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;

    bool IsSubtractionSupported(const TensorInfo& input0,
                                const TensorInfo& input1,
                                const TensorInfo& output,
                                Optional<std::string&> reasonIfUnsupported = EmptyOptional()) const override;
};

bool IsClDirectConvolution2dSupported(const TensorInfo& weightInfo, const Convolution2dDescriptor& desc);
bool IsClDepthwiseConvolution2dDescParamsSupported(Optional<std::string&> reasonIfUnsupported,
                                                   const DepthwiseConvolution2dDescriptor& parameters,
                                                   const TensorInfo& weights);

bool IsActivationSupportedCl(const TensorInfo& input,
                             const TensorInfo& output,
                             const ActivationDescriptor& descriptor,
                             Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsAdditionSupportedCl(const TensorInfo& input0,
                           const TensorInfo& input1,
                           const TensorInfo& output,
                           Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsBatchNormalizationSupportedCl(const TensorInfo& input,
                                     const TensorInfo& output,
                                     const TensorInfo& mean,
                                     const TensorInfo& var,
                                     const TensorInfo& beta,
                                     const TensorInfo& gamma,
                                     const BatchNormalizationDescriptor& descriptor,
                                     Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsConstantSupportedCl(const TensorInfo& output,
                           Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsConvolution2dSupportedCl(const TensorInfo& input,
                                const TensorInfo& output,
                                const Convolution2dDescriptor& descriptor,
                                const TensorInfo& weights,
                                const Optional<TensorInfo>& biases,
                                Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsDepthwiseConvolutionSupportedCl(const TensorInfo& input,
                                       const TensorInfo& output,
                                       const DepthwiseConvolution2dDescriptor& descriptor,
                                       const TensorInfo& weights,
                                       const Optional<TensorInfo>& biases,
                                       Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsDivisionSupportedCl(const TensorInfo& input0,
                           const TensorInfo& input1,
                           const TensorInfo& output,
                           Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsSubtractionSupportedCl(const TensorInfo& input0,
                              const TensorInfo& input1,
                              const TensorInfo& output,
                              Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsFullyConnectedSupportedCl(const TensorInfo& input,
                                 const TensorInfo& output,
                                 const TensorInfo& weights,
                                 const TensorInfo& biases,
                                 const FullyConnectedDescriptor& descriptor,
                                 Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsInputSupportedCl(const TensorInfo& input,
                        Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsL2NormalizationSupportedCl(const TensorInfo& input,
                                  const TensorInfo& output,
                                  const L2NormalizationDescriptor& descriptor,
                                  Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsLstmSupportedCl(const TensorInfo& input,
                       const TensorInfo& outputStateIn,
                       const TensorInfo& cellStateIn,
                       const TensorInfo& scratchBuffer,
                       const TensorInfo& outputStateOut,
                       const TensorInfo& cellStateOut,
                       const TensorInfo& output,
                       const LstmDescriptor& descriptor,
                       const TensorInfo& inputToForgetWeights,
                       const TensorInfo& inputToCellWeights,
                       const TensorInfo& inputToOutputWeights,
                       const TensorInfo& recurrentToForgetWeights,
                       const TensorInfo& recurrentToCellWeights,
                       const TensorInfo& recurrentToOutputWeights,
                       const TensorInfo& forgetGateBias,
                       const TensorInfo& cellBias,
                       const TensorInfo& outputGateBias,
                       const TensorInfo* inputToInputWeights,
                       const TensorInfo* recurrentToInputWeights,
                       const TensorInfo* cellToInputWeights,
                       const TensorInfo* inputGateBias,
                       const TensorInfo* projectionWeights,
                       const TensorInfo* projectionBias,
                       const TensorInfo* cellToForgetWeights,
                       const TensorInfo* cellToOutputWeights,
                       Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsMergerSupportedCl(const std::vector<const TensorInfo*> inputs,
                         const OriginsDescriptor& descriptor,
                         Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsMultiplicationSupportedCl(const TensorInfo& input0,
                                 const TensorInfo& input1,
                                 const TensorInfo& output,
                                 Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsNormalizationSupportedCl(const TensorInfo& input,
                                const TensorInfo& output,
                                const NormalizationDescriptor& descriptor,
                                Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsOutputSupportedCl(const TensorInfo& output,
                         Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsPermuteSupportedCl(const TensorInfo& input,
                          const TensorInfo& output,
                          const PermuteDescriptor& descriptor,
                          Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsPooling2dSupportedCl(const TensorInfo& input,
                            const TensorInfo& output,
                            const Pooling2dDescriptor& descriptor,
                            Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsResizeBilinearSupportedCl(const TensorInfo& input,
                                 Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsSoftmaxSupportedCl(const TensorInfo& input,
                          const TensorInfo& output,
                          const SoftmaxDescriptor& descriptor,
                          Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsSplitterSupportedCl(const TensorInfo& input,
                           const ViewsDescriptor& descriptor,
                           Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsFakeQuantizationSupportedCl(const TensorInfo& input,
                                   const FakeQuantizationDescriptor& descriptor,
                                   Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsReshapeSupportedCl(const TensorInfo& input,
                          Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsFloorSupportedCl(const TensorInfo& input,
                        const TensorInfo& output,
                        Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsConvertFp16ToFp32SupportedCl(const TensorInfo& input,
                                    const TensorInfo& output,
                                    Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsConvertFp32ToFp16SupportedCl(const TensorInfo& input,
                                    const TensorInfo& output,
                                    Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsMeanSupportedCl(const TensorInfo& input,
                       const TensorInfo& output,
                       const MeanDescriptor& descriptor,
                       Optional<std::string&> reasonIfUnsupported = EmptyOptional());

bool IsPadSupportedCl(const TensorInfo& input,
                      const TensorInfo& output,
                      const PadDescriptor& descriptor,
                      Optional<std::string&> reasonIfUnsupported = EmptyOptional());

}
