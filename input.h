#include <windows.h>


bool ispressed = 0;
bool pressedonce = 0;


bool keypressed(int key)
{
    if(GetAsyncKeyState(key))
    {
        return true;
    }
    return false;
}

bool keyreleased(int key)
{
    if(GetAsyncKeyState(key))
    {
        ispressed = 1;
    }
    if(!GetAsyncKeyState(key) && ispressed == 1)
    {
        return true;
    }
    return false;
}

bool keypressedonce(int key)
{
    if(GetAsyncKeyState(key) && pressedonce == 0)
    {
        pressedonce = 1;
        return true;
    }
    if(!GetAsyncKeyState(key) && pressedonce == 1)
    {
        pressedonce = 0;
    }
    return false;
}


