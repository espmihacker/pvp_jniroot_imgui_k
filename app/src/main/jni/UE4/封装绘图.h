//
// Created by Administrator on 2022/2/28.
//

#ifndef MY_LICCSU_FZHT
#define MY_LICCSU_FZHT
/*
 *DrawText
 * 参数1：屏幕x
 * 参数2：屏幕y
 * 参数3：透明度 最小值0  最大值1.0F
 * 参数4：红色 最小值0  最大值1.0F
 * 参数5：绿色 最小值0  最大值1.0F
 * 参数6：蓝色 最小值0  最大值1.0F
 * 参数7：绘制字符串
 */
 class ImguiInEgl { ;
void ImguiInEgl::DrawText(float X, float Y, float a, float r, float g, float b, const char *data) {
    ImGui::GetBackgroundDrawList()->AddText(imFont, imFont->FontSize, ImVec2(X, Y), ImColor(r, g, b, a), data);
}

void ImguiInEgl::DrawText(float X, float Y, const char *data) {
    ImGui::GetBackgroundDrawList()->AddText(imFont, imFont->FontSize, ImVec2(X, Y), TextColor, data);
}

void ImguiInEgl::DrawTextCx(float X, float Y, float a, float r, float g, float b, const char *data) {
    ImGui::GetBackgroundDrawList()->AddText(imFont, imFont->FontSize, ImVec2(X -= ((int) ImGui::CalcTextSize(data).x >> 1), Y), ImColor(r, g, b, a), data);
}

void ImguiInEgl::DrawTextCx(float X, float Y, const char *data) {
    ImGui::GetBackgroundDrawList()->AddText(imFont, imFont->FontSize, ImVec2(X -= ((int) ImGui::CalcTextSize(data).x >> 1), Y), TextColor, data);
}

void ImguiInEgl::DrawTextCy(float X, float Y, float a, float r, float g, float b, const char *data) {
    ImGui::GetBackgroundDrawList()->AddText(imFont, imFont->FontSize, ImVec2(X, Y -= ((int) ImGui::CalcTextSize(data).y >> 1)), ImColor(r, g, b, a), data);
}

void ImguiInEgl::DrawTextCy(float X, float Y, const char *data) {
    ImGui::GetBackgroundDrawList()->AddText(imFont, imFont->FontSize, ImVec2(X, Y -= ((int) ImGui::CalcTextSize(data).y >> 1)), TextColor, data);
}

void ImguiInEgl::DrawTextCxy(float X, float Y, float a, float r, float g, float b, const char *data) {
    auto size = ImGui::CalcTextSize(data);
    ImGui::GetBackgroundDrawList()->AddText(imFont, imFont->FontSize, ImVec2(X -= ((int) size.x >> 1), Y -= ((int) size.y >> 1)), ImColor(r, g, b, a), data);
}

void ImguiInEgl::DrawTextCxy(float X, float Y, ImColor &color, const char *data) {
    auto size = ImGui::CalcTextSize(data);
    ImGui::GetBackgroundDrawList()->AddText(imFont, imFont->FontSize, ImVec2(X -= ((int) size.x >> 1), Y -= ((int) size.y >> 1)), color, data);
}

void ImguiInEgl::DrawTextCxy(float X, float Y, ImColor *color, const char *data) {
    auto size = ImGui::CalcTextSize(data);
    ImGui::GetBackgroundDrawList()->AddText(imFont, imFont->FontSize, ImVec2(X -= ((int) size.x >> 1), Y -= ((int) size.y >> 1)), *color, data);
}


void ImguiInEgl::DrawTextCxy(float X, float Y, ImColor color, const char *data) {
    auto size = ImGui::CalcTextSize(data);
    ImGui::GetBackgroundDrawList()->AddText(imFont, imFont->FontSize, ImVec2(X -= ((int) size.x >> 1), Y -= ((int) size.y >> 1)), color, data);
}

void ImguiInEgl::DrawTextCxy(float X, float Y, const char *data) {
    auto size = ImGui::CalcTextSize(data);
    ImGui::GetBackgroundDrawList()->AddText(imFont, imFont->FontSize, ImVec2(X -= ((int) size.x >> 1), Y -= ((int) size.y >> 1)), TextColor, data);
}

/*
 *DrawLine
 * 参数1：屏幕x 开始
 * 参数2：屏幕y 开始
 * 参数3：屏幕x 结束
 * 参数4：屏幕y 结束
 * 参数5：透明度 最小值0  最大值1.0F
 * 参数6：红色 最小值0  最大值1.0F
 * 参数7：绿色 最小值0  最大值1.0F
 * 参数8：蓝色 最小值0  最大值1.0F
 * 参数9：线条宽度
 */
void ImguiInEgl::DrawLine(float startx, float starty, float endx, float endy, float a, float r, float g, float b, float thickness) {
    ImGui::GetBackgroundDrawList()->AddLine(ImVec2(startx, starty), ImVec2(endx, endy), ImColor(r, g, b, a), thickness);
}

void ImguiInEgl::DrawLine(float startx, float starty, float endx, float endy, float a, float r, float g, float b) {
    ImGui::GetBackgroundDrawList()->AddLine(ImVec2(startx, starty), ImVec2(endx, endy), ImColor(r, g, b, a), LineThickness);
}

void ImguiInEgl::DrawLine(float startx, float starty, float endx, float endy, ImColor &color, float thickness) {
    ImGui::GetBackgroundDrawList()->AddLine(ImVec2(startx, starty), ImVec2(endx, endy), color, thickness);
}

void ImguiInEgl::DrawLine(float startx, float starty, float endx, float endy, ImColor &color) {
    ImGui::GetBackgroundDrawList()->AddLine(ImVec2(startx, starty), ImVec2(endx, endy), color, LineThickness);
}

void ImguiInEgl::DrawLine(float startx, float starty, float endx, float endy) {
    ImGui::GetBackgroundDrawList()->AddLine(ImVec2(startx, starty), ImVec2(endx, endy), LineColor, LineThickness);
}

/*
 *DrawLine
 * 参数1：屏幕x,y 排列的连续数组
 * 参数2：线段数量
 * 参数3：透明度 最小值0  最大值1.0F
 * 参数4：红色 最小值0  最大值1.0F
 * 参数5：绿色 最小值0  最大值1.0F
 * 参数6：蓝色 最小值0  最大值1.0F
 * 参数7：线条宽度
 */
void ImguiInEgl::DrawLines(float *points, int points_count, float a, float r, float g, float b, float thickness) {
    ImGui::GetBackgroundDrawList()->AddPolyline((ImVec2 *) points, points_count, ImColor(r, g, b, a), 0, thickness);

}

void ImguiInEgl::DrawLines(float *points, int points_count, float a, float r, float g, float b) {
    ImGui::GetBackgroundDrawList()->AddPolyline((ImVec2 *) points, points_count, ImColor(r, g, b, a), 0, LinesThickness);

}

void ImguiInEgl::DrawLines(float *points, int points_count, ImColor &color, float thickness) {
    ImGui::GetBackgroundDrawList()->AddPolyline((ImVec2 *) points, points_count, color, 0, thickness);

}

void ImguiInEgl::DrawLines(float *points, int points_count, ImColor &color) {
    ImGui::GetBackgroundDrawList()->AddPolyline((ImVec2 *) points, points_count, color, 0, LinesThickness);

}

void ImguiInEgl::DrawLines(float *points, int points_count) {
    ImGui::GetBackgroundDrawList()->AddPolyline((ImVec2 *) points, points_count, LinesColor, 0, LinesThickness);

}

/*
 *DrawRect
 * 参数1：屏幕x 左上
 * 参数2：屏幕y 左上
 * 参数3：屏幕x 右下
 * 参数4：屏幕y 右下
 * 参数5：透明度 最小值0  最大值1.0F
 * 参数6：红色 最小值0  最大值1.0F
 * 参数7：绿色 最小值0  最大值1.0F
 * 参数8：蓝色 最小值0  最大值1.0F
 * 参数9：方框四角角度 0 为直角线条
 * 参数10：线条宽度
 */
void ImguiInEgl::DrawRect(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY, float a, float r, float g, float b, float rounding, float thickness) {
    ImGui::GetBackgroundDrawList()->AddRect(ImVec2(upper_leftX, upper_leftY), ImVec2(lower_rightX, lower_rightY), ImColor(r, g, b, a), rounding, ImDrawFlags_RoundCornersAll, thickness);
}

void ImguiInEgl::DrawRect(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY, float a, float r, float g, float b, float thickness) {
    ImGui::GetBackgroundDrawList()->AddRect(ImVec2(upper_leftX, upper_leftY), ImVec2(lower_rightX, lower_rightY), ImColor(r, g, b, a), RectRounding, ImDrawFlags_RoundCornersAll, thickness);
}

void ImguiInEgl::DrawRect(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY, ImColor &color, float thickness) {
    ImGui::GetBackgroundDrawList()->AddRect(ImVec2(upper_leftX, upper_leftY), ImVec2(lower_rightX, lower_rightY), color, RectRounding, ImDrawFlags_RoundCornersAll, thickness);
}

void ImguiInEgl::DrawRect(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY, float a, float r, float g, float b) {
    ImGui::GetBackgroundDrawList()->AddRect(ImVec2(upper_leftX, upper_leftY), ImVec2(lower_rightX, lower_rightY), ImColor(r, g, b, a), RectRounding, ImDrawFlags_RoundCornersAll, RectThickness);
}

void ImguiInEgl::DrawRect(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY) {
    ImGui::GetBackgroundDrawList()->AddRect(ImVec2(upper_leftX, upper_leftY), ImVec2(lower_rightX, lower_rightY), RectColor, RectRounding, ImDrawFlags_RoundCornersAll, RectThickness);
}

void ImguiInEgl::DrawRectCxy(float centerX, float centerY, int width, int high, float a, float r, float g, float b, float rounding, float thickness) {
    ImGui::GetBackgroundDrawList()->AddRect(ImVec2(centerX - (width >> 1), centerY - (high >> 1)), ImVec2(centerX + (width >> 1), centerY + (high >> 1)), ImColor(r, g, b, a), rounding, ImDrawFlags_RoundCornersAll, thickness);
}

void ImguiInEgl::DrawRectCxy(float centerX, float centerY, int width, int high, ImColor &color, float rounding, float thickness) {
    ImGui::GetBackgroundDrawList()->AddRect(ImVec2(centerX - (width >> 1), centerY - (high >> 1)), ImVec2(centerX + (width >> 1), centerY + (high >> 1)), color, rounding, ImDrawFlags_RoundCornersAll, thickness);
}

void ImguiInEgl::DrawRectCxy(float centerX, float centerY, int width, int high, ImColor *color, float rounding, float thickness) {
    ImGui::GetBackgroundDrawList()->AddRect(ImVec2(centerX - (width >> 1), centerY - (high >> 1)), ImVec2(centerX + (width >> 1), centerY + (high >> 1)), *color, rounding, ImDrawFlags_RoundCornersAll, thickness);
}


void ImguiInEgl::DrawRectCxy(float centerX, float centerY, int width, int high, float a, float r, float g, float b, float thickness) {
    ImGui::GetBackgroundDrawList()->AddRect(ImVec2(centerX - (width >> 1), centerY - (high >> 1)), ImVec2(centerX + (width >> 1), centerY + (high >> 1)), ImColor(r, g, b, a), RectRounding, ImDrawFlags_RoundCornersAll, thickness);
}

void ImguiInEgl::DrawRectCxy(float centerX, float centerY, int width, int high, float a, float r, float g, float b) {
    ImGui::GetBackgroundDrawList()->AddRect(ImVec2(centerX - (width >> 1), centerY - (high >> 1)), ImVec2(centerX + (width >> 1), centerY + (high >> 1)), ImColor(r, g, b, a), RectRounding, ImDrawFlags_RoundCornersAll, RectThickness);
}

void ImguiInEgl::DrawRectCxy(float centerX, float centerY, int width, int high) {
    ImGui::GetBackgroundDrawList()->AddRect(ImVec2(centerX - (width >> 1), centerY - (high >> 1)), ImVec2(centerX + (width >> 1), centerY + (high >> 1)), RectColor, RectRounding, ImDrawFlags_RoundCornersAll, RectThickness);
}


/*
 *DrawRectFilled
 * 参数1：屏幕x 左上
 * 参数2：屏幕y 左上
 * 参数3：屏幕x 右下
 * 参数4：屏幕y 右下
 * 参数5：透明度 最小值0  最大值1.0F
 * 参数6：红色 最小值0  最大值1.0F
 * 参数7：绿色 最小值0  最大值1.0F
 * 参数8：蓝色 最小值0  最大值1.0F
 * 参数9：方框四角角度 0 为直角线条
 */
void ImguiInEgl::DrawRectFilled(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY, float a, float r, float g, float b, float rounding) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(upper_leftX, upper_leftY), ImVec2(lower_rightX, lower_rightY), ImColor(r, g, b, a), rounding);
}

