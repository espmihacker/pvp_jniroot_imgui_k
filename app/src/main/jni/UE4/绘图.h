#ifndef MY_LICCSU_HT
#define MY_LICCSU_HT

#include "读写.h"
#include "图片配置.h"
#include "Tool.h"
#include "ui.h"
#include <set>

#define ZOOM 3.33333333
typedef uintptr_t Ptr;
typedef unsigned long long Pointer;
ImDrawList *draw;


std::string getString() {
    return debugStr;
}

/*
void setDebugStr()
{
    debugStr = "";
}
int 随机颜色(){
     int 红;
     int 绿;
     int 蓝;
     int 颜色=70;
     红=(0+255*rand());
     绿=(0+255*rand());
     蓝=(0+255*rand());
     if(sizeof(红)==1) 红=红+红;
     if(sizeof(绿)==1) 绿=绿+绿;
     if(sizeof(蓝)==1) 蓝=蓝+蓝;
     return 颜色+红+绿+蓝;
}
int 颜色数组[10];   // 必须分配空间
void 颜色初始化(){
    srand((unsigned)time(NULL));
    for(int 数量=0;数量<10;数量++){
        颜色数组[数量]=随机颜色();
    }
}

int 获取颜色(int 预号){
    if(颜色数组[预号-1]==NULL)
        return 88303030;
    else
        return 颜色数组[预号-1];
}

int 队伍颜色(int dw){
    if(dw<=10 && 队伍>dw)
        return 获取颜色(dw);
    else
        return 3411641396;
}
*/

ImVec4 Colmonster = ImVec4(255 / 255.f, 150 / 255.f, 30 / 255.f, 0.95f);//橘黄
ImVec4 Colline = ImVec4(169 / 255.f, 120 / 255.f, 223 / 255.f, 0.95f);//紫色
ImVec4 Colblood1 = ImVec4(50 / 255.f, 222 / 215.f, 50 / 255.f, 0.95f);//绿色
ImVec4 Colblood2 = ImVec4(255 / 255.f, 255 / 255.f, 0 / 255.f, 0.95f);//黄色
ImVec4 Colblood3 = ImVec4(233 / 255.f, 55 / 255.f, 51 / 255.f, 0.95f);//红色
ImVec4 Colinfor = ImVec4(255 / 255.f, 255 / 255.f, 0 / 255.f, 255 / 255.f);//黄色

void skill_draw(int role_id, int role_cnt, int skill_cnt, char *text, ImColor color, int per_hp,
                ImColor blood_color) {
    draw->AddImage(getHeroTexture(role_id), {750 + 75 * role_cnt - 30, 10},
                   {750 + 75 * role_cnt + 30, 70});
    draw->AddCircle({750 + 75 * role_cnt, 40}, 30, redColor, 0, 3);
    draw->AddRectFilled({750 + 75 * role_cnt - 30, 70}, {750 + 75 * role_cnt + 30, 75}, 半黑, 1.0f);
    draw->AddRectFilled({750 + 75 * role_cnt - 30, 70},
                        {750 + 75 * role_cnt - 30 + 60 * per_hp / 100, 75}, blood_color, 1.0f);
    绘制加粗文本(30, 750 + 75 * role_cnt - 15, 90 + 40 * skill_cnt, color, 黑色, text);
}

int 地图上下, 地图左右, 实体上下, 实体左右;
ImColor blood_color;
ReadSyscall R;

