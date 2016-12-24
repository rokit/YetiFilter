/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/


#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <cmath>


//==============================================================================
YetiFilterAudioProcessor::YetiFilterAudioProcessor()
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
	b01 = 0.99;
	currentBeat = 0;
	nextBeat = 0;
	beatIncrement = 0.25;
}

YetiFilterAudioProcessor::~YetiFilterAudioProcessor()
{
}

//==============================================================================
const String YetiFilterAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool YetiFilterAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool YetiFilterAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double YetiFilterAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int YetiFilterAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int YetiFilterAudioProcessor::getCurrentProgram()
{
    return 0;
}

void YetiFilterAudioProcessor::setCurrentProgram (int index)
{
	index = 1;
}

const String YetiFilterAudioProcessor::getProgramName (int index)
{
	index = 1;
    return String();
}

void YetiFilterAudioProcessor::changeProgramName (int index, const String& newName)
{
	index = 1;
}

//==============================================================================
void YetiFilterAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void YetiFilterAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool YetiFilterAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void YetiFilterAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();
	
	playhead = getPlayHead();
	playhead->getCurrentPosition(playheadInfo);
	currentBeat = playheadInfo.ppqPosition;
	if (currentBeat >= nextBeat)
	{
		// do stuff
		nextBeat += beatIncrement;
	}

	for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
	{
		buffer.clear(i, 0, buffer.getNumSamples());
	}

	int numSamples = buffer.getNumSamples();
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer(channel);

		for (int i = 0; i < numSamples; i++)
		{
			filter.setCutoff(b01);
			channelData[i] = filter.process(channelData[i]);
		}
    }
}

//==============================================================================
bool YetiFilterAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* YetiFilterAudioProcessor::createEditor()
{
	return new YetiFilterAudioProcessorEditor(*this);
}

//==============================================================================
void YetiFilterAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void YetiFilterAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new YetiFilterAudioProcessor();
}