void ImguiInEgl::DrawRectFilled(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY, float a, float r, float g, float b) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(upper_leftX, upper_leftY), ImVec2(lower_rightX, lower_rightY), ImColor(r, g, b, a), RectFilledRounding);
}

void ImguiInEgl::DrawRectFilled(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY, ImColor &color, float rounding) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(upper_leftX, upper_leftY), ImVec2(lower_rightX, lower_rightY), color, rounding);
}

void ImguiInEgl::DrawRectFilled(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY, ImColor &color) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(upper_leftX, upper_leftY), ImVec2(lower_rightX, lower_rightY), color, RectFilledRounding);
}


void ImguiInEgl::DrawRectFilled(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(upper_leftX, upper_leftY), ImVec2(lower_rightX, lower_rightY), RectFilledColor, RectFilledRounding);
}

void ImguiInEgl::DrawRectFilledCxy(float centerX, float centerY, int width, int high, float a, float r, float g, float b, float rounding) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(centerX - (width >> 1), centerY - (high >> 1)), ImVec2(centerX + (width >> 1), centerY + (high >> 1)), ImColor(r, g, b, a), rounding);
}

void ImguiInEgl::DrawRectFilledCxy(float centerX, float centerY, int width, int high, ImColor &color, float rounding) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(centerX - (width >> 1), centerY - (high >> 1)), ImVec2(centerX + (width >> 1), centerY + (high >> 1)), color, rounding);
}

