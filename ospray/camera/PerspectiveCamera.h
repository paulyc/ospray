// ======================================================================== //
// Copyright 2009-2019 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include "camera/Camera.h"

namespace ospray {

  struct OSPRAY_SDK_INTERFACE PerspectiveCamera : public Camera
  {
    PerspectiveCamera();
    virtual ~PerspectiveCamera() override = default;

    virtual std::string toString() const override;
    virtual void commit() override;
    virtual ProjectedPoint projectPoint(const vec3f &p) const override;

    // Data members //

    float fovy;
    float aspect;
    float apertureRadius;
    float focusDistance;
    bool architectural; // orient image plane to be parallel to 'up' and shift the lens
    vec3f dir_00;
    vec3f dir_du;
    vec3f dir_dv;
    vec2f imgPlaneSize;

    OSPStereoMode stereoMode;
    float interpupillaryDistance; // distance between the two cameras (stereo)
  };

} // namespace ospray
