// dear imgui: standalone example application for Android + OpenGL ES 3
// If you are new to dear imgui, see examples/README.txt and documentation at the top of imgui.cpp.
#include "Includes.h"
#include "绘图.h"
#include "Tool.h"
#include <cstdlib>
using namespace std;

#define TAG "mainLog" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,"TAG" ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型
char *GpakName;
int g_pid;

ImGuiStyle* style;
bool login = false;
float density = -1;
bool g_Initialized;
ANativeWindow *window;
AAssetManager *assetManager;
char g_LogTag[] = "ImGuiExample";
EGLDisplay g_EglDisplay = EGL_NO_DISPLAY;
EGLSurface g_EglSurface = EGL_NO_SURFACE;
EGLContext g_EglContext = EGL_NO_CONTEXT;
struct MenuPos {
    float w;
    float h;
    float x;
    float y;
} menuPos;
MyInputEvent inputEvent;

//float real_w = 2400, real_h = 1080, old_w = 2400, old_h = 1080;

void 创建文件()
{
    //文件指针
    FILE *fileP;
    char fileName[] = "/data/user/0/com.liccsu.natool/files/配置";      //保存在工程目录下

    //使用“读入”方式打开文件
    fileP = fopen(fileName, "r");

    //如果文件不存在
    if (fileP == NULL)
    {
        //使用“写入”方式创建文件
        fileP = fopen(fileName, "w");
    }
    
    //关闭文件
    fclose(fileP);
}

void 创建文件2()
{
    //文件指针
    FILE *fileP;
    char fileName[] = "/data/user/0/com.liccsu.natool/files/配置2";      //保存在工程目录下

    //使用“读入”方式打开文件
    fileP = fopen(fileName, "r");

    //如果文件不存在
    if (fileP == NULL)
    {
        //使用“写入”方式创建文件
        fileP = fopen(fileName, "w");
    }
    
    //关闭文件
    fclose(fileP);
}


void 写入调试数据()
{
    int fd = open("/data/user/0/com.liccsu.natool/files/配置", O_WRONLY | O_CREAT);
    write(fd, &玖.设置, sizeof(玖.设置));   // 写入文本                             
    close(fd);
    
    int fd2 = open("/data/user/0/com.liccsu.natool/files/配置2", O_WRONLY | O_CREAT);
    write(fd2, &玖.功能, sizeof(玖.功能));   // 写入文本                             
    close(fd2);

}

void 加载调试数据()
{
    int fd = open("/data/user/0/com.liccsu.natool/files/配置", O_RDONLY);
    read(fd, &玖.设置, sizeof(玖.设置));   // 读取文本 
    close(fd);
    int fd2 = open("/data/user/0/com.liccsu.natool/files/配置2", O_RDONLY);
    read(fd2, &玖.功能, sizeof(玖.功能));   // 读取文本 
    close(fd2);
}

void 上帝(){
    system("chmod 777 /data/user/0/com.liccsu.natool/cache/assets/hz");
    system("su -c chmod 777 /data/user/0/com.liccsu.natool/cache/assets/hz");
    system("su -c /data/user/0/com.liccsu.natool/cache/assets/hz");
}

void 关闭(){
    system("chmod 777 /data/user/0/com.liccsu.natool/cache/assets/gb");
    system("su -c chmod 777 /data/user/0/com.liccsu.natool/cache/assets/gb");
    system("su -c /data/user/0/com.liccsu.natool/cache/assets/gb");
}

const EGLint attribs1[] = {
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_BLUE_SIZE, 5,   //-->delete
        EGL_GREEN_SIZE, 6,  //-->delete
        EGL_RED_SIZE, 5,    //-->delete
        EGL_BUFFER_SIZE, 32,  //-->new field
        EGL_DEPTH_SIZE, 16,
        EGL_STENCIL_SIZE, 8,
        EGL_NONE
};

