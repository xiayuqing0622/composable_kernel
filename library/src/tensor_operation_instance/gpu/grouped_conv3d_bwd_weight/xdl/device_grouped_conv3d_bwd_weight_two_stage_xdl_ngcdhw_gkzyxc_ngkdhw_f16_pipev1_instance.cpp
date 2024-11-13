// SPDX-License-Identifier: MIT
// Copyright (c) 2024, Advanced Micro Devices, Inc. All rights reserved.

#include "ck/library/tensor_operation_instance/add_device_operation_instance.hpp"
#include "ck/library/tensor_operation_instance/gpu/grouped_conv_bwd_weight/device_grouped_conv_bwd_weight_two_stage_xdl_instance.hpp"

namespace ck {
namespace tensor_operation {
namespace device {
namespace instance {

// Compilation parameters for in[n, hi, wi, g, c] * wei[g, k, y, x, c] = out[n, ho, wo, g, k]
void add_device_grouped_conv3d_bwd_weight_two_stage_xdl_ngcdhw_gkzyxc_ngkdhw_f16_pipev1_instances(
    std::vector<std::unique_ptr<DeviceGroupedConvBwdWeight<3,
                                                           NGCDHW,
                                                           GKZYXC,
                                                           NGKDHW,
                                                           F16,
                                                           F16,
                                                           F16,
                                                           PassThrough,
                                                           PassThrough,
                                                           PassThrough>>>& instances)
{
    // 1. Default
    add_device_operation_instances(
        instances,
        device_grouped_conv_bwd_weight_two_stage_ngchw_xdl_c_shuffle_f16_generic_instances<
            3,
            NGCDHW,
            GKZYXC,
            NGKDHW,
            ConvBwdWeightDefault,
            BlockGemmPipelineScheduler::Intrawave,
            BlockGemmPipelineVersion::v1>{});
}

} // namespace instance
} // namespace device
} // namespace tensor_operation
} // namespace ck