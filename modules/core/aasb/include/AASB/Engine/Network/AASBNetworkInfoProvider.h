/*
 * Copyright 2017-2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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

#ifndef AASB_ENGINE_NETWORK_AASB_NETWORK_INFO_PROVIDER_H
#define AASB_ENGINE_NETWORK_AASB_NETWORK_INFO_PROVIDER_H

#include <AACE/Network/NetworkInfoProvider.h>
#include <AACE/Engine/MessageBroker/MessageBrokerInterface.h>

namespace aasb {
namespace engine {
namespace network {

class AASBNetworkInfoProvider
        : public aace::network::NetworkInfoProvider
        , public std::enable_shared_from_this<AASBNetworkInfoProvider> {
private:
    AASBNetworkInfoProvider() = default;

    bool initialize(std::shared_ptr<aace::engine::messageBroker::MessageBrokerInterface> messageBroker);

public:
    static std::shared_ptr<AASBNetworkInfoProvider> create(
        std::shared_ptr<aace::engine::messageBroker::MessageBrokerInterface> messageBroker);

    // aace::network::NetworkInfoProvider
    NetworkStatus getNetworkStatus() override;
    int getWifiSignalStrength() override;

private:
    std::weak_ptr<aace::engine::messageBroker::MessageBrokerInterface> m_messageBroker;
};

}  // namespace network
}  // namespace engine
}  // namespace aasb

#endif
