/*
  ==============================================================================

    Distortion.cpp
    Created: 20 Apr 2021 7:38:38pm
    Author:  Dan Hirlinger

  ==============================================================================
*/

#include "Distortion.h"

Distortion::Distortion(){};
Distortion::~Distortion(){};

float Distortion::infiniteClip(float x){
    if (x > 0){
        x = 1;
    }else{
        x = -1;
    }
    return x;
}

float Distortion::fwRect(float x){
    x = abs(x);
    return x;
}

float Distortion::hwRect(float x){
    if (x <= 0){
        x = 0;
    }
    return x;
}

float Distortion::hardClip(float x){
    x = drive * x;
    if (x > thresh){
        x = thresh;
    }else if (x < (-thresh)){
        x = -thresh;
    }
    return x;
}

float Distortion::softClipCubic(float x){
    x = drive * x;
    float xCubic = (1/3) * pow(x,3.f);
    x = x - xCubic;
    return x;
}

float Distortion::softClipArctan(float x){
    x = (2/M_PI) * atan(alpha*x);
    return x;
}