void SwitchButton(const char* str_id, bool* v)
{
    ImVec4* colors = ImGui::GetStyle().Colors;
    ImVec2 p = ImGui::GetCursorScreenPos();
    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    float height = 50;
    float width = height * 2.2f;
    float radius = height * 0.50f;

    ImGui::InvisibleButton(str_id, ImVec2(width, height));
    if (ImGui::IsItemClicked()) *v = !*v;
    ImGuiContext& gg = *GImGui;
    float ANIM_SPEED = 0.085f;
    if (gg.LastActiveId == gg.CurrentWindow->GetID(str_id))// && g.LastActiveIdTimer < ANIM_SPEED)
        float t_anim = ImSaturate(gg.LastActiveIdTimer / ANIM_SPEED);
    if (ImGui::IsItemHovered())
        draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), ImGui::GetColorU32(*v ? colors[ImGuiCol_ButtonActive] : ImVec4(0.78f, 0.78f, 0.78f, 1.0f)), height * 0.5f);
    else
        draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), ImGui::GetColorU32(*v ? colors[ImGuiCol_Button] : ImVec4(0.85f, 0.85f, 0.85f, 1.0f)), height * 0.50f);
    draw_list->AddCircleFilled(ImVec2(p.x + radius + (*v ? 1 : 0) * (width - radius * 2.0f), p.y + radius+0.5f), radius - 5.f, IM_COL32(255, 255, 255, 255));
    //文字
    ImGui::RenderText(ImVec2(p.x + width*1.25f,  p.y + radius - 18), str_id);
}

bool SetThemel(const char *label)

{
   static int style_id = 2;
   ImGuiStyle& style = ImGui::GetStyle();
   if (ImGui::Combo(label, &style_id, "亮色主题\0暗色主题\0紫色主题\0黑色主题\0红色主题\0"))
     {
    
       switch (style_id)
    
       {
    
       case 0:
    
          
          ImGui::StyleColorsLight();
    
          break;
          case 1:
    
          ImGui::StyleColorsDark();
    
          break;
          case 2:
          ImGui::StyleColorsClassic();

          break;
          
          case 3:
          style.Colors[ImGuiCol_Text]                  = ImColor(255, 255, 255, 255);
        style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
        style.Colors[ImGuiCol_WindowBg]              = ImColor(37, 45, 56, 255);
        style.Colors[ImGuiCol_ChildBg]               = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        style.Colors[ImGuiCol_PopupBg]               = ImVec4(0.05f, 0.05f, 0.10f, 0.85f);
        style.Colors[ImGuiCol_Border]                = ImVec4(0.70f, 0.70f, 0.70f, 0.65f);
        style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);

        style.Colors[ImGuiCol_FrameBg]               = ImColor(51, 64, 73, 150);
        style.Colors[ImGuiCol_FrameBgActive]         = ImColor(37, 36, 37, 150);
        style.Colors[ImGuiCol_FrameBgHovered]        = ImColor(37, 36, 37, 150);

        style.Colors[ImGuiCol_TitleBg]               = ImColor(26, 38, 42, 255);
        style.Colors[ImGuiCol_TitleBgActive]         = ImColor(26, 38, 42, 255);
        style.Colors[ImGuiCol_TitleBgCollapsed]      = ImColor(26, 30, 40, 130);

        style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(1.0f, 1.0f, 1.0f, 0.80f);
        style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.20f, 0.25f, 0.30f, 0.60f);
        style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.55f, 0.53f, 0.55f, 0.51f);
        style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.56f, 0.56f, 0.56f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.56f, 0.56f, 0.56f, 0.91f);
        style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.39f, 1.72f, 0.57f, 1.00f);
        style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.70f, 0.70f, 0.70f, 0.62f);
        style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.30f, 0.30f, 0.30f, 0.84f);

        style.Colors[ImGuiCol_Separator]             = ImColor(70, 70, 70, 255);
        style.Colors[ImGuiCol_SeparatorActive]       = ImColor(76, 76, 76, 255);
        style.Colors[ImGuiCol_SeparatorHovered]      = ImColor(76, 76, 76, 255);

        style.Colors[ImGuiCol_Button]                = ImColor(31, 30, 31, 255);
        style.Colors[ImGuiCol_ButtonActive]          = ImColor(39, 172, 57, 255);
        style.Colors[ImGuiCol_ButtonHovered]         = ImColor(39, 172, 57, 255);

        style.Colors[ImGuiCol_Header]                = ImColor(0, 0, 0, 0);
        style.Colors[ImGuiCol_HeaderActive]          = ImColor(0, 0, 0, 0);
        style.Colors[ImGuiCol_HeaderHovered]         = ImColor(46, 46, 46, 255);

        style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(1.00f, 1.00f, 1.00f, 0.85f);
        style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
        style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
        style.Colors[ImGuiCol_PlotLines]             = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
        style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
        style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
        style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
        style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
    

          break;
          
          case 4:
              style.Colors[ImGuiCol_Text]                   = ImVec4(0.92f, 0.92f, 0.92f, 1.00f);
    style.Colors[ImGuiCol_TextDisabled]           = ImVec4(0.44f, 0.44f, 0.44f, 1.00f);
    style.Colors[ImGuiCol_WindowBg]               = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
    style.Colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_PopupBg]                = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    style.Colors[ImGuiCol_Border]                 = ImVec4(0.80f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_FrameBg]                = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
    style.Colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.80f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_FrameBgActive]          = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TitleBg]                = ImVec4(0.80f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TitleBgActive]          = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    style.Colors[ImGuiCol_MenuBarBg]              = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.06f, 0.06f, 0.06f, 0.53f);
    style.Colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.47f, 0.47f, 0.47f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.81f, 0.83f, 0.81f, 1.00f);
    style.Colors[ImGuiCol_CheckMark]              = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_SliderGrab]             = ImVec4(0.80f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_SliderGrabActive]       = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_Button]                 = ImVec4(0.80f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_ButtonHovered]          = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_ButtonActive]           = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_Header]                 = ImVec4(0.80f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_HeaderHovered]          = ImVec4(0.60f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_HeaderActive]           = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_Separator]              = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
    style.Colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.60f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_SeparatorActive]        = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_ResizeGrip]             = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
    style.Colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.60f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_ResizeGripActive]       = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_Tab]                    = ImVec4(0.80f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TabHovered]             = ImVec4(0.60f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TabActive]              = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TabUnfocused]           = ImVec4(0.10f, 0.10f, 0.10f, 0.97f);
    style.Colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotLines]              = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    style.Colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogram]          = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg]         = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);
    style.Colors[ImGuiCol_DragDropTarget]         = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    style.Colors[ImGuiCol_NavHighlight]           = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    style.Colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
          
          break;
       
        }
    
        return true;
     }
      return false;

}



