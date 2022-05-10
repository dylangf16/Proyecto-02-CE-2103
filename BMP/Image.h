//
// Created by dylan16 on 02/05/22.
//

#ifndef BMP_IMAGE_H
#define BMP_IMAGE_H

#include <vector>
#include <iostream>
using namespace std;

struct Color
{
    float r, g, b;

    Color();
    Color(float r, float g, float b);
    ~Color();
};

class Image
{
public:
    Image(int width, int height);
    ~Image();

    Color GetColor(int x, int y) const;
    std::vector<Color> GetAllColors();
    void setColor(const Color& color, int x, int y);
    std::vector<std::vector<string>> BMPtoMatrix();

    void Read(const char* path);
    void createWhiteCanvas();
    void Export(const char *path) const;

private:
    int m_width;
    int m_height;
    std::vector<Color> m_colors;
};

#endif //BMP_IMAGE_H
