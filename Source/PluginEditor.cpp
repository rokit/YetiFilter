/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
YetiFilterAudioProcessorEditor::YetiFilterAudioProcessorEditor (YetiFilterAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

	addAndMakeVisible(PPQComp);
    setSize (400, 300);
}

YetiFilterAudioProcessorEditor::~YetiFilterAudioProcessorEditor()
{
}

//==============================================================================
void YetiFilterAudioProcessorEditor::paint (Graphics& g)
{
	PPQComp.setPPQ(processor.playheadInfo.ppqPosition);
	//ppq = processor.playheadInfo.ppqPosition;
    //g.fillAll (Colours::white);
    //g.setColour (Colours::black);
    //g.setFont (15.0f);
    //g.drawFittedText (String(ppq), getLocalBounds(), Justification::centred, 1);
}

void YetiFilterAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
