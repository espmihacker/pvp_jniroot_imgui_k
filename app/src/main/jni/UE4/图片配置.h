/*
long Mesh, Human, Bone;
float aimScope = 555,RadarX=320,RadarY=255,lineWidth=2.5,bonesWidth=2.5,boneWidth=2.5;
float length, BonesColor, X, Y, W, TOP, Distance, Health, Health1, BOTTOM, MIDDLE,angle,Fuel;
// jstring转换char*
Vector2 Head,Chest,Pelvis,Left_Shoulder,Right_Shoulder,Left_Elbow,Right_Elbow,Left_Wrist,Right_Wrist,Left_Thigh,Right_Thigh,Left_Knee,Right_Knee,Left_Ankle,Right_Ankle;
Vector3 relLocation,relLocation1,LrelLocation1,relLocation2,relLocation3,relLocation4,relLocation5,relLocation6,relLocation7,LrelLocation2,LrelLocation3,LrelLocation4,LrelLocation5,LrelLocation6,LrelLocation7;
int lineType=1,boxType=1,aimType=1,lockingPos=6,nmb=1;
ImColor 方框画笔,背敌颜色,射线颜色,血量颜色,掩体颜色;
uintptr_t lockBase = 0;
bool isFiring,isAds;
uintptr_t zmAddr;
char mz[32];
float tempDistance;
int plearzr,plearbot,hero;
char extra[32];
char status[100];
int playerCount;
int aimingRange = 350;          // 自瞄范围
float aimbotRange = 200.0f;
float bottom,bottom1;
uintptr_t 世界,数组,数量,自身控制器,自身结构体,敌人指针,名字,矩阵,对象,LockObj, yawPitch, POV,WeaponCamera,address,人物控制器,开火,开镜,自身角度,人物视角,矩阵1,g_lineOfSightTo,准心指针,准心x,准心y;
float 距离,血量,倒地血量;
int 队伍,人机判断,动作;
bool 漏打追踪,自动开火,变态全开,自瞄,防抖,射速,特效,无后,聚点,倒地,除雾,瞬机,加速,范围,功能,选项,ftcd,ftkq,ftgb,zzx,bt1,bt2,bt3,bt4,bt5,bt6,变态,AnimationKick,DeviationFactor,RecoilKickADS,BulletFireSpeed,aimMirror,aimTrack,showBox,showLine,showBones,showHealth,showinFormationn,showVehicle,show556,show762,showRifle,showSubmachine,showSniper,showMirror,showExpansion,showOtherParts,showDrug,showArmor,showItem,showDrop,showChest,showWarning,showRadar,showGrenade,showDistance,lockHP=true,lockAi=true,lockAi996=false,showsb,showqb,showwzqb;
int ye, xu, player, bot, quantity, MyTeamID, GoodsID, TeamID, State, isBot, Weaponbar,WeaponID,goodsid,ObjectCount,kh,mb;
*/
#ifndef MY_LICCSU_TPPZ
#define MY_LICCSU_TPPZ

#include <algorithm>

char extra[128];

ImColor bone_redColor = ImColor(ImVec4(255/255.f, 0/255.f, 0/255.f, 255/255.f));
ImColor bone_greenColor = ImColor(ImVec4(0/255.f, 255/255.f, 0/255.f, 255/255.f));
ImColor blueColor = ImColor(ImVec4(36/255.f, 249/255.f, 217/255.f, 255/255.f));
ImColor whiteColor = ImColor(ImVec4(255/255.f, 255/255.f, 258/255.f, 1.0f));
ImColor blackColor = ImColor(ImVec4(255/255.f,192/255.f,203/255.f,255.f/255.f));
ImColor halflackColor = ImColor(ImVec4(0/255.f, 0/255.f, 0/255.f, 0.3f));
ImColor health_Color = ImColor(ImVec4(255/255.f, 255/255.f, 258/255.f, 0.85f));
ImColor vehicle_color = ImColor(ImVec4(255/255.f,240/255.f,0/255.f,255/255.f));
ImColor rifle_color = ImColor(ImVec4(255/255.f,0/255.f,0/255.f,255.f/255.f));
ImColor submachine_color = ImColor(ImVec4(255/255.f,110/255.f,180/255.f,255.f/255.f));
ImColor snipe_color = ImColor(ImVec4(144/255.f,238/255.f,0/255.f,255.f/255.f));
ImColor box_color = ImColor(ImVec4(255/255.f,192/255.f,203/255.f,255.f/255.f));
ImColor drop_color = ImColor(ImVec4(255/255.f,0/255.f,0/255.f,255.f/255.f));
ImColor drug_color = ImColor(ImVec4(255/255.f,105/255.f,180/255.f,255.f/255.f));
ImColor armor_color = ImColor(ImVec4(255/255.f,215/255.f,0/255.f,255.f/255.f));
ImColor color_556 = ImColor(ImVec4(0/255.f,255/255.f,0/255.f,255.f/255.f));
ImColor color_762 = ImColor(ImVec4(255/255.f,255/255.f,0/255.f,255.f/255.f));
ImColor mirror_color = ImColor(ImVec4{255.f/255.f,144.f/255.f,0.f/255.f,255.f/255.f});
ImColor otherparts_color = ImColor(ImVec4{245.f/255.f,245.f/255.f,245.f/255.f,255.f/255.f});
ImColor expansion_color = ImColor(ImVec4{208.f/255.f,128.f/255.f,114.f/255.f,255.f/255.f});
ImColor aim_color = ImColor(ImVec4(255/255.f,0/255.f,0/255.f,255/255.f));
ImColor redColor = ImColor(ImVec4(255/255.f, 0/255.f, 0/255.f, 255/255.f));
ImColor greenColor = ImColor(ImVec4(50/255.f, 222/215.f, 50/255.f, 200/255.f));
ImColor yellowColor = ImColor(ImVec4(255/255.f, 215/255.f, 0/255.f, 200/255.f));
/*
char libmsg[256];
ImColor boxColor = ImColor(225, 0, 0, 255);
ImColor jbColor = ImColor(225,255, 255);
ImColor lineColor = ImColor(225, 0, 0, 255);
ImColor ggColor = ImColor(225, 0, 0, 255);
ImColor xlColor = ImColor(0, 255, 0, 100);
ImColor bdzrColor = ImColor(225, 0, 0, 100);
ImColor bdbotColor = ImColor(0, 255, 0, 100);
ImColor bone_color;
ImColor botline = ImColor(0,255,0);
*/
/*
ImColor name_yellowColor = ImColor(ImVec4(230/255.f, 180/255.f, 30/255.f, 0.47f));
ImColor name_greenColor = ImColor(ImVec4(0/255.f, 100/255.f, 0/255.f, 0.47f));
*/

ImTextureID createTexture(char* ImagePath)
{
    int w,h,n;
    stbi_uc * data = stbi_load(ImagePath,&w,&h,&n,0);
    GLuint texture;
    glGenTextures(1, &texture);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    if(n==3)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w , h , 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    } else{
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w , h , 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }
    
    stbi_image_free(data);
    ImTextureID image_id = (GLuint *)texture;
    return image_id;
}

void 绘制加粗文本(float size, float x, float y, ImColor color, ImColor color1, const char* str)
{
    ImGui::GetBackgroundDrawList()->AddText(NULL, size, {x-0.1, y-0.1}, color1, str);
    ImGui::GetBackgroundDrawList()->AddText(NULL, size, {x+0.1, y+0.1}, color1, str);
    ImGui::GetBackgroundDrawList()->AddText(NULL, size, {x, y}, color, str);
}

