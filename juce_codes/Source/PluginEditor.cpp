/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ConvolverAudioProcessorEditor::ConvolverAudioProcessorEditor (ConvolverAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // path to IR label
    pathToIRLabel.setText ("", dontSendNotification);
    pathToIRLabel.setJustificationType (Justification::centred);
    pathToIRLabel.setColour (Label::backgroundColourId, Colours::lightslategrey);
    addAndMakeVisible (pathToIRLabel);
    
    // button
    loadIRButton.setButtonText ("Load IR");
    loadIRButton.onClick = [this]() {loadIR();};
    addAndMakeVisible (loadIRButton);
    
    setSize (300, 300);
}

ConvolverAudioProcessorEditor::~ConvolverAudioProcessorEditor()
{
}

//==============================================================================
void ConvolverAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void ConvolverAudioProcessorEditor::resized()
{
    auto area = getLocalBounds();
    auto border = 4;

    auto buttonHeight = 30;
    auto LabelHeight = 80;
    
    loadIRButton.setBounds (area.removeFromTop (buttonHeight).reduced (border));
    pathToIRLabel.setBounds (area.removeFromTop (LabelHeight).reduced (border));
}


void ConvolverAudioProcessorEditor::loadIR()
{
    FileChooser chooser ("Select a Wave file to play...",
                             {},
                             "*.wav");
    
    if (chooser.browseForFileToOpen())
    {
        auto file = chooser.getResult();
        const juce::String pathToIR = file.getFullPathName();

        pathToIRLabel.setText (pathToIR, dontSendNotification);
        processor.setIR(pathToIR.toStdString());
    }
}
