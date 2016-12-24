/*
  ==============================================================================

    PPQComponent.cpp
    Created: 23 Dec 2016 1:30:08am
    Author:  Luke

  ==============================================================================
*/

#include "PPQComponent.h"
#include <ctime>
#include <cmath>

PPQComponent::PPQComponent()
{
	ppq = 0;
	elapsed = 0.f;
	setSize(400, 300);
	starttime = clock();
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
	g.drawFittedText(String(elapsed), getLocalBounds(), Justification::bottom, 1);
}

void PPQComponent::resized()
{

}

void PPQComponent::setPPQ(double i)
{
	//stoptime = clock();
	//elapsed = (stoptime - starttime) / (double)CLOCKS_PER_SEC;
	//if (elapsed > 0.25f)
	//{
	//	starttime = clock();
	//	elapsed = 0.f;
		ppq = i;
		
		repaint();
	//}
}
