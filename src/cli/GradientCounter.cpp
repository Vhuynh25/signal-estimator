/* Copyright (c) 2020 Victor Gaydov
 *
 * This code is licensed under the MIT License.
 */

#include "GradientCounter.hpp"

namespace signal_estimator {

double GradientCounter::add(double val) {
    if (size_ < 2) {
        prev_[size_++] = val;
        return 0;
    }

    const double ret = (val - prev_[0]) / 2;

    prev_[0] = prev_[1];
    prev_[1] = val;

    return ret;
}

} // namespace signal_estimator