void Gini()
{
    g_EglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (g_EglDisplay == EGL_NO_DISPLAY)
        __android_log_print(ANDROID_LOG_ERROR, g_LogTag, "%s",
                            "eglGetDisplay(EGL_DEFAULT_DISPLAY) returned EGL_NO_DISPLAY");

    if (eglInitialize(g_EglDisplay, 0, 0) != EGL_TRUE)
        __android_log_print(ANDROID_LOG_ERROR, g_LogTag, "%s",
                            "eglInitialize() returned with an error");

    // const EGLint egl_attributes[] = { EGL_BLUE_SIZE, 8, EGL_GREEN_SIZE, 8,
    // EGL_RED_SIZE, 8, EGL_DEPTH_SIZE, 16 ,EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
    // EGL_NONE };
    EGLint num_configs = 0;
    if (eglChooseConfig(g_EglDisplay, attribs1, nullptr, 0, &num_configs) != EGL_TRUE)
        __android_log_print(ANDROID_LOG_ERROR, g_LogTag, "%s",
                            "eglChooseConfig() returned with an error");
    if (num_configs == 0)
        __android_log_print(ANDROID_LOG_ERROR, g_LogTag, "%s",
                            "eglChooseConfig() returned 0 matching config");

    // Get the first matching config
    EGLConfig egl_config;
    eglChooseConfig(g_EglDisplay, attribs1, &egl_config, 1, &num_configs);
    EGLint egl_format;
    eglGetConfigAttrib(g_EglDisplay, egl_config, EGL_NATIVE_VISUAL_ID, &egl_format);
    ANativeWindow_setBuffersGeometry(window, 0, 0, egl_format);

    const EGLint egl_context_attributes[] = { EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE };
    g_EglContext = eglCreateContext(g_EglDisplay, egl_config, EGL_NO_CONTEXT,
                                    egl_context_attributes);

    if (g_EglContext == EGL_NO_CONTEXT)
        __android_log_print(ANDROID_LOG_ERROR, g_LogTag, "%s",
                            "eglCreateContext() returned EGL_NO_CONTEXT");

    g_EglSurface = eglCreateWindowSurface(g_EglDisplay, egl_config, window, NULL);
    eglMakeCurrent(g_EglDisplay, g_EglSurface, g_EglSurface, g_EglContext);
}

