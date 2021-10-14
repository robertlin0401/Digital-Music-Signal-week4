/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MyAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    MyAudioProcessorEditor(MyAudioProcessor&);
    ~MyAudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MyAudioProcessor& audioProcessor;
    
    juce::Slider levelSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> levelSliderAttachment;

    juce::ComboBox comboBox;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> modeComboBoxAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MyAudioProcessorEditor)
};
