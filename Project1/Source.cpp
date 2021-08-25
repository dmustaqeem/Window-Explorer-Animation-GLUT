#include <iostream>
#include <GL/glut.h>
#include <cmath>


//Screen Size Variables 
const int width = 1202;
const int height = 650;

//Box Translations 
int bx = 0, by = 0;

//Enum variables used as hierarchy names 
enum Directories {Home, Documents, Videos, Music, Downloads, Back, MyVideos, SavedVideos, DownloadedVideos, BackVid, MyMusic, SavedMusic, BackMusic, RecentDownloads, OldDownloads, BackDwn, WordDocuments, VSDocuments, BackDoc, null};

//Directory Property Struct
struct DirProp {
	enum Directories subDir;
	float xVal;
	float yVal;
	float alpha;
};

//Home Directory Struct
struct Parent 
{
	struct DirProp dp[5];
};
struct Parent p;

//Documents Directory Struct 
struct Documents
{
	struct DirProp dp[5];
};
struct Documents doc;

//Music Directory Struct 
struct Music
{
	struct DirProp dp[5];
};
struct Music music;

//Videos Directory Struct 
struct Videos 
{
	struct DirProp dp[5];
};
struct Videos videos;

//Downloads Directory Struct
struct Downloads
{
	struct DirProp dp[5];
};
struct Downloads downloads;

//Initially Home Directory is selected
Directories selectedDir = Directories::Home;
//Initially None is Clicked
Directories clicked = Directories::null;

//To render names of directories
const int font = (int)GLUT_BITMAP_9_BY_15;
//copied function for text rendering
void renderBitmapString(float x, float y, void* font, const char* string) {
	const char* c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}


//To initialize directory values 
void initDirectories() 
{
	
	p.dp[0].subDir = Directories::Documents;
	//x val
	p.dp[0].xVal = 100;
	//Set y Val
	p.dp[0].yVal = 550;
	//Color Transparency
	p.dp[0].alpha = 0.0;

	
	p.dp[1].subDir = Directories::Music;
	//Set X Val 
	p.dp[1].xVal = 250;
	//Set y Val
	p.dp[1].yVal = 550;
	//Color Transparency
	p.dp[1].alpha = 0.0;

	
	p.dp[2].subDir = Directories::Videos;
	//Set X Val 
	p.dp[2].xVal = 400;
	//Set y Val
	p.dp[2].yVal = 550;
	//Color Transparency
	p.dp[2].alpha = 0.0;

	
	p.dp[3].subDir = Directories::Downloads;
	//Set X Val 
	p.dp[3].xVal = 550;
	//Set y Val
	p.dp[3].yVal = 550;
	//Color Transparency
	p.dp[3].alpha = 0.0;

	
	//Document Directory inside Home Directory 
	
	doc.dp[0].subDir = Directories::BackDoc;
	//Color Transparency
	doc.dp[0].alpha = 0.0;
	//Set x Val
	doc.dp[0].xVal = 100;
	//Set y Val
	doc.dp[0].yVal = 550;

	
	doc.dp[1].subDir = Directories::WordDocuments;
	//Color Transparency
	doc.dp[1].alpha = 0.0;
	//Set X Val
	doc.dp[1].xVal = 250;
	//Set y Val
	doc.dp[1].yVal = 550;

	//To render VS Documents Folder in Document 
	doc.dp[2].subDir = Directories::VSDocuments;
	//Color Transparency
	doc.dp[2].alpha = 0.0;
	//Set x Val
	doc.dp[2].xVal = 400;
	//Set y Val
	doc.dp[2].yVal = 550;


	//Music Directory
	
	music.dp[0].subDir = Directories::BackMusic;
	//Color Transparency
	music.dp[0].alpha = 0.0;
	//Set x Val
	music.dp[0].xVal = 100;
	//Set y Val
	music.dp[0].yVal = 550;
	
	//To render Saved Music Folder in Music 
	music.dp[1].subDir = Directories::SavedMusic;
	//Color Transparency
	music.dp[1].alpha = 0.0;
	//Set x Val
	music.dp[1].xVal = 250;
	//Set y Val
	music.dp[1].yVal = 550;

	//To render MyMusic Folder in Music 
	music.dp[2].subDir = Directories::MyMusic;
	music.dp[2].alpha = 0.0;
	//Set x Val
	music.dp[2].xVal = 400;
	//Set y Val
	music.dp[2].yVal = 550;

	//Videos Folder 
	
	videos.dp[0].subDir = Directories::BackVid;
	//Color Transparency
	videos.dp[0].alpha = 0.0;
	//Set x Val
	videos.dp[0].xVal = 100;
	//Set y Val
	videos.dp[0].yVal = 550;

	
	videos.dp[1].subDir = Directories::DownloadedVideos;
	//Color Transparency
	videos.dp[1].alpha = 0.0;
	//Set x Val
	videos.dp[1].xVal = 250;
	//Set y Val
	videos.dp[1].yVal = 550;

	
	videos.dp[2].subDir = Directories::OldDownloads;
	//Color Transparency
	videos.dp[2].alpha = 0.0;
	//Set x Val
	videos.dp[2].xVal = 400;
	//Set y Val
	videos.dp[2].yVal = 550;

	
	videos.dp[3].subDir = Directories::SavedVideos;
	//Color Transparency
	videos.dp[3].alpha = 0.0;
	//Set x Val
	videos.dp[3].xVal = 550;
	//Set y Val
	videos.dp[3].yVal = 550;
	
	
	
	//Downloads Folder
	
	downloads.dp[0].subDir = Directories::BackDwn;
	//Color Transparency
	downloads.dp[0].alpha = 0.0;
	//Set x Val
	downloads.dp[0].xVal = 100;
	//Set y Val
	downloads.dp[0].yVal = 550;

	
	downloads.dp[1].subDir = Directories::OldDownloads;
	//Color Transparency
	downloads.dp[1].alpha = 0.0;
	//Set x Val
	downloads.dp[1].xVal = 250;
	//Set y Val
	downloads.dp[1].yVal = 550;

	///To render Recent Downloads Folder in Downloads
	downloads.dp[2].subDir = Directories::RecentDownloads;
	//Color Transparency
	downloads.dp[2].alpha = 0.0;
	//Set x Val
	downloads.dp[2].xVal = 400;
	//Set y Val
	downloads.dp[2].yVal = 550;

	

}


