#ifndef TOOL_H
#define TOOL_H
#include "ImGuiInEGL.h"

typedef unsigned long S;
typedef std::uint64_t hash_t;

constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;


template<typename T>
struct Vector2
{
    T X;
    T Y;

    Vector2()
    {
        this->X = 0;
        this->Y = 0;
    }

	template<typename T>
    Vector2(T x, T y)
    {
        this->X = x;
        this->Y = y;
    }
};

template<typename T>
struct Vector3
{
    T X;
    T Z;
    T Y;

    Vector3()
    {
        this->X = 0;
        this->Z = 0;
        this->Y = 0;
    }

	template<typename T>
    Vector3(T x, T z, T y)
    {
        this->X = x;
        this->Z = z;
        this->Y = y;
    }

};

uintptr_t ReadModule(const char *name, int index)
{
    char fname[128];
    char dname[128];
    char line[1024] = {0};
    long start = 0, end = 0;
    int i = 0, ii = 0, iii = 0;
    if (strstr(name, "bss") != NULL) {
        sscanf(name, "%[^:]", dname);
        i++;
    } else {
        sprintf(dname, "%s", name);
    }
    sprintf(fname, "/proc/%d/maps", pid);
    FILE *fp = fopen(fname, "r");
    if (fp)
    {
        while (fgets(line, sizeof(line), fp))
        {
            if (strstr(line, dname) != NULL) {
                iii++;
                if (i == 0) {
                    if (iii == index) {
                        sscanf(line, "%lx-%lx", &start, &end);
                        return start;
                        break;
                    }
                } else {
                    ii++;
                }
            }
            if (ii > 0) {
                if (strstr(line, "[anon:.bss]") != NULL) {
                    sscanf(line, "%lx-%lx", &start, &end);
                    return start;
                    break;
                }
            }
        }
        fclose(fp);
    }
    return start;
}

inline float GetDistance(Vector2<float> *selfVec2, Vector2<float> *objVec2) {
	float dx = pow(objVec2->X - selfVec2->X, 2);
	float dy = pow(objVec2->Y - selfVec2->Y, 2);
	return sqrt(dx + dy);
}


template<typename ... Args>
static std::string str_format(const std::string& format, Args ... args)
{
	auto size_buf = std::snprintf(nullptr, 0, format.c_str(), args ...) + 1;
	std::unique_ptr<char[]> buf(new(std::nothrow) char[size_buf]);

	if (!buf)
		return std::string("");

	std::snprintf(buf.get(), size_buf, format.c_str(), args ...);
	return std::string(buf.get(), buf.get() + size_buf - 1);
}


