#define _UNICODE
#include <windows.h>
#include <iostream>
#include "input.h"
#include <iostream>
#include <string>

int width = 160;
int height = 80;
int xshift = 0;
int yshift = 0;
wchar_t *screendata = new wchar_t[width*height];

bool h = true;
/*void save()
{
    FILE *file;
    if(file = fopen("file.txt", "w+"))
    {

        for(int h = 0; h < height; h++)
        {
            for(int w = 0; w < width; w++)
            {

                    fputc(char(screendata[w + h * 160]), file);


            }
            fputs("\n", file);
        }

    }else
    {

    }
}*/

/*void load(HANDLE hconsole)
{
    DWORD dw = 0;
    WORD cw = 15;
    for(int i = 0; i < width*height; i++)
    {
        if(screendata[i] != 'x')
        {
           screendata[i] = 'x';
        }


    }
    for(int h = 0; h < height; h++)
    {
        for(int w = 4; w < width; w++)
        {
            WriteConsoleOutputAttribute(hconsole, &cw, 1, {w, h}, &dw);
        }
    }




    FILE *file;
    int h = 0;
    if(file = fopen("file.txt", "r"))
    {
        for(int h = 0; h < height; h++)
        {
            WORD color;
            for(int w = 0; w <=  width; w++)
            {
               screendata[w*h] = fgetc(file);
               switch (screendata[w*h])
               {
                   case 'i':
                   {
                       color = 0;
                       WriteConsoleOutputAttribute(hconsole, &color, 1, {w, h}, &dw);
                       break;
                   }
                   case 'j':
                   {
                       color = 1;
                       WriteConsoleOutputAttribute(hconsole, &color, 1, {w, h}, &dw);
                       break;
                   }
                   case 'k':
                   {
                       color = 2;
                       WriteConsoleOutputAttribute(hconsole, &color, 1, {w, h}, &dw);
                       break;
                   }
                   case 'l':
                   {
                       color = 3;
                       WriteConsoleOutputAttribute(hconsole, &color, 1, {w, h}, &dw);
                       break;
                   }
                   case 'm':
                   {
                       color = 4;
                       WriteConsoleOutputAttribute(hconsole, &color, 1, {w, h}, &dw);
                       break;
                   }
                   case 'n':
                   {
                       color = 5;
                       WriteConsoleOutputAttribute(hconsole, &color, 1, {w, h}, &dw);
                       break;
                   }
                   case 'o':
                   {
                       color = 6;
                       WriteConsoleOutputAttribute(hconsole, &color, 1, {w, h}, &dw);
                       break;
                   }
                   case 'p':
                   {
                       color = 7;
                       WriteConsoleOutputAttribute(hconsole, &color, 1, {w, h}, &dw);
                       break;
                   }
                   case 'q':
                   {
                       color = 8;
                       WriteConsoleOutputAttribute(hconsole, &color, 1, {w, h}, &dw);
                       break;
                   }
                   case 'r':
                   {
                       color = 9;
                       WriteConsoleOutputAttribute(hconsole, &color, 1, {w, h}, &dw);
                       break;
                   }
                   case 's':
                   {
                       color = 10;
                       WriteConsoleOutputAttribute(hconsole, &color, 1, {w, h}, &dw);
                       break;
                   }
                   case 't':
                   {
                       color = 11;
                       WriteConsoleOutputAttribute(hconsole, &color, 1, {w, h}, &dw);
                       break;
                   }
                   case 'u':
                   {
                       color = 12;
                       WriteConsoleOutputAttribute(hconsole, &color, 1, {w, h}, &dw);
                       break;
                   }
                   case 'v':
                   {
                       color = 13;
                       WriteConsoleOutputAttribute(hconsole, &color, 1, {w, h}, &dw);
                       break;
                   }
                   case 'w':
                   {
                       color = 14;
                       WriteConsoleOutputAttribute(hconsole, &color, 1, {w, h}, &dw);
                       break;
                   }

               }

            }
        }


        fclose(file);
    }else
    {

    }
}*/
int main()
{

    wchar_t *screen = new wchar_t[width*height];
    HANDLE hconsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hconsole);
    DWORD dwBytesWritten = 0;

        WORD Defaultcolor = 15;
    WORD Color[17] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 , 11, 12, 13, 14, 15, 16};
    for(int w = 0; w < height; w++)
    {
        for(int i = 0; i < width; i++) WriteConsoleOutputAttribute(hconsole, &Defaultcolor, 1, { i, w }, &dwBytesWritten);
    }
