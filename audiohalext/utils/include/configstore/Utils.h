// Copyright (C) 2020 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef VENDOR_QTI_AUDIOHALEXT_UTILS_H
#define VENDOR_QTI_AUDIOHALEXT_UTILS_H

#include <android/hardware/configstore/1.0/types.h>
#include <vendor/qti/hardware/audiohalext/1.0/types.h>

namespace vendor {
namespace qti {
namespace hardware {

namespace audiohalext {

using namespace android;

using ::vendor::qti::hardware::audiohalext::V1_0::ApmConfigs;
using ::vendor::qti::hardware::audiohalext::V1_0::ApmValues;
using ::vendor::qti::hardware::audiohalext::V1_0::AVConfigs;
using ::vendor::qti::hardware::audiohalext::V1_0::AVValues;

template <typename I,
          android::hardware::Return<void> (I::*func)(std::function<void(const ApmConfigs&)>)>
ApmValues getApmConfigs(ApmValues defValue) {
    return get<ApmConfigs, I, func>(defValue);
}

template <typename I,
          android::hardware::Return<void> (I::*func)(std::function<void(const AVConfigs&)>)>
AVValues getAVConfigs(AVValues defValue) {
    return get<AVConfigs, I, func>(defValue);
}

}  // namespace audiohalext
}  // namespace hardware
}  // namespace qti
}  // namespace vendor

#endif  // VENDOR_QTI_AUDIOHALEXT_UTILS_H
