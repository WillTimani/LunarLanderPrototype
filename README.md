# LunarLander

//TEMPORARY
> Objects:
      Game (Create on StartUp [in main()])
        -Constructor/Destructor
        -Play()
        -Pause()
        -Settings()
          + Play, Pause, Settings each start a new state
          + If in play() and pause() is taken, save the play() state
      LunarLander (Create on myGame.start())
        -RotateRight (keyIsPressedDown('d')
        -RotateLeft (keyIsPressedDown('a')
        -Accelerate (tkeyIsPressedDown('space')
      Terrain (yes this I think should be an object)
        -Populate terrain on myGame.play()
 
//END TEMPORARY
