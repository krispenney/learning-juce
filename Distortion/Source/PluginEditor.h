/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
 */
class DistortionAudioProcessorEditor  : public AudioProcessorEditor
{
public:
  DistortionAudioProcessorEditor (DistortionAudioProcessor&);
  ~DistortionAudioProcessorEditor();
  
  //==============================================================================
  void paint (Graphics&) override;
  void resized() override;
  
private:
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  DistortionAudioProcessor& processor;
  
  ScopedPointer<Slider> driveSlider;
  ScopedPointer<Slider> rangeSlider;
  ScopedPointer<Slider> blendSlider;
  ScopedPointer<Slider> volumeSlider;
  
  ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> driveAttachment;
  ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> rangeAttachment;
  ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> blendAttachment;
  ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> volumeAttachment;
  
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortionAudioProcessorEditor)
};
