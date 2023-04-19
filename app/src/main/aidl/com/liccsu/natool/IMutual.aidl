// ITestService.aidl
package com.liccsu.natool;

// Declare any non-default types here with import statements

interface IMutual {
    void setSurface(in Surface surface);
    void navateInputEvent(in MotionEvent motionEvent);
    float getMenuW();
    float getMenuH();
    float getMenuX();
    float getMenuY();
    void setPid(int pid);
    int getPID(String packageName);
    /*
    void setWidth(int width);
    void setHeight(int height);
    void setFilesDir(String filesDir);
    */
}
