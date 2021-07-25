/* Copyright (c) 2020 Victor Gaydov
 *
 * This code is licensed under the MIT License.
 */

#pragma once

#include <vector>

namespace signal_estimator {

// simple moving average
class SmaCounter {
public:
    SmaCounter(size_t size);

    SmaCounter(const SmaCounter&) = delete;
    SmaCounter& operator=(const SmaCounter&) = delete;

    double add(double);

private:
    std::vector<double> window_;

    size_t head_ {};
    size_t tail_ {};
    size_t size_ {};

    double avg_ {};
};

} // namespace signal_estimator
