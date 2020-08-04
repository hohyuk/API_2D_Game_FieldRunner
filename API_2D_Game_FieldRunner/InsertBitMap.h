#pragma once

inline void Insert_BitMap();

inline void Logo_BitMap();
inline void Help_BitMap();
inline void Select_BitMap();
inline void Stage_BitMap();
inline void Tower_BitMap();
inline void Enemy_BitMap();
inline void UI_BitMap();


inline void Insert_BitMap()
{
	BMP_MGR->Insert_Texture(TEXT("BackBuffer"), TEXT("../Resources/Image/Stage/BackBuffer.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Mouse"), TEXT("../Resources/Image/UI/Mouse.bmp"));
	
	Logo_BitMap();
	Help_BitMap();
	Select_BitMap();
	Stage_BitMap();

	Tower_BitMap();
	Enemy_BitMap();
	UI_BitMap();
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

void Help_BitMap()
{
	BMP_MGR->Insert_Texture(TEXT("Help1"), TEXT("../Resources/Image/Help/help_build_creatively_wide.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Help2"), TEXT("../Resources/Image/Help/help_stop_enemies_wide.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Help3"), TEXT("../Resources/Image/Help/help_upgrade_towers_wide.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Exit"), TEXT("../Resources/Image/Help/button_Exit.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Next"), TEXT("../Resources/Image/Help/button_Next.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Back"), TEXT("../Resources/Image/Help/button_Next.bmp"));
}

inline void Select_BitMap()
{
	BMP_MGR->Insert_Texture(TEXT("SelectTitle"), TEXT("../Resources/Image/Stage/map_selection.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Grasslands_icon"), TEXT("../Resources/Image/Stage/grasslands_icon.bmp"));
	BMP_MGR->Insert_Texture(TEXT("lavaflow_icon"), TEXT("../Resources/Image/Stage/lavaflow_icon.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Map_thumb_grass"), TEXT("../Resources/Image/Stage/map_thumb_grass.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Map_thumb_lavaflow"), TEXT("../Resources/Image/Stage/map_thumb_lavaflow.bmp"));

	BMP_MGR->Insert_Texture(TEXT("Cave_icon"), TEXT("../Resources/Image/Stage/cave_icon.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Map_thumb_Cave"), TEXT("../Resources/Image/Stage/map_thumb_cave.bmp"));
}

inline void Stage_BitMap()
{
	BMP_MGR->Insert_Texture(TEXT("GrasslandsStage"), TEXT("../Resources/Image/Stage/grasslands.bmp"));
	BMP_MGR->Insert_Texture(TEXT("VolcanoStage"), TEXT("../Resources/Image/Stage/volcano.bmp"));
	BMP_MGR->Insert_Texture(TEXT("CaveStage"), TEXT("../Resources/Image/Stage/mines.bmp"));
}

inline void Tower_BitMap()
{
	BMP_MGR->Insert_Texture(TEXT("GatlingTower"), TEXT("../Resources/Image/Tower/GatlingObject.bmp"));
	BMP_MGR->Insert_Texture(TEXT("GooTower"), TEXT("../Resources/Image/Tower/GooObject.bmp"));
	BMP_MGR->Insert_Texture(TEXT("FlameTower"), TEXT("../Resources/Image/Tower/FlameObject.bmp"));
	BMP_MGR->Insert_Texture(TEXT("MortarTower"), TEXT("../Resources/Image/Tower/MortarObject.bmp"));
}

inline void Enemy_BitMap()
{
	BMP_MGR->Insert_Texture(TEXT("Soldier"), TEXT("../Resources/Image/Enemy/Soldier/Soldier.bmp"));
	BMP_MGR->Insert_Texture(TEXT("HeavySoldier"), TEXT("../Resources/Image/Enemy/Soldier/HeavySoldier.bmp"));
	BMP_MGR->Insert_Texture(TEXT("HeavyBike"), TEXT("../Resources/Image/Enemy/Heavy_Bike/heavy_bike.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Blimp"), TEXT("../Resources/Image/Enemy/Blimp/blimp.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Robot"), TEXT("../Resources/Image/Enemy/Robot.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Train"), TEXT("../Resources/Image/Enemy/Train.bmp"));
}

inline void UI_BitMap()
{
	//GameUI
	BMP_MGR->Insert_Texture(TEXT("Start_Stop"), TEXT("../Resources/Image/UI/Start_Stop.bmp"));
	BMP_MGR->Insert_Texture(TEXT("FastForward"), TEXT("../Resources/Image/UI/FastForward.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Option"), TEXT("../Resources/Image/UI/Option.bmp"));


	BMP_MGR->Insert_Texture(TEXT("Money"), TEXT("../Resources/Image/UI/money.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Health"), TEXT("../Resources/Image/UI/hud_health.bmp"));

	BMP_MGR->Insert_Texture(TEXT("Gatling"), TEXT("../Resources/Image/Game_UI/icon_gatling_tower.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Flame"), TEXT("../Resources/Image/Game_UI/icon_flame_tower.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Goo"), TEXT("../Resources/Image/Game_UI/icon_goo_tower.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Mortar"), TEXT("../Resources/Image/Game_UI/icon_mortar_tower.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Upgrade"), TEXT("../Resources/Image/Game_UI/icon_upgrade.bmp"));
	BMP_MGR->Insert_Texture(TEXT("Sell"), TEXT("../Resources/Image/Game_UI/icon_sell.bmp"));
}