//Function to render all sub directories of Home Directory
void homeDisp()
{
	
	//To render Documents Folder in Home 
	glPushMatrix();
	glTranslatef(p.dp[0].xVal, p.dp[0].yVal, 0);
	
	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();
	
	glPushMatrix();
	glColor4f(0, 0, 1, p.dp[0].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(p.dp[0].xVal - 40, p.dp[0].yVal - 40, (void*)font, "Document");
	glPopMatrix();
	
	//Music
	//To render Music Folder in Home 
	glPushMatrix();
	glTranslatef(p.dp[1].xVal, p.dp[1].yVal, 0);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, p.dp[1].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	glPopMatrix();

	//To add Name to folder
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(p.dp[1].xVal - 40, p.dp[1].yVal - 40, (void*)font, "Music");
	glPopMatrix();

	//Videos
	//To render Videos Folder in Home 
	glPushMatrix();
	glTranslatef(p.dp[2].xVal, p.dp[2].yVal, 0);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, p.dp[2].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	glPopMatrix();
	//To add Name to folder
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(p.dp[2].xVal - 40, p.dp[2].yVal - 40, (void*)font, "Videos");
	glPopMatrix();

	//Downloads
	//To render Downloads Folder in Home 
	glPushMatrix();
	glTranslatef(p.dp[3].xVal, p.dp[3].yVal, 0);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, p.dp[3].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	glPopMatrix();
	//To add Name to folder
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(p.dp[3].xVal - 40, p.dp[3].yVal - 40, (void*)font, "Downloads");
	glPopMatrix();

}

//Function to render all sub directories of Documents Directory
void DocumentDisp()
{
	//Back Button 
	//To render Back Folder in Document  
	glPushMatrix();
	glTranslatef(doc.dp[0].xVal, doc.dp[0].yVal, 0);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, doc.dp[0].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	glPopMatrix();
	//To add Name to folder
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(doc.dp[0].xVal - 40, doc.dp[0].yVal - 40, (void*)font, "Back");
	glPopMatrix();

	//Word Documents
	//To render Word Document Folder in Document 
	glPushMatrix();
	glTranslatef(doc.dp[1].xVal, doc.dp[1].yVal, 0);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, doc.dp[1].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	glPopMatrix();
	//To add Name to folder
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(doc.dp[1].xVal - 40, doc.dp[1].yVal - 40, (void*)font, "Word Doc");
	glPopMatrix();


	//VS Documents
	//To render VS Document Folder in Document 
	glPushMatrix();
	glTranslatef(doc.dp[2].xVal, doc.dp[2].yVal, 0);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, doc.dp[2].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	glPopMatrix();
	//To add Name to folder
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(doc.dp[2].xVal - 40, doc.dp[2].yVal - 40, (void*)font, "VS Doc");
	glPopMatrix();

}


void MusicDisp() 
{
	//Back 
	glPushMatrix();
	glTranslatef(music.dp[0].xVal, music.dp[0].yVal, 0);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, music.dp[0].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	glPopMatrix();
	//To add Name to folder
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(music.dp[0].xVal - 40, music.dp[0].yVal - 40, (void*)font, "Back");
	glPopMatrix();

	//To render Playlist Folder in Music  
	glPushMatrix();
	glTranslatef(music.dp[1].xVal, music.dp[1].yVal, 0);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, music.dp[1].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	glPopMatrix();
	//To add Name to folder
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(music.dp[1].xVal - 40, music.dp[1].yVal - 40, (void*)font, "Playlist");
	glPopMatrix();


	//To render Saved Folder in Music  

	glPushMatrix();
	glTranslatef(music.dp[2].xVal, music.dp[2].yVal, 0);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, music.dp[2].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	glPopMatrix();
	//To add Name to folder
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(music.dp[2].xVal - 40, music.dp[2].yVal - 40, (void*)font, "Saved");
	glPopMatrix();
}


void VideoDisp()
{
	//Back
	//To render Back Folder in Videos  
	glPushMatrix();
	glTranslatef(videos.dp[0].xVal, videos.dp[0].yVal, 0);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, videos.dp[0].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	glPopMatrix();
	//To add Name to folder
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(videos.dp[0].xVal - 40, videos.dp[0].yVal - 40, (void*)font, "Back");
	glPopMatrix();

	//Downloaded Videos 
	//To render Downloaded Videos Folder in Videos  
	glPushMatrix();
	glTranslatef(videos.dp[1].xVal, videos.dp[1].yVal, 0);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, videos.dp[1].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	glPopMatrix();
	//To add Name to folder
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(videos.dp[1].xVal - 40, videos.dp[1].yVal - 40, (void*)font, "Download");
	glPopMatrix();


	//Old Videos 
	//To render Old Videos Folder in Videos  
	glPushMatrix();
	glTranslatef(videos.dp[2].xVal, videos.dp[2].yVal, 0);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, videos.dp[2].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	glPopMatrix();
	//To add Name to folder
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(videos.dp[2].xVal - 40, videos.dp[2].yVal - 40, (void*)font, "Old");
	glPopMatrix();

	//Saved Videos 
	//To render Saved Videos Folder in Videos  
	glPushMatrix();
	glTranslatef(videos.dp[3].xVal, videos.dp[3].yVal, 0);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, videos.dp[3].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	glPopMatrix();
	//To add Name to folder
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(videos.dp[3].xVal - 40, videos.dp[3].yVal - 40, (void*)font, "Saved");
	glPopMatrix();
}

void DownloadsDisp()
{
	//Back
	//To render Back Folder in Downloads 
	glPushMatrix();
	glTranslatef(downloads.dp[0].xVal, downloads.dp[0].yVal, 0);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, downloads.dp[0].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	glPopMatrix();
	//To add Name to folder
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(downloads.dp[0].xVal - 40, downloads.dp[0].yVal - 40, (void*)font, "Back");
	glPopMatrix();

	//Old Documents 
	//To render Old Downloads Folder in Downloads 
	glPushMatrix();
	glTranslatef(downloads.dp[1].xVal, downloads.dp[1].yVal, 0);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, downloads.dp[1].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	glPopMatrix();
	//To add Name to folder
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(downloads.dp[1].xVal - 40, downloads.dp[1].yVal - 40, (void*)font, "Old");
	glPopMatrix();


	
	//Recent Documents 
	//To render Recent Downloads Folder in Downloads 
	glPushMatrix();
	glTranslatef(downloads.dp[2].xVal, downloads.dp[2].yVal, 0);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireCube(100.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, downloads.dp[2].alpha);
	glutSolidCube(100.0);
	glPopMatrix();

	glPopMatrix();
	//To add Name to folder
	glPushMatrix();
	glColor3f(0, 0, 0);
	renderBitmapString(downloads.dp[2].xVal - 40, downloads.dp[2].yVal - 40, (void*)font, "Recent");
	glPopMatrix();

}


/*This function is called after the right button of mouse is clicked, xand y of mouse are passed as parametersand is checked if cursor lies in the
* area of folder cube, if so then is checked that is that folder is previously selected or no, if selected then selected directory variable is set
* equal to it else the clicked variable is set equal to it and the alpha value of the folder is changed to 0.5 so it is seen as selected 
*/
void updateClicked()
{
	//go inside the selected directory and find the clicked directory and update alpha value, if already 0.5 then change selected directory
	if (selectedDir == Directories::Home)
	{
		for (int i = 0; i < 4; i++)
		{
			if (clicked != p.dp[i].subDir && p.dp[i].alpha == 0.5) 
			{
				p.dp[i].alpha = 0.0;
			}
			if (clicked == p.dp[i].subDir)
			{
				if (p.dp[i].alpha != 0.5) {
					p.dp[i].alpha = 0.5;
				}
				else
				{
					//if directory is already selected then current directory will be converted to selected one 
					selectedDir = p.dp[i].subDir;
				}
			}
			if (clicked == Directories::null)
			{
				//if clicked at any point other then directories
				p.dp[i].alpha = 0.0;
			}
		}
	}


	else if (selectedDir == Directories::Documents)
	{
		for (int i = 0; i < 4; i++)
		{
			if (clicked != doc.dp[i].subDir && doc.dp[i].alpha == 0.5)
			{
				doc.dp[i].alpha = 0.0;
			}
			if (clicked == doc.dp[i].subDir)
			{
				if (doc.dp[i].alpha != 0.5) {
					doc.dp[i].alpha = 0.5;
				}
				else if(i==0 && doc.dp[i].alpha == 0.5 )
				{
					//If back is already selected then go back to home 
					selectedDir = Directories::Home;
				}
			}
			if (clicked == Directories::null)
			{
				doc.dp[i].alpha = 0.0;
			}
		}
	}

	else if (selectedDir == Directories::Music)
	{
		for (int i = 0; i < 3; i++)
		{
			if (clicked != music.dp[i].subDir && music.dp[i].alpha == 0.5)
			{
				music.dp[i].alpha = 0.0;
			}
			if (clicked == music.dp[i].subDir)
			{
				if (music.dp[i].alpha != 0.5) {
					music.dp[i].alpha = 0.5;
				}
				else if (i == 0 && music.dp[i].alpha == 0.5)
				{
					//If back is already selected then go back to home 
					selectedDir = Directories::Home;
				}
			}
			if (clicked == Directories::null)
			{
				music.dp[i].alpha = 0.0;
			}
		}
	}

	else if (selectedDir == Directories::Videos)
	{
		for (int i = 0; i < 3; i++)
		{
			if (clicked != videos.dp[i].subDir && videos.dp[i].alpha == 0.5)
			{
				videos.dp[i].alpha = 0.0;
			}
			if (clicked == videos.dp[i].subDir)
			{
				if (videos.dp[i].alpha != 0.5) {
					videos.dp[i].alpha = 0.5;
				}
				else if (i == 0 && videos.dp[i].alpha == 0.5)
				{
					//If back is already selected then go back to home 
					selectedDir = Directories::Home;
				}
			}
			if (clicked == Directories::null)
			{
				videos.dp[i].alpha = 0.0;
			}
		}
	}

	else if (selectedDir == Directories::Downloads)
	{
	for (int i = 0; i < 3; i++)
	{
		if (clicked != downloads.dp[i].subDir && downloads.dp[i].alpha == 0.5)
		{
			downloads.dp[i].alpha = 0.0;
		}
		if (clicked == downloads.dp[i].subDir)
		{
			if (downloads.dp[i].alpha != 0.5) {
				downloads.dp[i].alpha = 0.5;
			}
			else if (i == 0 && downloads.dp[i].alpha == 0.5)
			{
				selectedDir = Directories::Home;
			}
		}
		if (clicked == Directories::null)
		{
			downloads.dp[i].alpha = 0.0;
		}
	}
	}
}


/*This function is called after every 50ms to check if user is not preasent in a directory then none of the folders should be selected in there
should have alpha value set to 0*/
void unselectMarked() 
{
	if (selectedDir != Directories::Home)
	{
		for (int i = 0; i < 4; i++)
		{
			p.dp[i].alpha = 0.0;
		}
	}


	else if (selectedDir != Directories::Documents)
	{
		for (int i = 0; i < 4; i++)
		{
			doc.dp[i].alpha = 0.0;
		}
	}

	else if (selectedDir != Directories::Music)
	{
		for (int i = 0; i < 3; i++)
		{
			music.dp[i].alpha = 0.0;
		}
	}

	else if (selectedDir != Directories::Videos)
	{
		for (int i = 0; i < 3; i++)
		{
			videos.dp[i].alpha = 0.0;
		}
	}

	else if (selectedDir != Directories::Downloads)
	{
		for (int i = 0; i < 3; i++)
		{
			downloads.dp[i].alpha = 0.0;
	    }
	}
}

//To get the mouse position if it is inside a block of directory
/*If mouse is preasent inside a directory then clicked value is set equal to that Directory enum value, if user just clicked on anyother point on the 
screen but not the folder then clicked value will be set to Directory::null
Here the cube size is 100 so mouse coordinates are compared with 50 less and 50 addition to the center coordinates of each cube
*/
void mousePosition(int x, int y)
{
	if (selectedDir == Directories::Home)
	{
		if ((x >= p.dp[0].xVal - 50) && (x <= p.dp[0].xVal + 50) && (y >= p.dp[0].yVal - 50) && (y <= p.dp[0].yVal + 50))
		{
			clicked = p.dp[0].subDir;
		}
		else if ((x >= p.dp[1].xVal - 50) && (x <= p.dp[1].xVal + 50) && (y >= p.dp[1].yVal - 50) && (y <= p.dp[1].yVal + 50))
		{
			clicked = p.dp[1].subDir;
		}
		else if ((x >= p.dp[2].xVal - 50) && (x <= p.dp[2].xVal + 50) && (y >= p.dp[2].yVal - 50) && (y <= p.dp[2].yVal + 50))
		{
			clicked = p.dp[2].subDir;
		}
		else if ((x >= p.dp[3].xVal - 50) && (x <= p.dp[3].xVal + 50) && (y >= p.dp[3].yVal - 50) && (y <= p.dp[3].yVal + 50))
		{
			clicked = p.dp[3].subDir;
		}
		else
		{
			clicked = Directories::null;
		}
	}


	if (selectedDir == Directories::Documents)
	{
		if ((x >= doc.dp[0].xVal - 50) && (x <= doc.dp[0].xVal + 50) && (y >= doc.dp[0].yVal - 50) && (y <= doc.dp[0].yVal + 50))
		{
			clicked = doc.dp[0].subDir;
		}
		else if ((x >= doc.dp[1].xVal - 50) && (x <= doc.dp[1].xVal + 50) && (y >= doc.dp[1].yVal - 50) && (y <= doc.dp[1].yVal + 50))
		{
			clicked = doc.dp[1].subDir;
		}
		else if ((x >= doc.dp[2].xVal - 50) && (x <= doc.dp[2].xVal + 50) && (y >= doc.dp[2].yVal - 50) && (y <= doc.dp[2].yVal + 50))
		{
			clicked = doc.dp[2].subDir;
		}
		else
		{
			clicked = Directories::null;
		}
	}

	if (selectedDir == Directories::Music)
	{
		if ((x >= music.dp[0].xVal - 50) && (x <= music.dp[0].xVal + 50) && (y >= music.dp[0].yVal - 50) && (y <= music.dp[0].yVal + 50))
		{
			clicked = music.dp[0].subDir;
		}
		else if ((x >= music.dp[1].xVal - 50) && (x <= music.dp[1].xVal + 50) && (y >= music.dp[1].yVal - 50) && (y <= music.dp[1].yVal + 50))
		{
			clicked = music.dp[1].subDir;
		}
		else if ((x >= music.dp[2].xVal - 50) && (x <= music.dp[2].xVal + 50) && (y >= music.dp[2].yVal - 50) && (y <= music.dp[2].yVal + 50))
		{
			clicked = music.dp[2].subDir;
		}
		else
		{
			clicked = Directories::null;
		}
	}

	if (selectedDir == Directories::Videos)
	{
		if ((x >= videos.dp[0].xVal - 50) && (x <= videos.dp[0].xVal + 50) && (y >= videos.dp[0].yVal - 50) && (y <= videos.dp[0].yVal + 50))
		{
			clicked = videos.dp[0].subDir;
		}
		else if ((x >= videos.dp[1].xVal - 50) && (x <= videos.dp[1].xVal + 50) && (y >= videos.dp[1].yVal - 50) && (y <= videos.dp[1].yVal + 50))
		{
			clicked = videos.dp[1].subDir;
		}
		else if ((x >= videos.dp[2].xVal - 50) && (x <= videos.dp[2].xVal + 50) && (y >= videos.dp[2].yVal - 50) && (y <= videos.dp[2].yVal + 50))
		{
			clicked = videos.dp[2].subDir;
		}
		else if ((x >= videos.dp[3].xVal - 50) && (x <= videos.dp[3].xVal + 50) && (y >= videos.dp[3].yVal - 50) && (y <= videos.dp[3].yVal + 50))
		{
			clicked = videos.dp[3].subDir;
		}
		else
		{
			clicked = Directories::null;
		}
	}

	if (selectedDir == Directories::Downloads)
	{
		if ((x >= downloads.dp[0].xVal - 50) && (x <= downloads.dp[0].xVal + 50) && (y >= downloads.dp[0].yVal - 50) && (y <= downloads.dp[0].yVal + 50))
		{
			clicked = downloads.dp[0].subDir;
		}
		else if ((x >= downloads.dp[1].xVal - 50) && (x <= downloads.dp[1].xVal + 50) && (y >= downloads.dp[1].yVal - 50) && (y <= downloads.dp[1].yVal + 50))
		{
			clicked = downloads.dp[1].subDir;
		}
		else if ((x >= downloads.dp[2].xVal - 50) && (x <= downloads.dp[2].xVal + 50) && (y >= downloads.dp[2].yVal - 50) && (y <= downloads.dp[2].yVal + 50))
		{
			clicked = downloads.dp[2].subDir;
		}
		else
		{
			clicked = Directories::null;
		}
	}
	
	updateClicked();
}




//Each time right button of mouse is pressed then this function callback is activated and it calls the mousePosition function
void cameraHandelingFromMouse(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN) {
			float yy = height - y;
			mousePosition(x, yy);
		}
	}
}





