/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PPQComponent.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class YetiFilterAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    YetiFilterAudioProcessorEditor (YetiFilterAudioProcessor&);
    ~YetiFilterAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
	PPQComponent PPQComp;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    YetiFilterAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (YetiFilterAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
