/** Sets all members of the MotionRequest representation for executing a TargetMode-WalkRequest
 *  (i.e. Walk to a \c target at a \c speed)
 *  @param speed Walking speeds, in percentage.
 *  @param target Walking target, in mm and radians, relative to the robot.
 */
option(WalkToPosition, (const Pose2f&) speed, (const Vector2f&) target)
{
  /** Set the motion request. */
  initial_state(setRequest)
  {
    transition
    {
      if(theMotionInfo.motion == MotionRequest::walk)
        goto requestIsExecuted;
    }
    action
    {
      theMotionRequest.motion = MotionRequest::walk;
      theMotionRequest.walkRequest.mode = WalkRequest::targetMode;
      theMotionRequest.walkRequest.target = Transformation::fieldToRobot(theRobotPose,target);
      theMotionRequest.walkRequest.speed = speed;
      theMotionRequest.walkRequest.kickType = WalkRequest::none;
    }
  }

  /** The motion process has started executing the request. */
  target_state(requestIsExecuted)
  {
    transition
    {
      if(theMotionInfo.motion != MotionRequest::walk)
        goto setRequest;
    }
    action
    {
      theMotionRequest.motion = MotionRequest::walk;
      theMotionRequest.walkRequest.mode = WalkRequest::targetMode;
      theMotionRequest.walkRequest.target = Transformation::fieldToRobot(theRobotPose,target);
      theMotionRequest.walkRequest.speed = speed;
      theMotionRequest.walkRequest.kickType = WalkRequest::none;
    }
  }
}