/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class ConvolverAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    ConvolverAudioProcessorEditor (ConvolverAudioProcessor&);
    ~ConvolverAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void loadIR();

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ConvolverAudioProcessor& processor;
    TextButton loadIRButton;
    Label pathToIRLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ConvolverAudioProcessorEditor)
};