void ImguiInEgl::DrawRectFilledCxy(float centerX, float centerY, int width, int high, float a, float r, float g, float b) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(centerX - (width >> 1), centerY - (high >> 1)), ImVec2(centerX + (width >> 1), centerY + (high >> 1)), ImColor(r, g, b, a), RectFilledRounding);
}

void ImguiInEgl::DrawRectFilledCxy(float centerX, float centerY, int width, int high, ImColor &color) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(centerX - (width >> 1), centerY - (high >> 1)), ImVec2(centerX + (width >> 1), centerY + (high >> 1)), color, RectFilledRounding);
}

void ImguiInEgl::DrawRectFilledCxy(float centerX, float centerY, int width, int high) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(centerX - (width >> 1), centerY - (high >> 1)), ImVec2(centerX + (width >> 1), centerY + (high >> 1)), RectFilledColor, RectFilledRounding);
}

/*
 *DrawCircle
 * 参数1：屏幕x 圆中心
 * 参数2：屏幕y 圆中心
 * 参数3：圆半径
 * 参数4：透明度 最小值0  最大值1.0F
 * 参数5：红色 最小值0  最大值1.0F
 * 参数6：绿色 最小值0  最大值1.0F
 * 参数7：蓝色 最小值0  最大值1.0F
 * 参数8：圆，线条数量  默认0为完整圆形， 填入指定的参数生成指定线段的圆
 * 参数9：圆，线条宽度
 */
