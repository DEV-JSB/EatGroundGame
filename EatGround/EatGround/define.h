#pragma once


	
#define PIE 3.141592
#define DEGREE_TO_RADIN(angle) angle * (float)(PIE/180.0)
#define RADIAN_TO_DEGREE(rad) rad * (float)(180.0 / PIE)

#define GET_DT (float)CTimeMgr::GetInstance()->GetDT()

#define NOCOPPY(classtype)  private:\
							classtype(const classtype& obj);\
							classtype* operator = (classtype* obj)\
							{return nullptr;}


#define SINGLE(classtype) NOCOPPY(classtype);\
						  public:\
						  static classtype* GetInstance(){\
								static classtype mgr;\
								return &mgr;\
						 }\
						 private:\
							classtype();\
							~classtype()
enum class COLLISION_TYPE
{
	COLLISION_TYPE_BOX2D,
	COLLISION_TYPE_CIRCLE2D,
	COLLISION_TYPE_END
};
enum class EVENT
{
	EVENT_DRAWAREA,
	EVENT_END
};
enum class OBJECT_TYPE
{
	OBJECT_TYPE_MISSILE,
	OBJECT_TYPE_BRICK,
	OBJECT_TYPE_ENEMY,
	OBJECT_TYPE_PLAYER,
	OBJECT_TYPE_END
};

enum class COMPONENT
{
	COMPONENT_TRANSFORM2D,
	COMPONENT_COLLIDER,
	COMPONENT_END
};