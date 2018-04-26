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
  
  driveAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "Drive", *driveSlider);
  rangeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "Range", *rangeSlider);
  blendAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "Blend", *blendSlider);
  volumeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "Volume", *volumeSlider);
  
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
  const float offsetWidth = getWidth() / 5;
  const float offsetHeight = getHeight() / 2 + 5;
  
  // (Our component is opaque, so we must completely fill the background with a solid colour)
  g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
  
  g.setColour (Colours::white);
  g.setFont (15.0f);
  g.drawText("Drive", offsetWidth * 1 - (CONTROL_SIZE / 2), offsetHeight, CONTROL_SIZE, CONTROL_SIZE, Justification::centred, false);
  g.drawText("Range", offsetWidth * 2 - (CONTROL_SIZE / 2), offsetHeight, CONTROL_SIZE, CONTROL_SIZE, Justification::centred, false);
  g.drawText("Blend", offsetWidth * 3 - (CONTROL_SIZE / 2), offsetHeight, CONTROL_SIZE, CONTROL_SIZE, Justification::centred, false);
  g.drawText("Volume", offsetWidth * 4 - (CONTROL_SIZE / 2), offsetHeight, CONTROL_SIZE, CONTROL_SIZE, Justification::centred, false);
}

void DistortionAudioProcessorEditor::resized()
{
  // This is generally where you'll want to lay out the positions of any
  // subcomponents in your editor..
  const float offsetWidth = getWidth() / 5;
  const float offsetHeight = getHeight() / 2;
  
  
  driveSlider->setBounds(offsetWidth * 1 - (CONTROL_SIZE / 2), offsetHeight - (CONTROL_SIZE / 2), CONTROL_SIZE, CONTROL_SIZE);
  rangeSlider->setBounds(offsetWidth * 2 - (CONTROL_SIZE / 2), offsetHeight - (CONTROL_SIZE / 2), CONTROL_SIZE, CONTROL_SIZE);
  blendSlider->setBounds(offsetWidth * 3 - (CONTROL_SIZE / 2), offsetHeight - (CONTROL_SIZE / 2), CONTROL_SIZE, CONTROL_SIZE);
  volumeSlider->setBounds(offsetWidth * 4 - (CONTROL_SIZE / 2), offsetHeight - (CONTROL_SIZE / 2), CONTROL_SIZE, CONTROL_SIZE);
}