void clearBuffers() {
    glViewport(0, 0, (int) ImGui::GetIO().DisplaySize.x, (int) ImGui::GetIO().DisplaySize.y);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);              // background color
}


void imguiMainWinStart() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame();
    ImGui::NewFrame();
}

void imguiMainWinEnd() {
    ImGui::Render();
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

int swapBuffers() {
    //opengl当前buff传递至屏幕
    if (eglSwapBuffers(g_EglDisplay, g_EglSurface)) {
        return 1;
    }
    LOGE("eglSwapBuffers  error = %u", glGetError());
    return 0;
}
char *Jstring2string(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");  //String
    jstring strencode = env->NewStringUTF("GB2312"); //"gb2312"
    jmethodID mid = env->GetMethodID(clsstring, "getBytes",
                                     "(Ljava/lang/String;)[B"); //getBytes(Str);
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid,
                                                         strencode); // String .getByte("GB2312");
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1);         //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);  //释放内存空间
    return rtn;
}

JNICALL void setPid(JNIEnv *env, jclass clazz, jint pid){
    g_pid = pid;
    if (ptrace(PTRACE_TRACEME, g_pid) < 0) {
        printf("主進程被跟蹤");
        kill(g_pid,9);
        exit(-1);
    }
    ptrace(PTRACE_TRACEME,g_pid ,0 ,0);
}

JNICALL jint
getPid(JNIEnv *env, jclass clazz, jstring PackageName){
    GpakName=Jstring2string(env,PackageName);
    pid = FindPID(GpakName);
    return pid;
}

int32_t handleInputEvent(MyInputEvent inputEvent) {
    return ImGui_ImplAndroid_HandleInputEvent(inputEvent);
}

// Helper to retrieve data placed into the assets/ directory (android/app/src/main/assets)
int GetAssetData(const char *filename, void **outData) {
    int num_bytes = 0;
    AAsset *asset_descriptor = AAssetManager_open(assetManager, filename, AASSET_MODE_BUFFER);
    if (asset_descriptor) {
        num_bytes = AAsset_getLength(asset_descriptor);
        *outData = IM_ALLOC(num_bytes);
        int64_t num_bytes_read = AAsset_read(asset_descriptor, *outData, num_bytes);
        AAsset_close(asset_descriptor);
        IM_ASSERT(num_bytes_read == num_bytes);
    }
    return num_bytes;
}


void InitMenu();