void ImguiInEgl::DrawCircle(float X, float Y, float radius, float a, float r, float g, float b, int num_segments, float thickness) {
    ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(X, Y), radius, ImColor(r, g, b, a), num_segments, thickness);
}

void ImguiInEgl::DrawCircle(float X, float Y, float radius, float a, float r, float g, float b, float thickness) {
    ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(X, Y), radius, ImColor(r, g, b, a), CircleNum_segments, thickness);
}

void ImguiInEgl::DrawCircle(float X, float Y, float radius, float a, float r, float g, float b) {
    ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(X, Y), radius, ImColor(r, g, b, a), CircleNum_segments, CircleThickness);
}

void ImguiInEgl::DrawCircle(float X, float Y, float radius) {
    ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(X, Y), radius, CircleColor, CircleNum_segments, CircleThickness);
}

/*
 *CircleFilled
 * 参数1：屏幕x 圆中心
 * 参数2：屏幕y 圆中心
 * 参数3：圆半径
 * 参数4：透明度 最小值0  最大值1.0F
 * 参数5：红色 最小值0  最大值1.0F
 * 参数6：绿色 最小值0  最大值1.0F
 * 参数7：蓝色 最小值0  最大值1.0F
 * 参数8：圆，线条数量  默认0为完整圆形， 填入指定的参数生成指定线段的圆
 */
