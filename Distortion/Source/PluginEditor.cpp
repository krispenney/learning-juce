/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortionAudioProcessorEditor::DistortionAudioProcessorEditor (DistortionAudioProcessor& p)
: AudioProcessorEditor (&p), processor (p)
{
  addAndMakeVisible(driveSlider = new Slider("Drive"));
  driveSlider->setSliderStyle(Slider::Rotary);
  driveSlider->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
  
  addAndMakeVisible(rangeSlider = new Slider("Range"));
  rangeSlider->setSliderStyle(Slider::Rotary);
  rangeSlider->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
  
  addAndMakeVisible(blendSlider = new Slider("Blend"));
  blendSlider->setSliderStyle(Slider::Rotary);
  blendSlider->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
  
  addAndMakeVisible(volumeSlider = new Slider("Volume"));
  volumeSlider->setSliderStyle(Slider::Rotary);
  volumeSlider->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
  
  driveAttachment = new AudioProcessorValueTreeState::SliderAttachment();
  
  
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize (500, 200);
}

DistortionAudioProcessorEditor::~DistortionAudioProcessorEditor()
{
}

//==============================================================================
void DistortionAudioProcessorEditor::paint (Graphics& g)
{
  // (Our component is opaque, so we must completely fill the background with a solid colour)
  g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
  
  g.setColour (Colours::white);
  g.setFont (15.0f);
  g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void DistortionAudioProcessorEditor::resized()
{
  // This is generally where you'll want to lay out the positions of any
  // subcomponents in your editor..
}
