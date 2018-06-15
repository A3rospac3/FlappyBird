#pragma once

namespace Sonar
{
    class State
    {
      public:
        virtual void Init() = 0;
        
        virtual void HandleInout() = 0;
        virtual void Update(float dt) = 0;
        virtual void Draw(float dt) = 0; //dt account for frame rate variation on different devices

        virtual void Pause()
        {

        }

        virtual void Resume() 
        {
          
        }
    };
}