//The Main loop registered this function as the rendering function 
/* The timer function and window reshape function call this function function after every 50ms to keep the frame rate uptodate*/
void disp(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glLoadIdentity();
	glClearColor(0.752941, 0.752941, 0.752941, 0.0);
	gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);

	
	//The function will be called according to the enum value selected in selectedDir
	if (selectedDir == Directories::Home) 
	{
		//To display all the folders from Home directory
		homeDisp();
	}
	else if(selectedDir == Directories::Documents)
	{
		//To display all the folders from Document directory
		DocumentDisp();
	}
	else if (selectedDir == Directories::Music)
	{
		//To display all the folders from Music directory
		MusicDisp();
	}
	else if (selectedDir == Directories::Videos)
	{
		//To display all the folders from Video directory
		VideoDisp();
	}
	else if (selectedDir == Directories::Downloads)
	{
		//To display all the folders from Downloads directory
		DownloadsDisp();
	}
	
	//This callback unselects all the folders from unopnened directories
	unselectMarked();

	glutSwapBuffers();

}

//If screen size changes then it will keep objects intact
void resizableWindow(int w, int h)
{
	if (h == 0) {
		h = 1;
	}
	float ratio = w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	glOrtho(0, width, 0, height, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);
}


//The function calls display function after every 50ms to keep frame rate uptodate
void timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(50, timer, 0);
}




int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glColor3f(0.3f, 0.7f, 0.9f);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	glutCreateWindow("Windows Explorer");
	glutDisplayFunc(disp);
	initDirectories();
	glutMouseFunc(cameraHandelingFromMouse);
	glutReshapeFunc(resizableWindow);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();

	return 1;
}