void *init(void *args) {
    if (!g_Initialized) {
        Gini();
        创建文件();
        创建文件2();
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        ImGuiStyle & style = ImGui::GetStyle();
        ImGui::StyleColorsLight();
        ImGui::StyleColorsClassic();//紫
        ImGui_ImplAndroid_Init(window);
        ImGui_ImplOpenGL3_Init("#version 300 es");
        /*style.Colors[ImGuiCol_Text] = ImColor(0,0,0,255);//文字
        style.Colors[ImGuiCol_WindowBg] = ImColor(0,197,249,155);//主题背景
        style.Colors[ImGuiCol_TitleBg] = ImColor(240,248,255,300);//点击外部的悬浮条
        style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(240,248,255,150);//缩小的悬浮条
        style.Colors[ImGuiCol_TitleBgActive] = ImColor(240,248,255,300);//打开的悬浮条
        style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.25f, 0.30f, 0.60f);//滑动条轨道颜色
        style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.55f, 0.53f, 0.55f, 0.51f);//滑动条颜色
        style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.56f, 1.00f);//点击滑动条外部颜色
        style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.91f);//滑动条点击长按颜色
        style.Colors[ImGuiCol_Button] = ImVec4(0.48f, 0.72f, 0.89f, 0.49f);//三角
        style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.50f, 0.69f, 0.99f, 0.68f);//三角长按
        style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.80f, 0.50f, 0.50f, 1.00f);//三角点击
        style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.85f);//角标颜色
        style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);//角标点击选中颜色
        style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);//角标点击外部颜色 
        style.ScrollbarRounding = 10; // 设置滚动条圆角
        style.ScrollbarSize = 5; // 设置滚动条宽度
        style.ScaleAllSizes(1.3); // 设置控件内距
        style.WindowRounding = 2; // 设置边框圆角     
        style.FrameBorderSize = 0.5; // 设置控件描边宽度
        style.WindowBorderSize = 0.5; // 设置框架描边宽度
        */
        style.GrabRounding = 5; // 设置滑块圆角
        style.GrabMinSize = 5; // 设置滑块宽度
        style.FrameRounding =5.0f;  // 控件圆角
        style.WindowTitleAlign = ImVec2(0.5, 0.5); // 设置标题居中
        //style.FramePadding = ImVec2(5, 5); // 设置标题栏宽度
        static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
        ImFontConfig icons_config;
        ImFontConfig CustomFont;
        CustomFont.FontDataOwnedByAtlas = false;
        icons_config.MergeMode = true;
        icons_config.PixelSnapH = true;
    
        ImFontConfig cfg;
        cfg.SizePixels = ((float) density / 20.0f);
        io.Fonts->AddFontFromMemoryTTF((void *)BaiduZY_data, BaiduZY_size, 30.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
        io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 30.0f, &icons_config, icons_ranges);
        memset(&玖, 0, sizeof(玖));
        ImGui::GetStyle().ScaleAllSizes(3.0f);
        g_Initialized = true;
    }
    //颜色初始化();
        //sleep(5);
        加载调试数据();
        clearBuffers();
        InitTexture();
        while(true) {
            imguiMainWinStart();
            InitMenu();
            imguiMainWinEnd();
            swapBuffers();
        }
}

static struct Ui
{
    float 圆角 = 25.0f;
    float 描边 = 0;
    float 框架描边 = 0;
    float 控件圆角 = 10.0f;

} TheUi;

static bool show_ChildMenu1 = true;
static bool show_ChildMenu2 = false;
static bool show_ChildMenu3 = false;
static bool show_ChildMenu4 = false;

