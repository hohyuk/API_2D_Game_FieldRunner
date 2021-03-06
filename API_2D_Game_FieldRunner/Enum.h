#pragma once

namespace OBJECT
{
	enum ID { ENEMY, BULLET, PLAYER, EFFECT, OVERHANG, UI, END_ID };
	enum TILE_TYPE { NONE, TOWER_INSTALL, NOT_TOWER_INSTALL, START_POINT, LANDMARK, ARRIVAL_POINT };
	//enum TOWER { GATLING, GOO, FLAME, MORTAR, END_TOWER };
	enum STATE { RIGHT, LEFT, UP, DOWN, DIE_LEFT, DIE_RIGHT, DIE_UP, DIE_DOWN, END_MOTION };
	enum RENDER {
		GROUND_OBJECT_RENDER, BULLET_RENDER, OVERHANG_RENDER, AIR_OBJECT_RENDER,
		EFFECT_RENDER, UI_RENDER, CLICK_TOWER, END_RENDER
	};		// 그려지기 위한 순서
}

namespace UI_TYPE
{
	enum CLASS_ID { LOGO_UI, HELP_UI, TOWER_UI, SELECT_UI, EXIT_UI, OPTION_UI, END_UI };
	enum BUTTON {
		PLAY_BTN, HELP_BTN, SCORE_BTN, EDIT_BTN, NEXT_BTN, BACK_BTN, STAGE1_BTN, STAGE2_BTN, STAGE3_BTN, EXIT_BTN,
		START_BTN, FAST_BTN, GATLING_BTN, GOO_BTN, FLAME_BTN, MORTAR_BTN, END_BTN
	};
}