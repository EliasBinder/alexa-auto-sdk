/*
 * Copyright 2021 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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

#include <AACE/Engine/Core/EngineMacros.h>
#include <AACE/Engine/Metrics/MetricEvent.h>
#include <AACE/Engine/Utils/Metrics/Metrics.h>

namespace aace {
namespace engine {
namespace utils {
namespace metrics {

using namespace aace::engine::metrics;

/// Program Name prefix for metrics
static const std::string METRIC_PROGRAM_NAME_PREFIX = "AlexaAuto";

static const std::string CONTEXT_NONE = "0";

/// Delimiter
static const std::string DELIMITER = "_";

void emitCounterMetrics(
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::vector<std::string>& datapoints,
    MetricEvent::MetricBufferType bufferType,
    MetricEvent::MetricIdentityType identityType) {
    emitCounterMetrics(CONTEXT_NONE, metricSuffix, methodName, datapoints, bufferType, identityType);
}

void emitUniqueCounterMetrics(
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::vector<std::string>& datapoints) {
    emitCounterMetrics(CONTEXT_NONE,
        metricSuffix,
        methodName,
        datapoints,
        MetricEvent::MetricBufferType::NB,
        MetricEvent::MetricIdentityType::UNIQ);
}

void emitBufferedCounterMetrics(
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::vector<std::string>& datapoints) {
    emitCounterMetrics(CONTEXT_NONE,
        metricSuffix,
        methodName,
        datapoints,
        MetricEvent::MetricBufferType::BF,
        MetricEvent::MetricIdentityType::NUNI);
}

void emitCounterMetrics(
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::string& key,
    const int value,
    MetricEvent::MetricBufferType bufferType,
    MetricEvent::MetricIdentityType identityType) {
    emitCounterMetrics(CONTEXT_NONE, metricSuffix, methodName, key, value, bufferType, identityType);
}

void emitUniqueCounterMetrics(
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::string& key,
    const int value) {
    emitCounterMetrics(
        CONTEXT_NONE,
        metricSuffix,
        methodName,
        key,
        value,
        MetricEvent::MetricBufferType::NB,
        MetricEvent::MetricIdentityType::UNIQ);
}

void emitBufferedCounterMetrics(
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::string& key,
    const int value) {
    emitCounterMetrics(CONTEXT_NONE,
        metricSuffix,
        methodName,
        key,
        value,
        MetricEvent::MetricBufferType::BF,
        MetricEvent::MetricIdentityType::NUNI);
}

void emitTimerMetrics(
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::string& key,
    const double value,
    MetricEvent::MetricBufferType bufferType,
    MetricEvent::MetricIdentityType identityType) {
    emitTimerMetrics(CONTEXT_NONE, metricSuffix, methodName, key, value, bufferType, identityType);
}

void emitUniqueTimerMetrics(
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::string& key,
    const double value) {
    emitTimerMetrics(CONTEXT_NONE,
        metricSuffix,
        methodName,
        key,
        value,
        MetricEvent::MetricBufferType::NB,
        MetricEvent::MetricIdentityType::UNIQ);
}

void emitBufferedTimerMetrics(
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::string& key,
    const double value) {
    emitTimerMetrics(CONTEXT_NONE,
        metricSuffix,
        methodName,
        key,
        value,
        MetricEvent::MetricBufferType::BF,
        MetricEvent::MetricIdentityType::NUNI);
}

void emitMetrics(
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::vector<std::pair<std::string, int>>& counterDatapoints,
    const std::vector<std::pair<std::string, std::string>>& stringDatapoints,
    const std::vector<std::pair<std::string, double>>& timerDatapoints,
    MetricEvent::MetricBufferType bufferType,
    MetricEvent::MetricIdentityType identityType) {
    emitMetrics(
        CONTEXT_NONE,
        metricSuffix,
        methodName,
        counterDatapoints,
        stringDatapoints,
        timerDatapoints,
        bufferType,
        identityType);
}

void emitUniqueMetrics(
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::vector<std::pair<std::string, int>>& counterDatapoints,
    const std::vector<std::pair<std::string, std::string>>& stringDatapoints,
    const std::vector<std::pair<std::string, double>>& timerDatapoints) {
    emitMetrics(CONTEXT_NONE,
        metricSuffix,
        methodName,
        counterDatapoints,
        stringDatapoints,
        timerDatapoints,
        MetricEvent::MetricBufferType::NB,
        MetricEvent::MetricIdentityType::UNIQ);
}

void emitBufferedMetrics(
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::vector<std::pair<std::string, int>>& counterDatapoints,
    const std::vector<std::pair<std::string, std::string>>& stringDatapoints,
    const std::vector<std::pair<std::string, double>>& timerDatapoints) {
    emitMetrics(
        CONTEXT_NONE,
        metricSuffix,
        methodName,
        counterDatapoints,
        stringDatapoints,
        timerDatapoints,
        MetricEvent::MetricBufferType::BF,
        MetricEvent::MetricIdentityType::NUNI);
}

void emitCounterMetrics(
    const std::string& context,
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::vector<std::string>& datapoints,
    MetricEvent::MetricBufferType bufferType,
    MetricEvent::MetricIdentityType identityType) {
    auto metricEvent = std::shared_ptr<MetricEvent>(
        new MetricEvent(METRIC_PROGRAM_NAME_PREFIX + DELIMITER + metricSuffix, methodName, bufferType, identityType));
    if (metricEvent) {
        for (auto& datapoint : datapoints) {
            metricEvent->addCounter(datapoint, 1);
        }
        metricEvent->record(context);
    }
}

void emitUniqueCounterMetrics(
    const std::string& context,
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::vector<std::string>& datapoints) {
    emitCounterMetrics(
        context, metricSuffix, methodName, datapoints, MetricEvent::MetricBufferType::NB, MetricEvent::MetricIdentityType::UNIQ);
}

void emitBufferedCounterMetrics(
    const std::string& context,
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::vector<std::string>& datapoints) {
    emitCounterMetrics(
        context, metricSuffix, methodName, datapoints, MetricEvent::MetricBufferType::BF, MetricEvent::MetricIdentityType::NUNI);
}

void emitCounterMetrics(
    const std::string& context,
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::string& key,
    const int value,
    MetricEvent::MetricBufferType bufferType,
    MetricEvent::MetricIdentityType identityType) {
    auto metricEvent = std::shared_ptr<MetricEvent>(
        new MetricEvent(METRIC_PROGRAM_NAME_PREFIX + DELIMITER + metricSuffix, methodName, bufferType, identityType));
    if (metricEvent) {
        metricEvent->addCounter(key, value);
        metricEvent->record(context);
    }
}

void emitUniqueCounterMetrics(
    const std::string& context,
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::string& key,
    const int value) {
    emitCounterMetrics(
        context, metricSuffix, methodName, key, value, MetricEvent::MetricBufferType::NB, MetricEvent::MetricIdentityType::UNIQ);
}

void emitBufferedCounterMetrics(
    const std::string& context,
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::string& key,
    const int value) {
    emitCounterMetrics(
        context, metricSuffix, methodName, key, value, MetricEvent::MetricBufferType::BF, MetricEvent::MetricIdentityType::NUNI);
}

void emitTimerMetrics(
    const std::string& context,
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::string& key,
    const double value,
    MetricEvent::MetricBufferType bufferType,
    MetricEvent::MetricIdentityType identityType) {
    auto metricEvent = std::shared_ptr<MetricEvent>(
        new MetricEvent(METRIC_PROGRAM_NAME_PREFIX + DELIMITER + metricSuffix, methodName, bufferType, identityType));
    if (metricEvent) {
        metricEvent->addTimer(key, value);
        metricEvent->record(context);
    }
}

void emitUniqueTimerMetrics(
    const std::string& context,
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::string& key,
    const double value) {
    emitTimerMetrics(
        context, metricSuffix, methodName, key, value, MetricEvent::MetricBufferType::NB, MetricEvent::MetricIdentityType::UNIQ);
}

void emitBufferedTimerMetrics(
    const std::string& context,
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::string& key,
    const double value) {
    emitTimerMetrics(
        context, metricSuffix, methodName, key, value, MetricEvent::MetricBufferType::BF, MetricEvent::MetricIdentityType::NUNI);
}

void emitMetrics(
    const std::string& context,
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::vector<std::pair<std::string, int>>& counterDatapoints,
    const std::vector<std::pair<std::string, std::string>>& stringDatapoints,
    const std::vector<std::pair<std::string, double>>& timerDatapoints,
    MetricEvent::MetricBufferType bufferType,
    MetricEvent::MetricIdentityType identityType) {
    auto metricEvent = std::shared_ptr<MetricEvent>(
        new MetricEvent(METRIC_PROGRAM_NAME_PREFIX + DELIMITER + metricSuffix, methodName, bufferType, identityType));
    if (metricEvent) {
        for (auto& counterDatapoint : counterDatapoints) {
            metricEvent->addCounter(counterDatapoint.first, counterDatapoint.second);
        }
        for (auto& stringDatapoint : stringDatapoints) {
            metricEvent->addString(stringDatapoint.first, stringDatapoint.second);
        }
        for (auto& timerDatapoint : timerDatapoints) {
            metricEvent->addTimer(timerDatapoint.first, timerDatapoint.second);
        }
        metricEvent->record(context);
    }
}

void emitUniqueMetrics(
    const std::string& context,
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::vector<std::pair<std::string, int>>& counterDatapoints,
    const std::vector<std::pair<std::string, std::string>>& stringDatapoints,
    const std::vector<std::pair<std::string, double>>& timerDatapoints) {
    emitMetrics(
        context,
        metricSuffix,
        methodName,
        counterDatapoints,
        stringDatapoints,
        timerDatapoints,
        MetricEvent::MetricBufferType::NB,
        MetricEvent::MetricIdentityType::UNIQ);
}

void emitBufferedMetrics(
    const std::string& context,
    const std::string& metricSuffix,
    const std::string& methodName,
    const std::vector<std::pair<std::string, int>>& counterDatapoints,
    const std::vector<std::pair<std::string, std::string>>& stringDatapoints,
    const std::vector<std::pair<std::string, double>>& timerDatapoints) {
    emitMetrics(
        context,
        metricSuffix,
        methodName,
        counterDatapoints,
        stringDatapoints,
        timerDatapoints,
        MetricEvent::MetricBufferType::BF,
        MetricEvent::MetricIdentityType::NUNI);
}

double getCurrentTimeInMs() {
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
    double duration = now_ms.count();
    return duration;
}

}  // namespace metrics
}  // namespace utils
}  // namespace engine
}  // namespace aace
