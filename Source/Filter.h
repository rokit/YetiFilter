/*
  ==============================================================================

    Filter.h
    Created: 23 Dec 2016 11:29:25pm
    Author:  Luke

  ==============================================================================
*/

#ifndef FILTER_H_INCLUDED
#define FILTER_H_INCLUDED


enum EParams2
{
	dkGain = 0,
	dkTempoSync,
	dmFilterMode,
	dmFilterCutoff,
	dmFilterResonance,
	dmFilterCutoff1,
	dmFilterCutoff2,
	dmFilterCutoff3,
	dmFilterCutoff4,
	dmFilterCutoff5,
	dmFilterCutoff6,
	dmFilterCutoff7,
	dmFilterCutoff8,
	dkNumParams
};

class Filter
{
public:

	enum FilterMode
	{
		FILTER_MODE_LOWPASS = 0,
		FILTER_MODE_HIGHPASS,
		FILTER_MODE_BANDPASS,
		kNumFilterModes
	};

	Filter();
	double process(double inputValue);
	void setCutoff(double newCutoff);
	//void setResonance(double newResonance);
	//void setFilterMode(FilterMode newMode);
	//double GetCutoff();
	//double GetMaxCutoff();
	//double GetMinCutoff();
	//void SetCutoffArrayElement(int element, double value);
	//double GetCutoffArrayElement(int element);

private:
	double CutoffArray[8];
	double cutoff;
	double MAX_CUTOFF;
	double MIN_CUTOFF;
	double resonance;
	FilterMode mode;
	double feedbackAmount;
	double buf0;
	double buf1;

	//void calculateFeedbackAmount();
};


#endif  // FILTER_H_INCLUDED
