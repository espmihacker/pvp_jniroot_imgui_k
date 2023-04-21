#ifndef MY_DUXIE_H
#define MY_DUXIE_H

#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/syscall.h>
#include <sys/mman.h>
#include <sys/uio.h>
#include <malloc.h>
#include <math.h>
#include <thread>
#include <iostream>
#include <sys/stat.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#include <locale>
#include <string>
#include <codecvt>
#include <dlfcn.h>
#include <unordered_map>
#include <set>
#include <string>
//#include "mem.h"
using namespace std;
typedef long ADDRESS;
typedef char PACKAGENAME;
typedef unsigned short UTF16;
typedef char UTF8;
typedef unsigned long long  kaddr;
int 分辨率Y = 1080;
int 分辨率X = 2400;
int 屏幕宽 =  分辨率X;
int 屏幕高 =  分辨率Y;
float 屏宽, 屏高;
uintptr_t ue4Address;
uint64_t libGameCore;
uint64_t libil2cpp;
uint64_t libunity;
std::string debugStr = "Debug测试";
typedef uintptr_t Ptr;

using namespace std;
unordered_map < int, std::string > ClassCache;
uintptr_t GName;
char sz[256];
int isSize = 8;//默认32位
int fd,pid;

/*
// 定义圆周率
#define PI 3.141592653589793238

float matrix[50] = { 0 }, camera, r_x, r_y, r_w;

struct FVector
{
    float X;
    float Y;
    float Z;

    FVector()
    {
        this->X = 0;
        this->Y = 0;
        this->Z = 0;
    }

    FVector(float x, float y, float z)
    {
        this->X = x;
        this->Y = y;
        this->Z = z;
    }

};




struct Vector2
{
    float X;
    float Y;

    Vector2()
    {
        this->X = 0;
        this->Y = 0;
    }

    Vector2(float x, float y)
    {
        this->X = x;
        this->Y = y;
    }
};

struct Vector3
{
    float X;
    float Y;
    float Z;

    Vector3()
    {
        this->X = 0;
        this->Y = 0;
        this->Z = 0;
    }

    Vector3(float x, float y, float z)
    {
        this->X = x;
        this->Y = y;
        this->Z = z;
    }

};
*/

/* 绘制变量区 */



