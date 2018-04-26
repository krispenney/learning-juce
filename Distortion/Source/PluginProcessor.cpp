/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin processor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortionAudioProcessor::DistortionAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
: AudioProcessor (BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
                  .withInput  ("Input",  AudioChannelSet::stereo(), true)
#endif
                  .withOutput ("Output", AudioChannelSet::stereo(), true)
#endif
                  )
#endif
{
  state = new AudioProcessorValueTreeState(*this, nullptr);
  state->createAndAddParameter("Drive", "Drive", "Drive", NormalisableRange<float>(0, 1, 0.001), 0.5, nullptr, nullptr);
  state->createAndAddParameter("Range", "Range", "Range", NormalisableRange<float>(0, 3000, 0.001), 0.5, nullptr, nullptr);
  state->createAndAddParameter("Blend", "Blend", "Blend", NormalisableRange<float>(0, 1, 0.001), 0.5, nullptr, nullptr);
  state->createAndAddParameter("Volume", "Volume", "Volume", NormalisableRange<float>(0, 3, 0.001), 0.5, nullptr, nullptr);
  
  // This object overloads the operator=, this builds the index
  state->state = ValueTree("Drive");
  state->state = ValueTree("Range");
  state->state = ValueTree("Blend");
  state->state = ValueTree("Volume");
}

DistortionAudioProcessor::~DistortionAudioProcessor()
{
}

//==============================================================================
const String DistortionAudioProcessor::getName() const
{
  return JucePlugin_Name;
}

bool DistortionAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
  return true;
#else
  return false;
#endif
}

bool DistortionAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
  return true;
#else
  return false;
#endif
}

bool DistortionAudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
  return true;
#else
  return false;
#endif
}

double DistortionAudioProcessor::getTailLengthSeconds() const
{
  return 0.0;
}

int DistortionAudioProcessor::getNumPrograms()
{
  return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
  // so this should be at least 1, even if you're not really implementing programs.
}

int DistortionAudioProcessor::getCurrentProgram()
{
  return 0;
}

void DistortionAudioProcessor::setCurrentProgram (int index)
{
}

const String DistortionAudioProcessor::getProgramName (int index)
{
  return {};
}

void DistortionAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void DistortionAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
  // Use this method as the place to do any pre-playback
  // initialisation that you need..
}

void DistortionAudioProcessor::releaseResources()
{
  // When playback stops, you can use this as an opportunity to free up any
  // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool DistortionAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
  ignoreUnused (layouts);
  return true;
#else
  // This is the place where you check if the layout is supported.
  // In this template code we only support mono or stereo.
  if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
      && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
    return false;
  
  // This checks if the input layout matches the output layout
#if ! JucePlugin_IsSynth
  if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
    return false;
#endif
  
  return true;
#endif
}
#endif

void DistortionAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
  ScopedNoDenormals noDenormals;
  auto totalNumInputChannels  = getTotalNumInputChannels();
  auto totalNumOutputChannels = getTotalNumOutputChannels();
  
  // In case we have more outputs than inputs, this code clears any output
  // channels that didn't contain input data, (because these aren't
  // guaranteed to be empty - they may contain garbage).
  // This is here to avoid people getting screaming feedback
  // when they first compile a plugin, but obviously you don't need to keep
  // this code if your algorithm always overwrites all the output channels.
  for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
    buffer.clear (i, 0, buffer.getNumSamples());
  
  // This is the place where you'd normally do the guts of your plugin's
  // audio processing...
  // Make sure to reset the state if your inner loop is processing
  // the samples and the outer loop is handling the channels.
  // Alternatively, you can process the samples with the channels
  // interleaved by keeping the same state.
  
  float drive = *state->getRawParameterValue("Drive");
  float range = *state->getRawParameterValue("Range");
  float blend = *state->getRawParameterValue("Blend");
  float volume = *state->getRawParameterValue("Volume");
  
  for (int channel = 0; channel < totalNumInputChannels; ++channel)
  {
    auto* channelData = buffer.getWritePointer (channel);
    
    for (int sample = 0; sample < buffer.getNumSamples(); ++sample) {
      const float cleanSample = channelData[sample];
      
      channelData[sample] *= drive * range;
      channelData[sample] = volume * ((blend * (2 / float_Pi) * atan(channelData[sample]) + (1 - blend) * cleanSample) / 2);
    }
  }
}

//==============================================================================
bool DistortionAudioProcessor::hasEditor() const
{
  return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* DistortionAudioProcessor::createEditor()
{
  return new DistortionAudioProcessorEditor (*this);
}

//==============================================================================
void DistortionAudioProcessor::getStateInformation (MemoryBlock& destData)
{
  // You should use this method to store your parameters in the memory block.
  // You could do that either as raw data, or use the XML or ValueTree classes
  // as intermediaries to make it easy to save and load complex data.
  MemoryOutputStream stream(destData, false);
  state->state.writeToStream(stream);
}

void DistortionAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
  // You should use this method to restore your parameters from this memory block,
  // whose contents will have been created by the getStateInformation() call.
  ValueTree tree = ValueTree::readFromData(data, sizeInBytes);
  
  if (tree.isValid()) {
    state->state = tree;
  }
}

AudioProcessorValueTreeState& DistortionAudioProcessor::getState() {
  return *state;
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
  return new DistortionAudioProcessor();
}