int 绘制() {
    ImColor Monstercol = ImColor(Colmonster);
    ImColor Linecol = ImColor(Colline);
    ImColor Blood1col = ImColor(Colblood1);
    ImColor Blood2col = ImColor(Colblood2);
    ImColor Blood3col = ImColor(Colblood3);
    ImColor Inforcol = ImColor(Colinfor);

    static float tpf = 0.0f;
    static float fps = 0.0f;

    if (tpf < 100.0f) {
        tpf += 100.0f / ImGui::GetIO().Framerate;
    } else {
        tpf = 0.0f;
        fps = ImGui::GetIO().Framerate;
    }

    draw = ImGui::GetBackgroundDrawList();

    sprintf(extra, "FPS:%.1f", fps);
    if (fps > 70)
        绘制加粗文本(36, 120, 460, 绿色, 黑色, extra);
    else if (fps > 40)
        绘制加粗文本(36, 120, 460, 黄色, 黑色, extra);
    else
        绘制加粗文本(36, 120, 460, 红色, 黑色, extra);

    try {
        uint64_t heroBase = R.GetPointer(libGameCore, 0x392A930);
        uint64_t buffBase = R.GetPointer(libGameCore, 0x392A260);
        uint64_t laneBase = R.GetPointer(libGameCore, 0x381E1B0);
        uint64_t matrixBase = R.GetPointer(libil2cpp, 0xAA5E4F0);

        int 开局判断 = R.ReadZZ<int>(libGameCore + 0x3AB7940);
        int 人物数量 = R.ReadZZ<int>(R.GetPointer(libGameCore, 0x381E1B0) + 0x244); // S31未更新
        // if (开局判断 != 1 || 人物数量 <= 0) return 0;
		if (开局判断 != 1) return 0;

        //debugStr = str_format("人数:%d", 人物数量);
        if (!玖.开关.总开关) {
            return 0;
        }
//libil2cpp.so:bss+0x108A4F0+0x130+0xA0+0xA0+0x10+0xC0
        float matrix[16] = {0.0f};
        uint64_t matrixAddr = R.GetPointer(matrixBase, 0x130, 0xA0, 0xA0, 0x10, 0xC0, 0x0);
        R.ReadZZ(matrixAddr, matrix, sizeof(float) * 16);

        int 红蓝判断;
        int myTeam;

        // if (matrix[0] > 0.0f) {
        if (玖.设置.阵营 == 1) {
            红蓝判断 = 1;
            myTeam = 1;
        } else {
            红蓝判断 = -1;
            myTeam = 2;
        }

        if (玖.功能.野怪) {
            uint64_t buffAddr = R.GetPointer(buffBase, 0x3A8, 0x88, 0x120, 0x0);
            for (char i = 0; i < 30; ++i) {
                uint64_t buffArray = R.GetPointer(buffAddr, i * 0x18);
                uint64_t buffPosAddr = 0;
                int buffId = R.ReadZZ<int>(buffArray + 0xC0);
                int buffCd = R.ReadZZ<int>(buffArray + 0x238);
                int buffTeam = 0;
                int buffCurHp = 0;
                int buffMaxHp = 60000;
                int buffPerHp = 70000;
                ImColor buffHpColor;
                if (!(buffId > 6000 && buffCd >= 0)) continue;
                sprintf(extra, "%d", buffCd / 1000);
                switch (buffId) {
                    case 6008://狼
                        if (!玖.功能.计时.小怪) break;
                        buffTeam = R.ReadZZ<int>(buffArray + 0x2B0) > 0 ? -1 : 1;
                        if (buffCd == 70000) {
                            buffCurHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0xA0)); // S31未更新
                            buffMaxHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0x118)); // S31未更新
                            if (buffMaxHp <= 0) break;
                            buffPerHp = 100 * buffCurHp / buffMaxHp;
                            if (buffPerHp >= 60) {
                                buffHpColor = Blood1col;
                            } else if (buffPerHp >= 20) {
                                buffHpColor = Blood2col;
                            } else {
                                buffHpColor = Blood3col;
                            }
                            draw->AddCircleFilled({292 - 红蓝判断 * buffTeam * ZOOM * 30170 / 1000 +
                                                   玖.设置.地图左右,
                                                   170 + 红蓝判断 * buffTeam * ZOOM * 9828 / 1000 +
                                                   玖.设置.地图上下}, 5, yellowColor);

                        } else
                            绘制加粗文本(16, 292 - 红蓝判断 * buffTeam * ZOOM * 30170 / 1000 - 8 +
                                             玖.设置.地图左右,
                                         170 + 红蓝判断 * buffTeam * ZOOM * 9828 / 1000 - 8 +
                                         玖.设置.地图上下, yellowColor, 黑色, extra);
                        break;
                    case 6010://蓝
                        if (!玖.功能.计时.BUFF) break;
                        buffTeam = R.ReadZZ<int>(buffArray + 0x2B0) > 0 ? -1 : 1;
                        if (buffCd == 90000) {
                            buffCurHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0xA0));
                            buffMaxHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0xA8));
                            if (buffMaxHp <= 0) break;
                            buffPerHp = 100 * buffCurHp / buffMaxHp;
                            if (buffPerHp >= 60) {
                                buffHpColor = Blood1col;
                            } else if (buffPerHp >= 20) {
                                buffHpColor = Blood2col;
                            } else {
                                buffHpColor = Blood3col;
                            }
                            draw->AddCircleFilled({292 - 红蓝判断 * buffTeam * ZOOM * 23120 / 1000 +
                                                   玖.设置.地图左右,
                                                   170 - 红蓝判断 * buffTeam * ZOOM * 1230 / 1000 +
                                                   玖.设置.地图上下}, 8, blueColor);

                        } else
                            绘制加粗文本(24, 292 - 红蓝判断 * buffTeam * ZOOM * 23120 / 1000 - 12 +
                                             玖.设置.地图左右,
                                         170 - 红蓝判断 * buffTeam * ZOOM * 1230 / 1000 - 12 +
                                         玖.设置.地图上下, blueColor, 黑色, extra);
                        break;
                    case 6011://红
                        if (!玖.功能.计时.BUFF) break;
                        buffTeam = R.ReadZZ<int>(buffArray + 0x2B0) > 0 ? 1 : -1;
                        if (buffCd == 90000) {
                            buffCurHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0xA0));
                            buffMaxHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0xA8));
                            if (buffMaxHp <= 0) break;
                            buffPerHp = 100 * buffCurHp / buffMaxHp;
                            if (buffPerHp >= 60) {
                                buffHpColor = Blood1col;
                            } else if (buffPerHp >= 20) {
                                buffHpColor = Blood2col;
                            } else {
                                buffHpColor = Blood3col;
                            }
                            draw->AddCircleFilled({292 + 红蓝判断 * buffTeam * ZOOM * 2500 / 1000 +
                                                   玖.设置.地图左右,
                                                   170 + 红蓝判断 * buffTeam * ZOOM * 30000 / 1000 +
                                                   玖.设置.地图上下}, 8, redColor);

                        } else
                            绘制加粗文本(24, 292 + 红蓝判断 * buffTeam * ZOOM * 2500 / 1000 - 12 +
                                             玖.设置.地图左右,
                                         170 + 红蓝判断 * buffTeam * ZOOM * 30000 / 1000 - 12 +
                                         玖.设置.地图上下, redColor, 黑色, extra);
                        break;
                    case 6013://蜥蜴
                        if (!玖.功能.计时.小怪) break;
                        if (buffCd == 70000) {
                            buffCurHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0x11A0));
                            buffMaxHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0x118));
                            if (buffMaxHp <= 0) break;
                            buffPerHp = 100 * buffCurHp / buffMaxHp;
                            if (buffPerHp >= 60) {
                                buffHpColor = Blood1col;
                            } else if (buffPerHp >= 20) {
                                buffHpColor = Blood2col;
                            } else {
                                buffHpColor = Blood3col;
                            }
                            draw->AddCircleFilled(
                                    {292 - 红蓝判断 * ZOOM * 36190 / 1000 + 玖.设置.地图左右,
                                     170 - 红蓝判断 * ZOOM * 4500 / 1000 + 玖.设置.地图上下}, 5,
                                    yellowColor);

                        } else
                            绘制加粗文本(16, 292 - 红蓝判断 * ZOOM * 36190 / 1000 - 8 +
                                             玖.设置.地图左右,
                                         170 - 红蓝判断 * ZOOM * 4500 / 1000 - 8 + 玖.设置.地图上下,
                                         yellowColor, 黑色, extra);
                        break;
                    case 60132:
                        if (!玖.功能.计时.小怪) break;
                        if (buffCd == 70000) {
                            buffCurHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0x110));
                            buffMaxHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0x118));
                            if (buffMaxHp <= 0) break;
                            buffPerHp = 100 * buffCurHp / buffMaxHp;
                            if (buffPerHp >= 60) {
                                buffHpColor = Blood1col;
                            } else if (buffPerHp >= 20) {
                                buffHpColor = Blood2col;
                            } else {
                                buffHpColor = Blood3col;
                            }
                            draw->AddCircleFilled(
                                    {292 + 红蓝判断 * ZOOM * 36190 / 1000 + 玖.设置.地图左右,
                                     170 + 红蓝判断 * ZOOM * 4500 / 1000 + 玖.设置.地图上下}, 5,
                                    yellowColor);

                        } else
                            绘制加粗文本(16, 292 + 红蓝判断 * ZOOM * 36190 / 1000 - 8 +
                                             玖.设置.地图左右,
                                         170 + 红蓝判断 * ZOOM * 4500 / 1000 - 8 + 玖.设置.地图上下,
                                         yellowColor, 黑色, extra);
                        break;
                    case 6050://穿山甲
                        if (!玖.功能.计时.小怪) break;
                        if (buffCd == 70000) {
                            buffCurHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0x110));
                            buffMaxHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0x118));
                            if (buffMaxHp <= 0) break;
                            buffPerHp = 100 * buffCurHp / buffMaxHp;
                            if (buffPerHp >= 60) {
                                buffHpColor = Blood1col;
                            } else if (buffPerHp >= 20) {
                                buffHpColor = Blood2col;
                            } else {
                                buffHpColor = Blood3col;
                            }
                            draw->AddCircleFilled(
                                    {292 - 红蓝判断 * ZOOM * 33300 / 1000 + 玖.设置.地图左右,
                                     170 - 红蓝判断 * ZOOM * 19900 / 1000 + 玖.设置.地图上下}, 5,
                                    yellowColor);

                        } else
                            绘制加粗文本(16, 292 - 红蓝判断 * ZOOM * 33300 / 1000 - 8 +
                                             玖.设置.地图左右,
                                         170 - 红蓝判断 * ZOOM * 19900 / 1000 - 8 +
                                         玖.设置.地图上下, yellowColor, 黑色, extra);
                        break;
                    case 6051:
                        if (!玖.功能.计时.小怪) break;
                        if (buffCd == 70000) {
                            buffCurHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0x110));
                            buffMaxHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0x118));
                            if (buffMaxHp <= 0) break;
                            buffPerHp = 100 * buffCurHp / buffMaxHp;
                            if (buffPerHp >= 60) {
                                buffHpColor = Blood1col;
                            } else if (buffPerHp >= 20) {
                                buffHpColor = Blood2col;
                            } else {
                                buffHpColor = Blood3col;
                            }
                            draw->AddCircleFilled(
                                    {292 + 红蓝判断 * ZOOM * 33300 / 1000 + 玖.设置.地图左右,
                                     170 + 红蓝判断 * ZOOM * 19900 / 1000 + 玖.设置.地图上下}, 5,
                                    yellowColor);

                        } else
                            绘制加粗文本(16, 292 + 红蓝判断 * ZOOM * 33300 / 1000 - 8 +
                                             玖.设置.地图左右,
                                         170 + 红蓝判断 * ZOOM * 19900 / 1000 - 8 +
                                         玖.设置.地图上下, yellowColor, 黑色, extra);
                        break;
                    case 6052://野猪
                        if (!玖.功能.计时.小怪) break;
                        if (buffCd == 70000) {
                            buffCurHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0x110));
                            buffMaxHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0x118));
                            if (buffMaxHp <= 0) break;
                            buffPerHp = 100 * buffCurHp / buffMaxHp;
                            if (buffPerHp >= 60) {
                                buffHpColor = Blood1col;
                            } else if (buffPerHp >= 20) {
                                buffHpColor = Blood2col;
                            } else {
                                buffHpColor = Blood3col;
                            }
                            draw->AddCircleFilled(
                                    {292 - 红蓝判断 * ZOOM * 3650 / 1000 + 玖.设置.地图左右,
                                     170 + 红蓝判断 * ZOOM * 18820 / 1000 + 玖.设置.地图上下}, 5,
                                    yellowColor);

                        } else
                            绘制加粗文本(16,
                                         292 - 红蓝判断 * ZOOM * 3650 / 1000 - 8 + 玖.设置.地图左右,
                                         170 + 红蓝判断 * ZOOM * 18820 / 1000 - 8 +
                                         玖.设置.地图上下, yellowColor, 黑色, extra);
                        break;
                    case 6053:
                        if (!玖.功能.计时.小怪) break;
                        if (buffCd == 70000) {
                            buffCurHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0x10));
                            buffMaxHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0x118));
                            if (buffMaxHp <= 0) break;
                            buffPerHp = 100 * buffCurHp / buffMaxHp;
                            if (buffPerHp >= 60) {
                                buffHpColor = Blood1col;
                            } else if (buffPerHp >= 20) {
                                buffHpColor = Blood2col;
                            } else {
                                buffHpColor = Blood3col;
                            }
                            draw->AddCircleFilled(
                                    {292 + 红蓝判断 * ZOOM * 3650 / 1000 + 玖.设置.地图左右,
                                     170 - 红蓝判断 * ZOOM * 18820 / 1000 + 玖.设置.地图上下}, 5,
                                    yellowColor);
                        } else
                            绘制加粗文本(16,
                                         292 + 红蓝判断 * ZOOM * 3650 / 1000 - 8 + 玖.设置.地图左右,
                                         170 - 红蓝判断 * ZOOM * 18820 / 1000 - 8 +
                                         玖.设置.地图上下, yellowColor, 黑色, extra);
                        break;
                    case 6054://小鸟
                        if (!玖.功能.计时.小怪) break;
                        if (buffCd == 70000) {
                            buffCurHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0xA0));
                            buffMaxHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0xA8));
                            if (buffMaxHp <= 0) break;
                            buffPerHp = 100 * buffCurHp / buffMaxHp;
                            if (buffPerHp >= 60) {
                                buffHpColor = Blood1col;
                            } else if (buffPerHp >= 20) {
                                buffHpColor = Blood2col;
                            } else {
                                buffHpColor = Blood3col;
                            }
                            draw->AddCircleFilled(
                                    {292 + 红蓝判断 * ZOOM * 16750 / 1000 + 玖.设置.地图左右,
                                     170 + 红蓝判断 * ZOOM * 36000 / 1000 + 玖.设置.地图上下}, 5,
                                    yellowColor);
                        } else
                            绘制加粗文本(16, 292 + 红蓝判断 * ZOOM * 16750 / 1000 - 8 +
                                             玖.设置.地图左右,
                                         170 + 红蓝判断 * ZOOM * 36000 / 1000 - 8 +
                                         玖.设置.地图左右, yellowColor, 黑色, extra);
                        break;
                    case 60541:
                        if (!玖.功能.计时.小怪) break;
                        if (buffCd == 70000) {
                            buffCurHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0xA0));
                            buffMaxHp = R.ReadZZ<int>(R.GetPointer(buffArray, 0x368, 0x8));
                            if (buffMaxHp <= 0) break;
                            buffPerHp = 100 * buffCurHp / buffMaxHp;
                            if (buffPerHp >= 60) {
                                buffHpColor = Blood1col;
                            } else if (buffPerHp >= 20) {
                                buffHpColor = Blood2col;
                            } else {
                                buffHpColor = Blood3col;
                            }
                            draw->AddCircleFilled(
                                    {292 - 红蓝判断 * ZOOM * 16750 / 1000 + 玖.设置.地图左右,
                                     170 - 红蓝判断 * ZOOM * 36000 / 1000 + 玖.设置.地图上下}, 5,
                                    yellowColor);

                        } else
                            绘制加粗文本(16, 292 - 红蓝判断 * ZOOM * 16750 / 1000 - 8 +
                                             玖.设置.地图左右,
                                         170 - 红蓝判断 * ZOOM * 36000 / 1000 - 8 +
                                         玖.设置.地图上下, yellowColor, 黑色, extra);
                        break;

                }
            }
        }

        if (玖.功能.兵线) {
            for (char i = 0; i < 50; i++) {
                uint64_t laneAddr = R.GetPointer(laneBase, 0x2D0, i * 0x18, 0x0);
                if (!R.ReadZZ<int>(laneAddr)) {
                    continue;
                }
                int laneId = R.ReadZZ<int>(laneAddr + 0x20);
                if (laneId < 6000) {
                    continue;
                }
                int laneTeam = R.ReadZZ<int>(laneAddr + 0x2C);
                if (laneTeam == myTeam) {
                    continue;
                }
                int laneHp = R.ReadZZ<int>(R.GetPointer(laneAddr, 0x110, 0xA0));
                if (laneHp <= 0) {
                    continue;
                }
                uint64_t lanePosAddr = R.GetPointer(laneAddr, 0x1B8, 0xB0, 0x78, 0x78);
                Vector3<int> lanePosInt;
                R.ReadZZ(lanePosAddr, &lanePosInt, sizeof(int) * 3);
                if (lanePosInt.X == 0 && lanePosInt.Y == 0) {
                    continue;
                }
                draw->AddCircleFilled(
                        {292 + 红蓝判断 * ZOOM * lanePosInt.X / 1000 + 玖.设置.地图左右,
                         170 - 红蓝判断 * ZOOM * lanePosInt.Y / 1000 + 玖.设置.地图上下}, 5,
                        redColor);
            }
        }

        char role_cnt = 0;
        for (char i = 0; i < 10; i++) {
            uint64_t heroAddr = R.GetPointer(heroBase, 0x120 + i * 0x18, 0x68, 0x0);
            if (!heroAddr) continue;

            int team = R.ReadZZ<int>(heroAddr + 0x34);
            if ((team != 1) && (team != 2)) {
                //debugStr = str_format("camp:%d", camp);
                continue;
            }
			
            debugStr = str_format("\n我的阵营:%s\n矩阵地址:0x%lX", (myTeam == 1) ? "蓝方" : "红方", matrixAddr);

            if (team == myTeam) {
                continue;
            }
            
            uint64_t posAddr = R.GetPointer(heroAddr, 0x248, 0x28, 0x10, 0x0, 0x48, 0x0);
            Vector3<int> heroPosInt;
            R.ReadZZ(posAddr, &heroPosInt, sizeof(int) * 3);
            if (heroPosInt.X == 0 && heroPosInt.Y == 0) {
                continue;
            }

            role_cnt++;

            Vector3<float> heroPosFloat = {
                    (float) heroPosInt.X * 0.001f,
                    (float) heroPosInt.Z * 0.001f,
                    (float) heroPosInt.Y * 0.001f,
            };

            float px = 玖.设置.分辨率X / 2;
            float py = 玖.设置.分辨率Y / 2;

            float camear_r = matrix[3] * heroPosFloat.X + matrix[7] * heroPosFloat.Z +
                             matrix[11] * heroPosFloat.Y + matrix[15];
            float r_x = px + (matrix[0] * heroPosFloat.X + matrix[4] * heroPosFloat.Z +
                              matrix[8] * heroPosFloat.Y + matrix[12]) / camear_r * px;
            float r_y = py - (matrix[1] * heroPosFloat.X + matrix[5] * heroPosFloat.Z +
                              matrix[9] * heroPosFloat.Y + matrix[13]) / camear_r * py;
            float r_w = py - (matrix[1] * heroPosFloat.X + matrix[5] * (heroPosFloat.Z + 3.7) +
                              matrix[9] * heroPosFloat.Y + matrix[13]) / camear_r * py;

            Vector2<float> 实体坐标 = {
                    r_x - (r_y - r_w) / 16,
                    r_y - (r_y - r_w) / 5
            };
            //debugStr = str_format("\n2D实体坐标:%.2f, %.2f", 实体坐标.X, 实体坐标.Y);
            int role_id = R.ReadZZ<int>(heroAddr + 0x28);
            int cur_hp = R.ReadZZ<int>(R.GetPointer(heroAddr, 0x128) + 0xA0);
            //if(cur_hp==0) continue;
            int max_hp = R.ReadZZ<int>(R.GetPointer(heroAddr, 0x128) + 0xA8);
            int is_back = R.ReadZZ<int>(R.GetPointer(heroAddr, 0xF8, 0x168, 0x110, 0x20)); // S31未更新
            int 主动cd = R.ReadZZ<int>(R.GetPointer(heroAddr, 0x140, 0x348, 0x4)) / 1000; // S31未更新
            int 召唤cd = R.ReadZZ<int>(R.GetPointer(heroAddr, 0x110, 0x150, 0xA0, 0x38)) / 8192000;
            int 大招cd = R.ReadZZ<int>(R.GetPointer(heroAddr, 0xF8, 0x108, 0xA0, 0x38)) / 8192000;
            int per_hp = cur_hp * 100 / max_hp;
            //debugStr = str_format("per_hp:%d", per_hp);

            if (per_hp >= 60) {
                blood_color = Blood1col;
            } else if (per_hp >= 20) {
                blood_color = Blood2col;
            } else {
                blood_color = Blood3col;
            }

            if (玖.功能.地图 && cur_hp > 0) {
                draw->AddImage(getHeroTexture(role_id),
                               {292 + 红蓝判断 * ZOOM * heroPosInt.X / 1000 - 25 + 玖.设置.地图左右,
                                170 - 红蓝判断 * ZOOM * heroPosInt.Y / 1000 - 25 +
                                玖.设置.地图上下},
                               {292 + 红蓝判断 * ZOOM * heroPosInt.X / 1000 + 25 + 玖.设置.地图左右,
                                170 - 红蓝判断 * ZOOM * heroPosInt.Y / 1000 + 25 +
                                玖.设置.地图上下});
                draw->AddCircle({292 + 红蓝判断 * ZOOM * heroPosInt.X / 1000 + 玖.设置.地图左右,
                                 170 - 红蓝判断 * ZOOM * heroPosInt.Y / 1000 + 玖.设置.地图上下},
                                20, redColor, 0, 3);
                /*
                if (is_back) {
                    draw->AddCircle({292 + 红蓝判断 * ZOOM * heroPosInt.X / 1000 + 玖.设置.地图左右,
                                     170 - 红蓝判断 * ZOOM * heroPosInt.Y / 1000 +
                                     玖.设置.地图上下}, 22, blueColor, 0, 5);
                }
                */
                draw->AddRectFilled(
                        {292 + 红蓝判断 * ZOOM * heroPosInt.X / 1000 - 25 + 玖.设置.地图左右,
                         170 - 红蓝判断 * ZOOM * heroPosInt.Y / 1000 + 18 + 玖.设置.地图上下},
                        {295 + 红蓝判断 * ZOOM * heroPosInt.X / 1000 + 25 + 玖.设置.地图左右,
                         170 - 红蓝判断 * ZOOM * heroPosInt.Y / 1000 + 18 + 5 + 玖.设置.地图上下},
                        半黑, 1.0f);
                draw->AddRectFilled(
                        {292 + 红蓝判断 * ZOOM * heroPosInt.X / 1000 - 25 + 玖.设置.地图左右,
                         170 - 红蓝判断 * ZOOM * heroPosInt.Y / 1000 + 18 + 玖.设置.地图上下},
                        {295 + 红蓝判断 * ZOOM * heroPosInt.X / 1000 - 25 + 50 * per_hp / 100 +
                         玖.设置.地图左右,
                         170 - 红蓝判断 * ZOOM * heroPosInt.Y / 1000 + 18 + 5 + 玖.设置.地图上下},
                        blood_color, 1.0f);
            }
            if (玖.功能.实体 && cur_hp > 0) {
                draw->AddImage(getHeroTexture(role_id), {实体坐标.X - 30 + 30, 实体坐标.Y - 30},
                               {实体坐标.X + 30 + 30, 实体坐标.Y + 30});
                draw->AddCircle({实体坐标.X + 30, 实体坐标.Y}, 30, redColor, 0, 5);
                /*
                if (is_back) {
                    draw->AddCircle({实体坐标.X + 30, 实体坐标.Y}, 32, blueColor, 0, 5);
                }
                */
                draw->AddRectFilled({实体坐标.X + 55 + 30, 实体坐标.Y - 80},
                                    {实体坐标.X + 65 + 30, 实体坐标.Y + 80}, 半黑, 1.0f);
                draw->AddRectFilled({实体坐标.X + 55 + 30, 实体坐标.Y - 80 + 100 - per_hp},
                                    {实体坐标.X + 65 + 30, 实体坐标.Y + 80}, blood_color, 1.0f);

                if (大招cd == 0) {
                    sprintf(extra, "大招: 有");
                    绘制加粗文本(30, 实体坐标.X - 45 + 30, 实体坐标.Y - 80, redColor, 黑色, extra);
                } else {
                    sprintf(extra, "大招: %d", 大招cd);
                    绘制加粗文本(30, 实体坐标.X - 45 + 30, 实体坐标.Y - 80, Colinfor, 黑色, extra);
                }

                if (召唤cd == 0) {
                    sprintf(extra, "召唤: 有");
                    绘制加粗文本(30, 实体坐标.X - 45 + 30, 实体坐标.Y + 50, redColor, 黑色, extra);
                } else {
                    sprintf(extra, "召唤: %d", 召唤cd);
                    绘制加粗文本(30, 实体坐标.X - 45 + 30, 实体坐标.Y + 50, Colinfor, 黑色, extra);
                }

            }
            if (玖.功能.技能) {
                char skill_cnt = 0;
                if (cur_hp == 0) {
                    role_id = 103;
                }
                if (玖.功能.计时.召唤) {
                    if (召唤cd > 0) {
                        sprintf(extra, "%d", 召唤cd);
                        skill_draw(role_id, role_cnt, skill_cnt, extra, 蓝色, per_hp, blood_color);
                    } else {
                        sprintf(extra, "召");
                        skill_draw(role_id, role_cnt, skill_cnt, extra, 红色, per_hp, blood_color);
                    }
                    skill_cnt++;
                }
                if (玖.功能.计时.大招) {
                    if (大招cd > 0) {
                        sprintf(extra, "%d", 大招cd);
                        skill_draw(role_id, role_cnt, skill_cnt, extra, 蓝色, per_hp, blood_color);
                    } else {
                        sprintf(extra, "大");
                        skill_draw(role_id, role_cnt, skill_cnt, extra, 红色, per_hp, blood_color);
                    }
                    skill_cnt++;
                }
            }
            if (玖.功能.射线 && cur_hp > 0) {
                Vector2<float> selfVec2 = {
                        玖.设置.分辨率X / 2,
                        玖.设置.分辨率Y / 2
                };
                if (GetDistance(&selfVec2, &实体坐标) < 1200.0f) {
                    draw->AddLine({selfVec2.X, selfVec2.Y}, {实体坐标.X, 实体坐标.Y}, Linecol,
                                  {1.5});
                }
            }
        }

        return 0;
    } catch (std::exception e) {
        return 0;
    }
}

#endif

