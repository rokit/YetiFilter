/*
  ==============================================================================

    Filter.cpp
    Created: 23 Dec 2016 11:29:25pm
    Author:  Luke

  ==============================================================================
*/

#include "Filter.h"

Filter::Filter()
{
	MAX_CUTOFF = 0.99;
	MIN_CUTOFF = 0.01;
	resonance = 0.0;
	mode = FilterMode::FILTER_MODE_LOWPASS;
	buf0 = 0.0;
	buf1 = 0.0;
	cutoff = MAX_CUTOFF;

	for (int i = 0; i < 8; i++)
	{
		CutoffArray[i] = MAX_CUTOFF;
	}

	//calculateFeedbackAmount();
}

double Filter::process(double inputValue)
{
	//buf0 += cutoff * (inputValue - buf0 + feedbackAmount * (buf0 - buf1));
	buf0 += cutoff * (inputValue - buf0);
	buf1 += cutoff * (buf0 - buf1);

	switch (mode)
	{
	case FILTER_MODE_LOWPASS:
		return buf1;
	case FILTER_MODE_HIGHPASS:
		return inputValue - buf0;
	case FILTER_MODE_BANDPASS:
		return buf0 - buf1;
	default:
		return 0.0;
	}
}

//void Filter::calculateFeedbackAmount()
//{
//	feedbackAmount = resonance + resonance / (1.0 - cutoff);
//}
//
//double Filter::GetCutoff()
//{
//	return cutoff;
//}
//
void Filter::setCutoff(double newCutoff)
{
	cutoff = newCutoff;
	//calculateFeedbackAmount();
}
//
//double Filter::GetMaxCutoff()
//{
//	return MAX_CUTOFF;
//}
//
//double Filter::GetMinCutoff()
//{
//	return MIN_CUTOFF;
//}
//
//void Filter::setResonance(double newResonance)
//{
//	resonance = newResonance;
//	if (resonance > 0.900)
//	{
//		resonance = 0.9;
//	}
//	if (resonance < 0.001)
//	{
//		resonance = 0.001;
//	}
//	calculateFeedbackAmount();
//}
//
//void Filter::setFilterMode(FilterMode newMode)
//{
//	mode = newMode;
//}
//
//void Filter::SetCutoffArrayElement(int element, double value)
//{
//	switch (element)
//	{
//	case dmFilterCutoff1:
//		CutoffArray[0] = value; break;
//	case dmFilterCutoff2:
//		CutoffArray[1] = value; break;
//	case dmFilterCutoff3:
//		CutoffArray[2] = value; break;
//	case dmFilterCutoff4:
//		CutoffArray[3] = value; break;
//	case dmFilterCutoff5:
//		CutoffArray[4] = value; break;
//	case dmFilterCutoff6:
//		CutoffArray[5] = value; break;
//	case dmFilterCutoff7:
//		CutoffArray[6] = value; break;
//	case dmFilterCutoff8:
//		CutoffArray[7] = value; break;
//	}
//}
//
//double Filter::GetCutoffArrayElement(int element)
//{
//	return CutoffArray[element];
//}
