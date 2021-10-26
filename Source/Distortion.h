/*
  ==============================================================================

    Distortion.h
    Created: 20 Apr 2021 7:38:38pm
    Author:  Dan Hirlinger

  ==============================================================================
*/

#pragma once
#include <cmath>

class Distortion{
    Distortion();~Distortion();
public:
    // all distortion functions take in and return a sample, not a buffer
    float thresh = 0.7;
    float drive = 2;
    float alpha = 5.f;
    
    float infiniteClip(float x);
    float fwRect(float x);
    float hwRect(float x);
    float hardClip(float x);
    float softClipCubic(float x);
    float softClipArctan(float x);
    
private:
    
};
