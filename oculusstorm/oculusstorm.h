#ifndef OCULUSSTORM_H_INCLUDED
#define OCULUSSTORM_H_INCLUDED

// A lightweight class to manage the Oculus Rift
// Written by Eugene Hopkinson for VoxelStorm Ltd, 2013-2015

#include <GL/glew.h>
#include <GL/gl.h>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wfloat-conversion"
#include <OVR.h>
#pragma GCC diagnostic pop
#include "vmath.h"

class oculusstorm {
public:
  bool enabled;

  static float constexpr gravity = 9.81f;
  unsigned int viewport_width;
  unsigned int viewport_height;
  float ipd;
  float ipd_half;
  float ild;
  float ild_half;
  float aspectratio;
  float fov;

  GLfloat nearplane;
  GLfloat farplane;

  Matrix4<GLfloat> projection_left;
  Matrix4<GLfloat> projection_right;
  Matrix4<GLfloat> viewadjust_left;
  Matrix4<GLfloat> viewadjust_right;

  OVR::Ptr<OVR::DeviceManager>    manager;
  OVR::Ptr<OVR::HMDDevice>        device;
  OVR::Ptr<OVR::SensorDevice>     sensor;
  OVR::SensorFusion               *sensorfusion;
  OVR::HMDInfo                    hmdinfo;
  bool                            infoloaded;
  OVR::Util::Render::StereoConfig stereoconfig;

  oculusstorm(float farplane, float nearplane = 0.0f);
  ~oculusstorm();

  void dumpinfo();
  Quatf getquat();
  Matrix4f getmatrix();
  Matrix4f convertmatrix(OVR::Matrix4f ovrmatrix);
  void cachematrices();
  void setup_left();
  void setup_right();
};

#endif // OCULUSSTORM_H_INCLUDED
