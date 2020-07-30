#pragma once

inline void Insert_BitMap();

inline void Logo_BitMap();
inline void Insert_BitMap()
{
	BMP_MGR->Insert_Texture(TEXT("BackBuffer"), TEXT("../Resources/Image/Stage/BackBuffer.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Mouse"), TEXT("../Resources/Image/UI/Mouse.bmp"));

	BMP_MGR->Insert_Texture(TEXT("GrasslandsStage"), TEXT("../Resources/Image/Stage/grasslands.bmp"));
	Logo_BitMap();
}

inline void Logo_BitMap()
{
	BMP_MGR->Insert_Texture(TEXT("LogoTitle"), TEXT("../Resources/Image/Logo/title.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Play_Button"), TEXT("../Resources/Image/Logo/title_screen_button_Play.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Resume_Button"), TEXT("../Resources/Image/Logo/title_screen_button_Resume.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Help_Button"), TEXT("../Resources/Image/Logo/title_screen_button_Help.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Scores_Button"), TEXT("../Resources/Image/Logo/title_screen_button_Scores.bmp"));
	BMP_MGR->Insert_Texture(TEXT("More_Button"), TEXT("../Resources/Image/Logo/title_screen_button_More.bmp"));
}