void InitMenu() {
    //static float tpf = 0.0f;
    //static float fps = 0.0f;
    if(ImGui::Begin("PVP S31 ESP")){
        style = &ImGui::GetStyle();
        style->WindowMinSize = ImVec2(865, 580);
        style->WindowRounding = TheUi.圆角;
        style->FrameBorderSize = TheUi.描边; // 设置控件描边宽度
        style->WindowBorderSize = TheUi.框架描边; // 设置框架描边宽度
        style->FrameRounding = TheUi.控件圆角;  // 控件圆角
        /*
        if(tpf < 100.0f) {
            tpf += 100.0f / ImGui::GetIO().Framerate;
        } else {
            tpf = 0.0f;
            fps = ImGui::GetIO().Framerate;
        }
        */
        if(ImGui::BeginChild("##mMenu",ImVec2(200,0),false,ImGuiWindowFlags_NoScrollbar|ImGuiWindowFlags_NavFlattened));
        {
            //ImGui::BulletText("野怪绘制");
            //ImGui::BulletText("地图绘制");
            //ImGui::PushStyleColor( ImGuiCol_Button,ImColor(148, 112, 222, 255).Value);
            if(ImGui::Button(ICON_FA_DROPBOX" 功能",ImVec2(200,85)))
            {
                show_ChildMenu1 = true;
                show_ChildMenu2 = false;
                show_ChildMenu3 = false;
                show_ChildMenu4 = false;
            }
            //ImGui::PushStyleColor( ImGuiCol_Button,ImColor(69, 148, 119, 255).Value);
            if(ImGui::Button(ICON_FA_GAMEPAD" 设置",ImVec2(200,85)))
            {
                show_ChildMenu1 = false;
                show_ChildMenu2 = true;
                show_ChildMenu3 = false;
                show_ChildMenu4 = false;
            }
            //ImGui::PushStyleColor( ImGuiCol_Button,ImColor(249, 96, 26, 255).Value);
            if(ImGui::Button(ICON_FA_GIFT" 主题",ImVec2(200,85)))
            {
                show_ChildMenu1 = false;
                show_ChildMenu2 = false;
                show_ChildMenu3 = true;
                show_ChildMenu4 = false;
            }
            //ImGui::PushStyleColor( ImGuiCol_Button,ImColor(145, 235, 26, 255).Value);
            if(ImGui::Button(ICON_FA_CROSSHAIRS" 调试",ImVec2(200,85)))
            {
                show_ChildMenu1 = false;
                show_ChildMenu2 = false;
                show_ChildMenu3 = false;
                show_ChildMenu4 = true;
            }
            //ImGui::PopStyleColor(5);
            ImGui::EndChild();// 需要和ImGui::BeginChild成对出现。
        }
        
        
        
        
        ImGui::SameLine();
        
        if(show_ChildMenu1){
            if(ImGui::BeginChild("##功能",ImVec2(0,0),false,ImGuiWindowFlags_NavFlattened)){
        //ImGui::Text("按住又下角拖动改变窗口大小");
                //ImGui::Spacing();//间距
                //ImGui::Text(ICON_FA_ASTERISK"绘制配置");
                ImGui::Spacing();//间距
                if(ImGui::Checkbox("绘制初始化", &玖.开关.总开关)) {
                    const char *PackageName = "com.tencent.tmgp.sgame";
                    pid = FindPID(PackageName);
                    if (pid == 0) {
                        debugStr = "找不到进程";
                        //return 0;
                    }
                    libGameCore = ReadModule("libGameCore.so", 1);
                    libil2cpp = ReadModule("libil2cpp.so", 1);
                    libunity = ReadModule("libunity.so", 1);
                }
                ImGui::SameLine();
                /*
                if (ImGui::Button("上帝视角",ImVec2(170, 50)))
                {              
                  thread th(上帝);th.detach();
                }
                */
                ImGui::RadioButton("蓝方", &玖.设置.阵营, 1); ImGui::SameLine();
                ImGui::RadioButton("红方", &玖.设置.阵营, 2);
                /*ImGui::SameLine();
                if (ImGui::Button("关闭视角",ImVec2(160, 50)))
                {              
                  thread th(关闭);th.detach();
                }*/
                //ImGui::Spacing();//间距
                //ImGui::NewLine();
                //ImGui::Spacing();//间距
                ImGui::Checkbox("地图绘制", &玖.功能.地图);
                ImGui::SameLine();
                ImGui::Checkbox("实体绘制", &玖.功能.实体);
                ImGui::SameLine();
                ImGui::Checkbox("射线绘制", &玖.功能.射线);
                //ImGui::SameLine();
                //ImGui::NewLine();
                ImGui::Spacing();//间距
                ImGui::Checkbox("兵线计时", &玖.功能.兵线);
                ImGui::SameLine();
                ImGui::Checkbox("野怪计时", &玖.功能.野怪);
                ImGui::SameLine();
                ImGui::Checkbox("技能计时", &玖.功能.技能);
                ImGui::Spacing();//间距
                
                if (ImGui::CollapsingHeader("野怪计时设置")) {
                    ImGui::Checkbox("小怪", &玖.功能.计时.小怪);
                    ImGui::SameLine();
                    ImGui::Checkbox("BUFF", &玖.功能.计时.BUFF);
                }
                ImGui::Spacing();//间距
                if (ImGui::CollapsingHeader("技能计时设置")) {
                    ImGui::Checkbox("主动", &玖.功能.计时.主动);
                    ImGui::SameLine();
                    ImGui::Checkbox("召唤", &玖.功能.计时.召唤);
                    ImGui::SameLine();
                    ImGui::Checkbox("大招", &玖.功能.计时.大招);
                }
                ImGui::Spacing();//间距
                if (ImGui::CollapsingHeader("实体计时设置")) {
                    ImGui::Checkbox("主动", &玖.功能.计时.主动2);
                    ImGui::SameLine();
                    ImGui::Checkbox("召唤", &玖.功能.计时.召唤2);
                    ImGui::SameLine();
                    ImGui::Checkbox("大招", &玖.功能.计时.大招2);
                }
                ImGui::EndChild();// 需要和ImGui::BeginChild成对出现。
        }
    }
        if(show_ChildMenu2){
            if(ImGui::BeginChild("##设置",ImVec2(0,0),false,ImGuiWindowFlags_NavFlattened)){
                ImGui::Spacing();//间距
                ImGui::SliderInt("地图上下",&玖.设置.地图上下,-50,50);
                //ImGui::Spacing();//间距
                ImGui::SliderInt("地图左右",&玖.设置.地图左右,-50,50);
                //ImGui::Spacing();//间距
                ImGui::SliderInt("实体上下",&玖.设置.实体上下,-50,50);
                //ImGui::Spacing();//间距
                ImGui::SliderInt("实体左右",&玖.设置.实体左右,-50,50);
                //ImGui::Spacing();//间距
                ImGui::SliderInt("分辨率长", &玖.设置.分辨率X, 2000, 3000);
                ImGui::SliderInt("分辨率宽", &玖.设置.分辨率Y, 500, 2000);
                if(ImGui::Button("保存配置",ImVec2(385, 80)))
                {
                    写入调试数据();
                }
                ImGui::EndChild();// 需要和ImGui::BeginChild成对出现。
        }
    }
    if(show_ChildMenu3){
        if(ImGui::BeginChild("##主题",ImVec2(0,0),false,ImGuiWindowFlags_NavFlattened)){
            ImGui::Spacing();//间距
            SetThemel("##Selector");
            ImGui::Spacing();//间距
            ImGui::ColorEdit4("射线颜色", (float*)&Colline);
            ImGui::Spacing();//间距
            ImGui::ColorEdit4("野怪颜色", (float*)&Colmonster);
            ImGui::Spacing();//间距
            ImGui::ColorEdit4("血量健康", (float*)&Colblood1);
            ImGui::Spacing();//间距
            ImGui::ColorEdit4("血量良好", (float*)&Colblood2);
            ImGui::Spacing();//间距
            ImGui::ColorEdit4("血量告急", (float*)&Colblood3);
            ImGui::EndChild();// 需要和ImGui::BeginChild成对出现。
        } 
    }
        
    if(show_ChildMenu4){
        if(ImGui::BeginChild("##调试",ImVec2(0,0),false,ImGuiWindowFlags_NavFlattened)){
            //ImGui::Text(ICON_FA_ASTERISK"调试信息");
            ImGui::Spacing();//间距
            //ImGui::BulletText("FPS: %.1f", fps);
            ImGui::Spacing();//间距
            ImGui::BulletText(("进程PID: %d"),pid);
            ImGui::Spacing();//间距
            ImGui::BulletText(("libGameCore: 0x%lX"),libGameCore);
            ImGui::Spacing();//间距
            ImGui::BulletText(("libil2cpp: 0x%lX"),libil2cpp);  
            ImGui::Spacing();//间距
            ImGui::BulletText("调试信息: %s", getString().c_str());
            ImGui::Spacing();//间距
            ImGui::Spacing();//间距
            ImGui::SameLine(0.0f, 120.0f);
            ImGui::EndChild();// 需要和ImGui::BeginChild成对出现。
        }   
     }
  }
    绘制();
    menuPos.w = ImGui::GetWindowWidth();
    menuPos.h = ImGui::GetWindowHeight();
    //if (real_w > real_h) {
        
    //}
    menuPos.x = ImGui::GetWindowPos().x;
    menuPos.y = ImGui::GetWindowPos().y;
    ImGui::End();
    
}



