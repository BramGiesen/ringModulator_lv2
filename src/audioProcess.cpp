#include "audioProcess.h"
#include <iostream>

namespace audioP {

  inline float decibel_to_coef(float gain) {
    return ((gain) > -90.0f ? powf(10.0f, (gain) * 0.05f) : 0.0f);
  }

  AudioProcess::AudioProcess()
  {
    oscillators = new Oscillator*[2];
    oscillators[0] = new RandomGenerator(sampleRate, 10);
    oscillators[1] = new SineWave(sampleRate, 440);
  }

  AudioProcess::~AudioProcess()
  {

  }

  void AudioProcess::sample_rate(double sampleRate)
  {
    this->sampleRate = sampleRate;
  }

  //create a divider for beatsync
  float AudioProcess::controlValueToDivider(int noteValue)
  {
    int base = 15;

    for (uint32_t times = 0; times < noteValue; times++) {
      base = base + base;
    }

    return base;
  }

  void AudioProcess::setFrequency()
  {
    //TODO get bpm for host
    float divider = controlValueToDivider(int(lfoSpeed[0]));
    //120 represents bpm for test
    float lfoFrequency = 120.0 / divider;
    //set LFO with beatsync frequency
    oscillators[0]->setFrequency(lfoFrequency);
    //TODO next step is to set the right phase coresponding to the possition in bar
    oscillators[1]->setFrequency(freq[0] + (oscillators[0]->getSample() * lfoDepth[0]));
  }

  void AudioProcess::run(uint32_t n_samples)
  {
    for (uint32_t pos = 0; pos < n_samples; ++pos) {

      setFrequency();

      float oscSample = oscillators[1]->getSample();
      float sampleL = in1[pos] * oscSample;
      float sampleR = in2[pos] * oscSample;

      out1[pos] = sampleL;
      out2[pos] = sampleL;

      for (uint32_t osc = 0; osc < 2; osc++) {
        oscillators[osc]->tick();
      }
    }
  }

  static LV2_Handle instantiate(const LV2_Descriptor*     descriptor,
				double                    rate,
				const char*               bundle_path,
				const LV2_Feature* const* features)
  {
    AudioProcess* audioProcess = new AudioProcess();
    audioProcess->sample_rate(rate);
    return static_cast<LV2_Handle>(audioProcess);
  }

  //mapping
  static void connect_port(LV2_Handle instance, uint32_t port, void* data)
  {
    AudioProcess* audioProcess = static_cast<AudioProcess*>(instance);
    switch (static_cast<AudioProcess::Port>(port)) {
      case AudioProcess::Port::IN1:
        audioProcess->in1 = static_cast<float*>(data);
        break;
      case AudioProcess::Port::IN2:
        audioProcess->in2 = static_cast<float*>(data);
        break;
      case AudioProcess::Port::OUT1:
        audioProcess->out1 = static_cast<float*>(data);
        break;
      case AudioProcess::Port::OUT2:
        audioProcess->out2 = static_cast<float*>(data);
        break;
      case AudioProcess::Port::FREQ:
        audioProcess->freq = static_cast<float*>(data);
        break;
      case AudioProcess::Port::LFOSPEED:
        audioProcess->lfoSpeed = static_cast<float*>(data);
        break;
      case AudioProcess::Port::LFODEPTH:
        audioProcess->lfoDepth = static_cast<float*>(data);
        break;
    }
  }

  static void activate(LV2_Handle instance)
  {
  }

  static void run(LV2_Handle instance, uint32_t n_samples)
  {
    AudioProcess* audioProcess = static_cast<AudioProcess*>(instance);
    audioProcess->run(n_samples);
  }

  static void deactivate(LV2_Handle instance)
  {
  }

  static void cleanup(LV2_Handle instance)
  {
    delete static_cast<AudioProcess*>(instance);
  }

  static const void* extension_data(const char* uri)
  {
    return nullptr;
  }
}

// Force no C++ name mangeling
extern "C" {
  const LV2_Descriptor* lv2_descriptor(uint32_t index) {
    switch (index) {
    case 0:  return &audioP::descriptor;
    default: return nullptr;
    }
  }
}
