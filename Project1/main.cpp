#include "simulation.h"
#include <fstream>

//ifstream //read
//ofstream //write
//fstream // read + write


double speed = 7000;

int YSGL_init_Caller()
{
	glEnable(GL_TEXTURE_2D);							// Enable Texture Mapping
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);					// Set The Blending Function For Translucency
	glClearColor(0.5f, 0.5f, 1.0f, 0.0f);				// This Will Clear The Background Color To Black
	glClearDepth(1.0);									// Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS);								// The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glShadeModel(GL_SMOOTH);							// Enables Smooth Color Shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	BuildFont();

	glEnable(GL_COLOR_MATERIAL);
	
	YSGL_init(speed);
	return TRUE;
}


int YSGL_mainGL_Caller()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	myCam.Render();
	YSGL_mainGL();

	return TRUE;
}


int mainCode()
{
	MSG		msg;
	BOOL	done=FALSE;

	if (!CreateGLWindow()) return 0;

	while(!done)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			if (msg.message==WM_QUIT)
			{
				done=TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if ((active && !YSGL_mainGL_Caller()) || keys[VK_ESCAPE])
			{
				done=TRUE;
			}
			else
			{
				SwapBuffers(hDC);
				myCam.camKBfunc(keys);
			}
		}
	}
	KillGLWindow();	
	return (msg.wParam);
}


string args[10];
int argn;


int main(int argc, char* argv[])
{

	//	 #################################### GUI ################################################


	

	//cout << "name = " << "Omran" << " - " << "Alhomsi" << endl ;
	argn = argc;
	for (int i = 0; i < argc; i++){

		args[i] = argv[i];
		cout << "i = " << i << " - " << args[i] << endl ;

	}

	if (args[1] == "/Insert")
	{

		ofstream myfile;
		myfile.open("myfile.txt");

		for (int i = 2; i < argc; i++)
		{

			myfile << args[i] << " - ";
			
			cout << i << " === " << args[i] << endl;

			if (i == 2)
			{
				speed = atof(args[i].c_str());
			}

		}

		myfile.close();

		cout << "___FINSH___" << endl;


	}


//		 #################################### End GUI ############################################


	cout << "Omran Start" << endl;
	return mainCode();

}