option(PlayingState)
{
  initial_state(play)
  {
    transition
    {
        
        if ( theRobotInfo.number == 3)
            goto Keeper;
        else if( theRobotInfo.number == 2)
            goto StrikerMing;
        else if(theRobotInfo.number == 4)
            goto StrikerDong1;
          
    }
    action
    {
      ;
    }
  }



  state(Keeper)
  {
      transition
      {
          ;
      }
      action
      {
          Keeper();
      }
  }


  state(StrikerMing)
  {
      transition
      {
          ;
      }
      action
      {
          StrikerMing();
      }
  }
  
  state(StrikerDong1)
  {
      transition
      {
          ;
      }
      action
      {
          StrikerDong1();
      }
  }
}