void ImguiInEgl::DrawCircleFilled(float X, float Y, float radius, float a, float r, float g, float b, int num_segments) {
    ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(X, Y), radius, ImColor(r, g, b, a), num_segments);
}

void ImguiInEgl::DrawCircleFilled(float X, float Y, float radius, float a, float r, float g, float b) {
    ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(X, Y), radius, ImColor(r, g, b, a), CircleFilledNum_segments);
}

void ImguiInEgl::DrawCircleFilled(float X, float Y, float radius, ImColor &color, int num_segments) {
    ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(X, Y), radius, color, num_segments);
}

void ImguiInEgl::DrawCircleFilled(float X, float Y, float radius, ImColor &color) {
    ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(X, Y), radius, color, CircleFilledNum_segments);
}

void ImguiInEgl::DrawCircleFilled(float X, float Y, float radius) {
    ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(X, Y), radius, CircleFilledColor, CircleFilledNum_segments);
}

 ImVec4  clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    //绘制文字封装
    //默认颜色
    ImColor TextColor   = ImColor(1.0f, 1.0f, 1.0f, 1.0f);

    void DrawText(float X, float Y, float a, float r, float g, float b, const char *data);

    void DrawText(float X, float Y, const char *data);

    //已X轴居中
    void DrawTextCx(float X_centerX, float X_centerY, float a, float r, float g, float b, const char *data);

    void DrawTextCx(float X_centerX, float X_centerY, const char *data);

    //已Y轴居中
    void DrawTextCy(float Y_centerX, float Y_centerY, float a, float r, float g, float b, const char *data);

    void DrawTextCy(float Y_centerX, float Y_centerY, const char *data);

    //已XY轴居中
    void DrawTextCxy(float centerX, float centerY, float a, float r, float g, float b, const char *data);

    void DrawTextCxy(float centerX, float centerY, ImColor &color, const char *data);

    void DrawTextCxy(float centerX, float centerY, ImColor *color, const char *data);

    void DrawTextCxy(float centerX, float centerY, ImColor color, const char *data);

    void DrawTextCxy(float centerX, float centerY, const char *data);

    //绘制线条封装
    //默认颜色
    ImColor LineColor     = ImColor(1.0f, 0.0f, 0.0f, 1.0f);
    //默认宽度
    float   LineThickness = 1.0f;

    void DrawLine(float startX, float startY, float endX, float endY, float a, float r, float g, float b, float thickness);

    void DrawLine(float startX, float startY, float endX, float endY, float a, float r, float g, float b);

    void DrawLine(float startX, float startY, float endX, float endY, ImColor &color, float thickness);

    void DrawLine(float startX, float startY, float endX, float endY, ImColor &color);

    void DrawLine(float startX, float startY, float endX, float endY);

    //绘制多线段封装
    //默认颜色
    ImColor LinesColor     = ImColor(1.0f, 1.0f, 0.0f, 1.0f);
    //默认宽度
    float   LinesThickness = 2.0f;

    void DrawLines(float *points, int points_count, float a, float r, float g, float b, float thickness);

    void DrawLines(float *points, int points_count, float a, float r, float g, float b);

    void DrawLines(float *points, int points_count, ImColor &color, float thickness);

    void DrawLines(float *points, int points_count, ImColor &color);

    void DrawLines(float *points, int points_count);

    //绘制空心矩形封装
    //默认颜色
    ImColor RectColor     = ImColor(1.0f, 0.0f, 0.0f, 1.0f);
    //默认宽度
    float   RectThickness = 2.0f;
    //默认圆角
    float   RectRounding  = 0.0f;

    void DrawRect(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY, float a, float r, float g, float b, float rounding, float thickness);

    void DrawRect(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY, float a, float r, float g, float b, float thickness);

    void DrawRect(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY, ImColor &color, float thickness);

    void DrawRect(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY, float a, float r, float g, float b);

    void DrawRect(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY);

    void DrawRectCxy(float centerX, float centerY, int width, int high, float a, float r, float g, float b, float rounding, float thickness);

    void DrawRectCxy(float centerX, float centerY, int width, int high, ImColor &color, float rounding, float thickness);

    void DrawRectCxy(float centerX, float centerY, int width, int high, ImColor *color, float rounding, float thickness);

    void DrawRectCxy(float centerX, float centerY, int width, int high, float a, float r, float g, float b, float thickness);

    void DrawRectCxy(float centerX, float centerY, int width, int high, float a, float r, float g, float b);

    void DrawRectCxy(float centerX, float centerY, int width, int high);

    //绘制填充矩形封装
    //默认颜色
    ImColor RectFilledColor    = ImColor(1.0f, 0.0f, 0.0f, 1.0f);
    //默认四角半径
    float   RectFilledRounding = 0.0f;

    void DrawRectFilled(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY, float a, float r, float g, float b, float rounding);

    void DrawRectFilled(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY, ImColor &color, float rounding);

    void DrawRectFilled(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY, float a, float r, float g, float b);

    void DrawRectFilled(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY, ImColor &color);

    void DrawRectFilled(float upper_leftX, float upper_leftY, float lower_rightX, float lower_rightY);

    void DrawRectFilledCxy(float centerX, float centerY, int width, int high, float a, float r, float g, float b, float rounding);

    void DrawRectFilledCxy(float centerX, float centerY, int width, int high, ImColor &color, float rounding);

    void DrawRectFilledCxy(float centerX, float centerY, int width, int high, float a, float r, float g, float b);

    void DrawRectFilledCxy(float centerX, float centerY, int width, int high, ImColor &color);

    void DrawRectFilledCxy(float centerX, float centerY, int width, int high);

    //绘制空心圆形封装
    //默认颜色
    ImColor CircleColor        = ImColor(1.0f, 1.0f, 1.0f, 1.0f);
    //默认宽度
    float   CircleThickness    = 2.0f;
    //默认圆边数量
    int     CircleNum_segments = 0;

    void DrawCircle(float centerX, float centerY, float radius, float a, float r, float g, float b, int num_segments, float thickness);

    void DrawCircle(float centerX, float centerY, float radius, float a, float r, float g, float b, float thickness);

    void DrawCircle(float centerX, float centerY, float radius, float a, float r, float g, float b);

    void DrawCircle(float centerX, float centerY, float radius);

    //绘制圆形填充封装
    //默认颜色
    ImColor CircleFilledColor        = ImColor(1.0f, 1.0f, 1.0f, 1.0f);
    //默认圆边数量
    int     CircleFilledNum_segments = 0;

    void DrawCircleFilled(float centerX, float centerY, float radius, float a, float r, float g, float b, int num_segments);

    void DrawCircleFilled(float centerX, float centerY, float radius, ImColor &color, int num_segments);

    void DrawCircleFilled(float centerX, float centerY, float radius, float a, float r, float g, float b);

    void DrawCircleFilled(float centerX, float centerY, float radius, ImColor &color);

    void DrawCircleFilled(float centerX, float centerY, float radius);

#endif
