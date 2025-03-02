/*
 * Copyright 2022 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#include "AACE/Wakeword/WakewordManager.h"

namespace aace {
namespace wakeword {

WakewordManager::~WakewordManager() = default;  // key function

bool WakewordManager::enable3PWakeword(const std::string& wakeword, bool wakewordState) {
    if (auto wakewordManagerEngineInterface_lock = m_wakewordManagerEngineInterface.lock()) {
        return  wakewordManagerEngineInterface_lock->onEnable3PWakeword(wakeword, wakewordState);
    }  else {
        return false;
    }

}

void WakewordManager::setEngineInterface(
    std::shared_ptr<WakewordManagerEngineInterface> wakewordManagerEngineInterface) {
    m_wakewordManagerEngineInterface = wakewordManagerEngineInterface;
}

}  // namespace wakeword
}  // namespace aace