/* 绘制计算区 */
/*

struct FMatrix
{
    float M[4][4];
};

struct Quat
{
    float X;
    float Y;
    float Z;
    float W;
};

struct FTransform
{
    Quat Rotation;
    Vector3 Translation;
  //  float chunk;
    Vector3 Scale3D;
};

#define PI 3.14159265358979323846


// 计算旋转坐标
Vector2 rotateCoord(float angle, float objRadar_x, float objRadar_y)
{
    Vector2 radarCoordinate;
    float s = sin(angle * PI / 180);
    float c = cos(angle * PI / 180);
    radarCoordinate.X = objRadar_x * c + objRadar_y * s;
    radarCoordinate.Y = -objRadar_x * s + objRadar_y * c;
    return radarCoordinate;
}

Vector2 WorldToScreen(Vector3 obj, float matrix[16], float ViewW)
{
    float x =
        屏幕宽/2 + (matrix[0] * obj.X + matrix[4] * obj.Y + matrix[8] * obj.Z + matrix[12]) / ViewW * 屏幕宽/2;
    float y =
        屏幕高/2 - (matrix[1] * obj.X + matrix[5] * obj.Y + matrix[9] * obj.Z + matrix[13]) / ViewW * 屏幕高/2;

    return Vector2(x, y);
}

Vector3 MarixToVector(FMatrix matrix)
{
    return Vector3(matrix.M[3][0], matrix.M[3][1], matrix.M[3][2]);
}

FMatrix MatrixMulti(FMatrix m1, FMatrix m2)
{
    FMatrix matrix = FMatrix();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                matrix.M[i][j] += m1.M[i][k] * m2.M[k][j];
            }
        }
    }
    return matrix;
}

FMatrix TransformToMatrix(FTransform transform)
{
    FMatrix matrix;
    matrix.M[3][0] = transform.Translation.X;
    matrix.M[3][1] = transform.Translation.Y;
    matrix.M[3][2] = transform.Translation.Z;
    float x2 = transform.Rotation.X + transform.Rotation.X;
    float y2 = transform.Rotation.Y + transform.Rotation.Y;
    float z2 = transform.Rotation.Z + transform.Rotation.Z;
    float xx2 = transform.Rotation.X * x2;
    float yy2 = transform.Rotation.Y * y2;
    float zz2 = transform.Rotation.Z * z2;
    matrix.M[0][0] = (1 - (yy2 + zz2)) * transform.Scale3D.X;
    matrix.M[1][1] = (1 - (xx2 + zz2)) * transform.Scale3D.Y;
    matrix.M[2][2] = (1 - (xx2 + yy2)) * transform.Scale3D.Z;
    float yz2 = transform.Rotation.Y * z2;
    float wx2 = transform.Rotation.W * x2;
    matrix.M[2][1] = (yz2 - wx2) * transform.Scale3D.Z;
    matrix.M[1][2] = (yz2 + wx2) * transform.Scale3D.Y;
    float xy2 = transform.Rotation.X * y2;
    float wz2 = transform.Rotation.W * z2;
    matrix.M[1][0] = (xy2 - wz2) * transform.Scale3D.Y;
    matrix.M[0][1] = (xy2 + wz2) * transform.Scale3D.X;
    float xz2 = transform.Rotation.X * z2;
    float wy2 = transform.Rotation.W * y2;
    matrix.M[2][0] = (xz2 + wy2) * transform.Scale3D.Z;
    matrix.M[0][2] = (xz2 - wy2) * transform.Scale3D.X;
    matrix.M[0][3] = 0;
    matrix.M[1][3] = 0;
    matrix.M[2][3] = 0;
    matrix.M[3][3] = 1;
    return matrix;
}



FTransform getBone(uintptr_t addr)
{
    FTransform transform;  
    vm_readv(addr, reinterpret_cast<void*>(&transform), 4 * 11);
    return transform;
}

struct D3DXMATRIX
{
	float _11;
	float _12;
	float _13;
	float _14;
	float _21;
	float _22;
	float _23;
	float _24;
	float _31;
	float _32;
	float _33;
	float _34;
	float _41;
	float _42;
	float _43;
	float _44;
};


FTransform ReadFTransform(long int address)
{
	FTransform Result;
	Result.Rotation.X = getfloat(address);	// Rotation_X 
	Result.Rotation.Y = getfloat(address + 4);	// Rotation_y
	Result.Rotation.Z = getfloat(address + 8);	// Rotation_z
	Result.Rotation.W = getfloat(address + 12);	// Rotation_w
	Result.Translation.X = getfloat(address + 16);	// /Translation_X
	Result.Translation.Y = getfloat(address + 20);	// Translation_y
	Result.Translation.Z = getfloat(address + 24);	// Translation_z
	Result.Scale3D.X = getfloat(address + 32);;	// Scale_X
	Result.Scale3D.Y = getfloat(address + 36);;	// Scale_y
	Result.Scale3D.Z = getfloat(address + 40);;	// Scale_z
	return Result;
}

Vector3 D3dMatrixMultiply(D3DXMATRIX bonematrix, D3DXMATRIX actormatrix)
{
	Vector3 result;
	result.X =
		bonematrix._41 * actormatrix._11 + bonematrix._42 * actormatrix._21 +
		bonematrix._43 * actormatrix._31 + bonematrix._44 * actormatrix._41;
	result.Y =
		bonematrix._41 * actormatrix._12 + bonematrix._42 * actormatrix._22 +
		bonematrix._43 * actormatrix._32 + bonematrix._44 * actormatrix._42;
	result.Z =
		bonematrix._41 * actormatrix._13 + bonematrix._42 * actormatrix._23 +
		bonematrix._43 * actormatrix._33 + bonematrix._44 * actormatrix._43;
	return result;
}

D3DXMATRIX ToMatrixWithScale(Quat Rotation, Vector3 Translation, Vector3 Scale3D)
{
    D3DXMATRIX M;
    float X2, Y2, Z2, xX2, Yy2, Zz2, Zy2, Wx2, Xy2, Wz2, Zx2, Wy2;
    M._41 = Translation.X;
    M._42 = Translation.Y;
    M._43 = Translation.Z;
    X2 = Rotation.X + Rotation.X;
    Y2 = Rotation.Y + Rotation.Y;
    Z2 = Rotation.Z + Rotation.Z;
    xX2 = Rotation.X * X2;
    Yy2 = Rotation.Y * Y2;
    Zz2 = Rotation.Z * Z2;
    M._11 = (1 - (Yy2 + Zz2)) * Scale3D.X;
    M._22 = (1 - (xX2 + Zz2)) * Scale3D.Y;
    M._33 = (1 - (xX2 + Yy2)) * Scale3D.Z;
    Zy2 = Rotation.Y * Z2;
    Wx2 = Rotation.W * X2;
    M._32 = (Zy2 - Wx2) * Scale3D.Z;
    M._23 = (Zy2 + Wx2) * Scale3D.Y;
    Xy2 = Rotation.X * Y2;
    Wz2 = Rotation.W * Z2;
    M._21 = (Xy2 - Wz2) * Scale3D.Y;
    M._12 = (Xy2 + Wz2) * Scale3D.X;
    Zx2 = Rotation.X * Z2;
    Wy2 = Rotation.W * Y2;
    M._31 = (Zx2 + Wy2) * Scale3D.Z;
    M._13 = (Zx2 - Wy2) * Scale3D.X;
    M._14 = 0;
    M._24 = 0;
    M._34 = 0;
    M._44 = 1;
    return M;
}

//Vector3 getBoneXYZ(long int humanAddr, long int boneAddr, int Part);
Vector3 getBoneXYZ(long int humanAddr, long int boneAddr, int Part)
{
	// 获取Bone数据
	FTransform Bone = ReadFTransform(boneAddr + Part * 48);
	// 获取Actor数据
	FTransform Actor = ReadFTransform(humanAddr);
	D3DXMATRIX Bone_Matrix = ToMatrixWithScale(Bone.Rotation, Bone.Translation, Bone.Scale3D);
	D3DXMATRIX Component_ToWorld_Matrix = ToMatrixWithScale(Actor.Rotation, Actor.Translation, Actor.Scale3D);
	Vector3 result = D3dMatrixMultiply(Bone_Matrix, Component_ToWorld_Matrix);
	return result;
}


float getDistance(Vector3 mxyz, Vector3 exyz) {
	float X = mxyz.X - exyz.X;
	float Y = mxyz.Y - exyz.Y;
	float Z = mxyz.Z - exyz.Z;
	return (sqrt(X * X + Y * Y + Z * Z) / 100) - 2;
}


char* getClassName(uintptr_t ObjectAddress){
    
    uintptr_t Gname = getPointer(getPointer(getPointer(getPointer(ue4Address + 0xB105670) + 0x110) + 0xA0)+0xA0);
    
    int oid = getdword(ObjectAddress + 0x890);
   
    uintptr_t ye = getPointer(Gname + (oid / 0x4000) * 0x8);
    uintptr_t xu = getPointer(ye + (oid % 0x4000) * 0x8);
     if (xu > 0 && oid > 0)
    {
        //static 类型的内部变量一直占据存储空间的变量。 函数调用完毕不会弹出栈
        static char Name[256];
        vm_readv(xu + 0xc, Name, sizeof(Name));
        return Name;
    }
    return "null";
}


int getProcessID(const char *packageName)
{
    int id = -1;
    DIR *dir;
    FILE *fp;
    char filename[64];
    char cmdline[64];
    struct dirent *entry;
    dir = opendir("/proc");
    while ((entry = readdir(dir)) != NULL)
    {
        id = atoi(entry->d_name);
        if (id != 0)
        {
            sprintf(filename, "/proc/%d/cmdline", id);
            fp = fopen(filename, "r");
            if (fp)
            {
                fgets(cmdline, sizeof(cmdline), fp);
                fclose(fp);
                if (strcmp(packageName, cmdline) == 0)
                {
                    return id;
                }
            }
        }
    }
    closedir(dir);
    return -1;
}

void DrawCircleFilled(int x, int y, int radius, ImVec4 color, int segments)
{
	ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(color), segments);
}

void DrawLine(int x1, int y1, int x2, int y2, ImVec4 color, int size)
{
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::ColorConvertFloat4ToU32(color), size);
}
void DrawRect(int x, int y, int w, int h, ImVec4 color,int size)
{  //rounding 方框边缘曲率  //rounding_corners_flags 方框边缘弯曲类型  1.ImDrawCornerFlags_All 2.ImDrawCornerFlags_Top 3. ImDrawCornerFlags_Bot 4. ImDrawCornerFlags_Left 5. ImDrawCornerFlags_Right
	ImGui::GetBackgroundDrawList()->AddRect(ImVec2(x, y), ImVec2(x+w, y+h), ImGui::ColorConvertFloat4ToU32(color), 0, 0, size);
}

void DrawRect2(float x, float y, float x2, float y2, int color,int size)
{  //rounding 方框边缘曲率  //rounding_corners_flags 方框边缘弯曲类型  1.ImDrawCornerFlags_All 2.ImDrawCornerFlags_Top 3. ImDrawCornerFlags_Bot 4. ImDrawCornerFlags_Left 5. ImDrawCornerFlags_Right
	ImGui::GetBackgroundDrawList()->AddRect(ImVec2(x, y), ImVec2(x2, y2), color, 0, 0, size);
}

void DrawRectFilled(int x, int y, int w, int h, ImVec4 color)
{
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x+w, y+h), ImGui::ColorConvertFloat4ToU32(color), 0, 0);
}
void DrawCircle(int x, int y, float radius, ImVec4 color, int segments, int thickness)
{
	ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(color), segments, thickness);
}
void DrawStrokeText(int x, int y, ImVec4 color, const char* str)
{
    ImGui::GetBackgroundDrawList()->AddText(ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
    ImGui::GetBackgroundDrawList()->AddText(ImVec2(x - 0.1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
    ImGui::GetBackgroundDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
    ImGui::GetBackgroundDrawList()->AddText(ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
    ImGui::GetBackgroundDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(color), str);
}
void DrawTriangleFilled(int x1, int y1, int x2, int y2, int x3, int y3, ImVec4 Color, int T)
{
	ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), ImGui::ColorConvertFloat4ToU32(Color));
}
void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, ImVec4 Color, int T)
{
	ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), ImGui::ColorConvertFloat4ToU32(Color));
}
void ImGui_NewTriangleFilled(int x, int y, ImVec4 color, int size, int px)
{
	x = x - px / 2;
	y = y - px / 2;
	DrawTriangle(x, y, y + px / 2, y + px, x + px, y,color, size);
}


int espWidth = 1;

static size_t page_size;

bool isMemoryTrap(uintptr_t _addr, int _size) {
	int pageSize = getpagesize();
    unsigned char vec = 0;
    unsigned long start = _addr & (~(pageSize - 1));
    mincore((void *)start, pageSize, &vec);
    if (vec == 1)
    {
         
        return false;
    }else{
        
        return true;
    }
}

struct D3DMatrix

{

    float _11, _12, _13, _14;

    float _21, _22, _23, _24;

    float _31, _32, _33, _34;

    float _41, _42, _43, _44;

};

float get_3D_Distance(float Self_x, float Self_y, float Self_z, float Object_x, float Object_y,
                      float Object_z)
{
    float x, y, z;
    x = Self_x - Object_x;
    y = Self_y - Object_y;
    z = Self_z - Object_z;
    // 求平方根
    return (float)(sqrt(x * x + y * y + z * z));
}

uintptr_t kzq,view;
float DropM;
Vector2 getPointingAngle(Vector3 Self, Vector3 xyz)
{
    Vector2 PointingAngle;
    float zbcx = xyz.X - Self.X;
    float zbcy = xyz.Y - Self.Y;
    float zbcz = xyz.Z - Self.Z;
    float pfg = (float)sqrt((zbcx * zbcx) + (zbcy * zbcy));
    PointingAngle.X = (float)atan2(zbcy, zbcx) * 180 / PI;
    PointingAngle.Y = (float)atan2(zbcz, pfg) * 180 / PI;
    return PointingAngle;
}


bool isStartWith(string str, string check)
{
    return (str.rfind(check, 0) == 0);
}

bool isEqual(string s1, string s2)
{
    return (s1 == s2);
}

bool isContain(string str, string check)
{
    size_t found = str.find(check);
    return (found != string::npos);
}
*/
#endif

