/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
RealGainAudioProcessorEditor::RealGainAudioProcessorEditor (RealGainAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Slider Initialisation

    mSlider.setSliderStyle(juce::Slider::Rotary);
    mSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 70, 30);
    mSlider.setRange(0.0f, 1.0f, 0.1f);
    mSlider.setValue(0.5f);
    mSlider.setDoubleClickReturnValue(true, 0.5f);
    mSlider.addListener(this);
    addAndMakeVisible(mSlider);

    getLookAndFeel().setColour(juce::Slider::thumbColourId, juce::Colour(117, 26, 255));
    getLookAndFeel().setColour(juce::Slider::rotarySliderFillColourId, juce::Colour(163, 102, 255));
    getLookAndFeel().setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour(162, 160, 160));

    // Label Initalisation

    titleLabel.setText("RealGain", juce::dontSendNotification);
    titleLabel.setFont(juce::Font(16.f, juce::Font::bold));
    titleLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(titleLabel);

    setSize (400, 300);
}

RealGainAudioProcessorEditor::~RealGainAudioProcessorEditor()
{
}

//==============================================================================
void RealGainAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void RealGainAudioProcessorEditor::resized()
{
    titleLabel.setBounds(getWidth() / 2, 20, getWidth() - 100, 30);
    mSlider.setBounds(getWidth() / 200, getHeight() / 2 - 100, 400, 200);
}

void RealGainAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
    
    if (slider == &mSlider) {
        audioProcessor.mGain = mSlider.getValue();
    }
}