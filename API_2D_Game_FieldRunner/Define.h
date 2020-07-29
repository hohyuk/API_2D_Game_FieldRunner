#pragma once

/* Message Box*/
#define MESSAGE_BOX(access, title)		MessageBox(nullptr, access, title, MB_OK)


/*Singleton °´Ã¼¸¦ Define*/
#define BMP_MGR		BmpManager::Get_Instance()

#define SCENE_MGR	SceneManager::Get_Instance()

#define OBJ_MGR		ObjectManager::Get_Instance()