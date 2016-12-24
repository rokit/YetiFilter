/*
  ==============================================================================

    PPQComponent.cpp
    Created: 23 Dec 2016 1:30:08am
    Author:  Luke

  ==============================================================================
*/

#include "PPQComponent.h"

PPQComponent::PPQComponent()
{
	ppq = 0;
	setSize(40, 40);
}


PPQComponent::~PPQComponent()
{
}

void PPQComponent::paint(Graphics& g)
{
	g.fillAll(Colours::white);
	g.setColour(Colours::black);
	g.setFont(15.0f);
	g.drawFittedText(String(ppq), getLocalBounds(), Justification::centred, 1);
}

void PPQComponent::resized()
{

}

void PPQComponent::setPPQ(double i)
{
	ppq = i;
	repaint();
}
