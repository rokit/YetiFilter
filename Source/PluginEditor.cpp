/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include <cmath>
#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
YetiFilterAudioProcessorEditor::YetiFilterAudioProcessorEditor (YetiFilterAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
	b1.setSliderStyle(Slider::LinearBarVertical);
	b1.setRange(0.01, 0.99, 0.001);
	b1.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
	b1.setPopupDisplayEnabled(true, this);
	//b1.setTextValueSuffix("0");
	b1.setValue(0.99);
	b1.setColour(Slider::ColourIds::thumbColourId, Colour(0xdd339966));
	b1.addListener(this);
	
	addAndMakeVisible(&PPQComp);
	addAndMakeVisible(&b1);
    setSize(400, 300);

	startTimer(16.666666666667);
}

YetiFilterAudioProcessorEditor::~YetiFilterAudioProcessorEditor()
{
}

//==============================================================================
void YetiFilterAudioProcessorEditor::paint (Graphics& g)
{
	//ppq = processor.playheadInfo.ppqPosition;
    g.fillAll (Colours::white);
    g.setColour (Colours::black);
    //g.setFont (15.0f);
    //g.drawFittedText (String(ppq), getLocalBounds(), Justification::centred, 1);
}

void YetiFilterAudioProcessorEditor::resized()
{
	// x, y, width, height
	b1.setBounds(40, 40, 40, getHeight() - 80);
	//PPQComp.setPPQ(processor.playheadInfo.ppqPosition);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void YetiFilterAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
	if (slider == &b1) {
		//processor.filter.SetCutoffArrayElement(0, b1.getValue());
		processor.b01 = b1.getValue();
	}
		
}
void YetiFilterAudioProcessorEditor::timerCallback()
{
	PPQComp.setPPQ(int(processor.playheadInfo.ppqPosition));
}