COORD mousepos;
    HANDLE hconsolein = GetStdHandle(STD_INPUT_HANDLE);
   SetConsoleMode(hconsolein, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
//   CONSOLE_FONT_INFOEX info = {0};
  //  info.cbSize       = sizeof(info);
    //info.dwFontSize.Y = 0; // leave X as zero
    //info.FontWeight   = FW_NORMAL;
    //wcscpy(info.FaceName, L"Lucida Console");
    //SetCurrentConsoleFontEx(hconsole);
    int current = 0;

    short shade = 0x2588;
    for(int i = 0; i < 3; i++)
    {
        for(int h = 0; h < 3; h++)
        {
            WriteConsoleOutputAttribute(hconsole, &Color[0], 1, { i , h }, &dwBytesWritten);
    WriteConsoleOutputAttribute(hconsole, &Color[1], 1, { i , h + 3 }, &dwBytesWritten);
    WriteConsoleOutputAttribute(hconsole, &Color[2], 1, { i , h + 6 }, &dwBytesWritten);
    WriteConsoleOutputAttribute(hconsole, &Color[3], 1, { i , h + 9 }, &dwBytesWritten);
    WriteConsoleOutputAttribute(hconsole, &Color[4], 1, { i , h + 12}, &dwBytesWritten);
    WriteConsoleOutputAttribute(hconsole, &Color[5], 1, { i , h + 15}, &dwBytesWritten);
    WriteConsoleOutputAttribute(hconsole, &Color[6], 1, { i , h + 18}, &dwBytesWritten);
    WriteConsoleOutputAttribute(hconsole, &Color[7], 1, { i , h + 21}, &dwBytesWritten);
    WriteConsoleOutputAttribute(hconsole, &Color[8], 1, { i , h + 24}, &dwBytesWritten);
    WriteConsoleOutputAttribute(hconsole, &Color[9], 1, { i , h + 27}, &dwBytesWritten);
    WriteConsoleOutputAttribute(hconsole, &Color[10], 1, { i , h + 30}, &dwBytesWritten);
    WriteConsoleOutputAttribute(hconsole, &Color[11], 1, { i , h + 33}, &dwBytesWritten);
    WriteConsoleOutputAttribute(hconsole, &Color[12], 1, { i , h + 36}, &dwBytesWritten);
    WriteConsoleOutputAttribute(hconsole, &Color[13], 1, { i , h + 39}, &dwBytesWritten);
    WriteConsoleOutputAttribute(hconsole, &Color[14], 1, { i , h + 42}, &dwBytesWritten);
    WriteConsoleOutputAttribute(hconsole, &Color[15], 1, { i , h + 45}, &dwBytesWritten);
    WriteConsoleOutputAttribute(hconsole, &Color[16], 1, { i , h + 48}, &dwBytesWritten);
        }

    }

    for(int i = 0; i < height; i++) WriteConsoleOutputAttribute(hconsole, &Color[0], 1, { 3 , i }, &dwBytesWritten);
    for(int i = 0; i < width*height; i++)
        {
             screen[i] = shade;
             screendata[i] = 120;
        }

    while(1)
    {

                INPUT_RECORD inBuf[32];
				DWORD events = 0;
				GetNumberOfConsoleInputEvents(hconsolein, &events);
				if (events > 0)
					ReadConsoleInput(hconsolein, inBuf, events, &events);
				for (DWORD i = 0; i < events; i++)
				{
					switch (inBuf[i].EventType)
					{



					case MOUSE_EVENT:
					{
						switch (inBuf[i].Event.MouseEvent.dwEventFlags)
						{
						case MOUSE_MOVED:
						{
							mousepos.X = inBuf[i].Event.MouseEvent.dwMousePosition.X;
							mousepos.Y = inBuf[i].Event.MouseEvent.dwMousePosition.Y;
						}
						break;
						}
					}
					}

				}



        if(GetAsyncKeyState(1))
        {
            if(mousepos.X > 3)
        {
            {
                if(!GetAsyncKeyState(VK_SHIFT) && !keypressed(VK_CONTROL))
                {
                    WriteConsoleOutputAttribute(hconsole, &Color[current], 1, mousepos, &dwBytesWritten);
                    screendata[mousepos.X - 1 + (mousepos.Y * 160) + 1] = current + 105;
                    if(current == Defaultcolor)
                    {
                        screendata[mousepos.X - 1 + (yshift * 160) + 1] = 'x';
                    }
                }
            }


        }else if(mousepos.X < 3 && !keypressed(VK_CONTROL) && !keypressed(VK_SHIFT))
        {
            switch(mousepos.Y)
        {
        case 0: case 1: case 2:
            {
                current = 0;
                break;
            }
        case 3: case 4:case 5:
            {
            current = 1;
                break;
            }
        case 6 :case 7 :case 8:
            {
                current = 2;
                break;
            }
        case 9 :case 10 :case 11:
            {
                current = 3;
                break;
            }
            case 12 :case 13 :case 14:
            {
                current = 4;
                break;
            }
        case 15 :case 16 :case 17:
            {
                current = 5;
                break;
            }
        case 18 :case 19 :case 20:
            {
                current = 6;
                break;
            }
        case 21 :case 22 :case 23:
            {
                current = 7;
                break;
            }
             case 24 :case 25 :case 26:
            {
                current = 8;
                break;
            }
             case 27 :case 28 :case 29:
            {
                current = 9;
                break;
            }
             case 30 :case 31 :case 32:
            {
                current = 10;
                break;
            }
            case 33 :case 34 :case 35:
            {
                current = 11;
                break;
            }
            case 36 :case 37 :case 38:
            {
                current = 12;
                break;
            }
            case 39 :case 40 :case 41:
            {
                current = 13;
                break;
            }
             case 42 :case 43 :case 44:
            {
                current = 14;
                break;
            }
             case 45 : case 46 :case 47:
            {
                current = 15;
                break;
            }
             case 48 : case 49 :case 50:
            {
                current = 16;
                break;
            }
            case 51 :case 52 :case 53:
            {
                current = 17;
                break;
            }
        }
        }
        }
        if(GetAsyncKeyState(2) && mousepos.X > 3)
        {
            WriteConsoleOutputAttribute(hconsole, &Defaultcolor, 1, mousepos, &dwBytesWritten);
            screendata[mousepos.X - 1 + (mousepos.Y * 160) + 1] = shade;
        }
        if(mousepos.X > 3)
        {
            if(GetAsyncKeyState(VK_SHIFT))
        {
            if(xshift == 0)
            {
                xshift = mousepos.X;
            }
            if(keypressed(1))
            {
             WriteConsoleOutputAttribute(hconsole, &Color[current], 1, { short(xshift), mousepos.Y}, &dwBytesWritten);
             screendata[xshift - 1 + (mousepos.Y * 160) + 1] = current + 105;
             if(current == Defaultcolor)
             {
                screendata[mousepos.X - 1 + (yshift * 160) + 1] = 'x';
             }
            }
        }

        if(GetAsyncKeyState(VK_CONTROL))
        {
            if(yshift == 0)
            {
                yshift = mousepos.Y;
            }
            if(keypressed(1))
            {
             WriteConsoleOutputAttribute(hconsole, &Color[current], 1, { mousepos.X, short(yshift)}, &dwBytesWritten);
             screendata[mousepos.X - 1 + (yshift * 160) + 1] = current + 105;
             if(current == Defaultcolor)
             {
                screendata[mousepos.X - 1 + (yshift * 160) + 1] = shade;
             }
            }
        }
        }

        if(keyreleased(VK_SHIFT))
        {
            xshift = 0;
        }
        if(keyreleased(VK_CONTROL))
        {
            yshift = 0;
        }
        if(keypressed('S') & 0x41)
        {
           // save();
        }
        if(keypressed('L') & 0x41)
        {
            //load(hconsole);
        }
        if(keyreleased('b') & 0x41)
        {
            for(int w = 3; w < width; w++)
            {
                for(int h = 0; h < height; h++)
                {
                    WriteConsoleOutputAttribute(hconsole, &Color[current], 1, { w, h}, &dwBytesWritten);
                }
            }
        }


        WriteConsoleOutputCharacter(hconsole, screen, width*height, { 0 , 0 }, &dwBytesWritten);
    }






    return 0;
}

