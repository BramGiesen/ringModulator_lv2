// ISC License
//
// Copyright (c) 2018 Jakob Dübel <jkbd@posteo.de>
//
// Permission to use, copy, modify, and/or distribute this software
// for any purpose with or without fee is hereby granted, provided
// that the above copyright notice and this permission notice appear
// in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
// WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
// AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR
// CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
// OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
// NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
// CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

#ifndef AudioProcess_H
#define AudioProcess_H

#include <cmath>
#define _USE_MATH_DEFINES

#include "lv2.h"
#include "oscillator.h"
#include "randomGen.h"
#include "sineWave.h"

// A namespace to force these symbols being not exported in the shared
// library.
namespace audioP {

  class AudioProcess {
  public:
    AudioProcess();
    ~AudioProcess();
    void sample_rate(double sampleRate);
    void run(uint32_t n_samples);
    void setFrequency();
    float controlValueToDivider(int noteValue);

    // Port buffers
    float *in1;
    float *in2;
    float *out1;
    float *out2;
    float *freq;
    float *lfoSpeed;
    float *lfoDepth;

    enum Port {
      IN1 = 0,
      IN2 = 1,
      OUT1 = 2,
      OUT2 = 3,
      FREQ = 4,
      LFOSPEED = 5,
      LFODEPTH =6
    };

  private:
    Oscillator **oscillators;
    double sampleRate = 48000.0;
  };

  static LV2_Handle
  instantiate(const LV2_Descriptor*     descriptor,
	      double                    rate,
	      const char*               bundle_path,
	      const LV2_Feature* const* features);

  static void
  connect_port(LV2_Handle instance,
	       uint32_t   port,
	       void*      data);

  static void
  activate(LV2_Handle instance);

  static void
  run(LV2_Handle instance, uint32_t n_samples);

  static void
  deactivate(LV2_Handle instance);

  static void
  cleanup(LV2_Handle instance);

  static const void*
  extension_data(const char* uri);

  static constexpr char uri[] = "https://github.com/BramGiesen/ringModulator";

  static const LV2_Descriptor
  descriptor = {
	      audioP::uri,
	      instantiate, // instantiate
	      connect_port, // connect_port,
	      activate, // activate
	      run, // run
	      deactivate, // deactivate
	      cleanup, // cleanup
	      extension_data // extension_data
  };
} // namespace audioP

// Force no C++ name mangeling
extern "C" {
  const LV2_Descriptor* lv2_descriptor(uint32_t index);
}

#endif // AudioProcess_H