inline bool fileIsExists (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

inline bool fileIsExists (const char* name) {
  struct stat buffer;   
  return (stat (name, &buffer) == 0); 
}

pid_t FindPID(const char *packageName)
{
	pid_t id = -1;
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

hash_t UniCode(const char *str)
{  
    hash_t ret{basis};
    while(*str) {
        ret ^= *str;
        ret *= prime;
        str++;
    }
    return ret;  
}

constexpr hash_t hash_time(const char *str, hash_t last_value = basis) {  
    return *str ? hash_time(str + 1, (*str ^ last_value) * prime) : last_value;  
}

constexpr unsigned long long operator "" _Hash(const char *p, size_t) {  
    return hash_time(p);  
}

ImColor RandomColor()
{
    int R, G, B, A = 180;
    R = (random() % 255);
    G = (random() % 255);
    B = (random() % 255);
    return ImColor(R, G, B, A);
}

ImColor ColorArr[100];
void ColorInitialization()
{
    for(int i = 0; i < 100; i++) {
        ColorArr[i] = RandomColor();
    }
}

ImColor TeamColor(int Num)
{
    if(Num < 99 && Num > 0) {
        return ColorArr[Num];
    } else {
        return ImColor(67, 205, 128, 150);
    }
}

struct FMatrix {
    float M[4][4];
};

struct FTransform
{
    Vec3 Scale3D;
    Vec4 Rotation;
    Vec3 Translation;
};

struct PlaData {
    int 动作;
    int 队伍;
    float 头部;
	float 距离;
	float 血量;
	float 相机;
    Vec2 底部左脚;
    Vec2 底部右脚;
    Vec3 对象向量;
	Vec4 屏幕坐标;
	char 名称[128];
    Vec2 对象骨骼[20];
    Vec3 BonsXYZ[20];
};

struct TotalData {
    int Sum;
    float Bottom1, Bottom2;
	struct PlaData Pla[500];
    unsigned long Mesh, Bone;
    FTransform MeshTrans, MeshTran;
	FMatrix Wmatrix, BoneMatr, OutMatr;
};

TotalData Tot;
class ReadSyscall:
public TotalData {
public:
    typedef char UTF8;
	float Matrix[16] = {0};
    int Widtih = 0, Higtih = 0;
    typedef unsigned short UTF16;
    static thread_local inline iovec local[1];
    static thread_local inline iovec remote[1];
	static thread_local inline UTF16 buf16[16] = {0};
    
    inline void GetResolution()
    {
        ImRect screen_rect = {0.0f, 0.0f, ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y};
        auto screen_center = screen_rect.GetCenter();
        Widtih = screen_center.x, Higtih = screen_center.y;
    }
    
	inline void GetUTF8(UTF8 *buf, S addr)
	{
        ReadZZ(addr, buf16, 28);
        UTF16 *pTempUTF16 = buf16;
        UTF8  *pTempUTF8  = buf;
        UTF8  *pUTF8End   = pTempUTF8 + 32;
        while (pTempUTF16 < pTempUTF16 + 28)
        {
            if (*pTempUTF16 <= 0x007F && pTempUTF8 + 1 < pUTF8End) {
                *pTempUTF8++ = (UTF8) *pTempUTF16;
            } else if (*pTempUTF16 >= 0x0080 && *pTempUTF16 <= 0x07FF && pTempUTF8 + 2 < pUTF8End) {
                *pTempUTF8++ = (*pTempUTF16 >> 6) | 0xC0;
                *pTempUTF8++ = (*pTempUTF16 & 0x3F) | 0x80;
            } else if (*pTempUTF16 >= 0x0800 && *pTempUTF16 <= 0xFFFF && pTempUTF8 + 3 < pUTF8End) {
                *pTempUTF8++ = (*pTempUTF16 >> 12) | 0xE0;
                *pTempUTF8++ = ((*pTempUTF16 >> 6) & 0x3F) | 0x80;
                *pTempUTF8++ = (*pTempUTF16 & 0x3F) | 0x80;
            } else {
                break;
            }
            pTempUTF16++;
        }
    }

    inline int readb(int *c, int num) {
        ++*c;
        return num;
    }

    template<typename... s>
    inline S GetPointer(S addr, s... args)
    {
		S add = 0;
        int con = 0;
        int arr[] = {(readb(&con, args))...};
        ReadZZ<S>(addr + arr[0], &add);
        for (int f = 1; f < con; f++) {
            if (f == con - 1) {
                add += arr[f];
                return add;
            }
            ReadZZ<S>(add + arr[f], &add);
        }
        return add;
    }
    
    template<typename start>
    inline start ReadZZ(S addr)
    {
        start temp;
        local[0].iov_base  = &temp;
        local[0].iov_len   = sizeof(start);
        remote[0].iov_base = reinterpret_cast<void*>(addr);
        remote[0].iov_len  = sizeof(start);
        syscall(SYS_process_vm_readv, pid, local, 1, remote, 1, 0);
        return temp;
    }
	
    template<typename start>
    inline void ReadZZ(S addr, start *data)
    {
        local[0].iov_base  = data;
        local[0].iov_len   = sizeof(start);
        remote[0].iov_base = reinterpret_cast<void*>(addr);
        remote[0].iov_len  = sizeof(start);
        syscall(SYS_process_vm_readv, pid, local, 1, remote, 1, 0);
    }
    
    template<typename T>
    inline void ReadZZ(S addr, T *data, unsigned int size)
    {
        local[0].iov_base  = data;
        local[0].iov_len   = size;
        remote[0].iov_base = reinterpret_cast<void*>(addr);
        remote[0].iov_len  = size;
        syscall(SYS_process_vm_readv, pid, local, 1, remote, 1, 0);
    }
    
    inline void GetDistance(Vec3 Object, Vec3 Self, float *Distance)
    {
        float DistanceX = pow(Object.x - Self.x, 2);
        float DistanceY = pow(Object.y - Self.y, 2);
        float DistanceZ = pow(Object.z - Self.z, 2);
        *Distance = sqrt(DistanceX + DistanceY + DistanceZ) * 0.01f;
    }
    
    inline void RotateCoord(Vec2 *Radar, float Angle, Vec3 Enemy, Vec3 Self, int Scaling)
    {
        float s = sin((Angle - 90) * M_PI / 180);
        float c = cos((Angle - 90) * M_PI / 180);
        float objRadar_x = (Self.x - Enemy.x) / Scaling;
        float objRadar_y = (Self.y - Enemy.y) / Scaling;
        Radar->x = objRadar_x * c + objRadar_y * s;
        Radar->y = -objRadar_x * s + objRadar_y * c;
    }
    
    inline void WorldToScreen(float *bscreen, Vec3 *obj)
    {
        float camear = Matrix[3] * obj->x + Matrix[7] * obj->y + Matrix[11] * obj->z + Matrix[15];
        *bscreen = Higtih - (Matrix[1] * obj->x + Matrix[5] * obj->y + Matrix[9] * obj->z + Matrix[13]) / camear * Higtih;
    }
    
    inline void WorldToScreen(Vec2 *bscreen, Vec3 *obj)
    {
        float camear = Matrix[3] * obj->x + Matrix[7] * obj->y + Matrix[11] * obj->z + Matrix[15];
        bscreen->x = Widtih + (Matrix[0] * obj->x + Matrix[4] * obj->y + Matrix[8] * obj->z + Matrix[12]) / camear * Widtih;
        bscreen->y = Higtih - (Matrix[1] * obj->x + Matrix[5] * obj->y + Matrix[9] * obj->z + Matrix[13]) / camear * Higtih;
    }
    
    inline void WorldToScreen(Vec2 *bscreen, Vec3 obj)
    {
        float camear = Matrix[3] * obj.x + Matrix[7] * obj.y + Matrix[11] * obj.z + Matrix[15];
        bscreen->x = Widtih + (Matrix[0] * obj.x + Matrix[4] * obj.y + Matrix[8] * obj.z + Matrix[12]) / camear * Widtih;
        bscreen->y = Higtih - (Matrix[1] * obj.x + Matrix[5] * obj.y + Matrix[9] * obj.z + Matrix[13]) / camear * Higtih;
    }
    
    inline void WorldToScreen(Vec2 *bscreen, float *camea, Vec3 obj)
    {
        float camear = Matrix[3] * obj.x + Matrix[7] * obj.y + Matrix[11] * obj.z + Matrix[15];
        *camea = camear;
        bscreen->x = Widtih + (Matrix[0] * obj.x + Matrix[4] * obj.y + Matrix[8] * obj.z + Matrix[12]) / camear * Widtih;
        bscreen->y = Higtih - (Matrix[1] * obj.x + Matrix[5] * obj.y + Matrix[9] * obj.z + Matrix[13]) / camear * Higtih;
    }
    
    inline void WorldToScreen(Vec4 *bscreen, float *camea, Vec3 obj)
    {
        float camear = Matrix[3] * obj.x + Matrix[7] * obj.y + Matrix[11] * obj.z + Matrix[15];
        *camea = camear;
        bscreen->x = Widtih + (Matrix[0] * obj.x + Matrix[4] * obj.y + Matrix[8] * obj.z + Matrix[12]) / camear * Widtih;
        bscreen->y = Higtih - (Matrix[1] * obj.x + Matrix[5] * obj.y + Matrix[9] * obj.z + Matrix[13]) / camear * Higtih;
        float bscreenZ = Higtih - (Matrix[1] * obj.x + Matrix[5] * obj.y + Matrix[9] * (obj.z + 165) + Matrix[13]) / camear * Higtih;
        bscreen->z = bscreen->y - bscreenZ;
        bscreen->w = (bscreen->y - bscreenZ) / 2;
	}
    
    inline void ReadBone(S addr, FTransform *result)
    {
        result->Rotation.x = ReadZZ<float>(addr);
        result->Rotation.y = ReadZZ<float>(addr + 4);
        result->Rotation.z = ReadZZ<float>(addr + 8);
        result->Rotation.w = ReadZZ<float>(addr + 12);
        result->Translation.x = ReadZZ<float>(addr + 16);
        result->Translation.y = ReadZZ<float>(addr + 20);
        result->Translation.z = ReadZZ<float>(addr + 24);
        result->Scale3D.x = ReadZZ<float>(addr + 32);
        result->Scale3D.y = ReadZZ<float>(addr + 36);
        result->Scale3D.z = ReadZZ<float>(addr + 40);
    }
    
    inline void TransformToMatrix(FMatrix &fMatrix, FTransform transform)
    {
        fMatrix.M[3][0] = transform.Translation.x;
        fMatrix.M[3][1] = transform.Translation.y;
        fMatrix.M[3][2] = transform.Translation.z;
        float x2 = transform.Rotation.x + transform.Rotation.x;
        float y2 = transform.Rotation.y + transform.Rotation.y;
        float z2 = transform.Rotation.z + transform.Rotation.z;
        float xx2 = transform.Rotation.x * x2;
        float yy2 = transform.Rotation.y * y2;
        float zz2 = transform.Rotation.z * z2;
        fMatrix.M[0][0] = (1 - (yy2 + zz2)) * transform.Scale3D.x;
        fMatrix.M[1][1] = (1 - (xx2 + zz2)) * transform.Scale3D.y;
        fMatrix.M[2][2] = (1 - (xx2 + yy2)) * transform.Scale3D.z;
        float yz2 = transform.Rotation.y * z2;
        float wx2 = transform.Rotation.w * x2;
        fMatrix.M[2][1] = (yz2 - wx2) * transform.Scale3D.z;
        fMatrix.M[1][2] = (yz2 + wx2) * transform.Scale3D.y;
        float xy2 = transform.Rotation.x * y2;
        float wz2 = transform.Rotation.w * z2;
        fMatrix.M[1][0] = (xy2 - wz2) * transform.Scale3D.y;
        fMatrix.M[0][1] = (xy2 + wz2) * transform.Scale3D.x;
        float xz2 = transform.Rotation.x * z2;
        float wy2 = transform.Rotation.w * y2;
        fMatrix.M[2][0] = (xz2 + wy2) * transform.Scale3D.z;
        fMatrix.M[0][2] = (xz2 - wy2) * transform.Scale3D.x;
        fMatrix.M[0][3] = 0;
        fMatrix.M[1][3] = 0;
        fMatrix.M[2][3] = 0;
        fMatrix.M[3][3] = 1;
    }

    inline void MatrixMulti(Vec3 *obj, FMatrix fMatrix, FMatrix m1, FMatrix m2)
    {
        memset(&fMatrix.M[0][0], 0, sizeof(fMatrix.M));
        for (int r = 0; r < 4; r++)
        {
            for (int jv = 0; jv < 4; jv++) {
                fMatrix.M[r][jv] += m1.M[r][0] * m2.M[0][jv];
                fMatrix.M[r][jv] += m1.M[r][1] * m2.M[1][jv];
                fMatrix.M[r][jv] += m1.M[r][2] * m2.M[2][jv];
                fMatrix.M[r][jv] += m1.M[r][3] * m2.M[3][jv];
            }
        }
        obj->x = fMatrix.M[3][0];
        obj->y = fMatrix.M[3][1];
        obj->z = fMatrix.M[3][2];
    }
    
    inline void GetBonesData(int DiGit, Vec3 *Bonexyz, Vec2 *Bonexy)
    {
        ReadBone(Tot.Bone + DiGit * 48, &Tot.MeshTran);
        TransformToMatrix(Tot.BoneMatr, Tot.MeshTran);
        MatrixMulti(Bonexyz, Tot.OutMatr, Tot.BoneMatr, Tot.Wmatrix);
        if (DiGit == 5) {
            Bonexyz->z += 7;
        }
        WorldToScreen(Bonexy, Bonexyz);
    }
    
    inline void GetBoneTransform(int DiGit, Vec2 *Bonexy)
    {
        Vec3 Bone_xyz = {0, 0, 0};
        ReadBone(Tot.Bone + DiGit * 48, &Tot.MeshTran);
        TransformToMatrix(Tot.BoneMatr, Tot.MeshTran);
        MatrixMulti(&Bone_xyz, Tot.OutMatr, Tot.BoneMatr, Tot.Wmatrix);
        WorldToScreen(Bonexy, Bone_xyz);
	}
    
    inline void SkeletonConnection(ImDrawList *ImDraw, ImU32 color, float thickn)
    {
        static int BoneList[14][2]
        {
            {5, 0}, // 脖子-盆骨
            
            {4, 11},
            {11, 12}, // 胸部-左手
            {12, 63},
            
            {4, 32},
            {32, 33}, // 胸部-右手
            {33, 62},
            
            {0, 52},
            {52, 53}, // 盆骨-左腿
            {53, 54},
            
            {0, 56},
            {56, 57}, // 盆骨-右腿
            {57, 58}
        };
        Vec2 rect_0[14], rect_1[14];
        for (int i = 0; i < 14; i++) {
            GetBoneTransform(BoneList[i][0], &rect_0[i]);
            GetBoneTransform(BoneList[i][1], &rect_1[i]);
            ImDraw->AddLine({rect_0[i].x, rect_0[i].y}, {rect_1[i].x, rect_1[i].y}, color, thickn);
        }
	}
    
    inline Rotator ToRotator(Vec3 local, Vec3 target)
    {
        Vec3 rotation = local - target;
        Rotator newViewAngle = {0, 0, 0};
        float hyp = sqrt(rotation.x * rotation.x + rotation.y * rotation.y);
        newViewAngle.Pitch = -atan(rotation.z / hyp) * (180.f / (float) M_PI);
        newViewAngle.Yaw = atan(rotation.y / rotation.x) * (180.f / (float) M_PI);
        newViewAngle.Roll = (float) 0.f;
        if(rotation.x >= 0.f) {
            newViewAngle.Yaw += 180.0f;
        }
        return newViewAngle;
    }
    
    inline float GetMinAngle(float Target, float Self)
    {
        Vec2 Angle;
        Angle.x = Target - Self;
        Angle.y = 360.0 - fabs(Angle.x);
        if (Angle.x > 0) {
            Angle.y *= -1.0;
        }
        return fabs(Angle.x) < fabs(Angle.y) ? Angle.x : Angle.y;
    }
};
#endif
