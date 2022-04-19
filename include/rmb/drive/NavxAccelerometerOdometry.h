// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/SPI.h>
#include <frc/geometry/Pose2d.h>

#include <AHRS.h>

#include <rmb/drive/DriveOdometry.h>

namespace rmb {

/**
 * Odometry manager using the navx gyro board
 */
class NavxAccelerometerOdometry : public DriveOdometry {
public:

  /**
   * Create a NavxAccelerometerOdometry
   * @param port The SPI port that the gyro is on
   * @param initialPosition the position the odometry should start at
   */
  NavxAccelerometerOdometry(frc::SPI::Port port,
                            const frc::Pose2d &initialPosition = frc::Pose2d());

  /**
   * Gets the current pose.
   * @see updatePose()
   * @see resetPose()
   * @return The current position of the robot
   */
  const frc::Pose2d &getPose() const;

  /**
   * Updates the current pose.
   * @see getPose()
   * @see resetPose()
   * @return The updated position
   */
  const frc::Pose2d &updatePose();

  /**
   * Resets the pose.
   * @param pose The pose to reset the the odometry to
   * @see getPose()
   * @see updatePose()
   */
  void resetPose(const frc::Pose2d &pose);

private:
  AHRS accelerometer;
  frc::Pose2d refrence, pose;
};
} // namespace rmb