void 绘制字体描边(float size,int x, int y, ImVec4 color, const char* str)
{
    ImGui::GetBackgroundDrawList()->AddText(NULL, size,ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
    ImGui::GetBackgroundDrawList()->AddText(NULL, size,ImVec2(x - 0.1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
    ImGui::GetBackgroundDrawList()->AddText(NULL, size,ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
    ImGui::GetBackgroundDrawList()->AddText(NULL, size,ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
    ImGui::GetBackgroundDrawList()->AddText(NULL, size,ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(color), str);
}

struct Hero{
    ImTextureID hero103;
    ImTextureID hero104;
    ImTextureID hero105;
    ImTextureID hero106;
    ImTextureID hero107;
    ImTextureID hero108;
    ImTextureID hero109;
    ImTextureID hero110;
    ImTextureID hero111;
    ImTextureID hero112;
    ImTextureID hero113;
    ImTextureID hero114;
    ImTextureID hero115;
    ImTextureID hero116;
    ImTextureID hero117;
    ImTextureID hero118;
    ImTextureID hero119;
    ImTextureID hero120;
    ImTextureID hero121;
    ImTextureID hero123;
    ImTextureID hero124;
    ImTextureID hero125;
    ImTextureID hero126;
    ImTextureID hero127;
    ImTextureID hero128;
    ImTextureID hero129;
    ImTextureID hero130;
    ImTextureID hero131;
    ImTextureID hero132;
    ImTextureID hero133;
    ImTextureID hero134;
    ImTextureID hero135;
    ImTextureID hero136;
    ImTextureID hero137;
    ImTextureID hero139;
    ImTextureID hero140;
    ImTextureID hero141;
    ImTextureID hero142;
    ImTextureID hero144;
    ImTextureID hero146;
    ImTextureID hero148;
    ImTextureID hero149;
    ImTextureID hero150;
    ImTextureID hero152;
    ImTextureID hero153;
    ImTextureID hero154;
    ImTextureID hero155;
    ImTextureID hero156;
    ImTextureID hero157;
    ImTextureID hero162;
    ImTextureID hero163;
    ImTextureID hero166;
    ImTextureID hero167;
    ImTextureID hero168;
    ImTextureID hero169;
    ImTextureID hero170;
    ImTextureID hero171;
    ImTextureID hero173;
    ImTextureID hero174;
    ImTextureID hero175;
    ImTextureID hero176;
    ImTextureID hero177;
    ImTextureID hero178;
    ImTextureID hero179;
    ImTextureID hero180;
    ImTextureID hero182;
    ImTextureID hero183;
    ImTextureID hero184;
    ImTextureID hero186;
    ImTextureID hero187;
    ImTextureID hero189;
    ImTextureID hero190;
    ImTextureID hero191;
    ImTextureID hero192;
    ImTextureID hero193;
    ImTextureID hero194;
    ImTextureID hero195;
    ImTextureID hero196;
    ImTextureID hero197;
    ImTextureID hero198;
    ImTextureID hero199;
    ImTextureID hero225;
    ImTextureID hero310;
    ImTextureID hero312;
    ImTextureID hero332;
    ImTextureID hero356;
    ImTextureID hero382;
    ImTextureID hero501;
    ImTextureID hero502;
    ImTextureID hero503;
    ImTextureID hero504;
    ImTextureID hero505;
    ImTextureID hero506;
    ImTextureID hero507;
    ImTextureID hero508;
    ImTextureID hero509;
    ImTextureID hero510;
    ImTextureID hero511;
    ImTextureID hero513;
    ImTextureID hero515;
    ImTextureID hero518;
    ImTextureID hero521;
    ImTextureID hero522;
    ImTextureID hero523;
    ImTextureID hero524;
    ImTextureID hero525;
    ImTextureID hero527;
    ImTextureID hero528;
    ImTextureID hero529;
    ImTextureID hero531;
    ImTextureID hero533;
    ImTextureID hero534;
    ImTextureID hero536;
    ImTextureID hero537;
    ImTextureID hero538;
    ImTextureID hero540;
    ImTextureID hero542;
    ImTextureID hero544;
    ImTextureID hero545;
    ImTextureID hero548;
    ImTextureID hero564;
    ImTextureID hero621;
    ImTextureID hero620;
    ImTextureID hero999;
}hero;

void InitTexture() {
    hero.hero103 = createTexture("/data/user/0/com.liccsu.natool/files/103.png");
    hero.hero104 = createTexture("/data/user/0/com.liccsu.natool/files/104.png");
    hero.hero105 = createTexture("/data/user/0/com.liccsu.natool/files/105.png");
    hero.hero106 = createTexture("/data/user/0/com.liccsu.natool/files/106.png");
    hero.hero107 = createTexture("/data/user/0/com.liccsu.natool/files/107.png");
    hero.hero108 = createTexture("/data/user/0/com.liccsu.natool/files/108.png");
    hero.hero109 = createTexture("/data/user/0/com.liccsu.natool/files/109.png");
    hero.hero110 = createTexture("/data/user/0/com.liccsu.natool/files/110.png");
    hero.hero111 = createTexture("/data/user/0/com.liccsu.natool/files/111.png");
    hero.hero112 = createTexture("/data/user/0/com.liccsu.natool/files/112.png");
    hero.hero113 = createTexture("/data/user/0/com.liccsu.natool/files/113.png");
    hero.hero114 = createTexture("/data/user/0/com.liccsu.natool/files/114.png");
    hero.hero115 = createTexture("/data/user/0/com.liccsu.natool/files/115.png");
    hero.hero116 = createTexture("/data/user/0/com.liccsu.natool/files/116.png");
    hero.hero117 = createTexture("/data/user/0/com.liccsu.natool/files/117.png");
    hero.hero118 = createTexture("/data/user/0/com.liccsu.natool/files/118.png");
    hero.hero119 = createTexture("/data/user/0/com.liccsu.natool/files/119.png");
    hero.hero120 = createTexture("/data/user/0/com.liccsu.natool/files/120.png");
    hero.hero121 = createTexture("/data/user/0/com.liccsu.natool/files/121.png");
    hero.hero123 = createTexture("/data/user/0/com.liccsu.natool/files/123.png");
    hero.hero124 = createTexture("/data/user/0/com.liccsu.natool/files/124.png");
    hero.hero125 = createTexture("/data/user/0/com.liccsu.natool/files/125.png");
    hero.hero126 = createTexture("/data/user/0/com.liccsu.natool/files/126.png");
    hero.hero127 = createTexture("/data/user/0/com.liccsu.natool/files/127.png");
    hero.hero128 = createTexture("/data/user/0/com.liccsu.natool/files/128.png");
    hero.hero129 = createTexture("/data/user/0/com.liccsu.natool/files/129.png");
    hero.hero130 = createTexture("/data/user/0/com.liccsu.natool/files/130.png");
    hero.hero131 = createTexture("/data/user/0/com.liccsu.natool/files/131.png");
    hero.hero132 = createTexture("/data/user/0/com.liccsu.natool/files/132.png");
    hero.hero133 = createTexture("/data/user/0/com.liccsu.natool/files/133.png");
    hero.hero134 = createTexture("/data/user/0/com.liccsu.natool/files/134.png");
    hero.hero135 = createTexture("/data/user/0/com.liccsu.natool/files/135.png");
    hero.hero136 = createTexture("/data/user/0/com.liccsu.natool/files/136.png");
    hero.hero137 = createTexture("/data/user/0/com.liccsu.natool/files/137.png");
    hero.hero139 = createTexture("/data/user/0/com.liccsu.natool/files/139.png");
    hero.hero140 = createTexture("/data/user/0/com.liccsu.natool/files/140.png");
    hero.hero141 = createTexture("/data/user/0/com.liccsu.natool/files/141.png");
    hero.hero142 = createTexture("/data/user/0/com.liccsu.natool/files/142.png");
    hero.hero144 = createTexture("/data/user/0/com.liccsu.natool/files/144.png");
    hero.hero146 = createTexture("/data/user/0/com.liccsu.natool/files/146.png");
    hero.hero148 = createTexture("/data/user/0/com.liccsu.natool/files/148.png");
    hero.hero149 = createTexture("/data/user/0/com.liccsu.natool/files/149.png");
    hero.hero150 = createTexture("/data/user/0/com.liccsu.natool/files/150.png");
    hero.hero152 = createTexture("/data/user/0/com.liccsu.natool/files/152.png");
    hero.hero153 = createTexture("/data/user/0/com.liccsu.natool/files/153.png");
    hero.hero154 = createTexture("/data/user/0/com.liccsu.natool/files/154.png");
    hero.hero155 = createTexture("/data/user/0/com.liccsu.natool/files/155.png");
    hero.hero156 = createTexture("/data/user/0/com.liccsu.natool/files/156.png");
    hero.hero157 = createTexture("/data/user/0/com.liccsu.natool/files/157.png");
    hero.hero162 = createTexture("/data/user/0/com.liccsu.natool/files/162.png");
    hero.hero163 = createTexture("/data/user/0/com.liccsu.natool/files/163.png");
    hero.hero166 = createTexture("/data/user/0/com.liccsu.natool/files/166.png");
    hero.hero167 = createTexture("/data/user/0/com.liccsu.natool/files/167.png");
    hero.hero168 = createTexture("/data/user/0/com.liccsu.natool/files/168.png");
    hero.hero169 = createTexture("/data/user/0/com.liccsu.natool/files/169.png");
    hero.hero170 = createTexture("/data/user/0/com.liccsu.natool/files/170.png");
    hero.hero171 = createTexture("/data/user/0/com.liccsu.natool/files/171.png");
    hero.hero173 = createTexture("/data/user/0/com.liccsu.natool/files/173.png");
    hero.hero174 = createTexture("/data/user/0/com.liccsu.natool/files/174.png");
    hero.hero175 = createTexture("/data/user/0/com.liccsu.natool/files/175.png");
    hero.hero176 = createTexture("/data/user/0/com.liccsu.natool/files/176.png");
    hero.hero177 = createTexture("/data/user/0/com.liccsu.natool/files/177.png");
    hero.hero178 = createTexture("/data/user/0/com.liccsu.natool/files/178.png");
    hero.hero179 = createTexture("/data/user/0/com.liccsu.natool/files/179.png");
    hero.hero180 = createTexture("/data/user/0/com.liccsu.natool/files/180.png");
    hero.hero182 = createTexture("/data/user/0/com.liccsu.natool/files/182.png");
    hero.hero183 = createTexture("/data/user/0/com.liccsu.natool/files/183.png");
    hero.hero184 = createTexture("/data/user/0/com.liccsu.natool/files/184.png");
    hero.hero186 = createTexture("/data/user/0/com.liccsu.natool/files/186.png");
    hero.hero187 = createTexture("/data/user/0/com.liccsu.natool/files/187.png");
    hero.hero189 = createTexture("/data/user/0/com.liccsu.natool/files/189.png");
    hero.hero190 = createTexture("/data/user/0/com.liccsu.natool/files/190.png");
    hero.hero191 = createTexture("/data/user/0/com.liccsu.natool/files/191.png");
    hero.hero192 = createTexture("/data/user/0/com.liccsu.natool/files/192.png");
    hero.hero193 = createTexture("/data/user/0/com.liccsu.natool/files/193.png");
    hero.hero194 = createTexture("/data/user/0/com.liccsu.natool/files/194.png");
    hero.hero195 = createTexture("/data/user/0/com.liccsu.natool/files/195.png");
    hero.hero196 = createTexture("/data/user/0/com.liccsu.natool/files/196.png");
    hero.hero197 = createTexture("/data/user/0/com.liccsu.natool/files/197.png");
    hero.hero198 = createTexture("/data/user/0/com.liccsu.natool/files/198.png");
    hero.hero199 = createTexture("/data/user/0/com.liccsu.natool/files/199.png");
    hero.hero225 = createTexture("/data/user/0/com.liccsu.natool/files/225.png");
    hero.hero310 = createTexture("/data/user/0/com.liccsu.natool/files/310.png");
    hero.hero312 = createTexture("/data/user/0/com.liccsu.natool/files/312.png");
    hero.hero332 = createTexture("/data/user/0/com.liccsu.natool/files/332.png");
    hero.hero356 = createTexture("/data/user/0/com.liccsu.natool/files/356.png");
    hero.hero382 = createTexture("/data/user/0/com.liccsu.natool/files/382.png");
    hero.hero501 = createTexture("/data/user/0/com.liccsu.natool/files/501.png");
    hero.hero502 = createTexture("/data/user/0/com.liccsu.natool/files/502.png");
    hero.hero503 = createTexture("/data/user/0/com.liccsu.natool/files/503.png");
    hero.hero504 = createTexture("/data/user/0/com.liccsu.natool/files/504.png");
    hero.hero505 = createTexture("/data/user/0/com.liccsu.natool/files/505.png");
    hero.hero506 = createTexture("/data/user/0/com.liccsu.natool/files/506.png");
    hero.hero507 = createTexture("/data/user/0/com.liccsu.natool/files/507png");
    hero.hero508 = createTexture("/data/user/0/com.liccsu.natool/files/508.png");
    hero.hero509 = createTexture("/data/user/0/com.liccsu.natool/files/509.png");
    hero.hero510 = createTexture("/data/user/0/com.liccsu.natool/files/510.png");
    hero.hero511 = createTexture("/data/user/0/com.liccsu.natool/files/511.png");
    hero.hero513 = createTexture("/data/user/0/com.liccsu.natool/files/513.png");
    hero.hero515 = createTexture("/data/user/0/com.liccsu.natool/files/515.png");
    hero.hero518 = createTexture("/data/user/0/com.liccsu.natool/files/518.png");
    hero.hero521 = createTexture("/data/user/0/com.liccsu.natool/files/521.png");
    hero.hero522 = createTexture("/data/user/0/com.liccsu.natool/files/522.png");
    hero.hero523 = createTexture("/data/user/0/com.liccsu.natool/files/523.png");
    hero.hero524 = createTexture("/data/user/0/com.liccsu.natool/files/524.png");
    hero.hero525 = createTexture("/data/user/0/com.liccsu.natool/files/525.png");
    hero.hero527 = createTexture("/data/user/0/com.liccsu.natool/files/527.png");
    hero.hero528 = createTexture("/data/user/0/com.liccsu.natool/files/528.png");
    hero.hero529 = createTexture("/data/user/0/com.liccsu.natool/files/529.png");
    hero.hero531 = createTexture("/data/user/0/com.liccsu.natool/files/531.png");
    hero.hero533 = createTexture("/data/user/0/com.liccsu.natool/files/533.png");
    hero.hero534 = createTexture("/data/user/0/com.liccsu.natool/files/534.png");
    hero.hero536 = createTexture("/data/user/0/com.liccsu.natool/files/536.png");
    hero.hero537 = createTexture("/data/user/0/com.liccsu.natool/files/537.png");
    hero.hero538 = createTexture("/data/user/0/com.liccsu.natool/files/538.png");
    hero.hero540 = createTexture("/data/user/0/com.liccsu.natool/files/540.png");
    hero.hero542 = createTexture("/data/user/0/com.liccsu.natool/files/542.png");
    hero.hero544 = createTexture("/data/user/0/com.liccsu.natool/files/544.png");
    hero.hero545 = createTexture("/data/user/0/com.liccsu.natool/files/545.png");
    hero.hero548 = createTexture("/data/user/0/com.liccsu.natool/files/548.png");
    hero.hero564 = createTexture("/data/user/0/com.liccsu.natool/files/564.png");
    hero.hero621 = createTexture("/data/user/0/com.liccsu.natool/files/621.png");
    hero.hero620 = createTexture("/data/user/0/com.liccsu.natool/files/620.png");
    hero.hero999 = createTexture("/data/user/0/com.liccsu.natool/files/999.png");
}

ImTextureID getHeroTexture(int hero_id) {
    switch(hero_id){
        case 103: return hero.hero103; break;
        case 104: return hero.hero104; break;
        case 105: return hero.hero105; break;
        case 106: return hero.hero106; break;
        case 107: return hero.hero107; break;
        case 108: return hero.hero108; break;
        case 109: return hero.hero109; break;
        case 110: return hero.hero110; break;
        case 111: return hero.hero111; break;
        case 112: return hero.hero112; break;
        case 113: return hero.hero113; break;
        case 114: return hero.hero114; break;
        case 115: return hero.hero115; break;
        case 116: return hero.hero116; break;
        case 117: return hero.hero117; break;
        case 118: return hero.hero118; break;
        case 119: return hero.hero119; break;
        case 120: return hero.hero120; break;
        case 121: return hero.hero121; break;
        case 123: return hero.hero123; break;
        case 124: return hero.hero124; break;
        case 125: return hero.hero125; break;
        case 126: return hero.hero126; break;
        case 127: return hero.hero127; break;
        case 128: return hero.hero128; break;
        case 129: return hero.hero129; break;
        case 130: return hero.hero130; break;
        case 131: return hero.hero131; break;
        case 132: return hero.hero132; break;
        case 133: return hero.hero133; break;
        case 134: return hero.hero134; break;
        case 135: return hero.hero135; break;
        case 136: return hero.hero136; break;
        case 137: return hero.hero137; break;
        case 139: return hero.hero139; break;
        case 140: return hero.hero140; break;
        case 141: return hero.hero141; break;
        case 142: return hero.hero142; break;
        case 144: return hero.hero144; break;
        case 146: return hero.hero146; break;
        case 148: return hero.hero148; break;
        case 149: return hero.hero149; break;
        case 150: return hero.hero150; break;
        case 152: return hero.hero152; break;
        case 153: return hero.hero153; break;
        case 154: return hero.hero154; break;
        case 155: return hero.hero155; break;
        case 156: return hero.hero156; break;
        case 157: return hero.hero157; break;
        case 162: return hero.hero162; break;
        case 163: return hero.hero163; break;
        case 166: return hero.hero166; break;
        case 167: return hero.hero167; break;
        case 168: return hero.hero168; break;
        case 169: return hero.hero169; break;
        case 170: return hero.hero170; break;
        case 171: return hero.hero171; break;
        case 173: return hero.hero173; break;
        case 174: return hero.hero174; break;
        case 175: return hero.hero175; break;
        case 176: return hero.hero176; break;
        case 177: return hero.hero177; break;
        case 178: return hero.hero178; break;
        case 179: return hero.hero179; break;
        case 180: return hero.hero180; break;
        case 182: return hero.hero182; break;
        case 183: return hero.hero183; break;
        case 184: return hero.hero184; break;
        case 186: return hero.hero186; break;
        case 187: return hero.hero187; break;
        case 189: return hero.hero189; break;
        case 190: return hero.hero190; break;
        case 191: return hero.hero191; break;
        case 192: return hero.hero192; break;
        case 193: return hero.hero193; break;
        case 194: return hero.hero194; break;
        case 195: return hero.hero195; break;
        case 196: return hero.hero196; break;
        case 197: return hero.hero197; break;
        case 198: return hero.hero198; break;
        case 199: return hero.hero199; break;
        case 225: return hero.hero225; break;
        case 310: return hero.hero310; break;
        case 312: return hero.hero312; break;
        case 332: return hero.hero332; break;
        case 356: return hero.hero356; break;
        case 382: return hero.hero382; break;
        case 501: return hero.hero501; break;
        case 502: return hero.hero502; break;
        case 503: return hero.hero503; break;
        case 504: return hero.hero504; break;
        case 505: return hero.hero505; break;
        case 506: return hero.hero506; break;
        case 507: return hero.hero507; break;
        case 508: return hero.hero508; break;
        case 509: return hero.hero509; break;
        case 510: return hero.hero510; break;
        case 511: return hero.hero511; break;
        case 513: return hero.hero513; break;
        case 515: return hero.hero515; break;
        case 518: return hero.hero518; break;
        case 521: return hero.hero521; break;
        case 522: return hero.hero522; break;
        case 523: return hero.hero523; break;
        case 524: return hero.hero524; break;
        case 525: return hero.hero525; break;
        case 527: return hero.hero527; break;
        case 528: return hero.hero528; break;
        case 529: return hero.hero529; break;
        case 531: return hero.hero531; break;
        case 533: return hero.hero533; break;
        case 534: return hero.hero534; break;
        case 536: return hero.hero536; break;
        case 537: return hero.hero537; break;
        case 538: return hero.hero538; break;
        case 540: return hero.hero540; break;
        case 542: return hero.hero542; break;
        case 544: return hero.hero544; break;
        case 545: return hero.hero545; break;
        case 548: return hero.hero548; break;
        case 564: return hero.hero564; break;
        case 621: return hero.hero621; break;
        case 620: return hero.hero620; break;
        default: return hero.hero999; break;
    }
}

inline bool roleHas4Skills(int role_id) {
	int has4SkillsRole[] = {
		125,//元歌
		153,//兰陵王
		154,//花木兰
		179,//女娲
		182,//干将莫邪
		191,//大乔
		225,//元歌
		382,//干将莫邪
		507,//李信
		509//盾山
	};
	int *p = find(has4SkillsRole, has4SkillsRole+sizeof(has4SkillsRole), role_id);
	return p != has4SkillsRole+sizeof(has4SkillsRole);
}

/*

//载具
struct Vehicle{
    ImTextureID jeep;
    ImTextureID bengbeng;
    ImTextureID jiaoche;
    ImTextureID paoche;
    ImTextureID mianyang;
    ImTextureID yueye;
    ImTextureID kuaiting;
    ImTextureID luonipika;
    ImTextureID daba;
    ImTextureID motuoting;
    ImTextureID xuedimotuo;
    ImTextureID sanlunmotuo;
    ImTextureID motuo;
    ImTextureID wupengpika;
    ImTextureID youpengpika;
    ImTextureID sanlunche;
    ImTextureID xueqiao;
    ImTextureID zhuangjiache;
	ImTextureID 飞机;
}vehicle;
//倍镜
struct Part{
    ImTextureID erbei;
    ImTextureID sanbei;
    ImTextureID sibei;
    ImTextureID liubei;
    ImTextureID babei;
    ImTextureID cemiao;
    ImTextureID hongdian;
    ImTextureID quanxi;
}part;
//步枪
static struct Rifle{
    ImTextureID AK;
    ImTextureID AUG;
    ImTextureID DP28;
    ImTextureID G36C;
    ImTextureID GROZA;
    ImTextureID M16A4;
    ImTextureID M249;
    ImTextureID M416;
    ImTextureID M762;
    ImTextureID QBU;
    ImTextureID QBZ;
    ImTextureID SCAR;
    ImTextureID xinhaoqiang;
}rifle;
//刀
static struct Knife{
    ImTextureID guo;
    ImTextureID kandao;
    ImTextureID liandao;
    ImTextureID qiaogun;
    ImTextureID nu;
}knife;
//冲锋枪
static struct charge{
    ImTextureID UMP45;
    ImTextureID VECTOR;
    ImTextureID TANGMUXUN;
    ImTextureID YENIU;
    ImTextureID VSS;
    ImTextureID UZI;
}charge;
//狙击枪
static struct Sniper{
    ImTextureID AWM;
    ImTextureID K98;
    ImTextureID M24;
    ImTextureID MINI14;
    ImTextureID MK14;
    ImTextureID MK47;
    ImTextureID SKS;
    ImTextureID SLR;
    ImTextureID WIN94;
}Sniper;
//子弹
static struct Bullet{
    ImTextureID ZD_45;
    ImTextureID ZD_AWM;
    ImTextureID ZD_556;
    ImTextureID ZD_762;
    ImTextureID ZD_9;
    ImTextureID ZD_12;
}bullet;
//投掷物
static struct missile{
    ImTextureID shoulei;
    ImTextureID ranshaoping;
    ImTextureID yanwudan;
    ImTextureID zhenbaodan;
}missile;
//散弹抢
static struct shot{
    ImTextureID dbs;
    ImTextureID sk12;
    ImTextureID s686;
    ImTextureID s1897;
}shot;
//药
static struct drug{
    ImTextureID bengdai;
    ImTextureID jijiubao;
    ImTextureID yinliao;
    ImTextureID yiliaoxiang;
    ImTextureID shenshangxiansu;
    ImTextureID zhitengyao;
}drug;
//头盔、防弹衣、背包
static struct Helmet{
    ImTextureID sanjitou;
    ImTextureID sanjijia;
    ImTextureID sanjibao;
    ImTextureID erjitou;
    ImTextureID erjijia;
    ImTextureID erjibao;
    ImTextureID yijitou;
    ImTextureID yijijia;
    ImTextureID yijibao;
    ImTextureID box1;
    ImTextureID box2;
}Helmet;
//配件
static struct parts{
    ImTextureID banjiewoba;
    ImTextureID chuizhiwoba;
    ImTextureID jiguangmiaozhun;
    ImTextureID jiandai;
    ImTextureID cf_kuaisudanjia;
    ImTextureID jj_kuaisudanjia;
    ImTextureID sq_kuaisudanjia;
    ImTextureID bq_kuaisudanjia;
    ImTextureID cf_kuaikuo;
    ImTextureID jj_kuaikuo;
    ImTextureID sq_kuaikuo;
    ImTextureID bq_kuaikuo;
    ImTextureID cf_kuorong;
    ImTextureID jj_kuorong;
    ImTextureID sq_kuorong;
    ImTextureID bq_kuorong;
    ImTextureID muzhiwoba;
    ImTextureID cf_buchang;
    ImTextureID jj_buchang;
    ImTextureID bq_buchang;
    ImTextureID uzi_qiangtuo;
    ImTextureID qingxingwoba;
    ImTextureID jj_tuosaiban;
    ImTextureID sd_shoushuqi;
    ImTextureID cf_xiaoyanqi;
    ImTextureID jj_xiaoyanqi;
    ImTextureID bq_xiaoyanqi;
    ImTextureID cf_xiaoyinqi;
    ImTextureID jj_xiaoyinqi;
    ImTextureID sq_xiaoyinqi;
    ImTextureID bq_xiaoyinqi;
    ImTextureID yazuiqiangkou;
    ImTextureID m416_qiangtuo;
    ImTextureID zhijiaowoba;
    ImTextureID k98zidandai;
    ImTextureID sd_zidandai;
}parts;
ImTextureID back1;
ImTextureID back2;

static struct Hand{
    ImTextureID K98;
    ImTextureID M416;
    ImTextureID M416A4;
    ImTextureID MK14;
    ImTextureID Grozy;
    ImTextureID Scar;
    ImTextureID M24;
    ImTextureID QBZ;
    ImTextureID DP28;
    ImTextureID MK47;
    ImTextureID S12K;
    ImTextureID S1896;
    ImTextureID SKS;
    ImTextureID SLR;
    ImTextureID M762;
    ImTextureID S686;
    ImTextureID VSS;
    ImTextureID UMP9;
    ImTextureID 手雷;
    ImTextureID 烟雾弹;
    ImTextureID 燃烧瓶;
    ImTextureID 拳头;
    ImTextureID AWM;
    ImTextureID AKM;
    ImTextureID M249;
    ImTextureID QBU;
    ImTextureID Mini14;
    ImTextureID AUG;
    ImTextureID G36C;
    ImTextureID PP19;
    ImTextureID UZI;
    ImTextureID P18C;
    ImTextureID WIN94;
    ImTextureID 汤姆逊;
    ImTextureID Vector;
    ImTextureID 短管散弹;
    ImTextureID 十字弩;
}hand;

ImTextureID 测试图;

void InitTexture()
{
    //枪支配件
    parts.banjiewoba=createTexture("/storage/emulated/0/Android/image/parts1.png");
    parts.chuizhiwoba=createTexture("/storage/emulated/0/Android/image/parts2.png");
    parts.jiguangmiaozhun=createTexture("/storage/emulated/0/Android/image/parts3.png");
    parts.jiandai=createTexture("/storage/emulated/0/Android/image/parts4.png");
    parts.cf_kuaisudanjia=createTexture("/storage/emulated/0/Android/image/parts5.png");
    parts.jj_kuaisudanjia=createTexture("/storage/emulated/0/Android/image/parts6.png");
    parts.sq_kuaisudanjia=createTexture("/storage/emulated/0/Android/image/parts7.png");
    parts.bq_kuaisudanjia=createTexture("/storage/emulated/0/Android/image/parts8.png");
    parts.cf_kuaikuo=createTexture("/storage/emulated/0/Android/image/parts9.png");
    parts.jj_kuaikuo=createTexture("/storage/emulated/0/Android/image/parts10.png");
    parts.sq_kuaikuo=createTexture("/storage/emulated/0/Android/image/parts11.png");
    parts.bq_kuaikuo=createTexture("/storage/emulated/0/Android/image/parts12.png");
    parts.cf_kuorong=createTexture("/storage/emulated/0/Android/image/parts13.png");
    parts.jj_kuorong=createTexture("/storage/emulated/0/Android/image/parts14.png");
    parts.sq_kuorong=createTexture("/storage/emulated/0/Android/image/parts15.png");
    parts.bq_kuorong=createTexture("/storage/emulated/0/Android/image/parts16.png");
    parts.muzhiwoba=createTexture("/storage/emulated/0/Android/image/parts17.png");
    parts.cf_buchang=createTexture("/storage/emulated/0/Android/image/parts18.png");
    parts.jj_buchang=createTexture("/storage/emulated/0/Android/image/parts19.png");
    parts.bq_buchang=createTexture("/storage/emulated/0/Android/image/parts20.png");
    parts.uzi_qiangtuo=createTexture("/storage/emulated/0/Android/image/parts21.png");
    parts.qingxingwoba=createTexture("/storage/emulated/0/Android/image/parts22.png");
    parts.jj_tuosaiban=createTexture("/storage/emulated/0/Android/image/parts23.png");
    parts.sd_shoushuqi=createTexture("/storage/emulated/0/Android/image/parts24.png");
    parts.cf_xiaoyanqi=createTexture("/storage/emulated/0/Android/image/parts25.png");
    parts.jj_xiaoyanqi=createTexture("/storage/emulated/0/Android/image/parts26.png");
    parts.bq_xiaoyanqi=createTexture("/storage/emulated/0/Android/image/parts27.png");
    parts.cf_xiaoyinqi=createTexture("/storage/emulated/0/Android/image/parts28.png");
    parts.jj_xiaoyinqi=createTexture("/storage/emulated/0/Android/image/parts29.png");
    parts.sq_xiaoyinqi=createTexture("/storage/emulated/0/Android/image/parts30.png");
    parts.bq_xiaoyinqi=createTexture("/storage/emulated/0/Android/image/parts31.png");
    parts.yazuiqiangkou=createTexture("/storage/emulated/0/Android/image/parts32.png");
    parts.m416_qiangtuo=createTexture("/storage/emulated/0/Android/image/parts33.png");
    parts.zhijiaowoba=createTexture("/storage/emulated/0/Android/image/parts34.png");
    parts.k98zidandai=createTexture("/storage/emulated/0/Android/image/parts35.png");
    parts.sd_zidandai=createTexture("/storage/emulated/0/Android/image/parts36.png");

    //头盔、防弹衣、背包
    Helmet.sanjitou=createTexture("/storage/emulated/0/Android/image/Helmet1.png");
    Helmet.sanjijia=createTexture("/storage/emulated/0/Android/image/Helmet2.png");
    Helmet.sanjibao=createTexture("/storage/emulated/0/Android/image/Helmet3.png");
    Helmet.erjitou=createTexture("/storage/emulated/0/Android/image/Helmet4.png");
    Helmet.erjijia=createTexture("/storage/emulated/0/Android/image/Helmet5.png");
    Helmet.erjibao=createTexture("/storage/emulated/0/Android/image/Helmet6.png");
    Helmet.yijitou=createTexture("/storage/emulated/0/Android/image/Helmet7.png");
    Helmet.yijijia=createTexture("/storage/emulated/0/Android/image/Helmet8.png");
    Helmet.yijibao=createTexture("/storage/emulated/0/Android/image/Helmet9.png");
    //药
    drug.bengdai=createTexture("/storage/emulated/0/Android/image/drug1.png");
    drug.jijiubao=createTexture("/storage/emulated/0/Android/image/drug2.png");
    drug.yinliao=createTexture("/storage/emulated/0/Android/image/drug3.png");
    drug.yiliaoxiang=createTexture("/storage/emulated/0/Android/image/drug4.png");
    drug.shenshangxiansu=createTexture("/storage/emulated/0/Android/image/drug5.png");
    drug.zhitengyao=createTexture("/storage/emulated/0/Android/image/drug6.png");
    //投掷物
    missile.shoulei=createTexture("/storage/emulated/0/Android/image/missile1.png");
    missile.ranshaoping=createTexture("/storage/emulated/0/Android/image/missile2.png");
    missile.yanwudan=createTexture("/storage/emulated/0/Android/image/missile3.png");
    missile.zhenbaodan=createTexture("/storage/emulated/0/Android/image/missile4.png");
    //散弹枪
    shot.dbs=createTexture("/storage/emulated/0/Android/image/shot1.png");
    shot.sk12=createTexture("/storage/emulated/0/Android/image/shot2.png");
    shot.s686=createTexture("/storage/emulated/0/Android/image/shot3.png");
    shot.s1897=createTexture("/storage/emulated/0/Android/image/shot4.png");
    //载具
    vehicle.jeep=createTexture("/storage/emulated/0/Android/image/Vehicle1.png");
    vehicle.bengbeng=createTexture("/storage/emulated/0/Android/image/Vehicle2.png");
    vehicle.jiaoche=createTexture("/storage/emulated/0/Android/image/Vehicle3.png");
    vehicle.paoche=createTexture("/storage/emulated/0/Android/image/Vehicle4.png");
    vehicle.mianyang=createTexture("/storage/emulated/0/Android/image/Vehicle5.png");
    vehicle.yueye=createTexture("/storage/emulated/0/Android/image/Vehicle6.png");
    vehicle.kuaiting=createTexture("/storage/emulated/0/Android/image/Vehicle7.png");
    vehicle.luonipika=createTexture("/storage/emulated/0/Android/image/Vehicle8.png");
    vehicle.daba=createTexture("/storage/emulated/0/Android/image/Vehicle9.png");
    vehicle.motuoting=createTexture("/storage/emulated/0/Android/image/Vehicle10.png");
    vehicle.xuedimotuo=createTexture("/storage/emulated/0/Android/image/Vehicle11.png");
    vehicle.sanlunmotuo=createTexture("/storage/emulated/0/Android/image/Vehicle12.png");
    vehicle.motuo=createTexture("/storage/emulated/0/Android/image/Vehicle13.png");
    vehicle.wupengpika=createTexture("/storage/emulated/0/Android/image/Vehicle14.png");
    vehicle.youpengpika=createTexture("/storage/emulated/0/Android/image/Vehicle15.png");
    vehicle.sanlunche=createTexture("/storage/emulated/0/Android/image/Vehicle16.png");
    vehicle.xueqiao=createTexture("/storage/emulated/0/Android/image/Vehicle17.png");
    vehicle.zhuangjiache=createTexture("/storage/emulated/0/Android/image/Vehicle18.png");
	vehicle.飞机=createTexture("/storage/emulated/0/Android/image/Vehicle19.png");
    //倍镜
    part.erbei=createTexture("/storage/emulated/0/Android/image/part1.png");
    part.sanbei=createTexture("/storage/emulated/0/Android/image/part2.png");
    part.sibei=createTexture("/storage/emulated/0/Android/image/part3.png");
    part.liubei=createTexture("/storage/emulated/0/Android/image/part4.png");
    part.babei=createTexture("/storage/emulated/0/Android/image/part5.png");
    part.cemiao=createTexture("/storage/emulated/0/Android/image/part6.png");
    part.hongdian=createTexture("/storage/emulated/0/Android/image/part7.png");
    part.quanxi=createTexture("/storage/emulated/0/Android/image/part8.png");
    //步枪
    rifle.AK=createTexture("/storage/emulated/0/Android/image/Rifle1.png");
    rifle.AUG=createTexture("/storage/emulated/0/Android/image/Rifle2.png");
    rifle.DP28=createTexture("/storage/emulated/0/Android/image/Rifle3.png");
    rifle.G36C=createTexture("/storage/emulated/0/Android/image/Rifle4.png");
    rifle.GROZA=createTexture("/storage/emulated/0/Android/image/Rifle5.png");
    rifle.M16A4=createTexture("/storage/emulated/0/Android/image/Rifle6.png");
    rifle.M249=createTexture("/storage/emulated/0/Android/image/Rifle7.png");
    rifle.M416=createTexture("/storage/emulated/0/Android/image/Rifle8.png");
    rifle.M762=createTexture("/storage/emulated/0/Android/image/Rifle9.png");
    rifle.QBU=createTexture("/storage/emulated/0/Android/image/Rifle11.png");
    rifle.QBZ=createTexture("/storage/emulated/0/Android/image/Rifle12.png");
    rifle.SCAR=createTexture("/storage/emulated/0/Android/image/Rifle13.png");
    rifle.xinhaoqiang=createTexture("/storage/emulated/0/Android/image/Rifle14.png");
    //冲锋枪
    charge.UMP45=createTexture("/storage/emulated/0/Android/image/charge1.png");
    charge.VECTOR=createTexture("/storage/emulated/0/Android/image/charge2.png");
    charge.TANGMUXUN=createTexture("/storage/emulated/0/Android/image/charge3.png");
    charge.YENIU=createTexture("/storage/emulated/0/Android/image/charge4.png");
    charge.VSS=createTexture("/storage/emulated/0/Android/image/charge5.png");
    charge.UZI=createTexture("/storage/emulated/0/Android/image/charge6.png");
    //狙击枪
    Sniper.AWM=createTexture("/storage/emulated/0/Android/image/Sniper1.png");
    Sniper.K98=createTexture("/storage/emulated/0/Android/image/Sniper2.png");
    Sniper.M24=createTexture("/storage/emulated/0/Android/image/Sniper3.png");
    Sniper.MINI14=createTexture("/storage/emulated/0/Android/image/Sniper4.png");
    Sniper.MK14=createTexture("/storage/emulated/0/Android/image/Sniper5.png");
    Sniper.MK47=createTexture("/storage/emulated/0/Android/image/Sniper6.png");
    Sniper.SKS=createTexture("/storage/emulated/0/Android/image/Sniper7.png");
    Sniper.SLR=createTexture("/storage/emulated/0/Android/image/Sniper8.png");
    Sniper.WIN94=createTexture("/storage/emulated/0/Android/image/Sniper9.png");
    //子弹
    bullet.ZD_45=createTexture("/storage/emulated/0/Android/image/bullet1.png");
    bullet.ZD_AWM=createTexture("/storage/emulated/0/Android/image/bullet2.png");
    bullet.ZD_556=createTexture("/storage/emulated/0/Android/image/bullet3.png");
    bullet.ZD_762=createTexture("/storage/emulated/0/Android/image/bullet4.png");
    bullet.ZD_9=createTexture("/storage/emulated/0/Android/image/bullet5.png");
    bullet.ZD_12=createTexture("/storage/emulated/0/Android/image/bullet6.png");
    //刀
    knife.guo=createTexture("/storage/emulated/0/Android/image/rifle10.png");
    knife.kandao=createTexture("/storage/emulated/0/Android/image/Knife1.png");
    knife.liandao=createTexture("/storage/emulated/0/Android/image/Knife2.png");
    knife.qiaogun=createTexture("/storage/emulated/0/Android/image/Knife3.png");
    knife.nu=createTexture("/storage/emulated/0/Android/image/Knife4.png");
    //人数背景
    back1=createTexture("/storage/emulated/0/Android/image/back1.png");
    back2=createTexture("/storage/emulated/0/Android/image/back2.png");
    //盒子 空投
    Helmet.box1=createTexture("/storage/emulated/0/Android/image/box1.png");
    Helmet.box2=createTexture("/storage/emulated/0/Android/image/box2.png");
    //持枪
    hand.K98=createTexture("/storage/emulated/0/Android/image/Hand1.png");
    hand.M416=createTexture("/storage/emulated/0/Android/image/Hand2.png");
    hand.M416A4=createTexture("/storage/emulated/0/Android/image/Hand3.png");
    hand.MK14=createTexture("/storage/emulated/0/Android/image/Hand4.png");
    hand.Grozy=createTexture("/storage/emulated/0/Android/image/Hand5.png");
    hand.Scar=createTexture("/storage/emulated/0/Android/image/Hand6.png");
    hand.M24=createTexture("/storage/emulated/0/Android/image/Hand7.png");
    hand.QBZ=createTexture("/storage/emulated/0/Android/image/Hand8.png");
    hand.DP28=createTexture("/storage/emulated/0/Android/image/Hand9.png");
    hand.MK47=createTexture("/storage/emulated/0/Android/image/Hand10.png");
    hand.S12K=createTexture("/storage/emulated/0/Android/image/Hand11.png");
    hand.S1896=createTexture("/storage/emulated/0/Android/image/Hand12.png");
    hand.SKS=createTexture("/storage/emulated/0/Android/image/Hand13.png");
    hand.SLR=createTexture("/storage/emulated/0/Android/image/Hand14.png");
    hand.M762=createTexture("/storage/emulated/0/Android/image/Hand15.png");
    hand.S686=createTexture("/storage/emulated/0/Android/image/Hand16.png");
    hand.VSS=createTexture("/storage/emulated/0/Android/image/Hand17.png");
    hand.UMP9=createTexture("/storage/emulated/0/Android/image/Hand18.png");
    hand.手雷=createTexture("/storage/emulated/0/Android/image/Hand19.png");
    hand.烟雾弹=createTexture("/storage/emulated/0/Android/image/Hand20.png");
    hand.燃烧瓶=createTexture("/storage/emulated/0/Android/image/Hand21.png");
    hand.拳头=createTexture("/storage/emulated/0/Android/image/Hand22.png");
    hand.AWM=createTexture("/storage/emulated/0/Android/image/Hand23.png");
    hand.AKM=createTexture("/storage/emulated/0/Android/image/Hand24.png");
    hand.M249=createTexture("/storage/emulated/0/Android/image/Hand25.png");
    hand.QBU=createTexture("/storage/emulated/0/Android/image/Hand26.png");
    hand.Mini14=createTexture("/storage/emulated/0/Android/image/Hand27.png");
    hand.AUG=createTexture("/storage/emulated/0/Android/image/Hand28.png");
    hand.G36C=createTexture("/storage/emulated/0/Android/image/Hand29.png");
    hand.PP19=createTexture("/storage/emulated/0/Android/image/Hand30.png");
    hand.UZI=createTexture("/storage/emulated/0/Android/image/Hand31.png");
    hand.P18C=createTexture("/storage/emulated/0/Android/image/Hand32.png");
    hand.WIN94=createTexture("/storage/emulated/0/Android/image/Hand33.png");
    hand.汤姆逊=createTexture("/storage/emulated/0/Android/image/Hand34.png");
    hand.Vector=createTexture("/storage/emulated/0/Android/image/Hand35.png");
    hand.短管散弹=createTexture("/storage/emulated/0/Android/image/Hand36.png");
    hand.十字弩=createTexture("/storage/emulated/0/Android/image/Hand37.png");
}

bool GetGrenadeInfo(char* gname, char** name, ImColor* color)
{
    if(strstr(gname,"BP_Grenade_Shoulei_C")!= nullptr)//手雷
    {
        *name="小心手雷";
        *color=redColor;
        return true;
    }
    if(strstr(gname,"BP_Grenade_Smoke_C")!=nullptr)
    {
        *name="小心烟雾弹";
        *color=redColor;
        return true;
    }
    if(strstr(gname,"BP_Grenade_Burn_C")!=nullptr)
    {
        *name="小心燃烧瓶";
        *color=redColor;
        return true;
    }
    return false;
}

//获取载具
bool GetVehicleInfo(char* gname, char** name, ImTextureID * textureId, ImColor* color)
{

    if(strcmp(gname,"VH_BRDM_C")==0)
    {
        *textureId=vehicle.zhuangjiache;
        *name="裝甲車";
        *color=vehicle_color;
        return true;
    }
    if(strcmp(gname,"VH_Scooter_C")==0)
    {
        *textureId=vehicle.mianyang;
        *name="小綿羊";
        *color=vehicle_color;
        return true;
    }
    if(strcmp(gname,"VH_Motorcycle_C")==0||strcmp(gname,"VH_Motorcycle_1_C")==0)
    {
        *textureId=vehicle.motuo;
        *name="摩托車";
        *color=vehicle_color;
        return true;
    }
    if(strcmp(gname,"VH_MotorcycleCart_1_C")==0||strcmp(gname,"VH_MotorcycleCart_C")==0)
    {
        *textureId=vehicle.sanlunmotuo;
        *name="三輪摩托";
        *color=vehicle_color;
        return true;
    }
    if(strcmp(gname,"VH_Snowmobile_C")==0)
    {
        *textureId=vehicle.xuedimotuo;
        *name="雪地摩托";
        *color=vehicle_color;
        return true;
    }
    if(strcmp(gname,"BP_VH_Tuk_C")==0||strcmp(gname,"BP_VH_Tuk_1_C")==0)
    {
        *textureId=vehicle.sanlunmotuo;
        *name="三輪摩托";
        *color=vehicle_color;
        return true;
    }
    if(strstr(gname,"Buggy")!= nullptr)
    {
        *textureId=vehicle.bengbeng;
        *name="蹦蹦車";
        *color=vehicle_color;
        return true;
    }
    if(strstr(gname,"Dacia")!= nullptr)
    {
        *textureId=vehicle.jiaoche;
        *name="轎車";
        *color=vehicle_color;
        return true;
    }
    if(strstr(gname,"UAZ")!= nullptr)
    {
        *textureId=vehicle.jeep;
        *name="吉普車";
        *color=vehicle_color;
        return true;
    }
    if(strstr(gname,"_PickUp")!= nullptr)
    {
        *textureId=vehicle.wupengpika;
        *name="皮卡車";
        *color=vehicle_color;
        return true;
    }
    if(strstr(gname,"Rony")!= nullptr)
    {
        *textureId=vehicle.luonipika;
        *name="皮卡車";
        *color=vehicle_color;
        return true;
    }
    if(strstr(gname,"Mirado")!= nullptr)
    {
        *textureId=vehicle.paoche;
        *name="跑車";
        *color=vehicle_color;
        return true;
    }
    if(strstr(gname,"MiniBus")!= nullptr)
    {
        *textureId=vehicle.daba;
        *name="迷你巴士";
        *color=vehicle_color;
        return true;
    }
    if(strstr(gname,"PG117")!= nullptr)
    {
        *textureId=vehicle.kuaiting;
        *name="快艇";
        *color=vehicle_color;
        return true;
    }
    if(strstr(gname,"AquaRail")!= nullptr)
    {
        *textureId=vehicle.motuoting;
        *name="摩托艇";
        *color=vehicle_color;
        return true;
    }
	if(strstr(gname,"AirDropPlane")!= nullptr)
    {
        *textureId=vehicle.飞机;
        *name="飞机";
        *color=vehicle_color;
        return true;
    }
    return false;
}

bool GetItemInfo(char* gname,char** name, ImTextureID * textureId, ImColor* color)
{
    if(show556)
    {
        if(strcmp(gname,"BP_Ammo_556mm_Pickup_C")== 0)
        {
            *textureId=bullet.ZD_556;
            *name="5.56MM";
            *color=color_556;
            return true;
        }
    }
    if(show762)
    {
        if(strcmp(gname,"BP_Ammo_762mm_Pickup_C")== 0) 
        {
            *textureId=bullet.ZD_762;
            *name = "7.62MM";
            *color = color_762;
            return true;
        }
    }
    //刀
    if(strcmp(gname,"BP_WEP_Pan_Pickup_C")== 0)
    {
        *textureId=knife.guo;
        *name="平底锅";
        *color=rifle_color;
        return true;
    }
    //显示步枪img
    if(showRifle)
    {
        if(strcmp(gname,"BP_Pistol_Flaregun")==0)
        {
            *textureId=rifle.xinhaoqiang;
            *name="信号枪";
            *color=rifle_color;
            return true;
        }
        if(strcmp(gname,"BP_Rifle_AKM_Wrapper_C")==0)
        {
            *textureId=rifle.AK;
            *name="AKM";
            *color=rifle_color;
            return true;
        }
        if(strcmp(gname,"BP_Rifle_M416_Wrapper_C")==0)
        {
            *textureId=rifle.M416;
            *name="M416";
            *color=rifle_color;
            return true;
        }
        if(strcmp(gname,"BP_Rifle_M16A4_Wrapper_C")==0)
        {
            *textureId=rifle.M16A4;
            *name="M16A4";
            *color=rifle_color;
            return true;
        }
        if(strcmp(gname,"BP_Rifle_SCAR_Wrapper_C")==0)
        {
            *textureId=rifle.SCAR;
            *name="SCAR";
            *color=rifle_color;
            return true;
        }
        if(strcmp(gname,"BP_Rifle_QBZ_Wrapper_C")==0)
        {
            *textureId=rifle.QBZ;
            *name="QBZ";
            *color=rifle_color;
            return true;
        }
        if(strcmp(gname,"BP_Rifle_M762_Wrapper_C")==0)
        {
            *textureId=rifle.M762;
            *name="M762";
            *color=rifle_color;
            return true;
        }
        if(strcmp(gname,"BP_Rifle_Groza_Wrapper_C")==0)
        {
            *textureId=rifle.GROZA;
            *name="Groza";
            *color=rifle_color;
            return true;
        }
        if(strcmp(gname,"BP_Other_Dp-28_Wrapper_C")==0)
        {
            *textureId=rifle.DP28;
            *name="Dp-28";
            *color=rifle_color;
            return true;
        }
        if(strcmp(gname,"BP_Other_M249_Wrapper_C")==0)
        {
            *textureId=rifle.M249;
            *name="M249";
            *color=rifle_color;
            return true;
        }
        if(strcmp(gname,"BP_Sniper_QBU_Wrapper_C")==0)
        {
            *textureId=rifle.QBU;
            *name="QBU";
            *color=rifle_color;
            return true;
        }
    }
    //显示冲锋枪
    if(showSubmachine)
    {
        if(strcmp(gname,"BP_MachineGun_UMP9_Wrapper_C")==0)
        {
            *textureId=charge.UMP45;
            *name="UMP45";
            *color=submachine_color;
            return true;
        }
        if(strcmp(gname,"BP_MachineGun_TommyGun_Wrapper_C")==0)
        {
            *textureId=charge.TANGMUXUN;
            *name="汤姆逊";
            *color=submachine_color;
            return true;
        }
        if(strcmp(gname,"BP_MachineGun_Uzi_Wrapper_C")==0)
        {
            *textureId=charge.UZI;
            *name="Uzi";
            *color=submachine_color;
            return true;
        }
        if(strcmp(gname,"BP_MachineGun_Vector_Wrapper_C")==0)
        {
            *textureId=charge.VECTOR;
            *name="Vector";
            *color=submachine_color;
            return true;
        }
    }
    //显示狙击枪
    if(showSniper)
    {
        if(strcmp(gname,"BP_Sniper_Kar98k_Wrapper_C")==0)
        {
            *textureId=Sniper.K98;
            *name="Kar98k";
            *color=snipe_color;
            return true;
        }
        if(strcmp(gname,"BP_Sniper_Mini14_Wrapper_C")==0)
        {
            *textureId=Sniper.MINI14;
            *name="Mini14";
            *color=snipe_color;
            return true;
        }
        if(strcmp(gname,"BP_Sniper_SKS_Wrapper_C")==0)
        {
            *textureId=Sniper.SKS;
            *name="SKS";
            *color=snipe_color;
            return true;
        }
        if(strcmp(gname,"BP_Sniper_M24_Wrapper_C")==0)
        {
            *textureId=Sniper.M24;
            *name="M24";
            *color=snipe_color;
            return true;
        }
        if(strcmp(gname,"BP_rifle_Mk47_Wrapper_C")==0)
        {
            *textureId=Sniper.MK47;
            *name="Mk47";
            *color=snipe_color;
            return true;
        }
        if(strcmp(gname,"BP_WEP_Mk14_Pickup_C")==0)
        {
            *textureId=Sniper.MK14;
            *name="MK14";
            *color=snipe_color;
            return true;
        }
        if(strcmp(gname,"BP_Sniper_AWM_Wrapper_C")==0)
        {
            *textureId=Sniper.AWM;
            *name="AWM";
            *color=snipe_color;
            return true;
        }
        if(strcmp(gname,"BP_Sniper_SLR_Wrapper_C")==0)
        {
            *textureId=Sniper.SLR;
            *name="SLR";
            *color=snipe_color;
            return true;
        }
    }
    //倍镜
    if(showMirror)
    {
        if(strcmp(gname,"BP_MZJ_8X_Pickup_C")==0)
        {
            *textureId=part.babei;
            *name="8x镜";
            *color=mirror_color;
            return true;
        }
        if(strcmp(gname,"BP_MZJ_6X_Pickup_C")==0)
        {
            *textureId=part.liubei;
            *name="6x镜";
            *color=mirror_color;
            return true;
        }
        if(strcmp(gname,"BP_MZJ_4X_Pickup_C")==0)
        {
            *textureId=part.sibei;
            *name="4x镜";
            *color=mirror_color;
            return true;
        }
        if(strcmp(gname,"BP_MZJ_3X_Pickup_C")==0)
        {
            *textureId=part.sanbei;
            *name="3x镜";
            *color=mirror_color;
            return true;
        }
        if(strcmp(gname,"BP_MZJ_2X_Pickup_C")==0)
        {
            *textureId=part.erbei;
            *name="2x镜";
            *color=mirror_color;
            return true;
        }
        if(strcmp(gname,"BP_MZJ_HD_Pickup_C")==0)
        {
            *textureId=part.hongdian;
            *name="红点";
            *color=otherparts_color;
            return true;
        }
        if(strcmp(gname,"BP_MZJ_QX_Pickup_C")==0)
        {
            *textureId=part.quanxi;
            *name="全息";
            *color=otherparts_color;
            return true;
        }
    }
    //扩容
    if(showExpansion)
    {
        if(strcmp(gname,"BP_DJ_Large_EQ_Pickup_C")==0)
        {
            *textureId=parts.bq_kuaikuo;
            *name="(步枪)快速扩容";
            *color=expansion_color;
            return true;
        }
        if(strcmp(gname,"BP_DJ_Large_E_Pickup_C")==0)
        {
            *textureId=parts.bq_kuorong;
            *name="(步枪)扩容";
            *color=expansion_color;
            return true;
        }
        if(strcmp(gname,"BP_DJ_Sniper_EQ_Pickup_C")==0)
        {
            *textureId=parts.jj_kuaikuo;
            *name="(狙)快速扩容";
            *color=mirror_color;
            return true;
        }
        if(strcmp(gname,"BP_DJ_Sniper_E_Pickup_C")==0)
        {
            *textureId=parts.jj_kuorong;
            *name="(狙)扩容";
            *color=mirror_color;
            return true;
        }
    }
    //其他配件
    if(showOtherParts)
    {
        if(strcmp(gname,"BP_QK_Large_Suppressor_Pickup_C")==0)
        {
            *textureId=parts.bq_xiaoyinqi;
            *name="(步枪)消音器";
            *color=otherparts_color;
            return true;
        }
        if(strcmp(gname,"BP_QK_Sniper_Suppressor_Pickup_C")==0)
        {
            *textureId=parts.jj_xiaoyinqi;
            *name="(狙)消音器";
            *color=otherparts_color;
            return true;
        }
        if(strcmp(gname,"BP_QT_Sniper_Pickup_C")==0)
        {
            *name="托腮板";
            *color=otherparts_color;
            return true;
        }
        if(strcmp(gname,"BP_QK_Large_Compensator_Pickup_C")==0)
        {
            *textureId=parts.bq_buchang;
            *name="(步枪)补偿器";
            *color=otherparts_color;
            return true;
        }
        if(strcmp(gname,"BP_QK_Sniper_Compensator_Pickup_C")==0)
        {
            *textureId=parts.jj_buchang;
            *name="(狙)补偿器";
            *color=otherparts_color;
            return true;
        }
        if(strcmp(gname,"BP_WB_Vertical_Pickup_C")==0)
        {
            *textureId=parts.chuizhiwoba;
            *name="垂直握把";
            *color=otherparts_color;
            return true;
        }
        if(strcmp(gname,"BP_QT_A_Pickup_C")==0)
        {
            *name="枪托";
            *color=otherparts_color;
            return true;
        }
    }
    //药品显示
    if(showDrug)
    {
        if(strcmp(gname,"Injection_Pickup_C")==0)
        {
            *textureId=drug.shenshangxiansu;
            *name="肾上腺素";
            *color=drug_color;
            return true;
        }
        if(strcmp(gname,"Firstaid_Pickup_C")==0)
        {
            *textureId=drug.jijiubao;
            *name="急救包";
            *color=drug_color;
            return true;
        }
        if(strcmp(gname,"FirstAidbox_Pickup_C")==0)
        {
            *textureId=drug.yiliaoxiang;
            *name="医疗箱";
            *color=drug_color;
            return true;
        }
        if(strcmp(gname,"Pills_Pickup_C")==0)
        {
            *textureId=drug.zhitengyao;
            *name="止痛药";
            *color=drug_color;
            return true;
        }
        if(strcmp(gname,"Drink_Pickup_C")==0)
        {
            *textureId=drug.yinliao;
            *name="饮料";
            *color=drug_color;
            return true;
        }
        if(strcmp(gname,"Bandage_Pickup_C")==0)
        {
            *textureId=drug.bengdai;
            *name="绷带";
            *color=drug_color;
            return true;
        }
    }
    //甲和头盔
    if(showArmor)
    {
        if(strcmp(gname,"PickUp_BP_Helmet_Lv3_C")==0)
        {
            *textureId=Helmet.sanjitou;
            *name="三级头";
            *color=armor_color;
            return true;
        }        
		if(strcmp(gname,"PickUpListWrapperActor")==0)
        {
            *textureId=Helmet.box1;
            *name="盒子";
            *color=armor_color;
            return true;
        }
        if(strcmp(gname,"PlayerDeadInventoryBox")==0)
        {
            *textureId=Helmet.box1;
            *name="盒子";
            *color=armor_color;
            return true;
        }
        if(strcmp(gname,"BP_AirDropBox_C")==0)
        {
            *textureId=Helmet.box2;
            *name="空投";
            *color=armor_color;
            return true;
        }
        if(strcmp(gname,"PickUp_BP_Armor_Lv3_C")==0)
        {
            *textureId=Helmet.sanjijia;
            *name="三级甲";
            *color=armor_color;
            return true;
        }
        if(strcmp(gname,"PickUp_BP_Bag_Lv3_B_C")==0 || strcmp(gname,"PickUp_BP_Bag_Lv3_A_C")==0 || strcmp(gname,"PickUp_BP_Bag_Lv3_C")==0 )
        {
            *textureId=Helmet.sanjibao;
            *name="三级包";
            *color=armor_color;
            return true;
        }
        if(strcmp(gname,"PickUp_BP_Helmet_Lv2_C")==0)
        {
            *textureId=Helmet.erjitou;
            *name="二级头";
            *color=armor_color;
            return true;
        }
        if(strcmp(gname,"PickUp_BP_Armor_Lv2_C")==0)
        {
            *textureId=Helmet.erjijia;
            *name="二级甲";
            *color=armor_color;
            return true;
        }
        if(strcmp(gname,"PickUp_BP_Bag_Lv2_C")==0)
        {
            *textureId=Helmet.erjibao;
            *name="二级包";
            *color=armor_color;
            return true;
        }
    }
    return false;
}
*/

ImColor 浅蓝 = ImColor(ImVec4(36/255.f, 249/255.f, 217/255.f, 255/255.f));
ImColor 蓝色 = ImColor(ImVec4(170/255.f, 203/255.f, 244/255.f, 0.95f));
ImColor 白色 = ImColor(ImVec4(255/255.f, 255/255.f, 258/255.f, 0.95f));
ImColor 浅粉 = ImColor(ImVec4(255/255.f, 200/255.f, 250/255.f, 0.95f));
ImColor 黑色 = ImColor(ImVec4(0/255.f, 0/255.f, 0/255.f, 0.7f));
ImColor 半黑 = ImColor(ImVec4(0/255.f, 0/255.f, 0/255.f, 0.18f));
ImColor 血色 = ImColor(ImVec4(0/255.f, 249/255.f, 0/255.f, 0.35f));
ImColor 红色 = ImColor(ImVec4(233/255.f, 55/255.f, 51/255.f, 0.95f));
ImColor 绿色 = ImColor(ImVec4(50/255.f, 222/215.f, 50/255.f, 0.95f));
ImColor 黄色 = ImColor(ImVec4(255/255.f, 255/255.f, 0/255.f, 0.95f));
ImColor 橘黄 = ImColor(ImVec4(255/255.f, 150/255.f, 30/255.f, 0.95f));
ImColor 粉红 = ImColor(ImVec4(220/255.f, 108/255.f, 1202/255.f, 0.95f));
ImColor 紫色 = ImColor(ImVec4(169/255.f, 120/255.f, 223/255.f, 0.95f));

/*
bool GetBoxItem(int id, char** name, ImColor* color)
{
    switch (id)
    {
        //子弹
        case 306002:
            *name=".50mm";
            *color = 绿色;
            return true;
        break;
        case 303001:
            *name="5.56mm";
            *color = 绿色;
            return true;
        break;
        case 3030013:
            *name="[抛光]5.56mm";
            *color = 紫色;
            return true;
        break;
        case 3030014:
            *name="[高爆]5.56mm";
            *color = 粉红;
            return true;
        break;
        case 3030015:
            *name="[燃烧]5.56mm";
            *color = 红色;
            return true;
        break;
        case 302001:
            *name="7.62mm";
            *color = 绿色;
            return true;
        break;
        case 3020013:
            *name="[抛光]7.62mm";
            *color = 紫色;
            return true;
        break;
        case 3020014:
            *name="[高爆]7.62mm";
            *color = 粉红;
            return true;
        break;
        case 3020015:
            *name="[燃烧]7.62mm";
            *color = 红色;
            return true;
        break;
        case 301001:
            *name="9mm";
            *color = 绿色;
            return true;
        break;
        case 305001:
            *name=".45mm";
            *color = 绿色;
            return true;
        break;
        case 304001:
            *name="12号霰弹";
            *color = 绿色;
            return true;
        break;
        case 301002:
            *name="5.7mm";
            *color = 绿色;
            return true;
        break;
        case 307001:
            *name="弩箭";
            *color = 绿色;
            return true;
        break;
        case 900006:
            *name=".300马格南";
            *color = 绿色;
            return true;
        break;
        
        
        //恢复品
        case 601004:
            *name="绷带";
            *color = 绿色;
            return true;
        break;
        case 601005:
            *name="急救包";
            *color = 绿色;
            return true;
        break;
        case 601006:
            *name="医疗箱";
            *color = 绿色;
            return true;
        break;
        case 601001:
            *name="能量饮料";
            *color = 绿色;
            return true;
        break;
        case 601002:
            *name="肾上腺素";
            *color = 绿色;
            return true;
        break;
        case 601003:
            *name="止痛药";
            *color = 绿色;
            return true;
        break;
        case 603004:
            *name="燃料";
            *color = 绿色;
            return true;
        break;
        
        
        //近战
        case 108003:
            *name="镰刀";
            *color =黄色;
            return true;
        break;
        case 108002:
            *name="撬棍";
            *color = 黄色;
            return true;
        break;
        case 108001:
            *name="大砍刀";
            *color = 黄色;
            return true;
        break;
        case 108004:
            *name="平底锅";
            *color = 橘黄;
            return true;
        break;
        
        
        case 204011:
            *name="[步枪]扩容弹夹";
            *color = 蓝色;
            return true;
        break;
        case 204013:
            *name="[步枪]快速扩容弹夹";
            *color = 蓝色;
            return true;
        break;
        case 204012:
            *name="[步枪]快速弹夹";
            *color = 蓝色;
            return true;
        break;
        case 204006:
            *name="[冲锋]快速扩容弹夹";
            *color = 蓝色;
            return true;
        break;
        case 204004:
            *name="[冲锋]扩容弹夹";
            *color = 蓝色;
            return true;
        break;
        case 204005:
            *name="[冲锋]快速弹夹";
            *color = 蓝色;
            return true;
        break;
        case 204009:
            *name="[狙]快速扩容弹夹";
            *color = 蓝色;
            return true;
        break;
        case 204008:
            *name="[狙]扩容弹夹";
            *color = 蓝色;
            return true;
        break;
        case 204007:
            *name="[狙]快速弹夹";
            *color = 蓝色;
            return true;
        break;
        case 201012:
            *name="鸭嘴枪口";
            *color = 蓝色;
            return true;
        break;
        case 201001:
            *name="收束器";
            *color = 蓝色;
            return true;
        break;
        case 201003:
            *name="[狙]补偿器";
            *color = 蓝色;
            return true;
        break;
        case 201005:
            *name="[狙]消焰器";
            *color = 蓝色;
            return true;
        break;
        case 201007:
            *name="[狙]消音器";
            *color = 蓝色;
            return true;
        break;
        case 201009:
            *name="[步枪]补偿器";
            *color = 蓝色;
            return true;
        break;
        case 201010:
            *name="[步枪]消焰器";
            *color = 蓝色;
            return true;
        break;
        case 201011:
            *name="[步枪]消音器";
            *color = 蓝色;
            return true;
        break;
        case 201002:
            *name="[冲锋]补偿器";
            *color = 蓝色;
            return true;
        break;
        case 201004:
            *name="[冲锋]消焰器";
            *color = 蓝色;
            return true;
        break;
        case 201006:
            *name="[冲锋]消音器";
            *color = 蓝色;
            return true;
        break;
        case 202006:
            *name="拇指握把";
            *color = 蓝色;
            return true;
        break;
        case 202001:
            *name="直角前握把";
            *color = 蓝色;
            return true;
        break;
        case 202002:
            *name="垂直握把";
            *color = 蓝色;
            return true;
        break;
        case 202004:
            *name="轻型握把";
            *color = 蓝色;
            return true;
        break;
        case 202005:
            *name="半截式握把";
            *color = 蓝色;
            return true;
        break;
        case 205002:
            *name="[步枪]战术枪托";
            *color = 蓝色;
            return true;
        break;
        case 204010:
            *name="子弹带";
            *color = 蓝色;
            return true;
        break;
        case 204014:
            *name="子弹带";
            *color = 蓝色;
            return true;
        break;
        case 205001:
            *name="[冲锋]UZI枪托";
            *color = 蓝色;
            return true;
        break;
        case 205003:
            *name="[狙]托腮板";
            *color = 蓝色;
            return true;
        break;
        case 205004:
            *name="[弓]箭袋";
            *color = 蓝色;
            return true;
        break;
        case 203001:
            *name="红点瞄准镜";
            *color = 蓝色;
            return true;
        break;
        case 203002:
            *name="全息瞄准镜";
            *color = 蓝色;
            return true;
        break;
        case 203003:
            *name="2倍瞄准镜";
            *color = 蓝色;
            return true;
        break;
        case 203014:
            *name="3倍瞄准镜";
            *color = 蓝色;
            return true;
        break;
        case 203004:
            *name="4倍瞄准镜";
            *color = 蓝色;
            return true;
        break;
        case 203015:
            *name="6倍瞄准镜";
            *color = 蓝色;
            return true;
        break;
        case 203005:
            *name="8倍瞄准镜";
            *color = 蓝色;
            return true;
        break;
        case 203018:
            *name="侧边瞄准镜";
            *color = 蓝色;
            return true;
        break;
        case 503107:
            *name="[独眼蛇]四级护甲";
            *color = 紫色;
            return true;
        break;
        case 503108:
            *name="[独眼蛇]五级护甲";
            *color = 粉红;
            return true;
        break;
        case 503109:
            *name="[独眼蛇]六级护甲";
            *color = 红色;
            return true;
        break;
        case 503110:
            *name="[钢铁阵线]四级护甲";
            *color = 紫色;
            return true;
        break;
        case 503111:
            *name="[钢铁阵线]五级护甲";
            *color = 粉红;
            return true;
        break;
        case 503112:
            *name="[钢铁阵线]六级护甲";
            *color = 红色;
            return true;
        break;
        case 502007:
            *name="[独眼蛇]四级头";
            *color = 紫色;
            return true;
        break;
        case 502008:
            *name="[独眼蛇]五级头";
            *color = 粉红;
            return true;
        break;
        case 502009:
            *name="[独眼蛇]六级头";
            *color = 红色;
            return true;
        break;
        case 502010:
            *name="[钢铁阵线]四级头";
            *color = 紫色;
            return true;
        break;
        case 502011:
            *name="[钢铁阵线]五级头";
            *color = 粉红;
            return true;
        break;
        case 502012:
            *name="[钢铁阵线]六级头";
            *color = 红色;
            return true;
        break;
        case 502106:
            *name="六级头";
            *color = 红色;
            return true;
        break;
        case 502105:
            *name="五级甲";
            *color = 粉红;
            return true;
        break;
        case 502104:
            *name="四级甲";
            *color = 紫色;
            return true;
        break;
        case 502003:
            *name="三级头";
            *color = 绿色;
            return true;
        break;
        case 502002:
            *name="二级头";
            *color = 绿色;
            return true;
        break;
        case 502001:
            *name="一级头";
            *color = 绿色;
            return true;
        break;
        case 502004:
            *name="一级头";
            *color = 绿色;
            return true;
        break;
        case 503001:
            *name="一级甲";
            *color = 绿色;
            return true;
        break;
        case 503002:
            *name="二级甲";
            *color = 绿色;
            return true;
        break;
        case 503003:
            *name="三级甲";
            *color = 绿色;
            return true;
        break;
        case 503104:
            *name="四级甲";
            *color = 紫色;
            return true;
        break;
        case 503105:
            *name="五级甲";
            *color = 粉红;
            return true;
        break;
        case 503106:
            *name="六级甲";
            *color = 红色;
            return true;
        break;
        case 403045:
            *name="吉利服";
            *color = 绿色;
            return true;
        break;
        case 501001:
            *name="一级背包";
            *color = 绿色;
            return true;
        break;
        case 501004:
            *name="一级背包";
            *color = 绿色;
            return true;
        break;
        case 501002:
            *name="二级背包";
            *color = 绿色;
            return true;
        break;
        case 501005:
            *name="二级背包";
            *color = 绿色;
            return true;
        break;
        case 501006:
            *name="三级背包";
            *color = 绿色;
            return true;
        break;
        case 501104:
            *name="四级背包";
            *color = 紫色;
            return true;
        break;
        case 501105:
            *name="五级背包";
            *color = 红色;
            return true;
        break;
        case 501106:
            *name="六级背包";
            *color = 红色;
            return true;
        break;
        case 602004:
            *name="破片手榴弹";
            *color = 绿色;
            return true;
        break;
        case 602002:
            *name="烟雾弹";
            *color = 绿色;
            return true;
        break;
        case 602001:
            *name="震撼弹";
            *color = 绿色;
            return true;
        break;
        case 106010:
            *name="沙漠之鹰";
            *color = 绿色;
            return true;
        break;
        case 106008:
            *name="蝎氏手枪";
            *color = 绿色;
            return true;
        break;
        case 106001:
            *name="[手枪]P92";
            *color = 绿色;
            return true;
        break;
        case 106002:
            *name="[手枪]P1911";
            *color = 绿色;
            return true;
        break;
        case 106004:
            *name="[手枪]P18C";
            *color = 绿色;
            return true;
        break;
        case 106005:
            *name="[手枪]R45";
            *color = 绿色;
            return true;
        break;
        case 106003:
            *name="[手枪]R1895";
            *color = 绿色;
            return true;
        break;
        case 106006:
            *name="短管霰弹枪";
            *color = 绿色;
            return true;
        break;
        case 105001:
            *name="[机枪]M249";
            *color = 绿色;
            return true;
        break;
        case 105002:
            *name="[机枪]DP-28";
            *color = 绿色;
            return true;
        break;
        case 105010:
            *name="[机枪]MG3";
            *color = 绿色;
            return true;
        break;
        case 1050104:
            *name="[改进][机枪]MG3";
            *color = 紫色;
            return true;
        break;
        case 1050105:
            *name="[精致][机枪]MG3";
            *color = 粉红;
            return true;
        break;
        case 101008:
            *name="[步枪]M762";
            *color = 绿色;
            return true;
        break;
        case 1010084:
            *name="[改进][步枪]M762";
            *color = 紫色;
            return true;
        break;
        case 1010085:
            *name="[精致][步枪]M762";
            *color = 粉红;
            return true;
        break;
        case 101001:
            *name="[步枪]AKM";
            *color = 绿色;
            return true;
        break;
        case 1010014:
            *name="[改进][步枪]AKM";
            *color = 紫色;
            return true;
        break;
        case 1010015:
            *name="[精致][步枪]AKM";
            *color = 粉红;
            return true;
        break;
        case 101004:
            *name="[步枪]M416";
            *color = 绿色;
            return true;
        break;
        case 1010044:
            *name="[改进][步枪]M416";
            *color = 紫色;
            return true;
        break;
        case 1010045:
            *name="[精致][步枪]M416";
            *color = 粉红;
            return true;
        break;
        case 101003:
            *name="[步枪]SCAR-L";
            *color = 绿色;
            return true;
        break;
        case 101002:
            *name="[步枪]M16A4";
            *color = 绿色;
            return true;
        break;
        case 101009:
            *name="[步枪]Mk47 Mutant";
            *color = 绿色;
            return true;
        break;
        case 101006:
            *name="[步枪]AUG";
            *color = 绿色;
            return true;
        break;
        case 101005:
            *name="[步枪]Groza";
            *color = 绿色;
            return true;
        break;
        case 1010054:
            *name="[改进][步枪]Groza";
            *color = 紫色;
            return true;
        break;
        case 1010055:
            *name="[精致][步枪]Groza";
            *color = 粉红;
            return true;
        break;
        case 101010:
            *name="[步枪]G36C";
            *color = 绿色;
            return true;
        break;
        case 101007:
            *name="[步枪]QBZ";
            *color = 绿色;
            return true;
        break;
        case 101011:
            *name="[步枪]AC-VAL";
            *color = 绿色;
            return true;
        break;
        case 103001:
            *name="[狙]Kar98k";
            *color = 绿色;
            return true;
        break;
        case 103002:
            *name="[狙]M24";
            *color = 绿色;
            return true;
        break;
        case 103003:
            *name="[狙]AWM";
            *color = 绿色;
            return true;
        break;
        case 103011:
            *name="[狙]莫辛纳甘";
            *color = 绿色;
            return true;
        break;
        case 103008:
            *name="[狙]WIN94";
            *color = 绿色;
            return true;
        break;
        case 103012:
            *name="[狙]AMR";
            *color = 绿色;
            return true;
        break;
        case 107001:
            *name="[弓]弓弩";
            *color = 绿色;
            return true;
        break;
        case 103004:
            *name="[狙]SKS";
            *color = 绿色;
            return true;
        break;
        case 103007:
            *name="[狙]Mk14";
            *color = 绿色;
            return true;
        break;
        case 1030074:
            *name="[改进][狙]Mk14";
            *color = 紫色;
            return true;
        break;
        case 1030075:
            *name="[精致][狙]Mk14";
            *color = 粉红;
            return true;
        break;
        case 103009:
            *name="[狙]SLR";
            *color = 绿色;
            return true;
        break;
        case 103005:
            *name="[狙]VSS";
            *color = 绿色;
            return true;
        break;
        case 103006:
            *name="[狙]Mini14";
            *color = 绿色;
            return true;
        break;
        case 103010:
            *name="[狙]QBU";
            *color = 绿色;
            return true;
        break;
        case 104001:
            *name="[喷子]S686";
            *color = 绿色;
            return true;
        break;
        case 104002:
            *name="[喷子]S1897";
            *color = 绿色;
            return true;
        break;
        case 104003:
            *name="[喷子]S12K";
            *color = 绿色;
            return true;
        break;
        case 104004:
            *name="[喷子]DBS";
            *color = 绿色;
            return true;
        break;
        case 104100:
            *name="[喷子]SPAS-12";
            *color = 绿色;
            return true;
        break;
        case 102001:
            *name="[冲锋]UZI";
            *color = 绿色;
            return true;
        break;
        case 102003:
            *name="[冲锋]Vector";
            *color = 绿色;
            return true;
        break;
        case 100103:
            *name="[冲锋]PP-19";
            *color = 绿色;
            return true;
        break;
        case 102007:
            *name="[冲锋]MP5K";
            *color = 绿色;
            return true;
        break;
        case 102002:
            *name="[冲锋]UMP-45";
            *color = 绿色;
            return true;
        break;
        case 102004:
            *name="[冲锋]汤姆逊";
            *color = 绿色;
            return true;
        break;
        case 102105:
            *name="[冲锋]P90";
            *color = 绿色;
            return true;
        break;
        case 102005:
            *name="[冲锋]野牛";
            *color = 绿色;
            return true;
        break;
        default:
            return false;
     }
}


bool GetHandInfo(char* gname,char** name)
{
    if(strstr(gname,"WEP_Pan_C")!= nullptr)
    {
        *name="拳头";
        return false;
    }
    if(strstr(gname,"CrossBow")!= nullptr)
    {
        *name="十字弩";
        return true; 
    }
    if(strstr(gname,"Groza")!= nullptr)
    {
        *name="狗砸";
        return true;
    }
    if(strstr(gname,"SKS")!= nullptr)
    {
        *name="SKS";
        return true;
    }
    if(strstr(gname,"M249")!= nullptr)
    {
        *name="M249";
        return true;
    }
    if(strstr(gname,"DP28")!= nullptr)
    {
        *name="DP28";
        return true;
    }
    if(strstr(gname,"MG3")!= nullptr)
    {
        *name="MG3";
        return true;
    }
    if(strstr(gname,"Kar98k")!= nullptr)
    {
        *name="Kar98k";
        return true;
    }
    if(strstr(gname,"R1895")!= nullptr)
    {
        *name="R1895";
        return true;
    }
    if(strstr(gname,"R45")!= nullptr)
    {
        *name="R45";
        return true;
    }if(strstr(gname,"AKM")!= nullptr)
    {
        *name="AKM";
        return true;
    }
    if(strstr(gname,"AUG")!= nullptr)
    {
        *name="AUG";
        return true;
    }
    if(strstr(gname,"Mini14")!= nullptr)
    {
        *name="Mini14";
        return true;
    }
    if(strstr(gname,"M16A4")!= nullptr)
    {
        *name="M16A4";
        return true;
    }
    if(strstr(gname,"SCAR")!= nullptr)
    {
        *name="SCAR";
        return true;
    }
    if(strstr(gname,"WIN94")!= nullptr)
    {
        *name="WIN94";
        return true;
    }
    if(strstr(gname,"UZI")!= nullptr)
    {
        *name="UZI";
        return true;
    }
    if(strstr(gname,"TommyGun")!= nullptr)
    {
        *name="汤姆逊";
        return true;
    }
    if(strstr(gname,"Vector")!= nullptr)
    {
        *name="Vector";
        return true;
    }
    if(strstr(gname,"UMP9")!= nullptr)
    {
        *name="UMP9";
        return true;
    }
    if(strstr(gname,"VSS")!= nullptr)
    {
        *name="VSS";
        return true;
    }
    if(strstr(gname,"M416")!= nullptr)
    {
        *name="M416";
        return true;
    }
    if(strstr(gname,"MK14")!= nullptr)
    {
        *name="MK14";
        return true;
    }
    if(strstr(gname,"SLR")!= nullptr)
    {
        *name="SLR";
        return true;
    }
    if(strstr(gname,"Mk47")!= nullptr)
    {
        *name="[狙]Mk47";
        return true;
    }
    if(strstr(gname,"M762")!= nullptr)
    {
        *name="[步枪]M762";
        return true;
    }
    if(strstr(gname,"QBZ")!= nullptr)
    {
        *name="[步枪]QBZ";
        return true;
    }
    if(strstr(gname,"QBU")!= nullptr)
    {
        *name="[狙]QBU";
        return true;
    }
    if(strstr(gname,"S1897")!= nullptr)
    {
        *name="[喷]S1897";
        return true;
    }
    if(strstr(gname,"S12K")!= nullptr)
    {
        *name="[喷]S12K";
        return true;
    }
    if(strstr(gname,"S686")!= nullptr)
    {
        *name="[喷]S686";
        return true;
    }
    if(strstr(gname,"FlareGun")!= nullptr)
    {
        *name="[喷]短管霰弹";
        return true;
    }
    if(strstr(gname,"Shoulei")!= nullptr)
    {
        *name="[投]手雷";
        return true;
    }
    if(strstr(gname,"Burn")!= nullptr)
    {
        *name="[投]燃烧瓶";
        return true;
    }
    if(strstr(gname,"Smoke")!= nullptr)
    {
        *name="[投]烟雾弹";
        return true;
    }
    if(strstr(gname,"AWM")!= nullptr)
    {
        *name="[狙]AWM";
        return true;
    }
    if(strstr(gname,"M24")!= nullptr)
    {
        *name="[狙]M24";
        return true;
    }
    if(strstr(gname,"UMP9")!= nullptr)
    {
        *name="[冲锋]UMP9";
        return true;
    }
    return false;
}
*/
#endif
