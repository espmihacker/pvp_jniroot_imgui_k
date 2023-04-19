#ifndef MY_LICCSU_UI
#define MY_LICCSU_UI
/*
char *VH_name(unsigned int id)
{
	static char name[10];
	memset(name, '\0', sizeof(name));
	if (id == 1077936128)
		strcpy(name,"小轿车");
	else if (id == 50790656)
		strcpy(name,"小轿车");
	else if (id == 1069547520)
		strcpy(name, "蹦蹦");
	else if (id == 118227200)
		strcpy(name, "蹦蹦");
	else if (id == 102367488)
		strcpy(name, "沙地吉普");
	else if (id == 321978624)
		strcpy(name, "三轮车");
	else if (id == 1077936128)
		strcpy(name, "大船");
	else if (id == 1030291712)
		strcpy(name, "敞篷跑车");
	else if (id == 68223232)
		strcpy(name,"大巴士");
	else if (id == 168493312)
		strcpy(name,"敞篷越野车");
	else if (id == 895942912)
		strcpy(name,"越野车");
	else if (id == 134807808)
		strcpy(name,"吉普车");
	else if (id == 271188224)
		strcpy(name,"大卡车");
	else if (id == 1065353216)
		strcpy(name,"三轮车");
	else if (id == 309264640)
		strcpy(name,"雪地三轮车");
	else if (id == 342819072)
		strcpy(name,"雪地摩托车");
	else if (id == 16908544)
		strcpy(name,"摩托车");
	else if (id == 1065353216)
		strcpy(name,"摩托车");
	else if (id == 288162048)
		strcpy(name,"小绵羊");
	else if (id == 202375424)
		strcpy(name,"小船");
	else if (id == 1010434304)
		strcpy(name,"滑翔机");
	else if (id == 405799168)
		strcpy(name,"装甲车");
	else if (id == 33751296)
		strcpy(name,"三轮车");
	else if (id == 50725120)
		strcpy(name,"小轿车");
	else if (id == 1082130432)
		strcpy(name,"吉普");
	return name;
}

char *WZ_name(unsigned int id)
{
	static char name[10];
	memset(name, '\0', sizeof(name));
	if (id == 1249988608)
		strcpy(name, "喷子");
	else if (id ==1065353216)
		strcpy(name, "AK");
	else if (id == 1331073956)
		strcpy(name, "3");
	return name;
}
*/

struct Config {
	static float 选项,圆角;
	struct 功能 {
	    bool 地图;
        bool 实体;
	    bool 射线;
	    bool 兵线;
	    bool 野怪;
	    bool 技能;
	    
	    struct 计时 {
	        bool 小怪;
	        bool BUFF;
            bool 龙坑;
	
	        bool 主动;
	        bool 恢复;
	        bool 召唤;
	        bool 大招;
	        bool 一技能;
	        bool 二技能;
        	bool 三技能;
	
	        bool 主动2;
	        bool 恢复2;
	        bool 召唤2;
	        bool 大招2;
	        bool 一技能2;
	        bool 二技能2;
	        bool 三技能2;
        } 计时;
        
	} 功能;
	
	struct 设置 {
	    int 地图上下,地图左右,实体上下,实体左右;
        int 分辨率X;
	    int 分辨率Y;
	    int 阵营;
	} 设置;
	
	struct 开关 {
	    bool 总开关;
	} 开关;
	
} 玖;





#endif
//bool gn1, gn2,hp,wh,cm,gm;