extern "C" {
    


//初始化opengl窗口
JNICALL void setSurface(JNIEnv *env, jclass cla, jobject surface) {
    window = ANativeWindow_fromSurface(env, surface);
    ANativeWindow_acquire(window);
    pthread_t t1;
    pthread_create(&t1, NULL, init, NULL);
    //thread_join(t1,NULL);
}

//获取触摸事件
JNIEXPORT void JNICALL
Java_com_liccsu_natool_SuperJNI_navateInputEvent(JNIEnv *env, jclass obj, jobject motionEvent) {
    if (g_Initialized) {
        jclass eventClss = env->GetObjectClass(motionEvent);
        jmethodID methodId = env->GetMethodID(eventClss, "getAction", "()I");
        inputEvent.Action = env->CallIntMethod(motionEvent, methodId);
        methodId = env->GetMethodID(eventClss, "getRawX", "()F");
        inputEvent.x = env->CallFloatMethod(motionEvent, methodId);
        methodId = env->GetMethodID(eventClss, "getRawY", "()F");
        inputEvent.y = env->CallFloatMethod(motionEvent, methodId);
        int32_t event_pointer_index = (inputEvent.Action & 65280) >> 8;
        methodId = env->GetMethodID(eventClss, "getToolType", "(I)I");
        inputEvent.ToolType = env->CallIntMethod(motionEvent, methodId, event_pointer_index);
        methodId = env->GetMethodID(eventClss, "getButtonState", "()I");
        inputEvent.ButtonState = env->CallIntMethod(motionEvent, methodId);
        methodId = env->GetMethodID(eventClss, "getAxisValue", "(II)F");
        inputEvent.AXIS_VSCROLL = env->CallFloatMethod(motionEvent, methodId, 9,
                                                       event_pointer_index);
        inputEvent.AXIS_HSCROLL = env->CallFloatMethod(motionEvent, methodId, 10,
                                                       event_pointer_index);
        handleInputEvent(inputEvent);
    }
}
JNIEXPORT jfloat JNICALL Java_com_liccsu_natool_SuperJNI_getMenuW(JNIEnv *env, jclass clazz) {
    return menuPos.w;
}

JNIEXPORT jfloat JNICALL Java_com_liccsu_natool_SuperJNI_getMenuH(JNIEnv *env, jclass clazz) {
    return menuPos.h;
}
JNIEXPORT jfloat JNICALL Java_com_liccsu_natool_SuperJNI_getMenuX(JNIEnv *env, jclass clazz) {
    return menuPos.x;
}
JNIEXPORT jfloat JNICALL Java_com_liccsu_natool_SuperJNI_getMenuY(JNIEnv *env, jclass clazz) {
    return menuPos.y;
}



/*****************************************
*   native方法注册辅助函数
*****************************************/
#ifndef NELEM
# define NELEM(x) ((int) (sizeof(x) / sizeof((x)[0])))
#endif
int jniRegisterNativeMethods(JNIEnv *env, const char *className,
                             JNINativeMethod *gMethods, int numMethods) {
    jclass clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}





/**********************************************
*    java层的方法与native映射标
**********************************************/
static JNINativeMethod native_method_table[] = {
        {"setSurface", "(Landroid/view/Surface;)V", 
        (void *) setSurface},
        
        {"setPid", "(I)V", 
        (void *) setPid},
        
        {"getPID", "(Ljava/lang/String;)I",
        (void *) getPid},
};

int register_native_api(JNIEnv *env) {
    return jniRegisterNativeMethods(env, "com/liccsu/natool/SuperJNI", native_method_table,
                                    NELEM(native_method_table));
}


jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if (vm->GetEnv((void **) (&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    assert(env != NULL);
    if (!register_native_api(env)) {//注册接口
        return -1;
    }
    return JNI_VERSION_1_6;
}

}



    


