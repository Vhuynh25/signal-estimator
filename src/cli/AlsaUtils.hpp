/* Copyright (c) 2020 Victor Gaydov
 *
 * This code is licensed under the MIT License.
 */

#pragma once

#include "Config.hpp"

#include <alsa/asoundlib.h>

namespace signal_estimator {

// open and setup ALSA PCM device
snd_pcm_t* alsa_open(const char* device, snd_pcm_stream_t mode, Config& config);

// close ALSA PCM device
void alsa_close(snd_pcm_t* pcm);

} // namespace signal_estimator
