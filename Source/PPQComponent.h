/*
  ==============================================================================

    PPQComponent.h
    Created: 23 Dec 2016 1:30:08am
    Author:  Luke

  ==============================================================================
*/

#ifndef PPQCOMPONENT_H_INCLUDED
#define PPQCOMPONENT_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"

class PPQComponent : public Component
{
public:
	double ppq;
	int starttime;
	int stoptime;
	float elapsed;

	PPQComponent();
	~PPQComponent();
	void paint(Graphics& g) override;
	void resized() override;
	void setPPQ(double i);

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PPQComponent)
};


#endif  // PPQCOMPONENT_H_INCLUDED
