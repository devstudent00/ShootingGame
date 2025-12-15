#pragma once
#include <DxLib.h>
#include <string>

enum DrawType {
    LEFT,
    CENTER,
    RIGHT
};

namespace GameUtil {

    inline void DrawFixText(DrawType type, int x, int y, unsigned int text_color, unsigned int edge_color, std::string text) {
        int strWidth = GetDrawStringWidth(text.c_str(), strlen(text.c_str()));
        if (type == DrawType::LEFT) {
            //
        }
        else if (type == DrawType::RIGHT) {
            x -= strWidth;
        }
        else if (type == DrawType::CENTER) {
            x -= strWidth / 2;
            y -= GetFontSize() / 2;
        }


        DrawString(x, y, text.c_str(), text_color, edge_color);
    }
}
